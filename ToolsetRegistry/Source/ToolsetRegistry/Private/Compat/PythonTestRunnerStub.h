// [5.7 port] Minimal stub for unreal.PythonTestRunner / unreal.PythonTestRunnerSearchOptions.
//
// Every toolset's init_unreal.py calls `unreal.PythonTestRunner.create(name, options)` to register
// its Python unit tests with the registry. The real implementation (UE 5.8) is automation-based and
// was not ported to 5.7 (it relied on latent-command APIs that changed). Without these reflected
// types, init_unreal.py raises AttributeError and aborts before/after toolset registration. This stub
// exposes the same Python-visible names with a no-op create() so registration proceeds. Running
// toolset Python unit tests via the registry is unavailable on 5.7; normal toolset use is unaffected.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"

#include "PythonTestRunnerStub.generated.h"

USTRUCT(BlueprintType, Category = "PythonTestRunner")
struct FPythonTestRunnerSearchOptions
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PythonTestRunner")
	FString RootModule;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PythonTestRunner")
	FString TestModuleGlob;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PythonTestRunner")
	TArray<FString> TestNameGlobs;
};

UCLASS(MinimalAPI, BlueprintType, Category = "PythonTestRunner")
class UPythonTestRunner : public UObject
{
	GENERATED_BODY()

public:
	/// [5.7 port] No-op stub. Returns a transient instance so callers can store it; tests are not run.
	UFUNCTION(BlueprintCallable, Category = "PythonTestRunner")
	static UPythonTestRunner* Create(const FString& TestName, const FPythonTestRunnerSearchOptions& Options);
};
