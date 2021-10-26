
//File name: LinkedList.hpp
//Stephen Watson C3339952
//Seng1120 Assignment 2 Template
 
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include "Node.h"

using namespace std;

//Default Constructors
template<class data_type>
LinkedList<data_type>::LinkedList() 
{
	//Setting head to NULL
	head = NULL;    
	//Setting current to NULL
	current = NULL;
	//Setting tail to NULL
	tail = NULL;
	//Setting list length to NULL
	length = 0;
}
//Parametrised Constructor
template<class data_type>
LinkedList<data_type>::LinkedList(data_type& data) 
{
	//Creating a new Node
	head = new Node<data_type>(data); 
	//Setting head node to the tail node
	tail = head;     
	//Setting the tail node to the current
	current = tail;
	//Increasing the list length of nodes as a nnode has been created.
	length = 1;                         
	return;
}
//Destructor
template<class data_type>
LinkedList<data_type>::~LinkedList() 
{
	
	 //If the head node is not empty
	while (head != NULL)   
	{
		//Create a temp node
		Node<data_type>* temp;      
		//Set the temp to head
		temp = head;                                       
		//Assign the head next to head
		head = head->getNext();
		//If the head is not NULL
		if (head != NULL) 
		{
			//The head nodes previous is set to NULL
			head->setPrevious(NULL);
		} 
		else 
		{	

			//otherwise Set the tail to NULL
			tail = NULL;
		}        
		//Delete the node temp 
		delete temp;  
		//Assign current node to the new head node.                       
		current = head;                      
	}
	//The length is now set to zero as no nodes in the list
	length = 0;                          
}
//The data that is inputed is set inside the head node.	
template<class data_type>
void LinkedList<data_type>::addToHead(const data_type& data) 
{
	//If the length is zero
	if (length == 0) 
	{
		//Creates a new head node
		head= new Node<data_type>(data); 
		//Assigning the head node to tail
		tail = head;
		//Assigning head to current node
		current = head;
		//Set the list length to 1 as a node exists
		length = 1;                       
	} 
	else 
	{
		//Creates a new temp node
		Node<data_type>* temp = new Node<data_type>(data); 
		//Setting tep previous to NULL
		temp->setPrevious(NULL);
		//Assigning the temps next to head
		temp->setNext(head); 
		//Assigning the temp node to NULL
		head = temp;
		//Setting the temp node to NULL
		temp = NULL;  
		//Set the list length to 1 as a node exists
		length++;
	}
}
//The data that is inputed is set inside the tail node.
template<class data_type>
void LinkedList<data_type>::addToTail(const data_type& data) 
{
	//If the current list has no nodes
	if (length == 0) 
	{
		
		//Creates a new node and assigns it to the tail
		tail = new Node<data_type>(data); 
		//Assigning the tail node to head node
		head = tail;
		//Assigning head node to current node
		current = head;
		//Set the list length to 1 as a node exists
		length = 1;                        
	} 
	else 
	{
		//Creates a new temp node
		Node<data_type>* temp = new Node<data_type>(data); 
		//Assigning the tails next to temp
		tail->setNext(temp); 
		//Assign the temp previous to tail
		temp->setPrevious(tail); 
		//Assign the temp node to tail
		tail = temp;                  
		//Sets the temp to NULL.
		temp = NULL;  
		//Increase the list length
		length++; 
	}

}
//The data that is inputed is set inside the current node.
template<class data_type>
void LinkedList<data_type>::setCurrent(Node<data_type>* newC) 
{
	//Current = new current
	current = newC;
}
//the data node is set to current
template<class data_type>
 Node<data_type>* LinkedList<data_type>::getCurrent() 
{
	//Returns the current node
	return current;    
}
template<class data_type>
void LinkedList<data_type>::removeHead() 
{
	//Assigning current node to head
	current = head;
	//using temp node on the heap
	Node<data_type>* temp;         
	//Assigning the head to temp
	temp = head;
	//Assing head next to the head  
	head = head->getNext();      
	//If the head is not NULL
	if (head != NULL) 
	{
		//Assigning the heads previous to NULL 
		head->setPrevious(NULL);
	}       
	else 
	{
		 //Assign NULL to tail
		tail = NULL;
	}           
	// Delete the temp node
	delete temp;                             
	//Assign the head to current                                               
	current = head;
	//Decrease the list length
	length--;
}
//The head node is now being pointed to by the current
template<class data_type>
void LinkedList<data_type>::resetCurrent() 
{
	//Assigning head node to current
	current = head;                    
}
//List length gets returned
template <class data_type>
int LinkedList<data_type>::get_length()
{
    //Returning the number of nodes in the list
    return length;  
}
//The current is now pointing to the next node
template<class data_type>
void LinkedList<data_type>::moveCurrent() 
{
	//Assigning the currents get next to the current
	current = current->getNext(); 
}
//Size of the data is returned
template<class data_type>
int LinkedList<data_type>::getDataSize()
{
	if(head == NULL)
	{
		//If nothing is in the head
		return 0;
	}
	//Assigning head to the current
	current = head;
	//Returning the data size of the current
	return current->get_data_size();
}
//Returning the head node data
template<class data_type>
const data_type LinkedList<data_type>::getHeadData() 
{
	// Retuens head node data
	return head->getData();
	          
}
//Returning the current node data
template<class data_type>
const data_type LinkedList<data_type>::getCurrentData() 
{
	//Returns the data in the current node
	return current->getData();    
}
//Operator 
template<class data_type>
ostream& operator <<(ostream& stream, LinkedList<data_type>& list) 
{

	//head node is now being pointed to by the current
	list.resetCurrent();
	//Returning the current node data wjile it is not NULL
	while (list.getCurrent() != NULL)
	{
		//Print the data that is in the current
		stream << list.getCurrentData(); 
		//Point the current node in the list to the next node 
		list.moveCurrent();
	}
	//head node is now being pointed to by the current
	list.resetCurrent();
	// returns the stream             
	return stream;       
}
