/*
File Name: HTable.h
Stephen Watson c3339952 
Seng 1120 Assignment 3 - binary tree & hashtable 
*/ 
#ifndef Steve_HTABLE
#define Steve_HTABLE

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;


	template <class valueType>
	class HTable
	{
		public: 
			// Constructor
			HTable();
			
			// Destructor
		    ~HTable();
			
			//Pre-condition: The name exists 
			//Post-condition: Name is stored into HTable bucket 
            void add(valueType key);

			//Pre-condition: The table has the key data stored inside the hashtable
			//Post-condition: The key data is removed from the table
            void remove(valueType key);
			 
			//Pre-condition: The key data exists inside the table
			//Post-condition: Returns true is the data is stored, false if not
			bool search(valueType key);

			//Pre-condition: The key data's position is vaild within the hashtable
			//Post-condition: The key data is returned 
            valueType getData(int key);

		private:			
			//Pre-condition: Interger array that stores the name array but is initialised to empty
			//Post-condition: Interger array that stores the name array if the names exists
			int array[150];

			//Pre-condition: Template array to store names is created an initialised to empty
			//Post-condition: The array stores the variable names 
			valueType name[150];			
							
			//Precondition: Given hash function that only excepts strings
			//Postcondition: Sums up the ASCII values of each character in the string and return the result of that sum mod (%) 150: 
			int hashfun(string value);			
	};

    template <class valueType>
	ostream& operator <<(ostream& stream, HTable<valueType>& Table);

#include "HTable.hpp"
#endif