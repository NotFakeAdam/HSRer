#include <windows.h>
#include <tlhelp32.h>
#include <set>

std::set<int> FindProcesses(const wchar_t* ProcessName)
{
    std::set<int> PID;
    HANDLE Snapshot;
    PROCESSENTRY32 PE;
    bool Result;

    Snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (INVALID_HANDLE_VALUE == Snapshot)
        return PID;

    PE.dwSize = sizeof(PROCESSENTRY32);
    Result = Process32First(Snapshot, &PE);

    while (Result)
    {
        if (wcscmp(ProcessName, PE.szExeFile) == 0)
        {
            PID.emplace(PE.th32ProcessID);
        }
        Result = Process32Next(Snapshot, &PE);
    }

    return PID;
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
    auto WindowTitle = (LPCWSTR)L"Star Railer";

    MessageBox(NULL, (LPCWSTR)L"Press Ok to rail stars", WindowTitle, 0);

    auto GamePIDS = FindProcesses(L"StarRail.exe");
    if (GamePIDS.size() != 0)
    {
        for (int GamePID : GamePIDS)
        {
            auto Process = OpenProcess(PROCESS_TERMINATE, false, GamePID);
            if (Process)
            {
                TerminateProcess(Process, 0);
                CloseHandle(Process);
            }
        }
        MessageBox(NULL, (LPCWSTR)L"Railed all the stars.", WindowTitle, 0);
    }
    else
    {
        MessageBox(NULL, (LPCWSTR)L"No stars to rail...", WindowTitle, 0);
    }
}
