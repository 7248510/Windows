#include <windows.h>
#include <iostream>
#include <cstdio>
//The binary is 117kb
//Clang requires pragma, the visual studio dev compiler does also(cl), g++ didn't.(for shell execute)
//Identify the OS to determine the which function to run.(Aiming for cross compatibly between Linux & Windows, I don't use Mac)
//This isn't designed to run on a home based system, I'm running these VM'S on rack servers
//After Attempting to use Createprocess & ShellExecute(when it came to passing vboxmanage arguments/target parameters), WinExec works!
//Code sign?
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
    //printf("%s %s %s", main.base,uid_ptr->uid,main.headless);
    //std::string vboxDir = "C:\\Program Files\\Oracle\\VirtualBox\\";
    //Adding an extra space caused a logical error(the command wouldn't execute)
    std::string finalCommand = vboxMain + space + uidPointer + space + vboxHeadless;
    //std::string finalArgs = uidPointer + space + vboxHeadless;
    const char *finalp = finalCommand.c_str();
    //const char *finalArgsp = finalArgs.c_str();
    //std::cout << finalp << "\n";
    //Executing the finalp, WinExec required a const char *, converting a string to a pointer is the [name].c_str()
    //printf("%s",finalp);
    WinExec(finalp,0);
    //const char *final2 = test.c_str();
    //WinExec(final2,0);
    //printf("%s\n", finalp);
    //std::cout << finalCommand << "\n";
    //std::cout << "" << finalArgsp << ")\n"; //Making sure the arguments pass 
    //SetCurrentDirectory(finalDir);
    //WinExec();
    //ShellExecute(NULL,"open",finalp,finalArgsp,NULL,0);
}
int vboxExecute()
{
    //bvirt is your UID structure, simply declare an array and pass the UID, it passes the value as a pointer to launch, once launch gets the pointer it passes it to WinExec
    bvirt uidMetasploitableW32[] = {"a005fd05-8305-438e-acc0-4e6dfea5ab8a"}; //Metasploitable3 Windows 
    bvirt uidMetasploitableUB[] = {"99bb87b5-beb6-4fd5-8e95-29c40c083e28"}; //Metasploitable3 Ubuntu
    bvirt w10[] = {"eee497e6-a22b-4ec2-b688-158dd812e65a"}; //I'll probably have to change the uid, the 90 days most likely expired
    bvirt w19[] = {"2df0931b-5bf9-46c3-978c-b692b79ad975"}; //Windows server
    bvirt gitLab[] = {"47e6ac85-92c2-4497-a177-1816dce47579"}; //Gitlab enterprise/community offline
    bvirt pfsenseBridge[] = {"1f82b7e4-0812-4a47-a716-b6ccfa718b6c"}; //pfsense bridged
    bvirt pfsenseInternal[] = {"b7f8d618-7382-4483-af93-865b8ce8bbe9"}; //internal pfsense
    //bvirt debian[] = {"683cda2a-1307-467a-91af-18dcbbb592c4"}; //Local machine
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
    //launch(debian);
    //launch();
    //launch();
    //launch();
    return 0;
}
int main()
{
    vboxExecute();
    //ShellExecute(NULL,"open","C:\\Users\\Caleb\\AppData\\Local\\Discord\\update.exe","parameters",NULL,10);
    //ShellExecute(NULL,"open","C:\\Users\\Caleb\\Downloads\\VirtualBox-6.1.10-138449-Win.exe",NULL,NULL,0);
    //WinExec("E:\\meta\\Vbox\\VboxManage.exe startvm 683cda2a-1307-467a-91af-18dcbbb592c4 --type headless", 0);
}