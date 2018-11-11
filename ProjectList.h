#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Employee.h"
#include "EmployeeList.h"
#include "listofPrjEmpAssignment.h"
#include "Project.h"
using namespace std;


class ProjectList {
private:
	vector<Project> listofProjects;
	string prjFileName;
	//…add more attributes as needed
public:
	ProjectList(); //reads from the file
	bool addProject(Project p);
	void deleteProject(string myid);
	Project getProject(int index);
	string getProjectTitle(string ID);
	string getProjectID(string title);
	int getIndexUsingID(string myid);
	int getIndexUsingTitle(string mytitle);
	void listProjects();
	~ProjectList(); //writes back to the same input file
					//…add other functions as needed

					// function used to check if its already in the list so we don't add it again. 
	int isItInList(Project p);

	int getPrjListSize();
	void printError(string& str);
	
};
