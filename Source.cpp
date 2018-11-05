#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

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

	//…add other functions as needed
};
void Employee::setID(string myid)
{
	ID = myid;
}
void Employee::setName(string myname)
{
	name = myname;
}
class Project {
private:
	string ID, title;
	//…add more attributes as needed
public:
	Project();
	Project(string mytitle, string myid);
	string getID();
	string getTitle();
	//…add other functions as needed
};
//-----------------------------------------
class ProjectEmployeeAssignment {
private:
	string pID, eID;
	bool completed;
	//…add more attributes as needed
public:
	ProjectEmployeeAssignment();
	ProjectEmployeeAssignment
	(string mypID, string myeID, bool complete = false);
	string getpID();
	string geteID();
	bool isCompleted();
	void setCompleted(bool flag) { completed = flag; };
	//…add other functions as needed
};
//-----------------------------------------

class EmployeeList {
private:
	vector<Employee> listofEmployees;
	string empFileName;
	//…add more attributes as needed 
public:
	EmployeeList(); //reads from the file
	void addEmployee(Employee e);
	bool deleteEmployee(string ID);
	Employee getEmployee(string ID);
	int findEmployeeIndexInVector(string ID);
	void listEmployees();
	~EmployeeList(); //writes back to the same input file
					 //…add other functions as needed
};
EmployeeList::EmployeeList()
{
	ifstream mycin("employeelist.txt");
	if (mycin.fail())
	{
		cout << "Error: Employee list file opening failed... Exiting\n";
		exit(1);
	}
	string myid, myname;
	Employee e;
	// the space char in getline is to prevent the second getline (the one for name)
	// to cin the space as well 
	getline(mycin, myid, ' ');
	while (!mycin.eof())
	{
		// pushing back employees
		e.setID(myid);
		getline(mycin, myname);
		listofEmployees.push_back(e);
		getline(mycin, myid, ' ');
	}
}


void EmployeeList::addEmployee(Employee e)
{
	listofEmployees.push_back(e);
}

bool EmployeeList::deleteEmployee(string ID)
{
	for (int i = 0; i < listofEmployees.size(); i++)
	{
		// if ids are the same return true else false
		if (ID = listofEmployees[i].getID)
		{
			return true;
		}
	}
	return false;
}

Employee EmployeeList::getEmployee(string ID)
{
	Employee e;
	char option;
	string myid, myname;
	int index = findEmployeeIndexInVector(ID);
	if (index = -1)
	{
		// ask the user if he wants to add a new employee or exit 
		cout << "Employee not found... Press Y if you want to add a new employee or X to exit.\n";
		cin >> option;
		if ((option == 'Y') || (option == 'y'))
		{
			cout << "Enter the ID of employee: ";
			cin >> myid;
			e.setID(myid);
			cout << "Enter the name of the employee: ";
			cin >> myname;
			e.setName(myname);
			listofEmployees.push_back(e);
			cout << "New employee with the ID: " << e.getID() << " and Name: " << e.getName() << " have been added to the list.\n";
		}
		else exit(3);
	}
	else
	{
		e = listofEmployees[index];
	}
	return  e;
}

int EmployeeList::findEmployeeIndexInVector(string ID)
{
	for (int i = 0; i < listofEmployees.size(); i++)
	{
		// if ids are the same return that index
		if (ID = listofEmployees[i].getID)
		{
			return i;
		}
	}
	return -1;
}

void EmployeeList::listEmployees()
{
	cout << "ID" << " " << "Name\n";
	for (int i = 0; i < listofEmployees.size(); i++)
	{
		cout << listofEmployees[i].getID << " " << listofEmployees[i].getName << endl;
	}
}

EmployeeList::~EmployeeList()
{
	// please do the destrcutor i dont know how to do it
}


//-----------------------------------------


class ProjectList {
private:
	vector<Project> listofProjects;
	string prjFileName;
	//…add more attributes as needed
public:
	ProjectList(); //reads from the file
	void addProject(Project p);
	bool deleteProject(string x);
	Project getProject(string x);
	string getProjectTitle(string ID);
	string getProjectID(string title);
	int findProjectIndexInVector(string ID);
	void listProjects();
	~ProjectList(); //writes back to the same input file
					//…add other functions as needed
};





class listofPrjEmpAssignment {
private:
	vector <ProjectEmployeeAssignment> list;
	string prj_empFileName;
	//…add more attributes as needed
public:
	listofPrjEmpAssignment();//reads from the file
	void addEmpPrjAssignment(Project b, Employee e);
	bool markProjectAsCompleted(Project b, Employee e);
	bool isEmpInList(string ID);
	bool isPrjInList(string ID);
	bool isEmpPrjInList(string eID, string pID);
	void listAllIncompleteProjects();
	void listAllCompleteProjects();
	void listAllProjectsAssignments();
	~listofPrjEmpAssignment();//writes back to the file
							  //…add other functions as needed
};
