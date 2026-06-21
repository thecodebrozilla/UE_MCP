// [5.7 port] See PythonTestRunnerStub.h.

#include "Compat/PythonTestRunnerStub.h"

#include "UObject/Package.h"

UPythonTestRunner* UPythonTestRunner::Create(const FString& TestName, const FPythonTestRunnerSearchOptions& Options)
{
	// No-op: the 5.7 port does not run toolset Python unit tests. Return a valid object so that
	// init_unreal.py's `tests._test_runner = unreal.PythonTestRunner.create(...)` succeeds.
	return NewObject<UPythonTestRunner>(GetTransientPackage());
}
