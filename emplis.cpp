
#include "EmployeeList.h"

using namespace std;
// non member function used in some of the classes to print error. 
void EmployeeList::printError(string& str)
{
	cout << "Error: ID or name you entered doesn't exist, enter again: ";
	cin >> str;
}

// Purpose: get the employee list vector size
// Input: nothing
// output: size of the vector of employee list 
int EmployeeList::getEmpListSize()
{
	return listofEmployees.size();
}
// Purpose: contructor that reads from a file.
// input: nothing
// output: nothing 
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

 // Purpose:the IsItInList function takes employee object and, using a for loop, it checks if the 

 //emeployee is already in the employee list vector and returnes the index of it if it finds it
 //other wise it will return -1

 // input: takes employee object. 

 // output:  returnes an int, the index of that employee if it exists, and -1 if it doesn't .

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



// Purpose: the function takes an object employee in its arguments, it assignes an integer 
// to the function IsItInList to check if it already exists before adding it, if the 
// integer is -1 meaning it doesn't exists, it will add it and return true, if it exists it will return 
// false and not add it. 

// Input: employee object

// output: bool true or false. 
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



//Purpose:  the function deleteEmployee, removes an employee and removes any employee and its project assginemtns
//	if they exist (the function is not implemented anywhere)
//input: string, ID of employee 
//output: nothing 
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

//Purpose: to get an employee from the employee list vector in its index 
//input: it takes an argument of int which is the index of an employee in the emplployee list vector 
//output: returnes an  employee object 
Employee EmployeeList::getEmployee(int index)
{

	if ((index < 0) || (index >= listofEmployees.size()))
	{
		cout << "Error, index is out of range. Returning the the first employee in the list instead. \n";
		return listofEmployees[0];
	}
	else return  listofEmployees[index];
}

/*Purpose: searches in the employee list vector uisng the employee ID and gives us its index in the vector
input: string employee ID 
output: integer, the index of the employee in the vector list.*/ 
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
/*Purpose: searches in the employee list vector uisng the employee name and gives us its index in the vector
input: string employee name
output: integer, the index of the employee in the vector list.*/
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

// purpse: print the employees (their IDs and names) in the employee list vector. 
// input: nothing
// output nothing
void EmployeeList::listEmployees()
{
	for (int i = 0; i < listofEmployees.size(); i++)
	{
		cout << "ID: " << listofEmployees[i].getID() << "  " << "Name: " << listofEmployees[i].getName() << endl;
	}
}

//purpose: destrctuor that outputs the list of employees into the employee list file. 
//	input: nothing
//	output: nothing 
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
