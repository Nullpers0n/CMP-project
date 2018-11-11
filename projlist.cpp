
#include "ProjectList.h"
using namespace std;

// Purpose: non member function used in some of the classes to print error.
// Input: string from another input or function
// Output: no output
void ProjectList::printError(string& str)
{
	cout << "Error: ID or name you entered doesn't exist, enter again: ";
	cin >> str;
}

// Purpose: returns the number of projects inside the list
// Input: no input
// Output: the size of listofProjects vector
int ProjectList::getPrjListSize()
{
	return listofProjects.size();
}

// Purpose: Searches if a project is in the list of projects
// Input: Project class (ID and title inside it)
// Output: returns the index where the project is located in the vector, else it returns -1 as an indicator that the project was not found
int ProjectList::isItInList(Project p)
{
	for (int i = 0; i< listofProjects.size(); i++)
	{
		if ((p.getID() == listofProjects[i].getID()) || (p.getTitle() == listofProjects[i].getTitle()))
		{
			return i;
		}
	}
	return -1;
}

// ------add project function
// Purpose: Adds a new project to the list of projects vector
// Input: A Project class (ID and title inside it)
// Output: returns true if the project was added, returns false if the project already exists
bool ProjectList::addProject(Project p)
{
	// if we assume that the Project's private components are empty, we need more statements 
	int i;
	// check if it exists
	i = isItInList(p);
	// if it doesn't exist add it. 
	if (i == -1)
	{
		listofProjects.push_back(p);
		return true; 
	}
	// if it exists dont add it.
	else
	{
		return false; 
	}

}

//------ GET index using ID function 
// Purpose: searches for the project that has the same id as the user entered
// Input: the id that the user is searching for
// Output: returns the index that the project is located on inside the listofprojects vector, else it returns -1
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
// Purpose: searches for the project that has the same title as the user entered
// Input: the title that the user is searching for
// Output: returns the index that the project is located on inside the listofprojects vector, else it returns -1
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
// Purpose: Opens the text file that contains the projects and stores them into the listofprojects vector
// Input: No Input
// Output: no output
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
// Purpose: Deletes a project out of the listofprojects
// Input: the id of the project that the user entered
// Output: no output
void ProjectList::deleteProject(string myid)
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
	// now delete the actual project
	listofProjects.erase(listofProjects.begin() + index);
}

//--------get project function
// Purpose: searches for the project that the user wants throught its index
// Input: the index that the project lies inside the vector
// Output: the Project P
Project ProjectList::getProject(int index)
{ 
	Project p;
	if ((index < 0) || (index >= listofProjects.size()))
	{
		cout << "Error: index is out of range, returning the first project.\n";
		p = listofProjects[0];
	}
	else p =listofProjects[index];
	return p;
}

//-------------- get project title
//Purpose : gets the project title and displays it to the user through the id
// Input: ID of the project
// output: The title of the project
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
// Purpose: Searches for the title of the project that the user entered to show the user the project id
// Input : the title of the project that the user entered
// output : The ID of the project
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
//Purpose : Lists all the projects inside the list
// Input: no input
// Output: the cout that shows the user the project id and title
void ProjectList::listProjects()
{
	for (int i = 0; i < listofProjects.size(); i++)
	{
		cout << "Project ID: " << listofProjects[i].getID() << " Project Title: " << listofProjects[i].getTitle() << endl;
	}
}
// Purpose : Destructor that returns the listofprojects vector back to the text file
// Input: no Input
// Output: no output
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
