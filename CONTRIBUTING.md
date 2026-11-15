# Contributing to ModalBrain 🧠🔊

Thank you for your interest in contributing to **ModalBrain**! We are building an open-source hub at the intersection of real-time digital signal processing (DSP), modular synthesis (VCV Rack, Cardinal, Max/MSP), microtonal modal music, and neural timbre modeling.

---

## 📋 Table of Contents
1. [Code of Conduct](#code-of-conduct)
2. [Contribution Pillars](#contribution-pillars)
3. [Real-Time Audio Safety Standard](#real-time-audio-safety-standard)
4. [Max for Live (.amxd) Guidelines](#max-for-live-amxd-guidelines)
5. [VCV Rack & Cardinal Guidelines](#vcv-rack--cardinal-guidelines)
6. [Academic Papers & Research Discussions](#academic-papers--research-discussions)
7. [Git LFS & Audio Assets](#git-lfs--audio-assets)
8. [Pull Request Workflow](#pull-request-workflow)

---

## 🤝 Code of Conduct

We are committed to providing a welcoming, inclusive, and harassment-free environment for everyone, regardless of experience level, background, identity, or musical tradition. Respectful discussion, constructive technical critique, and collaboration are expected across all GitHub issues, discussions, and Discord channels.

---

## 🏛️ Contribution Pillars

You can contribute to ModalBrain across several areas:
- **Core DSP (`dsp/`)**: C++20 / Rust math kernels, resonators, wavefolders, filters, and physical modeling algorithms.
- **Plugins (`plugins/`)**: CLAP, VST3, and LV2 plugin architectures with sample-accurate automation and MPE support.
- **Modular Patches (`patches/`)**: Modular patches for VCV Rack, DISTRHO Cardinal, and Max for Live devices.
- **Presets & Tunings (`presets/`)**: Scala (`.scl`) tuning files, mapping definitions, and synthesizer sound banks.
- **Neural Models (`models/`)**: Neural Amp Modeler (`.nam`), ONNX, and PyTorch audio checkpoints (via Git LFS).
- **Research & Documentation (`docs/`)**: Papers breakdowns (ISMIR, DAFx, NIME), mathematical specs, and documentation.

---

## 🛡️ Real-Time Audio Safety Standard

All code contributing to the audio processing path (e.g. `process()` callbacks or DSP kernels) must strictly obey the **Five Safety Rules**:

1. **Zero Heap Allocations on Audio Thread**:
   - Never call `malloc`, `free`, `new`, `delete`, or reallocate dynamic standard containers (`std::vector::push_back`, `std::string`, etc.) in real-time callbacks.
   - Pre-allocate memory during initialization (`prepareToPlay()` / `activate()`).
2. **Lock-Free Concurrency**:
   - Never use blocking primitives (`std::mutex`, semaphores, `std::condition_variable`) on the audio thread.
   - Use atomic variables with appropriate memory ordering or single-producer single-consumer (SPSC) lock-free ring buffers for audio/UI messaging.
3. **Denormal and NaN Shielding**:
   - Flush subnormal floating-point numbers to zero or inject subtle DC offsets (e.g., $10^{-25}$) into feedback loops to avoid CPU throttling.
   - Guard against divide-by-zero, invalid logarithms, and infinite feedback states.
4. **Sample-Rate Agnostic Architecture**:
   - Always scale frequency, damping, decay, and integration coefficients relative to the current sample rate ($F_s$). Recalculate coefficients dynamically on buffer updates.
5. **Parameter Dezippering**:
   - Smooth control-rate parameters (frequencies, filter cutoffs, modulation depths) using one-pole low-pass smoothers or slew limiters to prevent audible clicks, pops, and stepping artifacts.

---

## 🎛️ Max for Live (.amxd) Guidelines

When contributing Max for Live devices to `patches/m4l/`:
1. **Device Isolation**: Keep devices modular and focused on a single function (e.g., modal quantization, microtonal scale remapping, or resonator bank).
2. **Audio Preview**: Provide a short 10–30 second `.mp3` or `.ogg` audio demonstration preview alongside the `.amxd`.
3. **Live Object Model (LOM) Efficiency**: Avoid high-frequency queries to LOM inside audio clocks; defer UI telemetry to `deferlow` or control-rate queues.
4. **Documentation**: Include a brief markdown note detailing parameter ranges, Live compatibility (Live 11/12+), and external dependencies.

---

## 🔌 VCV Rack & Cardinal Guidelines

When submitting patches to `patches/vcv/` or `patches/cardinal/`:
1. **Open-Source Module Preference**: Whenever possible, construct patches using open-source, freely available modules from the VCV Library or Cardinal built-in collection.
2. **Manifest File**: Include a companion markdown file listing:
   - Required plugin packs and author slugs.
   - Cable routing intent and CV modulation philosophy.
   - Ideal input source (e.g., impulse exciter, MIDI MPE keyboard, noise burst).
3. **Patch Screenshot**: Include a PNG or WebP screenshot showing cable routing and front-panel states.

---

## 📚 Academic Papers & Research Discussions

ModalBrain bridges academic research and functional music production:
1. Open a topic in [GitHub Discussions (Papers)](https://github.com/ModalBrain/ModalBrain/discussions) using our structured Paper Review template.
2. Structure your review into three distinct sections:
   - **Core Problem & Theoretical Background**: What challenge does the paper tackle?
   - **DSP & Mathematical Method**: Key equations, filter architectures, or neural topologies.
   - **Practical Electronic Music Application**: How can artists or developers implement this in a synthesizer, pedal, or DAW plugin?
3. Cite official proceedings links ([ISMIR](https://ismir.net/), [DAFx](https://www.dafx.de/), [NIME](https://www.nime.org/), [AES](https://www.aes.org/)).

---

## 📦 Git LFS & Audio Assets

Audio files (`.wav`, `.flac`, `.aif`), soundfonts (`.sf2`, `.sfz`), and neural models (`.nam`, `.onnx`, `.pt`, `.safetensors`) must be tracked via **Git LFS**:

```bash
# Ensure Git LFS is installed and active
git lfs install

# Verify tracked extensions before committing
git lfs status
```

Never commit raw binary models or multi-megabyte audio files directly into standard Git history without Git LFS.

---

## 🚀 Pull Request Workflow

1. **Fork** the repository and create your feature branch:
   ```bash
   git checkout -b feature/modal-resonator-bank
   ```
2. **Build and Test**: Run local test suites or static checks.
3. **Fill PR Checklist**: Complete all points in [.github/pull_request_template.md](.github/pull_request_template.md).
4. **Submit PR**: Target the `main` branch with clear, descriptive commit messages.
