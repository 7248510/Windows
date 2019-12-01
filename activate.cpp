#include <iostream>
#include <string>
//void run()
//{
//	stage.start
//	std::string start = "Scripts";
//	std::string stage = "activate.bat";
//	
//	
	//std::string start = "";
	//std::string stage = "activate.bat";
	//start = system("cd Scripts/ && ", stage);
	//stage = system("");
//}

struct stage
{
	//using std::string;
	//using std::cout;
	std::string location;
	std::string start;
};

struct parameters
{
	std::string cd;
	std::string combine;
	std::string space;
};

int main()
{
	using std::cout;
	using std::string;
	string test;
	string command;
	string execute;
	stage virtualenv = 
	{
		"scripts",
		"activate.bat"
	};
	//Start stages here
	parameters passing =
	{
		"cd",
		"&&",
		" "
	};
	command = passing.cd + passing.space + virtualenv.location + passing.space + passing.combine + passing.space + virtualenv.start;
	//string command;
	//command = passing.cd + passing.space + virtualenv.location + passing.space + passing.combine + passing.space + virtualenv.start;
	cout << command;
	//execute = system(command);
}

//cout << virtualenv.location;
//cout << virtualenv.start;