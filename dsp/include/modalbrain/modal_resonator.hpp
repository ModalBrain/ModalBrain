#pragma once

#include "denormals.hpp"
#include <cmath>
#include <numbers>
#include <algorithm>

namespace modalbrain::dsp {

/**
 * @brief High-performance second-order real-time modal resonator filter.
 * 
 * Implements an impulse-invariant second-order resonant bandpass mode:
 *   y[n] = 2 * r * cos(theta) * y[n-1] - r^2 * y[n-2] + b0 * x[n]
 * 
 * Features:
 * - Zero allocations on the audio processing thread.
 * - Dynamic parameter dezippering via one-pole parameter smoothing.
 * - Sample-rate agnostic coefficient computation.
 * - Denormal and NaN protection.
 */
class ModalResonator {
public:
    ModalResonator() noexcept = default;

    /**
     * @brief Initialize resonator with the audio hardware sample rate.
     */
    void prepare(float sampleRate) noexcept {
        mSampleRate = (sampleRate > 1000.0f) ? sampleRate : 48000.0f;
        mInverseSampleRate = 1.0f / mSampleRate;
        reset();
        calculateCoefficients(true);
    }

    /**
     * @brief Clear internal filter delay registers.
     */
    void reset() noexcept {
        mY1 = 0.0f;
        mY2 = 0.0f;
    }

    /**
     * @brief Target modal frequency in Hertz (Hz).
     */
    void setFrequency(float freqHz) noexcept {
        // Clamp modal frequency between 10 Hz and Nyquist (0.49 * Fs)
        const float nyquist = 0.49f * mSampleRate;
        mTargetFreq = std::clamp(freqHz, 10.0f, nyquist);
    }

    /**
     * @brief Target decay time (T60) in seconds.
     * Duration for the resonance energy to decay by 60 dB.
     */
    void setDecay(float t60Seconds) noexcept {
        // Clamp decay time between 1 millisecond and 30 seconds
        mTargetDecay = std::clamp(t60Seconds, 0.001f, 30.0f);
    }

    /**
     * @brief Set modal output amplitude / excitation gain weight.
     */
    void setGain(float gain) noexcept {
        mTargetGain = std::max(0.0f, gain);
    }

    /**
     * @brief Process a single sample through the modal resonator.
     * Guaranteed noexcept and zero allocation.
     */
    [[nodiscard]] inline float processSample(float inSample) noexcept {
        // Smooth parameters to prevent zipper artifacts
        interpolateParameters();

        // Modal discrete equation: y[n] = a1 * y[n-1] + a2 * y[n-2] + b0 * x[n]
        float y0 = (mA1 * mY1) + (mA2 * mY2) + (mB0 * inSample) + DenormalGuard::kAntiDenormalOffset;

        // Anti-denormal flush & safety bound
        y0 = DenormalGuard::flush(y0);
        if (!DenormalGuard::isAudioFinite(y0)) {
            reset();
            return 0.0f;
        }

        mY2 = mY1;
        mY1 = y0;

        return y0 * mCurGain;
    }

    /**
     * @brief Process a contiguous audio block in-place or from input to output buffer.
     */
    void processBlock(const float* inBuffer, float* outBuffer, std::size_t numSamples) noexcept {
        for (std::size_t i = 0; i < numSamples; ++i) {
            outBuffer[i] = processSample(inBuffer[i]);
        }
    }

private:
    void interpolateParameters() noexcept {
        constexpr float kSlew = 0.002f; // One-pole smoothing factor (~1-2 ms convergence)

        bool needsUpdate = false;
        if (std::abs(mTargetFreq - mCurFreq) > 0.01f) {
            mCurFreq += kSlew * (mTargetFreq - mCurFreq);
            needsUpdate = true;
        }
        if (std::abs(mTargetDecay - mCurDecay) > 0.0001f) {
            mCurDecay += kSlew * (mTargetDecay - mCurDecay);
            needsUpdate = true;
        }
        if (std::abs(mTargetGain - mCurGain) > 0.0001f) {
            mCurGain += kSlew * (mTargetGain - mCurGain);
        }

        if (needsUpdate) {
            calculateCoefficients(false);
        }
    }

    void calculateCoefficients(bool snapToTarget) noexcept {
        if (snapToTarget) {
            mCurFreq = mTargetFreq;
            mCurDecay = mTargetDecay;
            mCurGain = mTargetGain;
        }

        const float theta = 2.0f * std::numbers::pi_v<float> * mCurFreq * mInverseSampleRate;
        
        // Pole radius r derived from T60 decay: r = exp(-6.907755 / (T60 * Fs))
        // where 6.907755 = ln(1000) for -60 dB attenuation
        const float alpha = 6.90775527898f / (mCurDecay * mSampleRate);
        const float r = std::exp(-alpha);

        mA1 = 2.0f * r * std::cos(theta);
        mA2 = - (r * r);
        
        // Impulse response gain scaling: normalized so peak resonance response is calibrated
        mB0 = (1.0f - (r * r)) * std::sin(theta);
    }

    // Audio configuration
    float mSampleRate{48000.0f};
    float mInverseSampleRate{1.0f / 48000.0f};

    // Filter coefficients & states
    float mA1{0.0f};
    float mA2{0.0f};
    float mB0{0.0f};
    float mY1{0.0f};
    float mY2{0.0f};

    // Parameter targets & smoothed currents
    float mTargetFreq{440.0f};
    float mCurFreq{440.0f};

    float mTargetDecay{1.0f};
    float mCurDecay{1.0f};

    float mTargetGain{1.0f};
    float mCurGain{1.0f};
};

} // namespace modalbrain::dsp
