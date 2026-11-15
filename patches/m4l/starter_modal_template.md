# Max for Live: Starter Modal Resonator & Quantizer Template 🎛️

## Overview
This template provides the design specification for building a clean, zero-latency **Max for Live Modal Quantizer & Resonator** in Ableton Live.

---

## 📐 Architecture & Routing

```text
[MIDI / Audio Input]
        │
   ┌────┴─────────────────────────────┐
   │                                  │
   ▼                                  ▼
[Scale / SCL Quantizer]       [Impulse Exciter]
(Remaps incoming MIDI pitch)   (Short click / filtered burst)
   │                                  │
   └────────────────┬─────────────────┘
                    ▼
          [gen~ Modal Bank]
   (2-8 Second-Order Biquad Resonators)
                    │
                    ▼
          [Live Audio Output]
```

---

## 🛠️ Parameters & Controls

1. **Root & Scale Mode**:
   - Equal temperament vs. Microtonal scale (links to `.scl` tuning definitions).
2. **Resonator Material / Inharmonicity**:
   - `Harmonic (1.0)`: String / open pipe behavior.
   - `Stiff Bar (1.05 - 1.25)`: Marimba, vibraphone, metal plate.
   - `Circular Membrane (1.5 - 2.29)`: Drum head / tabla resonance.
3. **Decay (T60)**:
   - Global resonance damping (50 ms – 15 seconds).
4. **Brightness / High Damping**:
   - Exponential roll-off of higher modal frequencies.

---

## 💡 gen~ Implementation Tip
In `gen~`, implement the 2nd-order resonator using two single-sample delay units (`history y1`, `history y2`) and anti-denormal flushes, matching `modalbrain/modal_resonator.hpp`.
