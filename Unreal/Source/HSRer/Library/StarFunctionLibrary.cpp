// Adam


#include "StarFunctionLibrary.h"

#include <windows.h>
#include <TlHelp32.h>

TArray<FProcessInfo> UStarFunctionLibrary::GetProcesses(FString ProcessName, int ProcessID)
{
    TArray<FProcessInfo> PID;
    HANDLE Snapshot = HANDLE();
    PROCESSENTRY32 PE = PROCESSENTRY32();
    bool Result = false;

    Snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (INVALID_HANDLE_VALUE == Snapshot)
        return PID;

    PE.dwSize = sizeof(PROCESSENTRY32);
    Result = Process32First(Snapshot, &PE);

    while (Result)
    {
        if (ProcessID == -1 && wcscmp(*ProcessName, PE.szExeFile) == 0)
        {
            FProcessInfo ProcessInfo = FProcessInfo(PE.szExeFile, PE.th32ProcessID,
                PE.dwSize, PE.cntUsage, PE.th32DefaultHeapID, PE.th32ModuleID, PE.cntThreads,
                PE.th32ParentProcessID, PE.pcPriClassBase, PE.dwFlags);

            PID.Add(ProcessInfo);
        }
        else if (PE.th32ProcessID == ProcessID)
        {
            FProcessInfo ProcessInfo = FProcessInfo(PE.szExeFile, PE.th32ProcessID,
                PE.dwSize, PE.cntUsage, PE.th32DefaultHeapID, PE.th32ModuleID, PE.cntThreads,
                PE.th32ParentProcessID, PE.pcPriClassBase, PE.dwFlags);

            PID.Add(ProcessInfo);
        }
        Result = Process32Next(Snapshot, &PE);
    }

    return PID;
}

FProcessInfo UStarFunctionLibrary::GetProcessInfo(int ProcessID)
{
    return GetProcesses(L"", ProcessID)[0]; // realistically when will it return more than one process from a single id, windows 12?!?!
}

bool UStarFunctionLibrary::KillProcessByInfo(FProcessInfo ProcessInfo, FString& OutErrorCode)
{
    OutErrorCode = TEXT("Success");
    bool ReturningSuccess = false;

    if (!ProcessInfo.ProcessName.IsEmpty())
    {
        if (ProcessInfo.ProcessID > 0)
        {
            auto Process = OpenProcess(PROCESS_TERMINATE, false, ProcessInfo.ProcessID);
            if (Process)
            {
                ReturningSuccess = TerminateProcess(Process, 0);
                CloseHandle(Process);
            }
            else
                OutErrorCode = TEXT("Failed to OpenProcess for termination");
        }
        else
            OutErrorCode = TEXT("ProcessInfo has an invalid PID");
    }
    else
        OutErrorCode = TEXT("ProcessInfo has an invalid name");

    return ReturningSuccess;
}

bool UStarFunctionLibrary::EqualEqual_ProcessInfo(FProcessInfo A, FProcessInfo B)
{
    return A.ProcessID == B.ProcessID;
}