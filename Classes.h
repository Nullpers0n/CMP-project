#pragma once


#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class EmployeeList;
class ProjectList;
class Employee;
class Project;
class ProjectEmployeeAssignment;
class listofPrjEmpAssignment;

class Employee {
private:
	string ID, name;
	//…add more attributes as needed
public:
	Employee();
	Employee(string myname, string myid);
	string getID();
	string getName();
	void setID(string myid);
	void setName(string myname);

	//…add other functions as 

};

class Project {
private:
	string ID, title;
	//…add more attributes as needed
public:
	Project();
	Project(string mytitle, string myid);
	string getID();
	string getTitle();
	void setID(string myid);
	void setTitle(string mytitle);
	//…add other functions as needed
};

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


class EmployeeList
{
private:
	vector<Employee> listofEmployees;
	string empFileName;
	//…add more attributes as needed 
public:
	EmployeeList(); //reads from the file
	void addEmployee(Employee e);
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
};

class ProjectList {
private:
	vector<Project> listofProjects;
	string prjFileName;
	//…add more attributes as needed
public:
	ProjectList(); //reads from the file
	void addProject(Project p);
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
};


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
	void putPrjsInList();


	// function that puts the employees assgined into a vector 
	void putEmpsInList();


};

