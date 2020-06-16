//Configuring VirtualBox
//First Launch the VM'S in headless mode
//This can be accomplished using Powershell but, I wanted to learn the windows api
#include <cstdio>
#include <windows.h>
#include <tchar.h>
//tmain operates the same as main. If you'd like to learn more https://docs.microsoft.com/en-us/cpp/cpp/main-function-command-line-args?view=vs-2019
//First structure the classes
//Second Output the correct configuration
//Third Createthe process
//Add persistence via taskmanager|Linux equivalanet would have been a cronjob
struct virt
{
    //too large could mean there's no room for the null operator(Stackoverflow)
    char base[11] = "vboxmanage";
    char headless[16] = "--type headless";
    char uid[100] = "4547d839-2f8d-4bd9-bae6-2042ac3bad78";
};

int _tmain()
{
    virt metasploitable;
    printf("%s ", metasploitable.base);
    printf("%s ", metasploitable.uid);
    printf("%s ", metasploitable.headless);
    return 0;
}












/*
int _tmain()
{
    return 0;
}
*/