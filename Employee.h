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
	Employee();
	Employee(string myname, string myid);
	string getID();
	string getName();
	void setID(string myid);
	void setName(string myname);

	//…add other functions as 

};
