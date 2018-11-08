#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Employee;
class Project;
class EmployeeList;
class ProjectList;
class ProjectEmployeeAssignment;
class listofPrjEmpAssignment;
// non member function used in some of the classes to print error. 
void printError(string& str)
{
	cout << "Error: ID or name you entered doesn't exist, enter again: ";
	cin >> str;
}

//-----------------------------------------

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
Employee::Employee()
{
	name = "NULL";
	ID = "00";
}
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

string Employee::getID() {

	return ID;

}

string Employee::getName() {

	return name;

}

//-----------------------------------------------------------

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
Project::Project()
{
	ID = "0";
	title = "NULL";
}
Project::Project(string mytitle, string myid)
{
	title = mytitle;
	ID = myid;
}
void Project::setID(string myid)
{
	ID = myid;
}
void Project::setTitle(string mytitle)
{
	title = mytitle;
}

//-----------------------------------------------------------

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

void EmployeeList::deleteEmployee(string myid)
{
	int index;
	index = getIndexUsingID(myid);
	while (index == -1)
	{
		printError(myid);
		index = getIndexUsingID(myid);
	}
	listofEmployees.erase(listofEmployees.begin() + index);
}

Employee EmployeeList::getEmployee(int index)
{
	Employee e;
	e = listofEmployees[index];
	return  e;
}

