
#include "EmployeeList.h"

using namespace std;
// non member function used in some of the classes to print error. 
void EmployeeList::printError(string& str)
{
	cout << "Error: ID or name you entered doesn't exist, enter again: ";
	cin >> str;
}

int EmployeeList::getEmpListSize()
{
	return listofEmployees.size();
}

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



bool EmployeeList::addEmployee(Employee e)
{
	int i;
	i = IsItInList(e);
	if (i == -1)
	{
		listofEmployees.push_back(e);
		return true; 
	}
	//should we check if the employee already exists?
	else
	{
		return false;
	}
}

void EmployeeList::deleteEmployee(string myid)
{
	listofPrjEmpAssignment epa;
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
