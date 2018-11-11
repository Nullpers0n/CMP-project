
#include "ProjectList.h"
using namespace std;
// non member function used in some of the classes to print error. 
void ProjectList::printError(string& str)
{
	cout << "Error: ID or name you entered doesn't exist, enter again: ";
	cin >> str;
}

int ProjectList::getPrjListSize()
{
	return listofProjects.size();
}

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
	if ((index < 0) || (index >= listofProjects.size()))
	{
		cout << "Error: index is out of range, returning the first project.\n";
		p = listofProjects[0];
	}
	else p =listofProjects[index];
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
		cout << "Project ID: " << listofProjects[i].getID() << " Project Title: " << listofProjects[i].getTitle() << endl;
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
