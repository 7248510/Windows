//Using Beej's guide and the windows api
//https://beej.us/guide/bgnet/
#include <winsock.h>
#include <cstdio>
//g++ connect.cpp -lws2_32 
//#pragma comment(lib, "Ws2_32.lib")
//Running Debian WSL/WSL may unlock unix sockets on Windows, time to do some testing
//Additional note, to have root in WSL, you have to add a password
/*From Beej's guide 
close() == closesocket()
select() only works with socket descriptors
fork() doesn't exist, createprocess has a lot of arguments, createthread() might be easier
*/
int initalWinsock() {
    WSAData wsaData; //Creating the object WSADATA called wsaData (Win32 docs)
    int iResult; //The error code or success value
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        printf("The initialization failed\nError code%d", iResult);
    }
    if (iResult == 0) {
        printf("Succesfully initalized");
    }
    return 1;
    WSACleanup();
}
int main()
    {
        initalWinsock();
    }