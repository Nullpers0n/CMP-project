#pragma once

#ifndef CLASSES
#define CLASSES

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Classes.h"

using namespace std;

void printError(string& str)
{
	cout << "Error: ID or name you entered doesn't exist, enter again: ";
	cin >> str;
}

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

string Project::getID() {

	return ID;

}

string Project::getTitle() {

	return title;

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


EmployeeList::EmployeeList()
{
	ifstream mycin("Employeelist.txt");
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
		listofEmployees.push_back(e);
		getline(mycin, myid, ' ');
	}
	mycin.close();
}
int EmployeeList::IsItInList(Employee e)
{
	for (int i = 0; i < listofEmployees.size(); i++)
	{
		if (e.getID() == listofEmployees[i].getID() || (e.getName() == listofEmployees[i].getName()))
		{
			return i;
		}
	}
	return -1;
}



void EmployeeList::addEmployee(Employee e)
{
	int i;
	i = IsItInList(e);
	if (i == -1)
	{
		listofEmployees.push_back(e);
		cout << "Employee added.\n";
	}
	//should we check if the employee already exists?
	else
	{
		cout << "Employee with this ID or name already exists.\n";
	}
}

void EmployeeList::deleteEmployee(string myid)
{
	listofPrjEmpAssignment epa;
	ProjectEmployeeAssignment pe;
	Project p;
	Employee e;
	int index;
	int j;
	index = getIndexUsingID(myid);
	while (index == -1)
	{
		printError(myid);
		index = getIndexUsingID(myid);
	}
	// check if this employee is assinged to a project before deleting
	j = epa.isEmpInList(myid);
	if (j >= 0)
	{
		e = epa.getEmpFromList(j);
		p = epa.getProjFromList(j);
		// delete that assingment 
		epa.deleteEmpPrjAss(e, p);
	}
	// now delete the actual employee. 
	listofEmployees.erase(listofEmployees.begin() + index);

	//maybe delete the projects that he/she was working on too?

}

Employee EmployeeList::getEmployee(int index)
{

	if ((index < 0) || (index >= listofEmployees.size()))
	{
		cout << "Error, index is out of range. Returning the the first employee in the list instead. \n";
		return listofEmployees[0];
	}
	else return  listofEmployees[index];
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
		cout << "ID: " << listofEmployees[i].getID() << "  " << "Name: " << listofEmployees[i].getName() << endl;
	}
}

EmployeeList::~EmployeeList()
{
	ofstream mycout("Employeelist.txt");
	for (int i = 0; i < listofEmployees.size(); i++)
	{
		mycout << listofEmployees[i].getID() << " " << listofEmployees[i].getName() << endl;
	}
	mycout.flush();
	mycout.close();
}

int EmployeeList::getEmpListSize()
{
	return listofEmployees.size();
}

//-----------------------------------------


// functions definition of projectlist


int ProjectList::isItInList(Project p)
{
	for (int i = 0; i < listofProjects.size(); i++)
	{
		if ((p.getID() == listofProjects[i].getID()) || (p.getTitle() == listofProjects[i].getTitle()))
		{
			return i;
		}
	}
	return -1;
}

// ------add project function
void ProjectList::addProject(Project p)
{
	// if we assume that the Project's private components are empty, we need more statements 
	int i;
	// check if it exists
	i = isItInList(p);
	// if it doesn't exist add it. 
	if (i == -1)
	{
		listofProjects.push_back(p);
		cout << "Project added.\n";
	}
	// if it exists dont add it.
	else
	{
		cout << "Project with this ID or title already exists.\n";
	}

}

//------ GET index using ID function 
int ProjectList::getIndexUsingID(string myid)
{
	for (int i = 0; i < listofProjects.size(); i++)
	{
		if (myid == listofProjects[i].getID())
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
		if (mytitle == listofProjects[i].getTitle())
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
	ifstream mycin("Projectlist.txt");
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
		listofProjects.push_back(p); //good
		getline(mycin, myid, ' ');
	}
	mycin.close();
}

// -------delete project 

