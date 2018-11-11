
#include "listofPrjEmpAssignment.h"

using namespace std;

//--------------------------------------
void listofPrjEmpAssignment::putPrjsInList(Project myp)
{
	/*creating employeeslist and project list to use in the loop so we can get the names and ids*/
	ProjectList pl;
	Employee e;
	Project p;
	if ((myp.getID() != "0") && (myp.getTitle() != "NULL"))
	{
		pl.addProject(myp);
	}
	int index;
	bool temp = false;
	// do the first reading outside the loop 
	index = pl.getIndexUsingID(list[0].getpID());
	p = pl.getProject(index);
	if (plist.size() == 0)
	{
		plist.push_back(p);
	}

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

void listofPrjEmpAssignment::putEmpsInList(Employee mye)
{
	/*creating employeeslist and project list to use in the loop so we can get the names and ids*/
	ProjectList pl;
	EmployeeList el;
	Employee e;
	Project p;
	if ((mye.getID() != "00") && (mye.getName() != "NULL"))
	{
		el.addEmployee(mye);
	}
	int index;
	bool temp = false;
	// do the first reading outside the loop 
	index = el.getIndexUsingID(list[0].geteID());
	e = el.getEmployee(index);
	if (elist.size() == 0)
	{
		elist.push_back(e);
	}
	
	for (int i = 1; i < list.size(); i++)
	{

		index = el.getIndexUsingID(list[i].geteID());
		e = el.getEmployee(index);

		// nested loop to check if we alredy checked for that project. 
		for (int k = 0; k < elist.size();k++)
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
	for (int i = 0; i < list.size();i++)
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
	for (int i = 0; i < list.size();i++)
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
			cout << "Part set as completed. \n";
		}
	}
	if (mys == 0)
	{
		if (list[index].getStatus() == 0)
		{
			cout << "Part is already set as incomplete.\n";
		}
		else
		{
			list[index].setStatus(0);
			cout << "Part set as incomplete.\n";
		}
	}
}

void listofPrjEmpAssignment::listAllCompleteProjects()
{
	bool temp = false;
	for (int i = 0; i < plist.size();i++)
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
	for (int i = 0; i < plist.size();i++)
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

}
listofPrjEmpAssignment::~listofPrjEmpAssignment()
{
	ofstream mycout("epa.txt");
	if (mycout.fail())
	{
		cout << "Error: EPA file opening failed... exsiting.\n";
		exit(6);
	}
	for (int i = 0; i < list.size();i++)
	{
		mycout << list[i].geteID() << " " << list[i].getpID() << " " << list[i].getStatus() << endl;
	}

	mycout.flush();
	mycout.close();
}
