#include <windows.h>
#include <iostream>
#include <cstdio>
#pragma comment(lib, "shell32.lib")
//The binary is 117kb :(
//Clang requires pragma, the visual studio dev compiler does also(cl), g++ didn't.
//Identify the OS to determine the which function to run.(Aiming for cross compatibly between Linux & Windows, I don't use Mac)
//This isn't designed to run on a home based system, I'm running these VM'S on rack servers
struct bvirt {
    char uid[150];
};
struct cmdargs {
    std::string vboxExec = "E:\\meta\\Vbox\\VBoxManage.exe startvm";
    //std::string vboxExec = "C:\\Program Files\\Oracle\\VirtualBox\\VboxManage.exe startvm";
    std::string vboxType = "--type headless";
};
void launch(bvirt* uid_ptr)
{
    cmdargs main;
    std::string vboxMain, vboxHeadless, combinationVbox, uidPointer, space; //Declaring strings
    vboxMain =  main.vboxExec;
    vboxHeadless = main.vboxType;
    uidPointer = uid_ptr->uid;
    combinationVbox = main.vboxExec + main.vboxType;
    space = " ";
    //printf("%s %s %s", main.base,uid_ptr->uid,main.headless);
    std::string vboxDir = "C:\\Program Files\\Oracle\\VirtualBox\\";
    std::string finalCommand = space + vboxMain + space + uidPointer + space + vboxHeadless;
    const char *finalp = finalCommand.c_str();
    const char *finalDir = vboxDir.c_str();
    //std::cout << finalp << "\n";
    std::cout << "ShellExecute(args" << finalCommand << ")\n"; //Making sure the arguments pass 
    //SetCurrentDirectory(finalDir);
    ShellExecute(NULL,"open",finalp,NULL,NULL,0);
}
int vboxExecute()
{
    bvirt uidMetasploitableW32[] = {"a005fd05-8305-438e-acc0-4e6dfea5ab8a"}; //Metasploitable3 Windows 
    bvirt uidMetasploitableUB[] = {"99bb87b5-beb6-4fd5-8e95-29c40c083e28"}; //Metasploitable3 Ubuntu
    bvirt w10[] = {"eee497e6-a22b-4ec2-b688-158dd812e65a"}; //I'll probably have to change the uid, the 90 days most likely expired
    bvirt w19[] = {"2df0931b-5bf9-46c3-978c-b692b79ad975"}; //Windows server
    bvirt gitLab[] = {"47e6ac85-92c2-4497-a177-1816dce47579"}; //Gitlab enterprise/community offline
    bvirt pfsenseBridge[] = {"1f82b7e4-0812-4a47-a716-b6ccfa718b6c"}; //pfsense bridged
    bvirt pfsenseInternal[] = {"b7f8d618-7382-4483-af93-865b8ce8bbe9"}; //internal pfsense
    //bvirt [] = {""}; 
    //bvirt [] = {""};
    //bvirt [] = {""};
    launch(uidMetasploitableW32);
    launch(uidMetasploitableUB);
    launch(w10);
    launch(w19);
    launch(gitLab);
    launch(pfsenseBridge);
    launch(pfsenseInternal);
    //launch();
    //launch();
    //launch();
    return 0;
}
int main()
{
    vboxExecute();
}

//vboxmanage uid --type headless
//Shellexecute