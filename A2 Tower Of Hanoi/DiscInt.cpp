
//File name: DiscInt.cpp
//Stephen Watson C3339952
//Seng1120 Assignment 2 Template
 
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include "DiscInt.h"

using namespace std;
//Default constructor
DiscInt::DiscInt()
{	
	//Defining what the data is
	this->data = 0; 
}
//Parametrised Constructor.
DiscInt::DiscInt(int x)
{
	//Defining what the data is
	this->data = x;
}
//Destructor
DiscInt::~DiscInt()
{
	data = 0;

}	
 //Getter for size 
int DiscInt::get_size() const
{
	//Returns the data size
	return data;
}
//Print function
string DiscInt::print(int x)
{
	//Using thew sstream
	stringstream ss;
	//Setting a defined gap between data 
	ss << "     " << data << "    ";
	//Assigning the ss string to the str string
	string str = ss.str();
	//Returning the str string
	return str;
}
