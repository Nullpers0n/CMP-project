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
	//Purpose : sets id to 0 and title to NULL
	//input: none
	// output: none
	Project();
	// purpose : sets title to mytitle and id to myid
	// input : string mytitle and myid that were inputted by the user
	// output : none
	Project(string mytitle, string myid);
	// purpose : gets the id of the project
	// input : none
	// output : returns the id of the project
	string getID();
	// purpose : gets the title of the project
	// input : none
	// output : returns the title of the project
	string getTitle();
	// purpose : sets id to myid
	// input : string myid that the user inputs
	// output : none
	void setID(string myid);
	//purpose  :sets title to mytitle
	//input : string mytitle that the user inputs 
	//output : none
	void setTitle(string mytitle);
	//…add other functions as needed
};

