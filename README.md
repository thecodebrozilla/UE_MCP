# UE_MCP Plugins

Ported Unreal Engine MCP from 5.8 to 5.7 (eventually will do earlier versions too) along with most toolkists.

> **Engine:** UE 5.7. Several plugins are backports of UE 5.8 APIs so the suite
> runs on 5.7. See [`BlueprintGraphEditorPort`](BlueprintGraphEditorPort) and
> [`JsonUtilitiesSchema`](JsonUtilitiesSchema).

## Repository layout

This repository's root **is** an Unreal `Plugins/` directory. Drop it into a
project (or engine) `Plugins/` folder, or clone it directly as
`YourProject/Plugins/UE_MCP`.

### Core plugins

| Plugin | Description |
| --- | --- |
| [`ModelContextProtocol`](ModelContextProtocol) | Anthropic MCP server implementation for Unreal Engine. The entry point for the suite. |
| [`ToolsetRegistry`](ToolsetRegistry) | Editor-only registry that discovers and exposes toolsets to the MCP server. Depends on `PythonScriptPlugin`, `EditorScriptingUtilities`, and `FileSandbox`. |
| [`FileSandbox`](FileSandbox) | Core functionality for sandboxing file access in the editor. |
| [`Terminal`](Terminal) | Native Slate terminal emulator. |
| [`SemanticSearch`](SemanticSearch) | Early work-in-progress semantic search system for assets. **Currently disabled on 5.7** — see [Not yet ported](#not-yet-ported-disabled-on-57). |

### UE 5.8 backports (for running on 5.7)

| Plugin | Description |
| --- | --- |
| [`BlueprintGraphEditorPort`](BlueprintGraphEditorPort) | Backport of UE 5.8's `UBlueprintGraphEditor` / `FBlueprintGraphPin` graph-authoring API. Exposes `unreal.BlueprintGraphEditor` / `unreal.BlueprintGraphPin` used by `EditorToolset`'s `blueprint.py`. |
| [`JsonUtilitiesSchema`](JsonUtilitiesSchema) | Backport of UE 5.8's JSON Schema generator (`FJsonSchemaGenerator` / `FJsonSchemaGeneratorEditor`) used across the MCP/Toolset suite. |

### Toolsets

The [`Toolsets`](Toolsets) directory holds the individual tool-call packages.
[`AllToolsets`](Toolsets/AllToolsets) is an aggregator plugin that depends on
every toolset below.

**Status legend:** ✅ ported & enabled · ⚠️ enabled, but some advanced tools
require 5.8 and no-op on 5.7 · ❌ not ported (disabled on 5.7) — see
[Not yet ported](#not-yet-ported-disabled-on-57).

| Toolset | Area | Status |
| --- | --- | --- |
| `AIModuleToolset` | AI / behavior | ✅ |
| `AnimationAssistantToolset` | Animation | ✅ |
| `AutomationTestToolset` | Automation tests | ✅ |
| `ChaosClothAssetToolset` | Chaos Cloth | ⚠️ 3 cloth-conversion tools require 5.8 |
| `ConfigSettingsToolset` | Config / settings | ✅ |
| `ConversationToolset` | Conversation flow | ✅ |
| `DataRegistryToolset` | Data Registry | ✅ |
| `DataflowAgent` | Dataflow | ⚠️ node add/remove, asset-create & template-list require 5.8 |
| `EditorToolset` | Editor & core types (Blueprints, Actors, Properties, …) | ✅ ¹ |
| `GASToolsets` | Gameplay Ability System | ✅ |
| `GameFeaturesToolset` | Game Features | ✅ |
| `GameplayTagsToolset` | Gameplay Tags | ✅ |
| `LiveCodingToolset` | Live Coding | ✅ |
| `MCPClientToolset` | MCP client | ✅ |
| `MVVMToolset` | MVVM / data binding | ✅ |
| `MetaHumanGenerator` | MetaHuman | ✅ (asset-dependent) |
| `NiagaraToolsets` | Niagara VFX | ❌ not ported |
| `PCGToolset` | Procedural Content Generation | ⚠️ 2 tools require 5.8 (DataView, instant-graph execution) |
| `PhysicsToolsets` | Physics | ✅ |
| `PluginToolset` | Plugin management | ✅ |
| `SemanticSearchToolset` | Semantic search | ❌ not ported |
| `SequencerAnimMixerToolset` | Sequencer anim mixing | ❌ not ported |
| `SlateInspectorToolset` | Slate inspection | ✅ |
| `StateTreeToolset` | StateTree | ✅ |
| `UMGToolSet` | UMG / Slate UI | ✅ (5.8 `FWidgetBlueprintOperationUtils` reimplemented as a compat layer) |
| `WorldConditionsToolset` | World Conditions | ✅ |

¹ `EditorToolset`: 13 tools that referenced 5.8-only Python types (`StringTable`,
`SimpleCurveKey`, `K2Node_CreateDelegate`) are restored on 5.7 via C++ shims in
[`BlueprintGraphEditorPort`](BlueprintGraphEditorPort). CurveTable `set_keys` /
`get_keys` use a small `CurveKey` ustruct in place of 5.8's `SimpleCurveKey`
(an Array-of-Map signature isn't a valid reflected type on 5.7).

### Not yet ported (disabled on 5.7)

These three are **disabled in the `.uproject`** and cannot be enabled on a stock
(launcher / binary) UE 5.7 install. Each is blocked by *engine-internal* code —
not plugin code — so a plugin-level backport can't reach it. Re-enabling any of
them requires a **source-built engine** (or the specific engine pieces below).

| Toolset | Why it's blocked | What it needs |
| --- | --- | --- |
| `NiagaraToolsets` | Built entirely on the 5.8-only `NiagaraExternalSystemEditorUtilities`, which depends on `NiagaraEditor` `Internal/` headers (`NiagaraStackQuery.h`, `NiagaraStackEntryEnumerable.h`) and on symbols not exported by 5.7's prebuilt `NiagaraEditor` (e.g. `FNiagaraScriptMergeManager`, several `FNiagaraStackGraphUtilities` methods). No subset is salvageable — see [`NiagaraToolsets/PORT_NOTES_5_7.md`](Toolsets/NiagaraToolsets/PORT_NOTES_5_7.md). | A from-source UE engine so `Niagara` can be recompiled with the needed headers public and symbols exported. |
| `SequencerAnimMixerToolset` | 5.7's shipped `MovieSceneAnimMixer` plugin lacks the 5.8 `MovieSceneAnimMixerScripting` module **and** the `…Layer` / `…TransitionSection` / `…DecorationContainer` UClasses the tools annotate, so the Python package can't even import. | The full 5.8 `MovieSceneAnimMixer` plugin + its `AnimNext` / MovieScene-runtime dependencies (trends toward full 5.8 engine source). |
| `SemanticSearch` + `SemanticSearchToolset` | The core depends on the engine-level `FAISS` ThirdParty module (FAISS + OpenBLAS libs), which is not present anywhere reachable (only a 5.8 engine install ships it). The 5.8 ContentBrowser search-override API is also absent in 5.7 (editor-UI only; the MCP query tools don't need it). | Either `Engine/Source/ThirdParty/FAISS/` from a 5.8 install, **or** a from-scratch FAISS-free vector index (Flat L2). Embeddings already use an OpenAI HTTP API, so no local model is needed. |

> **Engine rebuild constraint:** if the engine cannot be rebuilt, `NiagaraToolsets`
> and `SequencerAnimMixerToolset` are not achievable on 5.7 by any plugin-level
> means. `SemanticSearch` is the only one of the three that *could* be made to
> work without an engine rebuild (by replacing FAISS with an in-engine index).

> **Licensing:** this suite is a backport of Epic's `NoRedist` engine code. It is
> fine for **local / private** use, but the ported Epic code must **not** be
> redistributed (publicly or privately, free or paid) — that violates the UE
> EULA. Only your own original shims + a patch that each recipient applies to
> their **own** legitimately-obtained engine source is shareable.

## How to install

Download the zip, extract it, and copy **all** of the plugin folders into a
`Plugins/` directory in **one** of these two locations:

- **Per project** — copy the folders into your project's `Plugins/` folder (next
  to your `.uproject`), so each plugin lives at:
  ```
  YourProject/Plugins/<PluginName>/...
  ```
  If your project doesn't have a `Plugins/` folder yet, create one. Existing
  plugins in that folder are left untouched.

- **Per engine** — copy the folders into your engine install's
  `Engine/Plugins/` folder, so each plugin lives at:
  ```
  <UE install>/Engine/Plugins/<PluginName>/...
  ```
  (e.g. `C:\Program Files\Epic Games\UE_5.7\Engine\Plugins\`). Installing here
  makes the suite available to **every** project that uses that engine.

Use the **per-project** location if you only want these plugins in one project;
use the **per-engine** location to share them across all of your projects.

After copying the files:

1. Enable the `ModelContextProtocol` plugin (and `AllToolsets`, or the specific
   toolsets you need) in your project's plugin settings.
2. Ensure `PythonScriptPlugin` is enabled — toolsets are Python-backed.
3. Regenerate project files and build the editor target.

> Prefer Git? You can instead clone this repository directly into your project's
> `Plugins/` directory:
> ```sh
> git clone https://github.com/thecodebrozilla/UE_MCP.git Plugins/UE_MCP
> ```

## Requirements

- Unreal Engine 5.7
- `PythonScriptPlugin` and `EditorScriptingUtilities` enabled

## Notes

- Build artifacts (`Binaries/`, `Intermediate/`, `Saved/`, `DerivedDataCache/`,
  `__pycache__/`) are ignored via `.gitignore`. Because the repo root is the
  `Plugins/` folder, the ignore rules use `**/`-anchored patterns to catch
  artifacts inside each plugin subdirectory.
- Several plugins are marked experimental / `NoRedist`.
