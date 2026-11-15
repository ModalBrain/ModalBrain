#include "modalbrain/modal_resonator.hpp"
#include "modalbrain/modal_bank.hpp"
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

int main() {
    std::cout << "=== ModalBrain DSP Kernel Verification ===" << std::endl;

    constexpr float kSampleRate = 48000.0f;
    modalbrain::dsp::ModalResonator resonator;
    resonator.prepare(kSampleRate);
    resonator.setFrequency(440.0f);
    resonator.setDecay(0.1f); // 100ms decay
    resonator.setGain(1.0f);

    // Test 1: Impulse excitation response
    constexpr std::size_t kTestLength = 4800; // 100ms at 48kHz
    std::vector<float> output(kTestLength, 0.0f);

    // Inject unit impulse at sample 0
    float impulse = 1.0f;
    for (std::size_t i = 0; i < kTestLength; ++i) {
        output[i] = resonator.processSample(impulse);
        impulse = 0.0f; // Zero after first sample

        // Check for NaN / Inf
        assert(modalbrain::dsp::DenormalGuard::isAudioFinite(output[i]));
    }

    std::cout << "[PASS] Impulse excitation generated stable finite output." << std::endl;

    // Test 2: Energy decay check
    float initialEnergy = 0.0f;
    for (std::size_t i = 0; i < 200; ++i) {
        initialEnergy += output[i] * output[i];
    }

    float tailEnergy = 0.0f;
    for (std::size_t i = kTestLength - 200; i < kTestLength; ++i) {
        tailEnergy += output[i] * output[i];
    }

    assert(initialEnergy > tailEnergy);
    std::cout << "[PASS] Resonator energy decayed as expected (initial=" 
              << initialEnergy << ", tail=" << tailEnergy << ")." << std::endl;

    // Test 3: Modal Bank multi-mode synthesis
    modalbrain::dsp::ModalBank<16> bank;
    bank.prepare(kSampleRate);
    bank.setActiveModes(8);
    bank.configureDistribution(220.0f, 0.2f, 1.05f, 0.4f);

    impulse = 1.0f;
    float peakAmp = 0.0f;
    for (std::size_t i = 0; i < 2400; ++i) {
        float sample = bank.processSample(impulse);
        impulse = 0.0f;

        assert(modalbrain::dsp::DenormalGuard::isAudioFinite(sample));
        if (std::abs(sample) > peakAmp) {
            peakAmp = std::abs(sample);
        }
    }

    assert(peakAmp > 0.0f && peakAmp < 10.0f);
    std::cout << "[PASS] ModalBank multi-mode synthesis verified with peak amplitude=" << peakAmp << std::endl;

    std::cout << "All DSP core assertions passed successfully." << std::endl;
    return 0;
}
