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
	// Purpose: contructor that reads from a file.
	// input: nothing
	// output: nothing 
	EmployeeList(); //reads from the file
	// Purpose: the function takes an object employee in its arguments, it assignes an integer 
	// to the function IsItInList to check if it already exists before adding it, if the 
	// integer is -1 meaning it doesn't exists, it will add it and return true, if it exists it will return 
	// false and not add it. 
	// Input: employee object
	// output: bool true or false. 
	bool addEmployee(Employee e);
	//Purpose:  the function deleteEmployee, removes an employee and removes any employee and its project assginemtns
	//	if they exist (the function is not implemented anywhere)
	//input: string, ID of employee 
	//output: nothing 
	void deleteEmployee(string myid);
	//Purpose: to get an employee from the employee list vector in its index 
	//input: it takes an argument of int which is the index of an employee in the emplployee list vector 
	//output: returnes an  employee object 
	Employee getEmployee(int index);
	/*Purpose: searches in the employee list vector uisng the employee ID and gives us its index in the vector
	input: string employee ID 
	output: integer, the index of the employee in the vector list.*/ 
	int getIndexUsingID(string myid);
	/*Purpose: searches in the employee list vector uisng the employee name and gives us its index in the vector
	input: string employee name
	output: integer, the index of the employee in the vector list.*/
	int getIndexUsingName(string myname);
	// Purpose: outputting the employees that are inside the vector
	// input : none
	// output: none
	void listEmployees();
	//purpose: destrctuor that outputs the list of employees into the employee list file. 
	//input: nothing
	//output: nothing 
	~EmployeeList(); 

	// Purpose:the IsItInList function takes employee object and, using a for loop, it checks if the 
	//emeployee is already in the employee list vector and returnes the index of it if it finds it
	//other wise it will return -1
	// input: takes employee object. 
	// output:  returnes an int, the index of that employee if it exists, and -1 if it doesn't .
	int IsItInList(Employee e);
	// function that returnes the size of the employee list
	// Purpose: get the employee list vector size
	// Input: nothing
	// output: size of the vector of employee list 
	int getEmpListSize();
	//purpose: used in a function if the string id or name did not match or was inputted incorectly
	//input : string str by reference so that the string outside is changed too
	// output : none
	void printError(string& str);
};
