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
//-------- constrcutor 

Employee::Employee(string myname, string myid)
{
	ID = myid;
	name = myname;
}

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
	void setID(string myid);
	void setTitle(string mytitle);
	//…add other functions as needed
};

void Project::setID(string myid)
{
	ID = myid;
}
void Project::setTitle(string mytitle)
{
	title = mytitle;
}
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
		e.setName(myname);
		addEmployee(e);
		getline(mycin, myid, ' ');
	}
	mycin.close();
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
			listofEmployees.erase(listofEmployees.begin() + i);
			return true;
		}
	}
	cout << "Error: employee not found. \n";
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
		cout << "Employee not found... Press Y if you want to add a new employee or any key to exit.\n";
		cin >> option;
		if ((option == 'Y') || (option == 'y'))
		{
			cout << "Enter the ID of employee: ";
			cin >> myid;
			cin.ignore(1000, '\n');
			e.setID(myid);
			cout << "Enter the name of the employee: ";
			getline(cin, myname);
			e.setName(myname);
			addEmployee(e);
			cout << "New employee with the ID: " << e.getID() << " and Name: " << e.getName() << " have been added to the list.\n";
		}
		else exit(2);
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
	bool deleteProject(string myid);
	Project getProject(string ID);
	string getProjectTitle(string ID);
	string getProjectID(string title);
	int findProjectIndexInVector(string myid);
	void listProjects();
	~ProjectList(); //writes back to the same input file
					//…add other functions as needed
};

// functions definition of projectlist

// ------add project function
void ProjectList::addProject(Project p)
{
	listofProjects.push_back(p);
}

//------ index function 
int ProjectList::findProjectIndexInVector(string myid)
{
	for (int i = 0; i < listofProjects.size(); i++)
	{
		if (myid == listofProjects[i].getID)
		{
			return i; 
		}
	}
	return -1; 
}
//=-------- constrcutor 

ProjectList::ProjectList()
{
	// used to push back to the project vector 
	Project p; 
	string myid, mytitle;
	ifstream mycin("projectlist.txt");
	if (mycin.fail())
	{
		cout << "Error: project list file opening failed... Exiting.\n";
		exit(3);
	}
	getline(mycin, myid, ' ');
	while (!mycin.eof())
	{
		p.setID(myid);
		getline(mycin, mytitle);
		p.setTitle(mytitle);
		addProject(p);
		getline(mycin, myid, ' ');
	}
	mycin.close();
}

// -------delete project 

bool ProjectList::deleteProject(string myid)
{
	for (int i = 0; i < listofProjects.size(); i++)
	{
		if (myid == listofProjects[i].getID)
		{
			listofProjects.erase(listofProjects.begin() + i);
			return true;
		}
	}
	return false;
}

//--------get project function
Project ProjectList::getProject(string ID)
{
	Project p;
	char option;
	string mytitle, myid;
	int index;
	index = findProjectIndexInVector(ID);
	if (index == -1)
	{
		cout << "Project not found... Press Y if you want to add a new project or any key to exit.\n";
		cin >> option;
		if ((option == 'Y') || (option == 'y'))
		{
			cout << "Enter the ID of project: ";
			cin >> myid;
			cin.ignore(1000, '\n');
			p.setID(myid);
			cout << "Enter the title of the project: ";
			getline(cin, mytitle);
			p.setTitle(mytitle);
			addProject(p);
			cout << "New project with the ID: " << p.getID() << " and Title: " << p.getTitle() << " have been added to the list.\n";
		}
		else
		{
			exit(4);
		}
	}
	else
	{
		p = listofProjects[index];
	}
	return p;
}

//-------------- get project title
string ProjectList::getProjectTitle(string ID)
{
	for (int i = 0; i < listofProjects.size(); i++)
	{
		if (ID == listofProjects[i].getID())
		{
			return listofProjects[i].getTitle();
		}
	}
}


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

