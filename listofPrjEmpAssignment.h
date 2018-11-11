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
	// purpose: constrcutor, reads from the employee project assignemnt folder and stores them into a vector
	// input: nothing
	// output: nothong 
	listofPrjEmpAssignment();//reads from the file
	// purpose: to assign an employee to a project and adds them to the emp prj assignment list vector. 
	// input: objects project and employee.
	// output: nothing 
	void addEmpPrjAssignment(Employee e, Project b);
	// purpose: set the status of an employees part in a project (complete or incomplete)
	// input: objects prject and employee and integer status (0 or 1) 
	// output: nothing 
	void setProjectStatus(Employee e, Project b, int mys);
	// purpose: to check if an employee is in the emp prj assignment 
	// input: employee ID
	// output: int, the index of the first instance it in the vector. 
	int isEmpInList(string myeid);
	// purpose: to check if a project is in the emp prj assignment 
	// input: project ID
	// output: int, the index of the first instance it in the vector.
	int isPrjInList(string mypid);
	int isEmpPrjInList(string myeid, string mypid);
	// purpose: to print all the projects that are not completed. 
	// inpit: nothing
	// output: nothong 
	void listAllIncompleteProjects();
	// purpose: to print all the projects that are completed. 
	// inpit: nothing
	// output: nothong 
	void listAllCompleteProjects();
	// purpose: to print all the projects and their assignments
	// input : none
	// output : none
	void listAllProjectsAssignments();
	// purpose: destrcutor, outputs the list of emp prj assignment into the file.
	// input: nothing
	// output: nothing 
	~listofPrjEmpAssignment();//writes back to the file
							  //…add other functions as needed

							  //function to list the Employees working on a certain project. 

							  // function to delete a certin employee and project assingment. 
							  // EmployeesWorkingOnProject(string mypid);
	// purpose: to delete an assignment of prj and emp from the vector (NOT USED)
	// inpts: objects employee and project
	// output: nothing 
	void deleteEmpPrjAss(Employee e, Project b);

	// function to set project as incomplete 

	/*void markPrjAsIncomplete(Project b);*/

	// functions to get an employee and proects from the list.
	// purpose: to get an employee from the project employee assingment vector. 
	// input: index of that employee in the vector.
	// output: returnes an employee object. 
	Employee getEmpFromList(int index);
	// purpose: to get an project from the project employee assingment vector. 
	// input: index of that project in the vector.
	// output: returnes a project object. 
	Project getProjFromList(int index);
	// function to check if a project is completed 
	//purpose: checks if a project is complete it by looping through all the employee's parts , if parts are complete
	// then the project is complete and returnes true else it returnse false
	// input: string project ID
	// output: bool values true or false. 
	bool isPrjCmp(string pID);

	// function that stores the projects assigned to a certain employee into a vecotr and prints them.
	// purpose: prints the prjects assigned to a certain empployee
	// input : string emoployee ID.
	// output: nothing
	void PrjssAssignedToEmp(string myeid);
	// function that stroes employees assigned to certain project into a vecotr and then prints them. 
	// purpose: prints the employees assgined to a certain project
	// inputs: string project ID
	// output: nothing 
	void EmpsAssignedToPrj(string mypid);


	// function that puts projects assigned into a vector 
	// purpose:  this functionn puts the projects assgined to employees into a vector of project.
	// inputL project object
	// ouput: nothing. 
	void putPrjsInList(Project myp);
	
	// function that puts the employees assgined into a vector 
	// Prps: put the employees assgined to a project into a vector of employees. 
	// input: employee object
	// output: nothing
	void putEmpsInList(Employee mye);
	
};
