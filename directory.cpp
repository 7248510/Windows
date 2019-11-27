#include <iostream>
#include "path.h"
#include <string>
#include <fstream>
#include <cstdlib>
void winMessage();
void extract_info();
void winAdd();
void location();

int main()
{	
	winMessage();
	extract_info();
	winAdd();
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
	//string c_drive = "C:\\Users\\";
	//string username = "%username%";
	//string location = "\\Desktop\\";
	//string file_name = "location3.bat";
	//ofstream location(c_drive); //Object named location and writes the file
	ofstream location("C:\\Users\\&username&\\Desktop\\location3.bat"); //Apply the users desktop name so the file will be added to the correct desktop
}

void winAdd()
{
	using std::string;
	using std::cin;
	string win_name;
	cin >> win_name;
}
