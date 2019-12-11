//The purpose of this file is to write a start up script that allows 
#include <iostream>
#include "path.h"
#include <string>
#include <fstream>
#include <cstdlib>
void parameters();
void configuremsg();
int drive();
int main()
{
	configuremsg();
	drive();
	return 0;
}

void configuremsg()
	{
		using std::cout;
		using std::string;
		string netList; 
		netList = system("net use");
		string netMessage;
		netMessage = "Starting network drives";
		cout << netList;
		
}
//Gets the configuration information of your network drives
//Module will get your drive information

drive()
{
	using std::ofstream;
	using std::cout;
	using std::cin;
	using std::string;
	ofstream parameters;
	cout << "How many Network Drives would you like to add?\n";
	double NWDCount;
	cin >> NWDCount;
	void parameters()
	{
		cout << "Test";
	}
	if (NWDCount > 0)
	{
		cout << "Creating a BAT configuration file with " << NWDCount << " network drives.";
		parameters()
	} 
		else if(NWDCount <= 0)
	{
		cout << "Now exiting the program";
	}
	return 0;
}

