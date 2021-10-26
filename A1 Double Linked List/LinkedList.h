/*
 * File name: LinkedList.h
 * Stephen Watson C3339952
 * Seng1120 Assignment 1 LinkedList
 */


// Below is macroguard for LinkedList class
#ifndef LinkedList_H
#define LinkedList_H
#include<string>
#include <iostream>
#include <cstdlib> 
#include "Node.h"
 
using namespace std;

//class LinkedList
class LinkedList
{
public:

	typedef string valueType; //Assigns a Type definition of 'string' to 'valueType. 

	
	/*
	/Default constructor which checks that both pointers are null and arguments passed are vaild. 
	*/
	LinkedList();
	
	
	//Passes any valid data that validates with the parameter to a function to be stored. 
	LinkedList(const valueType& data); 
	
	//Member varaibles
	
	//pre condition: tokenise the input of the string
	//post condition: Take the input and store in a node.
	void add(const valueType& data);
	
	//pre condition: Find and compare the node you want to removed.
	//post condition: Remove the node if the input matches the name using the compare to function
	void remove(const string value);
	
	void remove_data(const valueType data);

	//pre condition: Start at the head node and move through the nodes. 
	//post condition: Compare value that shows the number of occurences of the string argument and return it. 
	int count(const string name);
	
	//pre condition: N/A
	//post condition: Moving current pointer to head of the list
	void go_to_head(); 
	
	//pre condition: Checking if the pointer is assigned to NULL.
	//post condition: If true it is returned and the current pointer is set to NULL.   
	bool confirm_current() const;
	
	//pre condition: N/A
	//post condition: Moving to the next node in the list until it reaches NUll.
	void Traversing();
	
	//pre condition: Gets the data from current pointers node. 
	//post condition: Returns that data to the console. 
	valueType get_current_data() const;
		
	/*Operator methods 
	operator to have user-defined function in my classe
	*/LinkedList& operator += (LinkedList& ll);
	

	/*destructor
	pre condition: Able to accept all prameters and aruments to clear heap memory.	
	post condition: Clears the heap memory, this automatically run at the end of the program.
	*/
	~LinkedList();

	

private:
	//Declaring private variables. 
	//Head pointer
	Node* head;
	//Current pointer
	Node* current;
	//Tail pointer 
	Node* tail;
	//List of node length
	int list_length;


 };
	
	ostream& operator <<(ostream& out, LinkedList& ll); 
 
 #endif