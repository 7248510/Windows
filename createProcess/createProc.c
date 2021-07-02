#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
//This launches an executable in the given directory.
int createProc() {
    int status = 0; //Tracking the functions success
    //https://docs.microsoft.com/en-us/windows/win32/procthread/creating-processes
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    SecureZeroMemory (&si, sizeof(si));
    si.cb = sizeof(si);
    SecureZeroMemory (&pi, sizeof(pi));
    LPCSTR applicationName = "hello.exe";
    LPSTR commandLineargs = NULL;
    LPSECURITY_ATTRIBUTES defaultAttr = NULL;
    LPSECURITY_ATTRIBUTES handleThread = NULL;
    BOOL inheritHandle = false;
    DWORD createFlags = 0; 
    LPVOID environment = NULL;
    LPCSTR currentDir = NULL;
    if (!CreateProcess(
        applicationName, //program to launch
        commandLineargs, //command arguments
        defaultAttr, //The security handles can be default    
        handleThread, //Thread does not need to be inherited  
        inheritHandle, //The handles do not need to be inherited
        createFlags, //The process inherits both the error mode of the caller and the parent's console. MSDN
        environment, //Use the new processes environment for the calling process
        currentDir, //Use the current directory
        &si, //Get SI's pointer
        &pi //Pi's pointer
    ));
    else {
         //By default the program will be successful. Therefore the int is initialized to zero.
        if (GetLastError() == 0) {
            printf("Successfully executed\n"); //The operation completed successfully. https://docs.microsoft.com/en-us/windows/win32/debug/system-error-codes--0-499-
            status = EXIT_SUCCESS;
            return status;
        }
        if (GetLastError() != 0) {
            printf("\nError Code: %d", GetLastError()); //Error occurs see https://docs.microsoft.com/en-us/windows/win32/debug/system-error-codes
            status = EXIT_FAILURE;
            return status;
        }
            return status;
        }
    // Wait until child process exits.
    WaitForSingleObject(pi.hProcess, INFINITE);
    // Close process and thread handles. 
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    return status;
}
int main()
{
    int launch = createProc();
    if (launch == 0) {
        return EXIT_SUCCESS;
    }
    else if (launch != 0) {
        printf("Create process failed.");
        return EXIT_FAILURE;
    }
}