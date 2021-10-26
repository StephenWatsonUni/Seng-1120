
//File name: Node.h
//Stephen Watson C3339952
//Seng1120 Assignment 2 Template
 
//Below is macroguard for Node class
#ifndef Steve_Node
#define Steve_Node
#include <cstdlib>
#include <iostream>

using namespace std;

	template <class data_type>
	class Node
	{
		public:
			
			//Default constructor which checks that both pointers are null and arguments passed are vaild.
			Node(const data_type& initialData = data_type(), Node<data_type>* initialNext = NULL, Node<data_type>* initialPrevious = NULL);
			
			//Destructor used to delete nodes,their data and there pointers
			~Node();
			
			//Pre-Condition: The node is created already. 
			//Post-Condition: The pointer is set to the input.
			void setPrevious(Node<data_type>* Previous);
			
			//Pre-Condition: The node is already created
			//Post-Condition:  The data that is inputed is set inside the node. 
			void setData(const data_type& Data);

			//Pre-Condition: The node is created already. 
			//Post-Condition: The pointer is set to the input. 
			void setNext(Node<data_type>* Next);

			//Pre-Condition:The list has nodes inside 
			//Post-Condition: The nodes stored within the list returned to the console.
			int get_data_size();

			//Pre-Condition:The nodes data has been set inside the node. 
			//Post-Condition: The data stored within the node is returned to the console.
			data_type getData() const;
			
			//Pre-Condition: The node is already created
			//Post-Condition: where the previous pointer is pointing is returned.
			Node<data_type>* getPrevious() const;
			
			//Pre-Condition: The node is already created
			//Post-Condition: where the next pointer is pointing is returned.
			Node<data_type>* getNext() const;

		private:
			//Private members
			//Node previous
			Node<data_type>* previous; 
			//template data
			data_type data;
			//Node previous    
			Node<data_type>* next;        
			   
	};
	#include "Node.hpp"
#endif