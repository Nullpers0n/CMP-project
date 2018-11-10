#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Employee.h"
#include "EmployeeList.h"
#include "listofPrjEmpAssignment.h"
#include "Project.h"
#include "ProjectEmployeeAssignment.h"
#include "ProjectList.h"

using namespace std;


//-----------------------------------------













// -----------------------------------------------------
//-------- constrcutor 

//-----------------------------------------------------------


//-----------------------------------------------------------




//-----------------------------------------


// functions definition of projectlist



//-----------------------------------------




void main() {

	char x;
	Employee emp;
	Project prj;
	EmployeeList elist;
	ProjectList plist;
	ProjectEmployeeAssignment peassign;
	listofPrjEmpAssignment peassignlist;
	string eID, pID, name, title;
	int index, mys, no;
	bool temp; 
	/*elist.listEmployees();
	plist.listProjects();
	peassignlist.listAllProjectsAssignments();*/
	peassignlist.putEmpsInList(emp);
	peassignlist.putPrjsInList(prj);
	while (true) {
		no = elist.getEmpListSize();
		cout << "--------------------------\n\n\n";
		cout << "a) Add a new employee to the list of employees" << endl;
		cout << "b) Add a new project to the list of projects" << endl;
		cout << "c) List all employees and the projects they are assigned to (if any)" << endl;
		cout << "d) List all projects (project name & ID)" << endl;
		cout << "e) List all completed projects (Employee’s name & ID, project’s name & ID)" << endl;
		cout << "f) List all incomplete projects (Employee’s name & ID, project’s name & ID)" << endl;
		cout << "g) Search for a given employee by ID" << endl;
		cout << "h) Search for a given employee by name" << endl;
		cout << "i) Search for a given project by ID " << endl;
		cout << "j) Search for a given project by title" << endl;
		cout << "k) Assign an employee to a project (if not assigned already)" << endl;
		cout << "L) Set a project as complete or incomplete for a given employee" << endl;
		cout << "Press any letter other than the mentioned ones to exit the program" << endl;
		cout << "\n\n";
		cout << "Enter the letter of the choice to choose it: ";
		cin >> x;
		cout << endl;
		if (x == 'a') {
			cout << "Enter ID and name  of new Employee" << endl;
			cin >> eID;
			cin.ignore(1000, '\n');
			getline(cin, name);
			emp.setName(name);
			emp.setID(eID);
			temp = elist.addEmployee(emp);
			if (temp == true)
			{
				cout << "Employee added.\n";
			}
			else cout << "Employee with this ID or name already exists.\n"; 
		}
		else if (x == 'b') {
			cout << "Enter ID and title of new Project" << endl;
			cin >> pID;
			cin.ignore(1000, '\n');
			getline(cin, title);
			prj.setTitle(title);
			prj.setID(pID);
			temp = plist.addProject(prj);
			if (temp == true)
			{
				cout << "Project added.\n";
			}
			else cout << "Project with this ID or title already exists. \n";
		}
		else if (x == 'c') {
			for (int i = 0; i < elist.getEmpListSize(); i++)
			{
				emp = elist.getEmployee(i);
				// if the employee is not assigned, print that they are not assigned 
				if (peassignlist.isEmpInList(emp.getID()) == -1)
				{
					cout << "Employee ID: " << emp.getID() << "  Employee Name: " << emp.getName() << endl;
					cout << "No projects assigned to this employee. \n";
				}
				else
				{
					// print the projects assgined to that employee 
					peassignlist.PrjssAssignedToEmp(emp.getID());
				}

			}

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

			cout << "Enter the employee ID: ";
			cin >> eID;
			index = elist.getIndexUsingID(eID);
			emp = elist.getEmployee(index);
			cout << "Name: " << emp.getName() << " ID: " << emp.getID() << endl;

		}
		else if (x == 'h')
		{
			cout << "Enter the employee name: ";
			cin.ignore(1000, '\n');
			getline(cin, name);
			index = elist.getIndexUsingName(name);
			emp = elist.getEmployee(index);
			cout << "Name: " << emp.getName() << " ID: " << emp.getID() << endl;
		}
		else if (x == 'i') {

			cout << "Enter the project ID: ";
			cin >> pID;
			index = plist.getIndexUsingID(pID);
			prj = plist.getProject(index);
			cout << "Title: " << prj.getTitle() << " ID: " << prj.getID() << endl;


		}

		else if (x == 'j')
		{
			cout << "Enter the project title: ";
			cin.ignore(1000, '\n');
			getline(cin, title);
			index = plist.getIndexUsingTitle(title);
			prj = plist.getProject(index);
			cout << "Title: " << prj.getTitle() << " ID: " << prj.getID() << endl;

		}
		else if (x == 'k')
		{
			no = elist.getEmpListSize();
			cout << "Enter the employee ID: ";
			cin >> eID;
			index = elist.getIndexUsingID(eID);
			while (index == -1)
			{
				cout << "Error the ID you entered doesn't exist, enter again: ";
				cin >> eID;
				index = elist.getIndexUsingID(eID);
			}
			emp = elist.getEmployee(index);

			cout << "Enter the project ID:";
			cin >> pID;
			index = plist.getIndexUsingID(pID);
			while (index == -1)
			{
				cout << "Error the ID you entered doesn't exist, enter again: ";
				cin >> pID;
				index = plist.getIndexUsingID(pID);
			}
			prj = plist.getProject(index);
			peassignlist.addEmpPrjAssignment(emp, prj);
			peassignlist.putEmpsInList(emp);
			peassignlist.putPrjsInList(prj);
		}
		else if (x == 'l')
		{
			cout << "Enter the project ID: ";
			cin >> pID;
			index = plist.getIndexUsingID(pID);
			prj = plist.getProject(index);
			cout << "Enter the Employee ID: ";
			cin >> eID;
			index = elist.getIndexUsingID(eID);
			emp = elist.getEmployee(index);
			cout << "Enter the status you want to set this prohject as, 0 for incomplete and 1 for complete: ";
			cin >> mys;
			while ((mys != 1) && (mys != 0))
			{
				cout << "Error, you enetered a value other than 0 or 1, enter again: ";
				cin >> mys;
			}
			peassignlist.setProjectStatus(emp, prj, mys);
			//still incomplete, needs project locator so that status can be changed
			// it should be better using this function: peassignlist.markProjectAsCompleted();

			// i think it works now. 
		}
		else {
			cout << "Exiting the program" << endl;
			break;
		}
	}
}
