# ModalBrain Microtonal Tuning Packs (.scl) 🎵

This directory contains starter [Scala](https://www.huygens-fokker.org/scala/) (`.scl`) tuning definitions for exploring modal traditions, non-Western musical systems, and alternative temperaments in electronic synthesis.

---

## 📂 Included Tuning Files

| File | Tuning System | Steps | Equave | Key Characteristics |
| :--- | :--- | :--- | :--- | :--- |
| `dastgah_shur.scl` | Dastgāh-e Šur (Persian) | 7 | 2:1 (Octave) | Neutral second (~150 cents) and neutral third with *koron* quarter-flat inflection. |
| `maqam_bayati.scl` | Maqām Bayātī (Arabic/Ottoman) | 7 | 2:1 (Octave) | Expressive half-flat second degree above tonic (D, E½♭, F, G, A, B♭, C). |
| `maqam_rast.scl` | Maqām Rāst (Arabic/Turkish) | 7 | 2:1 (Octave) | Foundational maqām with neutral 3rd (~350 cents) and neutral 7th (~1050 cents). |
| `bohlen_pierce.scl` | Bohlen-Pierce (13-ED3) | 13 | 3:1 (Tritave) | Divides the perfect twelfth into 13 steps; consonant with odd-harmonic modal synthesis. |
| `pelog_7.scl` | Pelog (Javanese Gamelan) | 7 | 2:1 (Octave) | Asymmetric 7-tone tuning rich in inharmonic chime/metallophone resonance. |

---

## 🛠️ How to Load in Modern Synths & DAWs

### 1. Ableton Live 12
- Ableton Live 12 natively supports `.ascl` and `.scl` tuning files.
- Drag any `.scl` file directly into the **Tuning** panel in the bottom-left control bar or onto MIDI tracks.
- All built-in instruments (Meld, Drift, Wavetable, Operator) and compatible plugins automatically adopt the tuning.

### 2. DISTRHO Cardinal & VCV Rack
- Use modules supporting `.scl` tuning files such as:
  - **Surge XT for Rack** (Microtonal tuning menu)
  - **Grande Quantizer** or **JW Quantizer**
  - **Fundamental VCV VCOs** driven via tuning-mapped CV quantizers.

### 3. Software Synthesizers (Surge XT, Vital, Pigments)
- **Surge XT**: Click the **Tuning** button at the top header $\to$ *Load Scala file* $\to$ select the `.scl` file.
- **Vital**: In the Advanced tab $\to$ click the tuning icon $\to$ select *Import .scl file*.
- **Xfer Serum**: In the Global tab $\to$ drag & drop the `.scl` file into the microtuning slot.