void ProjectList::deleteProject(string myid)
{

	listofPrjEmpAssignment epa;
	ProjectEmployeeAssignment pe;
	Project p;
	Employee e;
	int index;
	int j;
	index = getIndexUsingID(myid);
	while (index == -1)
	{
		printError(myid);
		index = getIndexUsingID(myid);
	}
	// check if this employee is assinged to a project before deleting
	j = epa.isEmpInList(myid);
	if (j >= 0)
	{
		e = epa.getEmpFromList(j);
		p = epa.getProjFromList(j);
		// delete that assingment 
		epa.deleteEmpPrjAss(e, p);
	}
	// now delete the actual project
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
	return listofProjects[index].getID();
}
void ProjectList::listProjects()
{
	for (int i = 0; i < listofProjects.size(); i++)
	{
		cout << "Project ID: " << listofProjects[i].getID() << " Project Tite:" << listofProjects[i].getTitle() << endl;
	}
}

ProjectList::~ProjectList() {

	ofstream mycout("Projectlist.txt");
	if (mycout.fail())
	{
		cout << "Error: Project list file opening failed... Exisitng\n";
		exit(7);
	}
	for (int i = 0; i < listofProjects.size(); i++)
	{
		mycout << listofProjects[i].getID() << " " << listofProjects[i].getTitle() << endl;
	}
	mycout.flush();
	mycout.close();
}

int ProjectList::getPrjListSize()
{
	return listofProjects.size();
}

//-----------------------------------------


ProjectEmployeeAssignment::ProjectEmployeeAssignment()
{
	pID = "0";
	eID = "0";
	status = 0;
}
ProjectEmployeeAssignment::ProjectEmployeeAssignment(string mypID, string myeID, int complete)
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
int ProjectEmployeeAssignment::getStatus()
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
void ProjectEmployeeAssignment::setStatus(int mys)
{
	status = mys;
}
bool ProjectEmployeeAssignment::isCompleted(int s)
{
	// i used find just in case cin took space aka " " from the file. 
	if (s == 1)
	{
		return true;
	}
	return false;
}
//--------------------------------------

bool listofPrjEmpAssignment::isPrjCmp(string pID)
{
	for (int i = 0; i < list.size(); i++)
	{
		// check for all the IDs and if one of the parts is zero, then project is incomplete. 
		if ((pID == list[i].getpID()) && (list[i].getStatus()) == 0)
		{
			return false;
		}
	}
	return true;
}

void listofPrjEmpAssignment::PrjssAssignedToEmp(string myeid)
{
	vector <Project> projects;
	ProjectList pl;
	Project p;
	Employee e;
	EmployeeList el;
	int j, index;
	// get the index of that employee and then use it to return an employee for me 
	index = el.getIndexUsingID(myeid);
	e = el.getEmployee(index);
	for (int i = 0; i < list.size(); i++)
	{
		// if eids are the same create this project and push it back to employee. 
		if (myeid == list[i].geteID())
		{
			// get the index 
			j = pl.getIndexUsingID(list[i].getpID());
			// return to me that project. 
			p = pl.getProject(j);
			projects.push_back(p);
		}
	}
	cout << "Employee ID: " << e.getID() << "  Employee Name: " << e.getName() << endl;
	cout << "Projects this Employee is working on: " << endl;;
	for (int i = 0; i < projects.size(); i++)
	{
		cout << "Project ID: " << projects[i].getID() << "  Project Title: " << projects[i].getTitle() << endl;
	}
}

void listofPrjEmpAssignment::EmpsAssignedToPrj(string mypid)
{
	vector <Employee> employees;
	ProjectList pl;
	Project p;
	Employee e;
	EmployeeList el;
	int j, index;
	// get the index of that project and then use it to return a porject for me 
	index = pl.getIndexUsingID(mypid);
	p = pl.getProject(index);
	for (int i = 0; i < list.size(); i++)
	{
		// if eids are the same create this employee and push it back to employee list. 
		if (mypid == list[i].getpID())
		{
			// get the index 
			j = el.getIndexUsingID(list[i].geteID());
			// return to me that employee . 
			e = el.getEmployee(j);
			employees.push_back(e);
		}
	}
	cout << "Project ID: " << p.getID() << "  Project Title: " << p.getTitle() << endl;
	cout << "Employees that are working on this project: " << endl;;
	for (int i = 0; i < employees.size(); i++)
	{
		cout << "Employee ID: " << employees[i].getID() << "  Employee Name: " << employees[i].getName() << endl;
	}
}