int EmployeeList::getIndexUsingID(string myid)
{
	for (int i = 0; i < listofEmployees.size(); i++)
	{
		// if ids are the same return that index
		if (myid == listofEmployees[i].getID())
		{
			return i;
		}
	}
	return -1;
}
int EmployeeList::getIndexUsingName(string myname)
{
	for (int i = 0; i < listofEmployees.size(); i++)
	{
		// if ids are the same return that index
		if (myname == listofEmployees[i].getName())
		{
			return i;
		}
	}
	return -1;
}
void EmployeeList::listEmployees()
{
	for (int i = 0; i < listofEmployees.size(); i++)
	{
		cout << "ID: " << listofEmployees[i].getID << "  " << "Name: " << listofEmployees[i].getName << endl;
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


};

// functions definition of projectlist

int ProjectList::isItInList(Project p)
{
	for (int i = 0; listofProjects.size(); i++)
	{
		if ((p.getID() == listofProjects[i].getID) && (p.getTitle() == listofProjects[i].getTitle))
		{
			return i;
		}
	}
	return -1;
}

// ------add project function
void ProjectList::addProject(Project p)
{
	int i;
	// check if it exists
	i = isItInList(p);
	// if it doesn't exist add it. 
	if (i == -1)
	{
		listofProjects.push_back(p);
	}
	// if it exists dont add it.
	else
	{
		cout << "Project already exists.\n";
	}

}

//------ GET index using ID function 
int ProjectList::getIndexUsingID(string myid)
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

// --------- Get indtex using title functiong
int ProjectList::getIndexUsingTitle(string mytitle)
{
	for (int i = 0; i < listofProjects.size(); i++)
	{
		if (mytitle == listofProjects[i].getTitle)
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

void ProjectList::deleteProject(string myid)
{
	int index;
	index = getIndexUsingID(myid);
	while (index == -1)
	{
		printError(myid);
		index = getIndexUsingID(myid);
	}
	listofProjects.erase(listofProjects.begin() + index);
}

//--------get project function
Project ProjectList::getProject(int index)
{
	Project p;
	p = listofProjects[index];
	return p;
}

//-------------- get project title
string ProjectList::getProjectTitle(string ID)
{
	int index;
	index = getIndexUsingID(ID);
	while (index == -1)
	{
		printError(ID);
		index = getIndexUsingID(ID);
	}
	return listofProjects[index].getTitle();
}

//-------GET PROJECT ID

string ProjectList::getProjectID(string mytitle)
{
	int index = getIndexUsingTitle(mytitle);
	while (index == -1)
	{
		printError(mytitle);
		index = getIndexUsingTitle(mytitle);
	}
	return listofProjects[index].getID;
}
void ProjectList::listProjects()
{
	for (int i = 0; i < listofProjects.size();i++)
	{
		cout << "Project ID: " << listofProjects[i].getID << " Project Tite:" << listofProjects[i].getTitle << endl;
	}
}

//-----------------------------------------


class ProjectEmployeeAssignment {
private:
	string pID, eID;
	bool status;
	//…add more attributes as needed
public:
	ProjectEmployeeAssignment();
	ProjectEmployeeAssignment
	(string mypID, string myeID, bool complete = false);
	string getpID();
	string geteID();
	bool getStatus();
	void setpID(string mypid);
	void seteID(string myeid);
	void setStatus(bool mys);
	bool isCompleted(string s);
	//…add other functions as needed
};
ProjectEmployeeAssignment::ProjectEmployeeAssignment()
{
	pID = "0";
	eID = "0";
	status = false;
}
ProjectEmployeeAssignment::ProjectEmployeeAssignment(string mypID, string myeID, bool complete)
{
	pID = mypID;
	eID = myeID;
	status = complete;
}

string ProjectEmployeeAssignment::getpID()
{
	return pID;
}
string ProjectEmployeeAssignment::geteID()
{
	return eID;
}
bool ProjectEmployeeAssignment::getStatus()
{
	return status;
}
void ProjectEmployeeAssignment::setpID(string mypid)
{
	pID = mypid;
}
void ProjectEmployeeAssignment::seteID(string myeid)
{
	eID = myeid;
}
void ProjectEmployeeAssignment::setStatus(bool mys)
{
	status = mys;
}
bool ProjectEmployeeAssignment::isCompleted(string s)
{
	// i used find just in case cin took space aka " " from the file. 
	if (s.find("1") <= 0)
	{
		return true;
	}
	return false;
}
//--------------------------------------

class listofPrjEmpAssignment {
private:
	vector <ProjectEmployeeAssignment> list;
	string epfname = "epa.txt";
	//…add more attributes as needed
public:
	listofPrjEmpAssignment();//reads from the file
	void addEmpPrjAssignment(Employee e, Project b);
	bool markProjectAsCompleted(Employee e, Project b);
	int isEmpInList(string myeid);
	int isPrjInList(string mypid);
	int isEmpPrjInList(string myeid, string mypid);
	void listAllIncompleteProjects();
	void listAllCompleteProjects();
	void listAllProjectsAssignments();
	~listofPrjEmpAssignment();//writes back to the file
							  //…add other functions as needed

							  //function to list the Employees working on a certain project. 
	void EmployeesWorkingOnProject(string mypid);
};

void listofPrjEmpAssignment::EmployeesWorkingOnProject(string mypid)
{
	EmployeeList el;
	Employee e;
	int index;
	for (int i = 0; list.size(); i++)
	{
		if (list[i].getpID == mypid)
		{
			// give me the index in the employeelist vector of that emplpoyee ID 
			index = el.getIndexUsingID(list[i].geteID);
			// so i can use it here to get that employee.
			e = el.getEmployee(index);
			cout << "Emplyee ID: " << e.getID() << "  Employee Name: " << e.getName() << endl;
		}
	}
}



int listofPrjEmpAssignment::isEmpPrjInList(string myeid, string mypid)
{
	for (int i = 0; i < list.size(); i++)
	{
		if ((myeid == list[i].geteID) && (mypid == list[i].getpID))
		{
			return i;
		}
	}
	return -1;
}

int listofPrjEmpAssignment::isEmpInList(string myeid)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (myeid == list[i].geteID)
		{
			return i;
		}
	}
	return -1;
}
int listofPrjEmpAssignment::isPrjInList(string mypid)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (mypid == list[i].getpID)
		{
			return i;
		}
	}
	return -1;
}

listofPrjEmpAssignment::listofPrjEmpAssignment()
{
	ifstream mycin(epfname);
	if (mycin.fail())
	{
		cout << "Error: opening employee project assingment file failed... Exiting...\n";
		exit(4);
	}
	ProjectEmployeeAssignment epa;
	// mys is for status (0 or 1)
	string mypid, myeid, mys;
	getline(mycin, myeid, ' ');
	while (!mycin.eof())
	{
		getline(mycin, myeid, ' ');
		getline(mycin, mys);
		epa.seteID(myeid);
		epa.setpID(mypid);
		// if there is a one in there push it back as true.
		if (epa.isCompleted(mys) == true)
		{
			epa.setStatus(true);
		}
		else
		{
			epa.setStatus(false);
		}
		list.push_back(epa);
		getline(mycin, myeid, ' ');
	}
	mycin.close();
}

