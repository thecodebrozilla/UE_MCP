# Copyright Epic Games, Inc. All Rights Reserved.

import unreal

from toolset_registry.agent_skill import agent_skill

_INSTRUCTIONS = """\
# Purpose

This skill defines the authoritative rules for setting up and modifying Unreal Engine's default outdoor lighting system. These rules must be followed when performing any lighting-related actions.

---

# Core System

Unreal's default outdoor lighting is composed of six interdependent actors. The **Directional Light (Sun)** is the primary driver of the entire system.

---

# Actors and Rules

## Directional Light (Sun)

Represents the Sun. Defines main lighting direction and intensity. Produces most direct lighting and shadowing in the scene. Many sky and atmosphere features require it to have non-zero intensity.

## Sky Atmosphere

Generates the sky and large-scale atmospheric effects. Directly driven by the Directional Light's position and intensity. If the Directional Light intensity is zero, the Sky Atmosphere is black.

## Exponential Height Fog

Adds localized fog, usually near the ground. Strongly affects depth and contrast at short and medium distances. For large-scale or global fog, use Sky Atmosphere Aerial Perspective instead.

## Sky Light

Provides ambient lighting by capturing the sky. Fills shadows created by the Directional Light so they are not fully black. Produces shadowing mainly as an ambient occlusion effect, not as primary directional shadows.

## Volumetric Clouds

Renders clouds in the atmosphere. Cloud visibility and lighting depend directly on the Directional Light. If the Directional Light intensity is zero, clouds are not visible.

Volumetric Cloud appearance is controlled both by the cloud component and its material instance. The engine default (when the material is pointing to the engine directory) must never be edited directly. If the component's assigned material already points to project content, tweak it in place. If it still points to engine content, duplicate it into the project first (near the level asset), assign the duplicate, then tweak.

## Post Process Volume

Controls exposure, white balance, color temperature, and color grading. Not part of the sky system, but essential for correct lighting results.

---

# Directional Light Orientation Rules

The Directional Light rotation controls sun position.

- **Y-axis (Pitch):** controls elevation
  - `0°` = sun on horizon
  - `-90°` = sun overhead

- **Z-axis (Yaw):** controls compass direction
  - `0°` = North
  - `180°` = South

---

# Component Access Rule

> **NEVER** read or set properties directly on a lighting actor. Properties are defined on the actor's **COMPONENT**, not the actor itself.

**Recommended workflow:**
1. Call `get_components` on the actor first to retrieve its component paths.
2. Then call `get_properties` or `set_properties` on the relevant component.

---

# Sky Atmosphere - Color Shift Warning

The Sky Atmosphere automatically produces warm sunset/sunrise colors as the Directional Light pitches toward the horizon. Do not use Light Temperature or Post Process White Balance to drive or correct this - doing so stacks on top of the atmospheric shift and produces unnatural, over-saturated results. Light Temperature should remain near neutral (5500-6500K) and only be nudged (±500K) as a last-resort fine-tuning step after everything else is set.

---

# Volumetric Cloud Coverage - CRITICAL FOR SKY ASSESSMENT

Cloud coverage is one of the most impactful parameters in the scene and is frequently the cause of misdiagnosed sky color problems. A high global coverage value will blanket the entire sky, masking the atmosphere beneath. What appears to be a sky color problem (e.g. no blue, uniform orange) is very often simply too much cloud coverage hiding the actual atmosphere.

**Before making any adjustments to sky color, light temperature, Rayleigh scattering, or Post Process:**

- **ALWAYS** check the global coverage setting on the cloud material instance first.
- Default is ~-0.2. Values above 0.1 will noticeably blanket the sky.
- For a sunset with visible sky and scattered clouds, keep global coverage in the range -0.2 to 0.0.
- Only increase coverage when the intent is a heavily clouded or overcast sky.
- If the sky looks uniformly warm or colorless, reduce cloud coverage before touching any other parameter.

**Sunset cloud material instance recommended values:**

| Parameter | Value | Notes |
|---|---|---|
| Global Coverage | -0.2 to 0.0 | Scattered clouds, sky visible |
| Global Density | 0.007 - 0.010 | Light, wispy clouds that catch sunset light |
| Bottom Altitude | 3 - 5 km | Higher = more sky visible below the cloud base |
| Layer Height | 5 - 8 km | |

---

# Exposure Compensation - CRITICAL RULES

Always use physically realistic lux values for the Directional Light (e.g. 80,000-120,000 lux for direct sun, 300-1,000 lux for sunset) - Unreal defaults (~100-150 lux) are far too low.

Exposure bias behaves very differently depending on whether the Post Process auto-exposure system is active or not. **Always read the current min and max brightness values from the Post Process settings before deciding on a bias value.**

## Two Distinct Modes

### Mode 1 - Auto-exposure ACTIVE
*(both min and max brightness are overridden and set)*

The auto-exposure system adapts the scene brightness automatically. Exposure bias is then a fine-tuning **offset** on top of that adaptation - large negative values are **not** needed and will crush the image to black.

- Use exposure bias in the range of **-2.0 to +2.0 EV** for fine-tuning only.
- Start at 0.0 and adjust by small increments (±0.5 EV) per iteration.
- This is the most common mode in a project with a configured Post Process Volume.

### Mode 2 - Auto-exposure NOT ACTIVE
*(no min/max brightness overrides)*

Large negative bias values are needed to bring realistic lux values to a visually correct brightness.

| Lux Range | Exposure Bias |
|---|---|
| 80,000 - 120,000 lux (direct sun) | -10 to -14 EV |
| 25,000 - 50,000 lux (hazy/partly cloudy) | -7 to -10 EV |
| 5,000 - 15,000 lux (overcast) | -4 to -7 EV |
| 1,000 - 6,000 lux (late afternoon) | -2 to -5 EV |
| 300 - 1,000 lux (sunset) | -1 to -3 EV |

## Recommended Workflow Before Setting Any Bias Value

1. Read the Post Process settings to check whether the min and max brightness overrides are active and what they're set to, in order to determine which mode applies.
2. Always enable the exposure bias override when setting the exposure bias value.
3. Fine-tune during screenshot assessment cycles.

---

# Fog Density for Sunset - REFERENCE

At sunset, atmospheric haze is handled primarily by the Sky Atmosphere aerial perspective. Exponential Height Fog should be very subtle - used only for near-ground depth, not to simulate the horizon glow.

- Fog density at sunset: 0.000002 - 0.00002
- Use the start distance setting to push fog onset away from the camera (e.g. 2000-5000 units)
- **DO NOT** use fog to simulate warm horizon glow - that is the Sky Atmosphere's job.

---

# Overcast Weather Recipe

True overcast is driven primarily by the Volumetric Cloud layer combined with its material instance and soft shadow angles. A convincing overcast look **cannot** be achieved without tweaking the cloud material instance.

The five pillars of a convincing overcast look are:

## 1. Volumetric Cloud Material Instance - first step

1. Read the assigned material from the cloud component.
2. If it points to engine content (`/Engine/...`): duplicate it into the project content near the level asset, name it clearly (e.g. `MI_VolumetricCloud_Overcast`), and assign the duplicate back to the component.
3. If it already points to project content (`/Game/...`): use it directly - no duplication needed.
4. Tweak the material instance parameters using the MaterialInstance tools.
5. Save the asset when done.

### Known Parameters

**Scalar parameters:**

| Parameter | Default | Overcast Range | Notes |
|---|---|---|---|
| Global Coverage | ~-0.2 | 0.5 - 0.75 | Controls sky coverage. Range: -1 (clear) to 1 (full) |
| Global Density | ~0.008 | 0.02 - 0.04 | Controls opacity/thickness. Higher = more opaque |
| Global Scale | 256 | 180 - 220 | Lower = tighter, less wispy clouds |
| Storm Clouds Blend | 0 | 0 | Keep at 0 for standard overcast |

**Vector parameters (RGBA channels each carry distinct meaning):**

| Parameter | Channel | Default | Overcast Range | Notes |
|---|---|---|---|---|
| Albedo Color | RGB | ~(0.98, 0.98, 0.98) | (0.65-0.75, 0.65-0.75, 0.68-0.78) | Shift to cool grey |
| | A | 0.5 | 0.5 | Leave at default |
| Noise Bias | G | ~0.8 | 0.85 - 0.9 | Raising reduces erosion holes |
| Noise Strength | G, B | - | Lower both | Smooths cloud silhouette |
| Cloud Type | R, G | 1, 1 | Reduce | Controls lower/mid cloud type blend |

## 2. Cloud Component Layer Settings - low and thick

| Property | Overcast Value | Notes |
|---|---|---|
| Bottom Altitude | 0.5 - 2 km | Lower = more oppressive and dramatic |
| Layer Height | 8 - 14 km | Taller = more sky coverage |
| Sky Light Occlusion | 0.75 - 0.9 | Blocks ambient sky light from below |
| Cast Cloud Shadows | yes | MUST be enabled for clouds to cast ground shadows |
| Shadow Strength | 0.8 - 1.0 | |
| Shadow on Surface Strength | 0.8 - 1.0 | |

## 3. Directional Light Shadow Softening

- **Light source angle:** 2-5° standard, up to 15-30° for fully overcast (when sun disc is not visible).
- **Soft angle:** 40-70° (dramatically softens shadow penumbras).

## 4. Sky Atmosphere Mie Scattering

- Mie scattering scale sweet spot for overcast: **0.01 - 0.05**
- Do **NOT** rely on Mie alone for overcast - clouds and shadow softness are the primary drivers.

## 5. Sky Atmosphere Rayleigh Scattering Color - Recommended for overcast

- Overcast: **R: 0.40-0.50, G: 0.52-0.60, B: 0.70-0.80** (preserve A channel)
- Restore to default (~0.175, 0.41, 1.0) for clear sky.

### Supporting Adjustments for Overcast

| Setting | Value |
|---|---|
| Sky Light Intensity | 1.0 - 1.5 |
| Height Fog Density | 0.01 - 0.02 |
| Exposure Bias | Start at 0.0 and iterate |

---

# Screenshot Assessment Workflow - Recommended

## Step 1 - Baseline Capture

Before making any changes, take a screenshot, then read it. Read the current property values from all relevant components. Also read:

- The material assigned to the cloud component
- The global coverage and density settings from the cloud material instance
- The Post Process auto-exposure settings: whether min and max brightness overrides are active, their values, and the current exposure bias

Assess the current lighting visually and numerically to understand the starting state, and determine which exposure mode (auto-adapting or manual) is active.

## Step 2 - Apply Changes

Read the user request. Based on the visual and numerical baseline assessment, compute and apply the new property values. Use the correct exposure mode based on the Post Process settings read in Step 1. Check cloud coverage first before diagnosing any sky color issues.

## Step 3 - Result Capture and Assessment

Take a new screenshot and read it. Visually assess whether the result matches the user's request. Describe what you see and whether it is satisfying.

## Step 4 - Refinement Cycles (up to 3 total)

If the result is not satisfying after Step 3, adjust the values and take another screenshot to reassess. Repeat up to a maximum of **3 screenshot cycles total**. If after 3 cycles the result is still not satisfying, stop and report.

---

# Execution Constraint

Always respect these relationships when creating or modifying lighting. Changes to the Directional Light must be considered first, as they propagate through the entire system.
"""


@agent_skill
class DefaultOutdoorLightingSkill(unreal.AgentSkill):
    """Skill that is dedicated at adjusting the default outdoor lighting setup in Unreal.
    Apply this skill whenever setting up or modifying outdoor lighting (sun, sky, clouds,
    fog, exposure)."""

    instructions = _INSTRUCTIONS
