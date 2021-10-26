
//File name: LStack.h
//Stephen Watson C3339952
//Seng1120 Assignment 2 Template
 

// Below is macroguard for LStack class
#ifndef Steve_LStack
#define Steve_LStack

// Below are all file includes
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include "Node.h"
#include "LinkedList.h"

using namespace std;


	template <class data_type>
	class LStack 
	{

		public:
	
		//Default Constructor
		LStack();
		//Destructor used to delete LStack, it's data and there pointers
		~LStack();
 		//Copy COnstructor
		LStack(LStack *source); 
		
		//Pre-condition: A list has be created
		//Post-condition: Checks to see if the list is empty
		bool empty() const;
		
		//Pre-condition: The list length has been set
		//Post-condition: Returns the length of the list
		int length() const;
		
		//Pre-condition: The disc size has been set
		//Post-condition: Returns the size of the disk on top
		int peek() const;
		
		//Pre-condition: stacks have been initialised
		//Post-condition: Pushes the data onto the stack in this case loads the disks by adding to head 
		void push(const data_type);
		
		//Pre-condition: head node must exist and have data stored inside
		//Post-condition: Gets the data from the head node then removes head node from the list
		data_type pop();
		
		//Pre-condition: Head node mujst have data stored inside
		//Post-condition: //Returns the data in the head node
		data_type top() const;
		
		
	private:
		//LinkedList is private
		LinkedList<data_type> *list;
		
};
#include "LStack.hpp"

#endif