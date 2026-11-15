# ModalBrain Community & Discord Server Setup Guide 💬

This guide outlines the complete configuration for the **Modal Music Electronic Community** Discord server, category structure, and automated GitHub integration.

---

## 🏛️ Discord Server Architecture

### Categories & Channels

```text
📁 01 · WELCOME & INFO
├── #welcome               # Rules, mission statement, and link to GitHub repo
├── #announcements         # Key releases, community meetings, paper club notices
└── #resources-index       # Pinned link to docs/awesome-modal-music.md

📁 02 · RESEARCH & ACOUSTICS
├── #paper-reading         # Weekly paper reading discussions (synced with GitHub)
├── #tuning-scales         # Microtonality, Scala (.scl) packs, Maqam, and Radif
└── #dsp-algorithms        # Real-time C++, Rust, FAUST, zero-allocation math

📁 03 · PATCHING & DEVICES
├── #m4l-devices           # Ableton Live Max for Live devices & .amxd sharing
├── #max-gen-dsp           # gen~ audio code, codebox DSP, and filter design
├── #vcv-patches           # VCV Rack modular patches, audio demos, cable routing
└── #cardinal-dsp          # DISTRHO Cardinal self-contained workflows

📁 04 · COMMUNITY LAB
├── #show-and-tell         # Tracks, jams, sound design snippets using modal techniques
├── #instrument-rfcs       # Brainstorming collaborative new instruments
└── #voice-lounge          # Voice channel for live Paper & Patch Club sessions
```

---

## 🤖 GitHub $\to$ Discord Webhook Integration

Connect GitHub repo events directly into Discord to keep both platforms in sync without manual posting:

### Step 1: Create Discord Webhooks
1. In Discord: Server Settings $\to$ **Integrations** $\to$ **Webhooks**.
2. Create Webhook 1:
   - **Name**: `GitHub Paper Sync`
   - **Target Channel**: `#paper-reading`
   - Copy the Webhook URL.
3. Create Webhook 2:
   - **Name**: `ModalBrain Git Bot`
   - **Target Channel**: `#announcements` or `#dsp-algorithms`
   - Copy the Webhook URL.

### Step 2: Add Webhooks to GitHub
1. In the GitHub repository: **Settings** $\to$ **Webhooks** $\to$ **Add webhook**.
2. **Payload URL**: Paste the Discord webhook URL (append `/github` to the end of the Discord URL to enable native GitHub formatting).
3. **Content type**: `application/json`.
4. **Events to trigger**:
   - `Discussions` (announces new research paper breakdowns).
   - `Pull requests` and `Releases`.
5. Click **Add webhook**.