void listofPrjEmpAssignment::putPrjsInList()
{
	/*creating employeeslist and project list to use in the loop so we can get the names and ids*/
	ProjectList pl;
	EmployeeList el;
	Employee e;
	Project p;
	int index;
	bool temp;
	// do the first reading outside the loop 
	index = pl.getIndexUsingID(list[0].getpID());
	p = pl.getProject(index);
	plist.push_back(p);
	for (int i = 1; i < list.size(); i++)
	{

		index = pl.getIndexUsingID(list[i].getpID());
		p = pl.getProject(index);

		// nested loop to check if we alredy checked for that project. 
		for (int k = 0; k < plist.size(); k++)
		{

			if (list[i].getpID() == plist[k].getID())
			{
				temp = false;
				break;
			}
			else
			{
				temp = true;
			}
		}
		if (temp == true)
		{
			plist.push_back(p);
		}
	}
}

Employee listofPrjEmpAssignment::getEmpFromList(int index)
{
	EmployeeList el;
	Employee e;
	// if the index is greater than the size of the list or less than zero, cout this error. 
	while ((index >= list.size()) || (index < 0))
	{
		cout << "Error: index is out of range, enter again: ";
		cin >> index;
	}
	// using the ID from the list get the index 
	index = el.getIndexUsingID(list[index].geteID());
	// use that index in a function that returnes an employee 
	e = el.getEmployee(index);
	return e;
}

Project listofPrjEmpAssignment::getProjFromList(int index)
{
	Project p;
	ProjectList pl;
	// if the index is greater than the size of the list or less than zero, cout this error. 
	while ((index >= list.size()) || (index < 0))
	{
		cout << "Error: index is out of range, enter again: ";
		cin >> index;
	}
	// using the ID from the list get the index 
	index = pl.getIndexUsingID(list[index].getpID());
	// use that index in a function that returnes an employee 
	p = pl.getProject(index);
	return p;
}

//void listofPrjEmpAssignment::EmpsAssignedToPrj(string mypid)
//{
//	EmployeeList el;
//	Employee e;
//	Employee* ptr; 
//	int index;
//	for (int i = 0; i < list.size(); i++)
//	{
//		if (list[i].getpID() == mypid)
//		{
//			// give me the index in the employeelist vector of that emplpoyee ID 
//			index = el.getIndexUsingID(list[i].geteID());
//			// so i can use it here to get that employee.
//			e = el.getEmployee(index);
//			cout << "Employee ID: " << e.getID() << "  Employee Name: " << e.getName() << endl;
//		}
//	}
//}

void listofPrjEmpAssignment::listAllProjectsAssignments()
{
	Project p;
	ProjectList pl;
	int index;
	for (int i = 0; i < list.size(); i++)
	{
		index = pl.getIndexUsingID(list[i].getpID());
		p = pl.getProject(index);
		cout << "Project ID: " << p.getID() << " Project title: " << p.getTitle() << endl;
		cout << "Employees working on this project: \n";
		EmpsAssignedToPrj(list[i].getpID());
	}
}

int listofPrjEmpAssignment::isEmpPrjInList(string myeid, string mypid)
{
	for (int i = 0; i < list.size(); i++)
	{
		if ((myeid == list[i].geteID()) && (mypid == list[i].getpID()))
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
		if (myeid == list[i].geteID())
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
		if (mypid == list[i].getpID())
		{
			return i;
		}
	}
	return -1;
}

listofPrjEmpAssignment::listofPrjEmpAssignment()
{
	ifstream mycin("epa.txt");
	if (mycin.fail())
	{
		cout << "Error: opening employee project assingment file failed... Exiting...\n";
		exit(4);
	}
	ProjectEmployeeAssignment epa;
	// mys is for status (0 or 1)
	string mypid, myeid;
	int mys;
	getline(mycin, myeid, ' ');
	while (!mycin.eof())
	{
		epa.seteID(myeid);
		getline(mycin, mypid, ' ');
		epa.setpID(mypid);
		mycin >> mys;
		epa.setStatus(mys);
		list.push_back(epa);
		mycin.ignore(1000, '\n');
		getline(mycin, myeid, ' ');
	}
	mycin.close();
}

