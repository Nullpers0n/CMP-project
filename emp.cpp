#include "Employee.h"
using namespace std;
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
