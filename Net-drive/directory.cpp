#include <iostream>
#include "path.h"
#include <string>
#include <fstream>
#include <cstdlib>
#include "winadd.h"
void winMessage();
void extract_info();
//void winAdd();
void location();

int main()
{	
	winMessage();
	extract_info();
//	winAdd();
	location();
}



void extract_info()
{
	int win_extract;
	win_extract = system("echo Your windows username is '%username%'");
	//System command allows the ability to run system commands inside your C++ program.
}

void winMessage()
{
	using std::string;
	using std::cout;
	string win_message = "Please enter your windows username.\n";
	cout << win_message;
}


void location()
{
	using std::ofstream;
	using std::string;
	using std::cout;
	using std::cin;
	string win_name;
	cin >> win_name;
	string locationf;
	string base_C = "C:\\Users\\";
	string end_Location = "\\Desktop\\location3.bat";
	cout << base_C + win_name + end_Location + "\n";
	locationf = base_C + win_name + end_Location;
	ofstream location(locationf); //Apply the users desktop name so the file will be added to the correct desktop
}


