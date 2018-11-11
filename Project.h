#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Project {
private:
	string ID, title;
	//…add more attributes as needed
public:
	Project();
	Project(string mytitle, string myid);
	string getID();
	string getTitle();
	void setID(string myid);
	void setTitle(string mytitle);
	//…add other functions as needed
};

