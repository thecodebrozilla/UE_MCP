# NiagaraToolsets — UE 5.7 backport status: INFEASIBLE (disabled + documented)

Date: 2026-06-21. Target engine: UE 5.7 launcher (C:\Program Files\Epic Games\UE_5.7).

## Verdict
**INFEASIBLE on 5.7 without an engine-level back-port.** NiagaraToolsets is left
**disabled** in `UE_MCP.uproject` (`{ "Name": "NiagaraToolsets", "Enabled": false }`,
already set — no .uproject change required).

## Why
Every tool in this plugin is built on the 5.8-only utility
`NiagaraExternalSystemEditorUtilities` (header `NiagaraExternalSystemEditorUtilities.h`,
class `UNiagaraExternalEditUtilities` + `FNiagaraExternalEditContext` +
the whole `FNiagaraExt_*` struct family). That header/cpp does not exist in 5.7.

5.8 reference source used for the analysis:
- `B:\Unreal Projects\UE_MCP\ue5_8_plugins_reference\Plugins\FX\Niagara\Source\NiagaraEditor\Public\NiagaraExternalSystemEditorUtilities.h`
- `B:\Unreal Projects\UE_MCP\ue5_8_plugins_reference\Plugins\FX\Niagara\Source\NiagaraEditor\Private\NiagaraExternalSystemEditorUtilities.cpp` (3540 lines)

The intended port strategy (copy the 5.8 .h/.cpp into a compat folder and re-point the
toolset at it) was evaluated method-by-method against 5.7's NiagaraEditor source
(`C:\Program Files\Epic Games\UE_5.7\Engine\Plugins\FX\Niagara\Source`). It fails on two
classes of blocker that together kill essentially the whole utility:

### A. Inaccessible-by-design (cannot be fixed without editing the read-only engine)
1. `NiagaraStackQuery.h` (`FNiagaraStackRootQuery`, `FNiagaraStackScriptItemGroupQuery`,
   `TNiagaraStackQueryResult`) and `NiagaraStackEntryEnumerable.h`
   (`TNiagaraStackEntryEnumerable`) live in `NiagaraEditor/Internal/` in 5.7, not `Public/`.
   An external plugin module cannot include `Internal/` headers (the engine module does not
   allow-list this plugin, and we may not edit `NiagaraEditor.Build.cs`). These power
   `FNiagaraExt_StackItemReference::GetScript`/`GetModule` and **every** topology / data /
   input-value / dependency / diagnostics walk — i.e. the core of the toolset.
2. `FNiagaraScriptMergeManager` is `Private/` and unexported in 5.7 (used by `RemoveEmitter`).
3. `FNiagaraStackGraphUtilities::AddScriptModuleToStack`, `RemoveModuleFromStack`,
   `RebuildEmitterNodes` exist but are not `NIAGARAEDITOR_API` (link failures); and
   `NiagaraEditorUtilities::KillSystemInstances` is likewise unexported.

### B. Genuinely missing APIs (no 5.7 equivalent)
4. `AssetBuildUtilities/NiagaraAssetBuilder.h` / `FNiagaraSystemAssetBuilder` — does not
   exist in 5.7 (kills `CreateNiagaraSystem`).
5. `UNiagaraStackFunctionInput::SetDataInterfaceValueExternal(UClass*, TFunction)` — missing
   (kills DI writes in `SetStackInputData`).
6. `FNiagaraStackGraphUtilities::ExtractInputPinsFromHistory(...)` — cpp-local in 5.7, not in
   any header, and takes `UEdGraph*` not `UNiagaraGraph*` (kills `GetModuleSchemaFromAsset`).
7. `UEdGraphSchema_Niagara::TryGetPinDefaultValueFromNiagaraVariant(...)` — missing
   (kills SetParameters default-value coercion).
8. `FVersionedNiagaraEmitterData::GetRenderer(int32)` — missing (only `GetRenderers()[i]`).
9. `FNiagaraUserRedirectionParameterStore::GetParameter_InternalUseOnly` /
   `SetParameter_InternalUseOnly` (FNiagaraVariant-based) — missing (5.7 only has templated
   `GetParameterValue<T>`/`SetParameterValue<T>`). Kills user-variable get/set,
   `GetSystemSummary`, `GetUserVariables`, `AddUserVariable`.
10. `FNiagaraVariant::GetBytesValue<int32>(FNiagaraTypeDefinition)` and
    `IsValid(FNiagaraTypeDefinition)` — missing. These are baked into the value-marshalling of
    `FNiagaraExt_VariableValue::Get/Set` and `FNiagaraExt_StackInputValue::Init*`, which nearly
    every read/write path uses.

(There are also numerous benign signature drifts — `Initialize` by-value options,
`EValueMode` enumerator order, global vs nested `EStackIssueSeverity`, const-ref vs value
params, the parameter-map types now being `FNiagaraCompilationGraphBridge` template aliases,
`FNiagaraVariant` in the Niagara module, `FNiagaraCompileEvent` in NiagaraShader — but those
are not what makes it infeasible.)

## Why not "implement the rest, no-op the unportable methods"
The task's fallback (port the rest; stub the one unportable method) does not apply here: the
blockers are pervasive and structural, not isolated. The Internal-header stack-query /
enumerable dependency (A1) and the missing `FNiagaraVariant`/parameter-store value APIs
(B9, B10) are used transitively by the great majority of the ~40 methods AND are embedded in
the `FNiagaraExt_*` struct member functions themselves. Because all methods compile in a
single UCLASS/translation unit alongside those struct methods, the unit cannot build until
every reference resolves. The handful of methods with no hard blocker (a few schema/property-
blob getters, `GetAvailableDynamicInputs`, renderer add/remove) are not independently useful
and cannot be salvaged into a compiling module on their own without a near-total rewrite of
the utility against a different (public-only) 5.7 API surface — effectively re-authoring
Epic's experimental subsystem, which is out of scope for a backport.

## Re-enabling later
A real 5.7 enablement would require either (a) Epic exposing the Niagara stack-query /
enumerable headers + the missing parameter-store/variant/asset-builder APIs in 5.7 (an
engine source build with edited Build.cs / added `NIAGARAEDITOR_API`), or (b) rewriting
`NiagaraExternalSystemEditorUtilities` from scratch on 5.7's public NiagaraEditor surface
(SystemViewModel + public stack view models, walking children via `GetUnfilteredChildren`
instead of the Internal enumerables, and templated parameter-store accessors). Both are
substantial engine-level efforts beyond this toolset.

## Files
- This plugin compiles **no** C++ on 5.7; it stays disabled. No source was added/changed for
  the (abandoned) port except this note. `Source/.../Private/Compat/KismetSystemLibraryCompat.cpp`
  is a pre-existing shared drift fix (catalog item 6) and is harmless/unused while disabled.
