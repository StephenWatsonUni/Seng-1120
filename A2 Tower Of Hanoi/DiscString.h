
//File name: DiscString.h
//Stephen Watson C3339952
//Seng1120 Assignment 2 Template
 

// Below is macroguard for Discstring class
#ifndef Steve_DiscString
#define Steve_DiscString

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class DiscString
{
public:
    
    //Default constructor
    DiscString();
    
    //Parametrised Constructor.
    DiscString(int x);
    
    //Destructor
    ~DiscString();
    
    //Precondition: Disc size is set
    //Postcondition: Getter for size  
    int get_size() const;
  	
    //Precondition: The string is loaded with the data
    //Postcondition: The string is printed   
  	string print(int x);
  	 

  private:
    //Private 
    //String of data
    string data;
      
};

#endif
