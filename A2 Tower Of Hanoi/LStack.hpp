
//File name: LStack.hpp
//Stephen Watson C3339952
//Seng1120 Assignment 2 Template

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include "LStack.h"

using namespace std;

//Default Constructor
template<class data_type>
LStack<data_type>::LStack() 
{
	//Creates a new LinkedList on the heap
	list = new LinkedList<data_type>();
}
//Destructor used to delete LStack, it's data and there pointers
template<class data_type>
LStack<data_type>::~LStack() 
{
	//Deletes a LinkedList off the heap
	delete list;
}
//Copy COnstructor
template<class data_type>
LStack<data_type>::LStack(LStack *copySource) 
{
	//Creating a new list
	list = new LinkedList<data_type>(); 
	////Copying the current list length
	int length = copySource->list->get_length(); 
	if(length!=0)
	{
		//Pointing to the head node with the current
		copySource->list->resetCurrent();
		do 
		{
			//Adding the copied current data to lists tail
			list->addToTail(copySource->list->getCurrentData());
			//copying list and pointing the current to the next node
			copySource->list->moveCurrent(); 
		//Checking the copy lists current data is not null		
		} while (copySource->list->getCurrent() != NULL); 
		//The copy list is Pointing to the head node with the current
		copySource->list->resetCurrent();
		//The list length is assigned the copied lists length
		length = copySource->list->get_length();
	}
}
//Boolean function checks if the list is empty.
template<class data_type>
bool LStack<data_type>::empty() const 
{
	if(list->length == 0)
	{
		//Returning true if the list is empty
		return true;
	}
	else
	{	
		//Returning false if the list is not empty
		return false;
	}
}
//Returns the amount of nodes in the list
template<class data_type>
int LStack<data_type>::length() const 
{
	//Returns the amount of nodes in the list, this is what the length of the list is
	return list->get_length();
}
//Returns the size of the disk on top.
template<class data_type>
int LStack<data_type>::peek() const 
{
	//Returns the size of the disk on top.
	return list->getDataSize();
}
//Pushes the data onto the stack
//adds it onto the head node 
template<class data_type>
void LStack<data_type>::push(data_type data) 
{

	//adding data to the head node in the list
	list->addToHead(data);
}
//Gets the data from the head node then removes head node from the list
template<class data_type>
data_type LStack<data_type>::pop() 
{
	//Getting head data to return
	data_type toReturn = list->getHeadData(); 
	//Removing the head node
	list->removeHead();
	//Returning to console
	return toReturn;
}
//this function returns the data_type being stored in the head Node of the Linked List.
template<class data_type>
data_type LStack<data_type>::top() const 
{	
	//this function returns the data_type being stored in the head Node of the Linked List.
	return list->getHeadData();
}