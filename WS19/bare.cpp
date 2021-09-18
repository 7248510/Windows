#include <windows.h>
#include <iostream>
#include <cstdio>
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
