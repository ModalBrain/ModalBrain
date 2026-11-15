# ModalBrain 🧠🔊

> Next-generation electronic music synthesis, DSP research, modular audio systems, and neural timbre modeling.

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![Audio Standard: CLAP](https://img.shields.io/badge/Audio-CLAP%20%7C%20VST3%20%7C%20LV2-orange.svg)](https://cleveraudio.org/)
[![Branch Protection](https://img.shields.io/badge/Branch%20Protection-main%20(Protected)-success.svg)]()

---

## ⚡ Vision & Philosophy

**ModalBrain** is an open-source hub dedicated to the intersection of modern digital signal processing (DSP), modular synthesis, neural audio modeling, and cutting-edge electronic music production.

### Core Pillars
1. **Real-Time DSP & Novel Synthesis Engines**
   - High-performance, zero-allocation algorithms (physical modeling, wavetable synthesis, modal resonators, wavefolding, and chaotic attractors).
   - SIMD-vectorized processing routines optimized for low-latency live performance.
2. **Open Plugin Standards**
   - First-class support for [CLAP (Clever Audio Plugin)](https://cleveraudio.org/), VST3, and LV2.
   - Non-destructive modulation, polyphonic parameter automation, and MPE (MIDI Polyphonic Expression) support.
3. **Modular & Generative Environments**
   - Interoperable patches and modules for [Cardinal](https://cardinal.kx.studio/), VCV Rack, Pure Data, and Max/MSP.
   - Algorithmic composition, Euclidean sequencers, and stochastic event generators.
4. **Neural Audio & Timbre Modeling**
   - Integration with deep learning audio workflows (e.g., [Neural Amp Modeler](https://github.com/sdatkinson/neural-amp-modeler), ONNX runtime inference for real-time waveshaping and nonlinear system emulation).
5. **Git LFS for Audio Artifacts**
   - Tracked neural weights, high-resolution impulse responses, and sonic reference datasets.

---

## 🗂️ Repository Structure

```text
ModalBrain/
├── .github/
│   ├── ISSUE_TEMPLATE/           # Electronic music & DSP-tailored issue forms
│   │   ├── config.yml
│   │   ├── 1_bug_audio_glitch.yml
│   │   ├── 2_dsp_algorithm_feature.yml
│   │   └── 3_sound_design_preset.yml
│   ├── workflows/                # Automated CI & DSP validation workflows
│   │   └── ci.yml
│   └── pull_request_template.md  # Real-time audio safety review checklist
├── dsp/                          # Pure DSP kernels, filters, oscillators, and math
├── plugins/                      # Audio plugin implementations (CLAP, VST3, LV2)
├── patches/                      # Modular patches (Cardinal, Pure Data, Max/MSP)
├── presets/                      # Curated preset banks & modulation mappings
├── models/                       # Neural model weights (.nam, .onnx via Git LFS)
├── docs/                         # Mathematical formulas, DSP architecture specs
├── .gitattributes                # Git LFS definitions for audio/binary files
├── .gitignore                    # DAW, plugin build, and DSP-focused ignore rules
└── LICENSE                       # MIT License
```

---

## 🛡️ Real-Time Audio Engineering Rules

All DSP algorithms and audio engine contributions to ModalBrain must strictly follow the **Real-Time Safety Standard**:

1. **Zero Heap Allocations on Audio Thread**: Never call `malloc`, `free`, `new`, `delete`, or expand dynamic containers (`std::vector::push_back`, etc.) in `process()`.
2. **Lock-Free Concurrency**: Never acquire blocking mutexes or locks in the audio render callback. Use lock-free single-producer single-consumer (SPSC) ring buffers and atomic operations.
3. **Denormal & NaN Shielding**: Guard all recursive filters and feedback paths with anti-denormal flushes or subtle DC offsets to avoid CPU throttling.
4. **Sample-Rate Agnostic**: Always scale frequency-dependent calculations with the current audio sample rate ($F_s$). Recalculate coefficients dynamically on buffer updates.
5. **Parameter Dezippering**: Smooth control-rate parameters (LFOs, automated cutoffs) using one-pole low-pass filters or slew-limiters to eliminate audible audio stepping artifacts.

---

## 🚀 Getting Started

### Prerequisites
- Modern C++ (C++20/23) or Rust toolchain
- CMake 3.24+ or Cargo
- [Git LFS](https://git-lfs.github.com/) for audio files and neural models

```bash
# Clone the repository with Git LFS
git clone https://github.com/ModalBrain/ModalBrain.git
cd ModalBrain

# Initialize Git LFS
git lfs install
git lfs pull
```

---

## 🤝 Contributing

We welcome contributions from DSP engineers, modular synthesists, sound designers, and electronic musicians! Please read our full [Contribution Guidelines](CONTRIBUTING.md) before submitting.

1. Explore the [Awesome Modal Music Reading List](docs/awesome-modal-music.md) and [Community Setup Guide](docs/COMMUNITY_SETUP.md).
2. Check open issues or start a discussion in our community.
3. Fork the repository and create your feature branch:
   ```bash
   git checkout -b feature/resonant-modal-filter
   ```
4. Ensure your pull request complies with our [Real-Time Audio Safety Checklist](.github/pull_request_template.md).
5. Submit a Pull Request targeting the `main` branch.

---

## 📜 License

ModalBrain is released under the [MIT License](LICENSE).
