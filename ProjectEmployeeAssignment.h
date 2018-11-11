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
	//purpose : sets pID, eID, and status to 0
	//input : none
	//output : none
	ProjectEmployeeAssignment();
	//purpose : sets pID to mypID, eID to myeID, and status to complete
	// input : mypID, myeID, and complete
	// output: none
	ProjectEmployeeAssignment
	(string mypID, string myeID, int complete = false);
	//purpose: gets the project id
	// input : none
	// output : the pID
	string getpID();
	//purpose : gets the employee id
	// input : none
	// output: the eID
	string geteID();
	// purpose: gets the status of the project
	// input : none
	// output : the status
	int getStatus();
	//purpose : sets the pID to mypid
	// input : mypid that the user inputs
	// output : none
	void setpID(string mypid);
	// purpose : sets the eID to myeid
	//input : myeid that the user inputs
	// output : none
	void seteID(string myeid);
	// purpose : sets the status to mys
	//input : mys that the user inputs
	//output : none
	void setStatus(int mys);
	//purpose : checks if s is 1 or 0
	// input : int s that the user inputs
	// output : true if s is 1 and false if s is 0
	bool isCompleted(int s);

	//…add other functions as needed
};
