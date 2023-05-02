// Adam

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "StarFunctionLibrary.generated.h"

USTRUCT(BlueprintType)
struct FProcessInfo
{
GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FString ProcessName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int ProcessID;
    
    DWORD dwSize;
    DWORD cntUsage;
    ULONG_PTR th32DefaultHeapID;
    DWORD th32ModuleID;
    DWORD cntThreads;
    DWORD th32ParentProcessID;
    LONG pcPriClassBase;
    DWORD dwFlags;

    FProcessInfo()
    {}

    FProcessInfo(FString InName,
        int InPID, DWORD IndwSize, DWORD IncntUsage,
        ULONG_PTR Inth32DefaultHeapID, DWORD Inth32ModuleID, DWORD IncntThreads,
        DWORD Inth32ParentProcessID, LONG InpcPriClassBase, DWORD IndwFlags)
    {
        ProcessName = InName;
        ProcessID = InPID;
        dwSize = IndwSize;
        cntUsage = IncntUsage;
        th32DefaultHeapID = Inth32DefaultHeapID;
        th32ModuleID = Inth32ModuleID;
        cntThreads = IncntThreads;
        th32ParentProcessID = Inth32ParentProcessID;
        pcPriClassBase = InpcPriClassBase;
        dwFlags = IndwFlags;
    }

    FProcessInfo(FString InName, int InPID)
    {
        ProcessName = InName;
    }
};

/**
 * 
 */
UCLASS()
class HSRER_API UStarFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

    // This function returns a list of process based on their name (the name is capital sensitive).
	UFUNCTION(BlueprintPure)
	static TArray<FProcessInfo> GetProcesses(FString ProcessName, int ProcessID = -1);

    // This function returns a process based on their ID.
    UFUNCTION(BlueprintPure)
    static FProcessInfo GetProcessInfo(int ProcessID);

    // This function kills a process from the info.
    UFUNCTION(BlueprintCallable)
    static bool KillProcessByInfo(FProcessInfo ProcessInfo, FString& OutErrorCode);

    UFUNCTION(BlueprintPure)
    static bool EqualEqual_ProcessInfo(FProcessInfo A, FProcessInfo B);
};
