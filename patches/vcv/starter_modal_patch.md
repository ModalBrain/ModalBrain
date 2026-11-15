# VCV Rack & DISTRHO Cardinal: Starter Modal Voice Template 🔌

## Overview
A modular patch architecture for constructing a rich acoustic modal synthesizer voice using 100% open-source modules available in the VCV Library and DISTRHO Cardinal.

---

## 🧩 Recommended Module Manifest

| Function | Module Suggestion | Plugin Pack | Open-Source? |
| :--- | :--- | :--- | :--- |
| **Exciter / Burst** | Befaco Noise Plethora / Bogaudio Noise | Befaco / Bogaudio | Yes (GPL-3.0) |
| **Exciter Envelope** | Bogaudio DADSR(H) or VCV Envelope | Bogaudio / Fundamental | Yes |
| **Resonator Bank** | VCV Resonator / Surge XT Filter Bank | Fundamental / Surge XT | Yes |
| **Microtonal Quantizer**| JW Quantizer / Grande Quantizer | JW-Modules / Grande | Yes |
| **VCA & Output** | Fundamental VCA & Audio 8 | Fundamental | Yes |

---

## 🎚️ Cable Routing Scheme

1. **Pitch CV**:
   - Keyboard / Sequencer $1\text{V/Oct} \to$ **Quantizer Pitch In** (configured with a modal scale or Scala file).
   - **Quantizer Pitch Out** $\to$ **Resonator V/Oct In**.
2. **Excitation Trigger**:
   - Gate signal $\to$ Trigger **Decay Envelope** (set very short: 5–15 ms).
   - Envelope $\to$ modulates Noise **VCA** to produce an acoustic strike burst (impulse/plectrum).
3. **Resonance Processing**:
   - Noise Burst Out $\to$ **Resonator Audio In**.
   - Resonator Out $\to$ **Master Mixer / Audio Out**.
4. **Modulation**:
   - LFO or velocity CV $\to$ **Resonator Structure / Inharmonicity** for dynamic acoustic material changes.
