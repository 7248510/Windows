#include <windows.h>
#include <iostream>
#include <cstdio>
//The binary is 117kb
//Designed for a workstation, I cycle between remote desktop panels or SSH
//Possible implementations:
//Identify the OS to determine the which function to run.(Aiming for cross compatibly between Linux & Windows, I don't use Mac)(Start learning Linux's internals)
//Sign the code on Windows

//This is the Unique Identification structure. Virtualbox hashes machines.
struct bvirt {
    char uid[150];
};
//Command line arguments, vboxExec's string needs the path of the VirtualBox installation location
struct cmdargs {
    std::string vboxExec = "C:\\Program Files\\Oracle\\VirtualBox\\VBoxManage.exe startvm";
    std::string vboxType = "--type headless";
};
void launch(bvirt* uid_ptr) //passing the UID pointer to the function, it gets the pointer from vboxExecute()
{
    cmdargs main; //initializing the structure command arguments
    std::string vboxMain, vboxHeadless, combinationVbox, uidPointer, space; //Declaring strings
    vboxMain =  main.vboxExec;
    vboxHeadless = main.vboxType;
    uidPointer = uid_ptr->uid;
    combinationVbox = main.vboxExec + main.vboxType;
    space = " ";
    //Adding an extra space caused a logical error(the command wouldn't execute)
    std::string finalCommand = vboxMain + space + uidPointer + space + vboxHeadless;
    const char *finalp = finalCommand.c_str();
    //Executing the finalp, WinExec required a const char *, converting a string to a pointer is the [name].c_str()
    WinExec(finalp,0);
}
int vboxExecute()
{
    //bvirt is your UID structure, simply declare an array and pass the UID, it passes the value as a pointer to launch, once launch gets the pointer it passes it to WinExec
    bvirt centos[] = {"fe5a304c-870c-4068-a0bf-420d5b576db2"}; //Local machine
    //Starting a centOS machine
    launch(centos);
    return 0;
}
int main()
{
    vboxExecute();
}