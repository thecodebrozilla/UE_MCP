# UE_MCP Plugins

Ported Unreal Engine MCP from 5.8 to 6.7 (eventually will do earlier versions too) along with most toolkists.

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
| [`SemanticSearch`](SemanticSearch) | Early work-in-progress semantic search system for assets. |

### UE 5.8 backports (for running on 5.7)

| Plugin | Description |
| --- | --- |
| [`BlueprintGraphEditorPort`](BlueprintGraphEditorPort) | Backport of UE 5.8's `UBlueprintGraphEditor` / `FBlueprintGraphPin` graph-authoring API. Exposes `unreal.BlueprintGraphEditor` / `unreal.BlueprintGraphPin` used by `EditorToolset`'s `blueprint.py`. |
| [`JsonUtilitiesSchema`](JsonUtilitiesSchema) | Backport of UE 5.8's JSON Schema generator (`FJsonSchemaGenerator` / `FJsonSchemaGeneratorEditor`) used across the MCP/Toolset suite. |

### Toolsets

The [`Toolsets`](Toolsets) directory holds the individual tool-call packages.
[`AllToolsets`](Toolsets/AllToolsets) is an aggregator plugin that depends on
every toolset below.

| Toolset | Area |
| --- | --- |
| `AIModuleToolset` | AI / behavior |
| `AnimationAssistantToolset` | Animation |
| `AutomationTestToolset` | Automation tests |
| `ChaosClothAssetToolset` | Chaos Cloth |
| `ConfigSettingsToolset` | Config / settings |
| `ConversationToolset` | Conversation flow |
| `DataRegistryToolset` | Data Registry |
| `DataflowAgent` | Dataflow |
| `EditorToolset` | Editor & core types (Blueprints, Actors, Properties, …) |
| `GASToolsets` | Gameplay Ability System |
| `GameFeaturesToolset` | Game Features |
| `GameplayTagsToolset` | Gameplay Tags |
| `LiveCodingToolset` | Live Coding |
| `MCPClientToolset` | MCP client |
| `MVVMToolset` | MVVM / data binding |
| `MetaHumanGenerator` | MetaHuman |
| `NiagaraToolsets` | Niagara VFX |
| `PCGToolset` | Procedural Content Generation |
| `PhysicsToolsets` | Physics |
| `PluginToolset` | Plugin management |
| `SemanticSearchToolset` | Semantic search |
| `SequencerAnimMixerToolset` | Sequencer anim mixing |
| `SlateInspectorToolset` | Slate inspection |
| `StateTreeToolset` | StateTree |
| `UMGToolSet` | UMG / Slate UI |
| `WorldConditionsToolset` | World Conditions |

## Getting started

1. Clone this repository into your project's `Plugins/` directory:
   ```sh
   git clone https://github.com/BodeSoftware/UE_MCP.git Plugins/UE_MCP
   ```
2. Enable the `ModelContextProtocol` plugin (and `AllToolsets`, or the specific
   toolsets you need) in your project's plugin settings.
3. Ensure `PythonScriptPlugin` is enabled — toolsets are Python-backed.
4. Regenerate project files and build the editor target.

## Requirements

- Unreal Engine 5.7
- `PythonScriptPlugin` and `EditorScriptingUtilities` enabled

## Notes

- Build artifacts (`Binaries/`, `Intermediate/`, `Saved/`, `DerivedDataCache/`,
  `__pycache__/`) are ignored via `.gitignore`. Because the repo root is the
  `Plugins/` folder, the ignore rules use `**/`-anchored patterns to catch
  artifacts inside each plugin subdirectory.
- Several plugins are marked experimental / `NoRedist`.
