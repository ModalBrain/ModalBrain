#pragma once

#include "modal_resonator.hpp"
#include <array>
#include <span>

namespace modalbrain::dsp {

/**
 * @brief Bank of coupled or parallel real-time modal resonators.
 * 
 * Template parameter `MaxModes` specifies the fixed maximum number of resonant 
 * modes allocated at compile-time to guarantee ZERO dynamic heap allocation.
 */
template <std::size_t MaxModes = 32>
class ModalBank {
public:
    static constexpr std::size_t kMaxModes = MaxModes;

    ModalBank() noexcept = default;

    /**
     * @brief Prepare all resonators in the bank with audio sample rate.
     */
    void prepare(float sampleRate) noexcept {
        mSampleRate = sampleRate;
        for (auto& resonator : mResonators) {
            resonator.prepare(sampleRate);
        }
    }

    /**
     * @brief Clear internal states of all active modes.
     */
    void reset() noexcept {
        for (auto& resonator : mResonators) {
            resonator.reset();
        }
    }

    /**
     * @brief Set number of active modes to compute (clamped to MaxModes).
     */
    void setActiveModes(std::size_t numModes) noexcept {
        mActiveModes = std::clamp(numModes, std::size_t{1}, MaxModes);
    }

    [[nodiscard]] std::size_t getActiveModes() const noexcept {
        return mActiveModes;
    }

    /**
     * @brief Configure individual mode parameters.
     */
    void setMode(std::size_t modeIndex, float freqHz, float decaySeconds, float gain) noexcept {
        if (modeIndex < MaxModes) {
            mResonators[modeIndex].setFrequency(freqHz);
            mResonators[modeIndex].setDecay(decaySeconds);
            mResonators[modeIndex].setGain(gain);
        }
    }

    /**
     * @brief Helper to configure harmonic or inharmonic dispersion from a fundamental.
     * 
     * @param fundamentalHz Base fundamental frequency
     * @param baseDecay Base decay time in seconds for mode 0
     * @param inharmonicity Stretch factor (> 1.0 for stiff bars/plates, = 1.0 for harmonic strings)
     * @param dampingDamp High-frequency damping exponential roll-off
     */
    void configureDistribution(float fundamentalHz, float baseDecay, float inharmonicity = 1.0f, float dampingDamp = 0.5f) noexcept {
        for (std::size_t i = 0; i < mActiveModes; ++i) {
            const float modeNumber = static_cast<float>(i + 1);
            
            // Inharmonic mode frequency formula: f_n = f_0 * n * sqrt(1 + B * n^2)
            const float stretch = std::sqrt(1.0f + (inharmonicity - 1.0f) * 0.05f * modeNumber * modeNumber);
            const float modeFreq = fundamentalHz * modeNumber * stretch;
            
            // Higher modes decay faster: decay_n = baseDecay / (1 + damp * modeNumber)
            const float modeDecay = baseDecay / (1.0f + dampingDamp * static_cast<float>(i));
            
            // Natural 1/n amplitude fall-off
            const float modeGain = 1.0f / (1.0f + 0.6f * static_cast<float>(i));

            setMode(i, modeFreq, modeDecay, modeGain);
        }
    }

    /**
     * @brief Process a single audio sample through the parallel modal bank.
     */
    [[nodiscard]] inline float processSample(float inSample) noexcept {
        float accum = 0.0f;
        for (std::size_t i = 0; i < mActiveModes; ++i) {
            accum += mResonators[i].processSample(inSample);
        }
        return accum;
    }

    /**
     * @brief Process a block of samples.
     */
    void processBlock(const float* inBuffer, float* outBuffer, std::size_t numSamples) noexcept {
        for (std::size_t n = 0; n < numSamples; ++n) {
            outBuffer[n] = processSample(inBuffer[n]);
        }
    }

private:
    float mSampleRate{48000.0f};
    std::size_t mActiveModes{8};
    std::array<ModalResonator, MaxModes> mResonators{};
};

} // namespace modalbrain::dsp
