# ModalBrain Core DSP Kernels 🧠🔊

Header-only, real-time safe C++20 algorithms for modal synthesis, physical modeling, and audio signal processing.

---

## 🛡️ Real-Time Safety Guarantee

All algorithms in this directory strictly comply with the **Real-Time Audio Safety Standard**:
- **Zero dynamic allocations** (`malloc`, `free`, `new`, `delete`) in `processSample()` / `processBlock()`.
- **Anti-denormal & NaN shielding** via `DenormalGuard`.
- **Parameter dezippering**: One-pole low-pass interpolation on control-rate parameter changes.
- **Sample-rate agnostic**: Dynamic coefficient scaling based on $F_s$.

---

## 📁 Architecture & Headers

```text
dsp/
├── include/
│   └── modalbrain/
│       ├── denormals.hpp         # Anti-denormal and NaN prevention utilities
│       ├── modal_resonator.hpp   # Second-order resonant bandpass modal mode
│       └── modal_bank.hpp        # Polyphonic / multi-mode parallel resonator bank
├── tests/
│   └── test_modal_resonator.cpp  # Impulse response and stability test suite
└── CMakeLists.txt                # CMake interface target `modalbrain_dsp`
```

---

## 🚀 Quick Usage

```cpp
#include "modalbrain/modal_bank.hpp"

// Allocate 16 resonant modes on the stack (zero heap allocation)
modalbrain::dsp::ModalBank<16> bank;

// Initialize with hardware audio sample rate
bank.prepare(48000.0f);
bank.setActiveModes(8);

// Configure an inharmonic acoustic plate / bar distribution
bank.configureDistribution(
    /* fundamentalHz = */ 220.0f,
    /* baseDecaySec  = */ 1.2f,
    /* inharmonicity = */ 1.05f,
    /* dampingRollOff= */ 0.4f
);

// In your audio engine's real-time render callback:
void process(const float* inBuffer, float* outBuffer, std::size_t numSamples) noexcept {
    bank.processBlock(inBuffer, outBuffer, numSamples);
}
```

---

## 🧪 Building & Running Tests

```bash
mkdir -p build && cd build
cmake ../dsp
cmake --build .
ctest --output-on-failure
```
