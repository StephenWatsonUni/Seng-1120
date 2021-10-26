
//File name: LinkedList.h
//Stephen Watson C3339952
//Seng1120 Assignment 2 Template


//Below is macroguard for LinkedList class
#ifndef Steve_LinkedList
#define Steve_LinkedList

#include <cstdlib>
#include "Node.h"
using namespace std;

	template <class data_type>
	class LinkedList
	{
		public:
			
			//Default Constructor
			LinkedList(); 			
			
			//Parametrised Constructor.
			LinkedList(data_type& data); 
			
			//Destructor used to delete LinkedList,their data and there pointers
			~LinkedList();			
			
			//Pre-condition: the list is already loaded
			//Post-condition: New node set to head
			void addToHead(const data_type& data);

			//Pre-condition: the list is already loaded
			//Post-condition: New node set to tail
			void addToTail(const data_type& data);

			//Precondition: The node is created already. 
			//Postcondition: the data node is set to current node
			void setCurrent(Node<data_type>* newCurrent);

			//Pre-condition:  a valid node is data
			//Post-condition: the data node is set to current
			Node<data_type>* getCurrent();

			//Pre-condition: A list is already loaded
			//Post-condition: The second node in the list is now the head node and the original head node is removed.
			void removeHead();

			//Pre-condition: A list is already loaded
			//Post-condition: The head node is now being pointed to by the current
			void resetCurrent();

			//Pre-condition: the legnth has been set
			////Post-condition: List length gets returned
			int get_length();

			//Precondition: A list is already loaded with current node has data in it
			//Postcondition: The current is now pointing to the next node
			void moveCurrent();

			//Pre-condition: A list is already loaded
			//Post-condition: Size of the data is returned
			int getDataSize();

			//Pre-condition: The list is loaded and head node has data in it
			//Post-condition: Returning the head node data
			const data_type getHeadData();
 
			//Pre-condition: The list is loaded and current node has data in it
			//Post-condition: Returning the current node data
			const data_type getCurrentData();

		private:
			//Private members
			//Head pointer
			Node<data_type>* head;     
			//Tail pointer
			Node<data_type>* tail; 
			//Current pointer
			Node<data_type>* current;  
			//List length
			int length;
	};

			//Precondition: List is loaded with data 
			//Postcondition: every node is printed    
			template <class data_type>
			ostream& operator<< (ostream& stream, LinkedList<data_type>& list);
	#include "LinkedList.hpp"
#endif
