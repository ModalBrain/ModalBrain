## Summary of Changes

Describe what this pull request introduces (DSP algorithm, UI enhancement, preset addition, or bug fix).

## Type of Change
- [ ] DSP kernel / Audio engine optimization
- [ ] Plugin format wrapper (CLAP, VST3, LV2)
- [ ] UI / Front-end rendering
- [ ] Preset / Sound design bank
- [ ] Documentation / Architecture spec
- [ ] Bug fix

---

## 🎧 Real-Time Audio Safety Checklist
Please verify the following before submitting for review:

- [ ] **No Dynamic Allocations on Audio Thread**: Verified that `malloc`, `new`, `free`, `delete`, and dynamic vector reallocations are not invoked in `process()`.
- [ ] **Lock-Free Concurrency**: Audio thread avoids blocking mutex locks; lock-free atomics or ringbuffers are utilized for parameter updates.
- [ ] **Sample Rate Independence**: Filter coefficients and frequency calculations account for variable sample rates (44.1 kHz – 192 kHz).
- [ ] **Denormal Protection**: Recursive feedback paths include anti-denormal flushes or DC offset protection to avoid CPU spikes.
- [ ] **Parameter Smoothing**: Automated parameters and modulation signals are de-zippered.
- [ ] **Buffer Boundaries**: Algorithm tested with small (64 frames) and large (1024 frames) audio buffer sizes.

---

## Verification & Environment
- **Host DAWs Tested**: [e.g., Bitwig Studio 5, Reaper 7, Cardinal]
- **Formats Tested**: [e.g., CLAP, VST3, Standalone]
- **Audio Interface / Driver**: [e.g., PipeWire JACK, ALSA]
