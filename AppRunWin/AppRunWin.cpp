// AppRunWin.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
int exec(const std::string& cmd, const std::string& params)
{
    STARTUPINFOA si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    
    std::auto_ptr<char> arg(new char[params.length() + 1]);
    std::memcpy(arg.get(), params.c_str(), params.length());
    arg.get()[params.length()] = 0;

    if (CreateProcessA(cmd.c_str(), arg.get(), NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi))
    {
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }

    return 0;
}

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
    exec("SlaveApp.exe", "> nul 2>&1");
    MessageBoxA(nullptr, "Info", "Done", MB_OK | MB_ICONINFORMATION);
    return 0;
}

