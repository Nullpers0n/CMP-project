#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Employee.h"
#include "EmployeeList.h"
#include "Project.h"
#include "ProjectEmployeeAssignment.h"
#include "ProjectList.h"
using namespace std;

class listofPrjEmpAssignment {
private:
	vector <ProjectEmployeeAssignment> list;
	vector <Employee> elist;
	vector <Project> plist;
	//…add more attributes as needed
public:
	listofPrjEmpAssignment();//reads from the file
	void addEmpPrjAssignment(Employee e, Project b);
	void setProjectStatus(Employee e, Project b, int mys);
	int isEmpInList(string myeid);
	int isPrjInList(string mypid);
	int isEmpPrjInList(string myeid, string mypid);
	void listAllIncompleteProjects();
	void listAllCompleteProjects();
	void listAllProjectsAssignments();
	~listofPrjEmpAssignment();//writes back to the file
							  //…add other functions as needed

							  //function to list the Employees working on a certain project. 

							  // function to delete a certin employee and project assingment. 
							  // EmployeesWorkingOnProject(string mypid);

	void deleteEmpPrjAss(Employee e, Project b);

	// function to set project as incomplete 

	/*void markPrjAsIncomplete(Project b);*/

	// functions to get an employee and proects from the list.
	Employee getEmpFromList(int index);
	Project getProjFromList(int index);
	// function to check if a project is completed 
	bool isPrjCmp(string pID);

	// function that stores the projects assigned to a certain employee into a vecotr and prints them.
	void PrjssAssignedToEmp(string myeid);
	// function that stroes employees assigned to certain project into a vecotr and then prints them. 
	void EmpsAssignedToPrj(string mypid);


	// function that puts projects assigned into a vector 
	void putPrjsInList(Project myp);
	
	// function that puts the employees assgined into a vector 
	void putEmpsInList(Employee mye);
	
};
