# Awesome Modal Music & Audio DSP 🧠🔊

> A curated list of foundational papers, physical modeling research, microtonal modal systems, open-source audio DSP tools, and neural timbre modeling resources.

---

## 📑 Table of Contents
- [1. Foundational Papers & Dissertations](#1-foundational-papers--dissertations)
  - [Modal Synthesis & Physical Modeling](#modal-synthesis--physical-modeling)
  - [Microtonality & Traditional Modal Frameworks](#microtonality--traditional-modal-frameworks)
  - [Neural Timbre & Machine Learning in Audio](#neural-timbre--machine-learning-in-audio)
- [2. Academic Conferences & Archives](#2-academic-conferences--archives)
- [3. Open-Source DSP Libraries & Frameworks](#3-open-source-dsp-libraries--frameworks)
- [4. Modular & Patch Environments](#4-modular--patch-environments)
- [5. Microtonal Tuning & Scala Standards](#5-microtonal-tuning--scala-standards)
- [6. Contributing](#6-contributing)

---

## 1. Foundational Papers & Dissertations

### Modal Synthesis & Physical Modeling
* **Adrien, J.-M. (1991)** — *The Representations of Structures in Sound Synthesis by Physical Modeling (Modal Synthesis)*. In *Representations of Musical Signals*, MIT Press.
  * *Significance*: The seminal work formalizing modal synthesis — decomposing vibrating structures into independent resonant modes characterized by frequency, decay rate (damping), and spatial mode shape weights.
* **Bilbao, S. (2009)** — *Numerical Sound Synthesis: Finite Difference Schemes and Simulation in Musical Acoustics*. John Wiley & Sons.
  * *Significance*: Rigorous mathematical foundation for physical modeling of strings, membranes, plates, and acoustic tubes with guaranteed energetic stability.
* **Smith, J. O. (2010)** — *Physical Audio Signal Processing for Virtual Musical Instruments and Digital Audio Effects*. W3K Publishing.
  * *Significance*: Accessible reference on digital waveguide synthesis, lumped modal models, and second-order resonator filter networks. [Online Edition](https://ccrma.stanford.edu/~jos/pasp/).
* **Välimäki, V., Pakarinen, J., Erkut, C., & Karjalainen, M. (2006)** — *Discrete-time modelling of musical instruments*. Reports on Progress in Physics, 69(1), 1–78.
  * *Significance*: Comprehensive survey comparing waveguide, modal, and finite-difference synthesis strategies for real-time acoustic emulation.
* **Djoharian, P. (1993)** — *Material design in physical modelling sound synthesis*. Computer Music Journal, 17(3), 31–41.
  * *Significance*: Methods for calculating modal parameters from structural physical properties (elasticity, mass density, boundary conditions).

### Microtonality & Traditional Modal Frameworks
* **Farhat, H. (2004)** — *The Dastgah Concept in Persian Music*. Cambridge University Press.
  * *Significance*: Detailed ethnomusicological and acoustic analysis of the 12 Dastgāhs, the Radif repertoire, and microtonal intervals (koron and sori quarter-tones).
* **Maqam World (Artistic Consortium)** — *The Arabic Maqam Analysis and Tuning Reference*.
  * *Significance*: Practical categorization of the 9 primary Maqam families (Rast, Bayati, Sikah, Hijaz, Saba, Kurd, Nahawand, Ajam, Nawa Athar) and their quarter-tone inflections.
* **Bohlen, H. (1978)** — *13 Tonstufen in der Duodezime*. Acustica, 39(2), 76–86.
  * *Significance*: Introduces the Bohlen-Pierce scale, a non-octave tuning system dividing the 3:1 frequency ratio (tritave) into 13 steps with odd-harmonic consonance.
* **Sethares, W. A. (2005)** — *Tuning, Timbre, Spectrum, Scale*. Springer Science & Business Media.
  * *Significance*: The theoretical bridge between modal instrument timbres (inharmonic spectra) and musical scales (sensory consonance and dissonant roughness curves).

### Neural Timbre & Machine Learning in Audio
* **Engel, J., et al. (2020)** — *DDSP: Differentiable Digital Signal Processing*. International Conference on Learning Representations (ICLR).
  * *Significance*: Combines classical DSP building blocks (harmonic additive oscillators, filtered noise, reverberation) with deep neural networks for interpretable, lightweight neural timbre transfer.
* **Atkinson, S. D. (2021)** — *Neural Amp Modeler: Real-Time Non-Linear Audio Processing via Lightweight WaveNet & LSTM Architectures*.
  * *Significance*: State-of-the-art open-source real-time neural modeling of nonlinear tube preamps, analog circuits, and saturation stages with low CPU overhead.
* **Hayes, B., Saitis, C., & Fazekas, G. (2021)** — *Neural Waveform Synthesis: A Review of Deep Learning Methods for Sound Synthesis*. IEEE Transactions on Audio, Speech, and Language Processing.

---

## 2. Academic Conferences & Archives

- **[ISMIR](https://ismir.net/conferences/)** — International Society for Music Information Retrieval. Focus on modal analysis, transcription, and music information modeling.
- **[DAFx](https://www.dafx.de/paper-archive/)** — International Conference on Digital Audio Effects. Gold standard for filter design, virtual analog, physical modeling, and spatial audio DSP.
- **[NIME](https://nime.org/papers/)** — International Conference on New Interfaces for Musical Expression. Explores novel modal electronic instruments, microtonal controllers, and gestural sound design.
- **[AES E-Library](https://www.aes.org/e-lib/)** — Audio Engineering Society convention papers and journal publications on transducer modeling and studio DSP.

---

## 3. Open-Source DSP Libraries & Frameworks

- **[CLAP (Clever Audio Plugin)](https://cleveraudio.org/)** — Modern open standard for audio plugins and hosts featuring polyphonic modulation, non-destructive parameter automation, and thread-pool execution.
- **[FAUST](https://faust.grame.fr/)** — Functional programming language for real-time signal processing that compiles to high-performance C++, Rust, WebAssembly, and CLAP/VST plugins.
- **[Soundpipe](https://paulbatchelor.github.io/soundpipe.html)** — Lightweight, dependency-free C audio DSP library with hundreds of filters, delays, and modal modules.
- **[JUCE](https://juce.com/)** — Cross-platform C++ framework for audio applications and plugins.

---

## 4. Modular & Patch Environments

- **[DISTRHO Cardinal](https://cardinal.kx.studio/)** — Virtual modular synthesizer plugin (CLAP/VST2/VST3/LV2) providing an open-source sandbox for VCV Rack modules with no external server dependencies.
- **[VCV Rack](https://vcvrack.com/)** — Open-source virtual Eurorack studio with thousands of community modules.
- **[Pure Data (Pd)](https://puredata.info/)** — Open-source visual programming environment for audio, MIDI, and modal research.
- **[Max/MSP & Max for Live](https://www.ableton.com/en/live/max-for-live/)** — Visual development environment tightly integrated into Ableton Live for bespoke instruments and MIDI controllers.

---

## 5. Microtonal Tuning & Scala Standards

- **[Huygens-Fokker Foundation Scala Archive](https://www.huygens-fokker.org/scala/)** — The definitive repository of over 5,000 microtonal and historic scale definitions (`.scl`).
- **[Surge Synth Team Tuning Library](https://github.com/surge-synthesizer/tuning-library)** — Production-grade C++ header-only library for parsing Scala (`.scl`) and keyboard mapping (`.kbm`) files.
- **[Leimma & Apotome](https://isartum.net/leimma)** — Modern browser-based microtonal exploration tools focused on traditional modal systems (Maqam, Raga, Dastgah).

---

## 6. Contributing

Found a seminal paper or open-source modal synthesis tool missing from this list? Open a Pull Request or start a thread in [GitHub Discussions](https://github.com/ModalBrain/ModalBrain/discussions).
