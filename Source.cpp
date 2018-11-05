#include <iostream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Employee {
private:
	// I changed it to eID (employee ID) and the project ID to pID so we don't get 
	// confused when we use them
	string eID, name;
	//…add more attributes as needed
public:
	Employee();  //constructor that does something
	Employee(string myname, string myid);   //sets myname and myid to "null" maybe or sets the name and id for a certain employee
	string getID();  //prints/returns out the id number (not an int after all)
	string getName(); //prints/returns out the name of the employee
					  //…add other functions as needed, maybe setters or destructors are needed
};


// ---------- class Emplyee functions ----------

// default constrcutor 
Employee::Employee()
{
	name = "null";
	eID = "0";
}

// constrcutor 
Employee::Employee(string myname, string myid)
{
	name = myname;
	eID = myid;
}

// employee get functions
string Employee::getID()
{
	return eID;
}

string Employee::getName()
{
	return name;
}

// ------------ class porject -------------
class Project {
private:
	string pID, title;
	//…add more attributes as needed
public:
	Project();  //constructor that does something
	Project(string mytitle, string myid);  //constructor that sets both strings to "null" or something else
	string getID(); //prints/returns out the id
	string getTitle(); //prints/returns out the title
					   //…add other functions as needed,  maybe setters or destructors are needed
};


////----------------------class project functions----------
Project::Project()
{
	title = "null";
	pID = "0";
}

Project::Project(string mytitle, string myid)
{
	title = mytitle;
	pID = myid;
}

string Project::getID()
{
	return pID;
}

string Project::getTitle()
{
	return title;
}
class ProjectEmployeeAssignment {
private:
	string pID, eID;  //project id and employee id
	bool completed;  //project completed or incompleted
					 //…add more attributes as needed
public:
	ProjectEmployeeAssignment();  //constructor that does something
	ProjectEmployeeAssignment(string mypID, string myeID, bool complete = false); //constructor that does something
	string getpID();  //prints/returns out the project id
	string geteID();  //prints/returns out the employee id
	bool isCompleted();  //prints/returns out the completion
	void setCompleted(bool flag) { completed = flag; };  //looks like it is already implemented, suspicious
														 //…add other functions as needed
};

class EmployeeList {
private:
	vector<Employee> listofEmployees;  //this will be used to return to the employee txt file
	string empFileName;  //there it is, it stores the txt file name
						 //…add more attributes as needed 
public:
	EmployeeList(); //reads from the file, oh god no, keep calm
	void addEmployee(Employee e);  //adds an employee to the vector above 
	bool deleteEmployee(string ID);  //deletes an employee from the vector above
	Employee getEmployee(string ID);  //returns the employee from the vector above 
	int findEmployeeIndexInVector(string ID);  //returns the id of the employee from the vector above
	void listEmployees();  //doesn't return anything but lists the employees
	~EmployeeList(); //writes back to the same input file, wait what??? (oh, a destructor)
					 //…add other functions as needed
};

////-----------------------------------------

class ProjectList {
private:
	vector<Project> listofProjects;  //stores a list of projects to be returned to project txt file
	string prjFileName;  //oh god here is the filename 
						 //…add more attributes as needed
public:
	ProjectList(); //a constructor that reads from the file
	void addProject(Project p); //adds a project to the vector
	bool deleteProject(string x); //deletes a project from the vector
	Project getProject(string x);  //returns a project from the vecotr
	string getProjectTitle(string ID); //returns the project title
	string getProjectID(string title); //returns the project id
	int findProjectIndexInVector(string ID);  //returns project id
	void listProjects();   //prints out (does not return) the list of projects
	~ProjectList(); //writes back to the same input file
					//…add other functions as needed
};

class listofPrjEmpAssignment {
private:
	vector <ProjectEmployeeAssignment> list;  //stores the list of projects that are assigned to the employees
	string prj_empFileName;  //opens the assignment txt file
							 //…add more attributes as needed
public:
	listofPrjEmpAssignment();  //constructor that reads from the file and maybe stores into the vector
	void addEmpPrjAssignment(Project b, Employee e);  //takes the corresponding project and employee and adds them to the vector?
	bool markProjectAsCompleted(Project b, Employee e);  //same as function above, but returns something
	bool isEmpInList(string ID);  //searches for employee id in vector and returns 0 if not found
	bool isPrjInList(string ID);  //searches for project id
	bool isEmpPrjInList(string eID, string pID);  //searches for both
	void listAllIncompleteProjects();   //lists all incomplete projects
	void listAllCompleteProjects();   //lists all complete projects 
	void listAllProjectsAssignments();  //lists everything
	~listofPrjEmpAssignment();   //destructor that writes back to the file
								 //…add other functions as needed
};



int main() 
{
	// to take the option of the menue 
	char option;
	return 0;
}
