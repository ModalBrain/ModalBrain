#pragma once

#include <cmath>
#include <cstdint>

namespace modalbrain::dsp {

/**
 * @brief Real-time audio denormal & NaN guard utilities.
 * 
 * Prevents CPU performance degradation caused by x86 floating-point 
 * subnormal/denormal numbers in recursive IIR and modal feedback paths.
 */
class DenormalGuard {
public:
    // Tiny DC offset to keep recursive float values out of subnormal range
    static constexpr float kAntiDenormalOffset = 1.0e-25f;

    /**
     * @brief Flush subnormal values to zero.
     */
    [[nodiscard]] static inline float flush(float val) noexcept {
        if (std::abs(val) < 1.0e-15f) {
            return 0.0f;
        }
        return val;
    }

    /**
     * @brief Safe check for valid audio sample (non-NaN, non-Inf).
     */
    [[nodiscard]] static inline bool isAudioFinite(float val) noexcept {
        return !std::isnan(val) && !std::isinf(val);
    }

    /**
     * @brief Clamp audio to safe dynamic range [-maxAmp, +maxAmp].
     */
    [[nodiscard]] static inline float hardLimit(float val, float maxAmp = 4.0f) noexcept {
        if (val > maxAmp) return maxAmp;
        if (val < -maxAmp) return -maxAmp;
        return val;
    }
};

} // namespace modalbrain::dsp
