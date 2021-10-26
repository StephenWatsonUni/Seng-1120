
//File name: DiscInt.h
//Stephen Watson C3339952
//Seng1120 Assignment 2 Template
 

// Below is macroguard for DiscInt class
#ifndef Steve_DiscInt
#define Steve_DiscInt

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class DiscInt
{
public:

	//Default constructor
	DiscInt();
	
	//Parametrised Constructor.
	DiscInt(int x);
	
	//Destructor
    ~DiscInt(); 
    
    //Pre-condition: Size has been set
	//Post-condition: Getter for size
    int get_size() const;
    
  	//Precondition: The string is loaded with the data
    //Postcondition: The string is printed     
	string print(int x);
   
private:
	//Private 
    //int of data
    int data;

};

#endif
