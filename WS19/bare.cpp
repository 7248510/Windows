#include <windows.h>
#include <iostream>
#include <cstdio>
//The binary is 52kb
//Designed for a workstation, I cycle between remote desktop panels or SSH
//Possible implementations:
//Identify the OS to determine the which function to run.(Aiming for cross compatibly between Linux & Windows, I don't use Mac)(Start learning Linux's internals)
//Sign the code on Windows
//signtool.exe sign /a Seems like I need to generate a certification with Makecert or buy one, I'm not buying one...
//This is the Unique Identification structure. Virtualbox hashes machines.
//g++ bare.cpp -o bare.exe -static-libgcc -static-libstdc++
//Linking the two libraries increased the file size too 2.1mb, yikes!
//The old executable works fine, I wonder what caused this behavior.
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
    bvirt securityOnion[] = {"3a278f50-f504-4eff-8028-56fb59747c1b"};
    bvirt pfSense[] = {"25e92566-240e-408e-ade7-0d2d32983d29"};
    bvirt metaSploitable3Win[] = {"a005fd05-8305-438e-acc0-4e6dfea5ab8a"};
    //Starting a centOS machine
    launch(securityOnion);
    launch(pfSense);
    launch(metaSploitable3Win);
    return 0;
}
int main()
{
    vboxExecute();
}