//The purpose of this file is to write a start up script that allows 
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
void configuremsg();
void execute();
int drive();
int main()
{
	configuremsg();
	drive();
	execute();
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

int drive()
{
	using std::cout;
	using std::cin;
	using std::string;
	string netd;
	netd = "netdrive.bat";
	cout << "How many Network Drives would you like to add?\n";
	double NWDCount;
	cin >> NWDCount;
	//Checking if the input is > 0
	if (NWDCount > 0)
	{
		using std::ofstream;
		ofstream parameters;
		string netList;
		string netanswer;
		netList = "net use";
		double lineControl;
		cout << "Creating a BAT configuration file for " << NWDCount << " network drives. \n";
		cout << "The file name will be called 'netdrive.bat'\n";
		cout << "What network drive would you like to add to the bat script?\n";
		/*
		Implement a loop counter
		*/
		cin >> netanswer;
		parameters.open(netd);
		parameters << netList << " " << netanswer;
		//cout << netList << " " << netanswer; (Testing the output)
		parameters.close();
	} 
		else if(NWDCount <= 0)
	{
		cout << "Exiting the program";
	}
	return 0;
}

void execute()
{
	std::string exec;
	exec = system("netdrive.bat");
}

