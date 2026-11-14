---
title: "[RFC]: "
labels: ["instrument-rfc"]
---

### 📜 RFC Title & Metadata
- **Proposed Name**: 
- **Author(s)**: 
- **Target Format**: [CLAP, VST3, LV2, Standalone, Embedded hardware]
- **Status**: [Draft / In Review / Accepted / Prototyping]

---

### 1. Abstract & Musical Motivation
*Summarize what this instrument does and why it needs to exist.*

### 2. Synthesis & Acoustic Architecture
- **Sound Generation**: [Wavetable, Additive, FM, Physical Modeling (Karplus-Strong, Banded Waveguides), Modal]
- **Nonlinear Shapers & Resonators**: 
- **Modulation Matrix**: 

### 3. Real-Time DSP Specification
- **Sampling Rate Handling**: 
- **Oversampling Strategy**: [e.g., 2x / 4x polyphase FIR for nonlinear sections]
- **Audio Thread Budget**: [Target CPU % per voice]

### 4. Expression & Human Interface
- **MPE Support**: [Pitch Bend range, Channel Pressure to Timbre, Slide]
- **Microtonality**: [MIDI Tuning Standard, Scala, MTS-ESP support]

### 5. Open Questions & Alternatives Considered
*Unresolved design decisions requiring community input.*
