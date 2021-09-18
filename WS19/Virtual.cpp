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
    std::string finalCommand = vboxMain + space + uidPointer + space + vboxHeadless;
    const char *finalp = finalCommand.c_str();
    WinExec(finalp,0);
}
int vboxExecute()
{
    //bvirt is your UID structure, simply declare an array and pass the UID, it passes the value as a pointer to launch, once launch gets the pointer it passes it to WinExec
    bvirt uidMetasploitableW32[] = {"a005fd05-8305-438e-acc0-4e6dfea5ab8a"}; //Metasploitable3 Windows 
    bvirt uidMetasploitableUB[] = {"99bb87b5-beb6-4fd5-8e95-29c40c083e28"}; //Metasploitable3 Ubuntu
    bvirt w10[] = {"eee497e6-a22b-4ec2-b688-158dd812e65a"}; //Change the uid, the 90 days VM expired
    bvirt w19[] = {"2df0931b-5bf9-46c3-978c-b692b79ad975"}; //Windows server
    bvirt gitLab[] = {"47e6ac85-92c2-4497-a177-1816dce47579"}; //Gitlab enterprise/community offline
    bvirt pfsenseBridge[] = {"1f82b7e4-0812-4a47-a716-b6ccfa718b6c"}; //pfsense bridged
    bvirt pfsenseInternal[] = {"b7f8d618-7382-4483-af93-865b8ce8bbe9"}; //internal pfsense
    launch(uidMetasploitableW32);
    launch(uidMetasploitableUB);
    launch(w10);
    launch(w19);
    launch(gitLab);
    launch(pfsenseBridge);
    launch(pfsenseInternal);
    return 0;
}
int main()
{
    vboxExecute();
}
