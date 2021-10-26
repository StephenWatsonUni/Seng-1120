
 //File name: DiscString.cpp
 //Stephen Watson C3339952
 //Seng1120 Assignment 2 Template
 
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include "DiscString.h"

using namespace std;

//Default constructor
DiscString::DiscString()
{
	//Defining what the data is
	this->data = "";
}

//Parametrised Constructor.
DiscString::DiscString(int x)
{
	//Switch statement displaying what each data will be for each case
	//this cycles through from a empty pole to nine x's
	switch (x) 
	{
		case 0:
			data = "|";
			break;
		case 1:
			data = "x";
			break;
		case 2:
			data = "xxx";
			break;
		case 3:
			data = "xxxxx";
			break;
		case 4:
			data = "xxxxxxx";
			break;
		case 5:
			data = "xxxxxxxxx";
			break;
			default:
			data = "";
			break;
	}
}
//Destructor
DiscString::~DiscString() 
{
	data = '\0';
}
//Getter for disc Size  
int DiscString::get_size() const
{
  //Getter for disc Size
  //Calculates disc size by adding 1 and dividing by 2 this equation gets the correct disc size.
  //This disc size then matches to the case number in the switch
  return (data.length()+1)/2;

}
//Print function
//Prints the length of each disc, the largest number having one spacing and the smallest number having the largest spacing
//This keeps all the strings at the same length 
string DiscString::print(int x) 
{
	string str;
	if (data.length() == 9)
        {
            str = " " + data;
        }
        else if (data.length() == 7)
        {
            str = "  " + data + " ";
        }
        else if (data.length() == 5)
        {
            str = "   " + data + "  ";
        }
        else if (data.length() == 3)
        { 
            str = "    " + data + "   ";
        }
        else if (data.length() == 1)
        {
            str = "     " + data + "    ";
        }
        else
        {
            str = "          ";
        }

        return str;
}


