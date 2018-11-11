
#include "Project.h"

using namespace std;

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