void listofPrjEmpAssignment::addEmpPrjAssignment(Employee e, Project b)
{
	ProjectEmployeeAssignment epa;
	epa.seteID(e.getID);
	epa.setpID(b.getID);
	epa.setStatus(false);
	list.push_back(epa);
}
bool listofPrjEmpAssignment::markProjectAsCompleted(Employee e, Project b)
{
	int index;
	if (index == -1)
	{
		// return fasle if the project and employee assingment do not exist
		return false;
	}
	index = isEmpPrjInList(e.getID, b.getID);
	list[index].setStatus(true);
	return true;
}


void listofPrjEmpAssignment::listAllCompleteProjects()
{
}

void listofPrjEmpAssignment::listAllIncompleteProjects()
{
	// creating employeeslist and project list to use in the loop so we can get the names and ids
	ProjectList pl;
	EmployeeList el;
	Employee e;
	Project p;
	int index;
	for (int i = 0; i < list.size(); i++)
	{
		// these functions we created return emoployee and project at a given index 
		if (list[i].getStatus == false)
		{
			// get the index of the "completed" project from the projectlist vector
			// and use it to return that project
			index = pl.getIndexUsingID(list[i].getpID);
			p = pl.getProject(index);
			cout << "Project ID: " << p.getID << "  Project Title: " << p.getTitle << endl;
			cout << "Employees working on that project:- \n";
			// use this functino to print them 
			EmployeesWorkingOnProject(list[i].getpID);
		}
	}
}

void main() {

	char x;
	string emptextfile, projecttextfile, assigntextfile;

	cout << "Enter the three files that will be used in the program : ";
	cin >> emptextfile >> projecttextfile >> assigntextfile;

	Employee emp;
	Project prj;
	EmployeeList elist;
	ProjectList plist;
	ProjectEmployeeAssignment peassign;
	listofPrjEmpAssignment peassignlist;

	cout << "Enter the letter corresponding to the command to initiate it : " << endl;

	while (cin >> x) {

		cout << "a) Add a new employee to the list of employees" << endl;
		cout << "b) Add a new project to the list of projects" << endl;
		cout << "c) List all employees and the projects they are assigned to (if any)" << endl;
		cout << "d) List all projects (project name & ID)" << endl;
		cout << "e) List all completed projects (Employee’s name & ID, project’s name & ID)" << endl;
		cout << "f) List all incomplete projects (Employee’s name & ID, project’s name & ID)" << endl;
		cout << "g) Search for a given employee or project by ID or name" << endl;
		cout << "h) Assign an employee to a project (if not assigned already)" << endl;
		cout << "i) Set a project as complete or incomplete for a given employee" << endl;
		cout << "Press any letter other than the mentioned ones to exit the program" << endl;

		if (x == 'a') {
			string name, ID;
			cout << "Enter name and ID of new Employee" << endl;
			cin >> name >> ID;
			emp.setName(name);
			emp.setID(ID);
			elist.addEmployee(emp);

		}
		else if (x == 'b') {

			string title, ID;
			cout << "Enter title and ID of new Project" << endl;
			cin >> title >> ID;
			prj.setTitle(title);
			prj.setID(ID);

		}
		else if (x == 'c') {

			peassignlist.listAllProjectsAssignments();

		}
		else if (x == 'd') {

			plist.listProjects();

		}
		else if (x == 'e') {

			peassignlist.listAllCompleteProjects();

		}
		else if (x == 'f') {

			peassignlist.listAllIncompleteProjects();

		}
		else if (x == 'g') {

			//in need for a function that searches for a given employee or project by id or name

		}
		else if (x == 'h') {

			//needs a function that checks if the employee is assigned to a particular project or not
			//in addition, it needs to check if employee and project exist

		}
		else if (x == 'i') {

			//still incomplete, needs project locator so that status can be changed
			int stat = -1;
			cout << "Enter 0 or 1 for the project status : ";
			while (!(stat == 0 || stat == 1)) cin >> stat;
			peassign.setStatus(stat);
			// it should be better using this function: peassignlist.markProjectAsCompleted();

		}
		else {
			cout << "Exiting the program" << endl;
			exit(1);
		}

	}

}
 
