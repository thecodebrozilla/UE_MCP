// [5.7 port] Compatibility definition for UKismetSystemLibrary::RaiseScriptError.
//
// In UE 5.8 this static method is exported (ENGINE_API), so the MCP/Toolset suite calls it
// directly from C++. In UE 5.7 the method is still declared in the header (as a UFUNCTION on a
// MinimalAPI class) so call sites compile, but the raw C++ symbol is NOT exported from the Engine
// module, producing unresolved-external link errors. We provide a local definition that mirrors
// the UE 5.7 engine implementation so this module links. (Each DLL keeps its own internal copy;
// the engine's own non-exported copy is unaffected.)

#include "Kismet/KismetSystemLibrary.h"

#include "Blueprint/BlueprintExceptionInfo.h"
#include "Internationalization/Text.h"
#include "Logging/LogMacros.h"
#include "UObject/Script.h"
#include "UObject/Stack.h"

void UKismetSystemLibrary::RaiseScriptError(const FString& ErrorMessage)
{
#if !(UE_BUILD_TEST || UE_BUILD_SHIPPING)
	FFrame* TopFrame = FFrame::GetThreadLocalTopStackFrame();
	if (TopFrame)
	{
#if WITH_EDITOR
		const FBlueprintExceptionInfo ExceptionInfo(EBlueprintExceptionType::UserRaisedError, FText::FromString(ErrorMessage));
		FBlueprintCoreDelegates::ThrowScriptException(TopFrame->Object, *TopFrame, ExceptionInfo);
#else
		UE_LOG(LogTemp, Error, TEXT("%s:\n%s"), *ErrorMessage, *TopFrame->GetStackTrace());
#endif // WITH_EDITOR
	}
#endif // !(UE_BUILD_TEST || UE_BUILD_SHIPPING)
}