void listofPrjEmpAssignment::addEmpPrjAssignment(Employee e, Project b)
{
	ProjectEmployeeAssignment epa;
	int i;
	i = isEmpPrjInList(e.getID(), b.getID());
	if (i == -1)
	{
		epa.seteID(e.getID());
		epa.setpID(b.getID());
		epa.setStatus(0);
		list.push_back(epa);
		cout << "Assignment created.\n";
	}
	else
	{
		cout << "Assignment already exists.\n";
	}
	putEmpsInList();
	putPrjsInList();
}
void listofPrjEmpAssignment::setProjectStatus(Employee e, Project b, int mys)
{
	string ID;
	int index;  //we got a problem in here // SOLVED (I THINK)
	index = isEmpPrjInList(e.getID(), b.getID());
	while (index == -1)
	{
		cout << "Error: Assingment doesn't exist. Enter the ID again: \n";
		b.setID(ID);
		index = isEmpPrjInList(e.getID(), b.getID());
	}
	if (mys == 1)
	{
		if (list[index].getStatus() == 1)
		{
			cout << "Part is already set as completed.\n";
		}
		else
		{
			list[index].setStatus(1);
		}
	}
	if (mys == 0)
	{
		if (list[index].getStatus() == 0)
		{
			cout << "Part is already set as false.\n";
		}
		else
		{
			list[index].setStatus(0);
		}
	}
	putEmpsInList();
	putPrjsInList();
}

void listofPrjEmpAssignment::listAllCompleteProjects()
{
	bool temp = false;
	for (int i = 0; i < plist.size(); i++)
	{
		if (isPrjCmp(plist[i].getID()) == true)
		{
			cout << "Project ID: " << plist[i].getID() << "  Project Title:" << plist[i].getTitle() << endl;
			temp = true;
		}
	}
	if (temp == false)
	{
		cout << "No projct is completed. \n";
	}
}

void listofPrjEmpAssignment::listAllIncompleteProjects()
{
	for (int i = 0; i < plist.size(); i++)
	{
		if (isPrjCmp(plist[i].getID()) == false)
		{
			cout << "Project ID: " << plist[i].getID() << "  Project Title:" << plist[i].getTitle() << endl;
		}
	}
}


void listofPrjEmpAssignment::deleteEmpPrjAss(Employee e, Project b)
{
	int index;
	string myeid, mypid;
	// check if these exist
	index = isEmpPrjInList(e.getID(), b.getID());
	while (index == -1)
	{
		cout << "Error: the employee project assingment doesn't exist. Enter the ID's again: \n";
		cin >> myeid;
		// set the new values 
		e.setID(myeid);
		cin >> mypid;
		b.setID(mypid);
		// check for index again to see if we run the loop again.
		index = isEmpPrjInList(e.getID(), b.getID());
	}
	// delete this assingment 
	list.erase(list.begin() + index);
	putEmpsInList();
	putPrjsInList();
}

void listofPrjEmpAssignment::putEmpsInList()
{
	/*creating employeeslist and project list to use in the loop so we can get the names and ids*/
	ProjectList pl;
	EmployeeList el;
	Employee e;
	Project p;
	int index;
	bool temp;
	// do the first reading outside the loop 
	index = el.getIndexUsingID(list[0].geteID());
	e = el.getEmployee(index);
	elist.push_back(e);
	for (int i = 1; i < list.size(); i++)
	{

		index = el.getIndexUsingID(list[0].geteID());
		e = el.getEmployee(index);

		// nested loop to check if we alredy checked for that project. 
		for (int k = 0; k < elist.size(); k++)
		{

			if (list[i].geteID() == elist[k].getID())
			{
				temp = false;
				break;
			}
			else
			{
				temp = true;
			}
		}
		if (temp == true)
		{
			elist.push_back(e);
		}
	}
}

listofPrjEmpAssignment::~listofPrjEmpAssignment()
{
	ofstream mycout("epa.txt");
	if (mycout.fail())
	{
		cout << "Error: EPA file opening failed... exsiting.\n";
		exit(6);
	}
	for (int i = 0; i < list.size(); i++)
	{
		mycout << list[i].geteID() << " " << list[i].getpID() << " " << list[i].getStatus() << endl;
	}
	mycout.flush();
	mycout.close();

}

#endif