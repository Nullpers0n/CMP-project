#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Employee.h"
#include "listofPrjEmpAssignment.h"
#include "Project.h"
#include "ProjectList.h"
using namespace std;

class EmployeeList
{
private:
	vector<Employee> listofEmployees;
	string empFileName;
	//…add more attributes as needed 
public:
	EmployeeList(); //reads from the file
	bool addEmployee(Employee e);
	void deleteEmployee(string myid);
	Employee getEmployee(int index);
	int getIndexUsingID(string myid);
	int getIndexUsingName(string myname);
	void listEmployees();
	~EmployeeList(); //writes back to the same input file
					 //…add other functions as needed

					 // function to check if employee is in list before adding. 
	int IsItInList(Employee e);
	// function that returnes the size of the employee list
	int getEmpListSize();

	void printError(string& str);
};
