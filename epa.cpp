
#include "ProjectEmployeeAssignment.h"

using namespace std;

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

	if (s == 1)
	{
		return true;
	}
	return false;
}
