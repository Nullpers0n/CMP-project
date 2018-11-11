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
	// Purpose: Opens the text file that contains the projects and stores them into the listofprojects vector
	// Input: No Input
	// Output: no output
	ProjectList(); //reads from the file
	// Purpose: Adds a new project to the list of projects vector
	// Input: A Project class p (ID and title inside it)
	// Output: returns true if the project was added, returns false if the project already exists
	bool addProject(Project p);
	// Purpose: Deletes a project out of the listofprojects
	// Input: the id of the project that the user entered
	// Output: no output
	void deleteProject(string myid);
	// Purpose: searches for the project that the user wants throught its index
	// Input: the index that the project lies inside the vector
	// Output: the Project P
	Project getProject(int index);
	//Purpose : gets the project title and displays it to the user through the id
	// Input: ID of the project
	// output: The title of the project
	string getProjectTitle(string ID);
	// Purpose: Searches for the title of the project that the user entered to show the user the project id
	// Input : the title of the project that the user entered
	// output : The ID of the project
	string getProjectID(string title);
	// Purpose: searches for the project that has the same id as the user entered
	// Input: the id that the user is searching for
	// Output: returns the index that the project is located on inside the listofprojects vector, else it returns -1
	int getIndexUsingID(string myid);
	// Purpose: searches for the project that has the same title as the user entered
	// Input: the title that the user is searching for
	// Output: returns the index that the project is located on inside the listofprojects vector, else it returns -1
	int getIndexUsingTitle(string mytitle);
	// Purpose : lists the projects that are inside the listofprojects vector 
	// input: no input
	// output: the cout that output the id and title of projects
	void listProjects();
	// Purpose : Destructor that returns the listofprojects vector back to the text file
	// Input: no Input
	// Output: no output
	~ProjectList(); //writes back to the same input file
					//…add other functions as needed

	// Purpose: Searches if a project is in the list of projects
	// Input: Project class (ID and title inside it)
	// Output: returns the index where the project is located in the vector, else it returns -1 as an indicator that the project was not found
	int isItInList(Project p);
	// Purpose: returns the number of projects inside the list
	// Input: no input
	// Output: the size of listofProjects vector
	int getPrjListSize();
	// Purpose: non member function used in some of the classes to print error.
	// Input: string from another input or function
	// Output: no output
	void printError(string& str);
	
};
