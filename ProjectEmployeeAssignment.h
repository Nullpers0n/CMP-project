#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


class ProjectEmployeeAssignment {
private:
	string pID, eID;
	int status;
	//…add more attributes as needed
public:
	ProjectEmployeeAssignment();
	ProjectEmployeeAssignment
	(string mypID, string myeID, int complete = false);
	string getpID();
	string geteID();
	int getStatus();
	void setpID(string mypid);
	void seteID(string myeid);
	void setStatus(int mys);
	bool isCompleted(int s);
	// ~ProjectEmployeeAssignment();
	//a destructor is needed
	//…add other functions as needed
};
