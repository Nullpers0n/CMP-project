#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


class Employee {
private:
	string ID, name;
	//…add more attributes as needed
public:
	//Purpose: setting ID to 000 and name to NULL
	//Input : nothing
	// Output : none
	Employee();
	//Purpose: setting ID to myid and name to myname
	// Input: string myname and string myid that were inputted by the user
	// Output: nothing
	Employee(string myname, string myid);
	//Purpose : Gets the ID of the employee
	// Input : None
	// Output : id of the employee
	string getID();
	//Purpose : gets the name of the employee
	// Input: none
	// output : name of the employe
	string getName();
	//Purpose : sets id to myid 
	// input: string myid that was inputted by the user
	//output : none
	void setID(string myid);
	// Purpose : sets name to myname
	// input : string myname that was inputted by the user
	// output : none
	void setName(string myname);

	//…add other functions as 

};
