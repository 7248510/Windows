/*
#include <windows.h>
#include <cstdio>
#pragma comment(lib, "shell32.lib") //Clang I had to link the library, the specific library was on the docs 
int main()
{
    struct vbasic
    {
        //too large could mean there's no room for the null operator(Stackoverflow)
        vbasic(char uid[])
        {
        char base[11] = "vboxmanage";
        char headless[16] = "--type headless";
        //char *uid;
        char tempvar[150] = "E:\\Visual-Studio\\Project-Locations\\Windows\\Virtual\\"; 
        //4547d839-2f8d-4bd9-bae6-2042ac3bad78
        printf("\n%s %s %s %c", tempvar, base, headless, uid);
        }
    };
    //vbasic metasploitable; //{"febe6f4f-7982-4a59-8dcd-c287fbc2fcd1"};
    vbasic t1 {"234"};
    //printf("%s",metasploitable);
    //ShellExecute(NULL,"open","E:\\Visual-Studio\\Project-Locations\\Windows\\Virtual\\Hello.exe",NULL,NULL,0);

    return 0;
}
*/
#include <iostream>
#include <cstdio>
struct bvirt {
    char uid[150];
};
struct cmdargs {
    std::string x = "VboxManage.exe startvm";
    std::string y = "--type headless";
    //char base[25] = "VboxManage.exe startvm";
    //char headless[16] = "--type headless";
};
void execute(bvirt* uid_ptr)
{
    cmdargs main;
    std::string t1, t2, t3, p1, t4;
    t1 =  main.x;
    t2 = main.y;
    p1 = uid_ptr->uid;
    t3 = main.x + main.y;
    t4 = " ";
    //printf("%s %s %s", main.base,uid_ptr->uid,main.headless);
    std::string as = t4 + t1 + t4 + p1 + t4 + t2;
    std::cout << "ShellExecute(args" << as << ")\n";
    //ShellExecute
}
int main()
{
    bvirt uidM[] = {"febe6f4f-7982-4a59-8dcd-c287fbc2fcd1"}; //Equals the pointer, uida = Unique id actually Metasploitable
    execute(uidM);
    bvirt uidB[] = {"66d3258e-6694-47ae-8a4e-8f00d4d67b9f"}; //Bulldog
    execute(uidB);
}

//vboxmanage uid --type headless
//Shellexecute