/*
 * File name: Node.cpp
 * Stephen Watson C3339952
 * Seng1120 Assignment 1 LinkedList
 */

//**this file has been influenced by labs 3 to 6 of the seng1120 course**

#include <string>
#include <cstdlib>
#include <iostream>
#include "Node.h"


using namespace std;
/*
default constructor
sets the next pointer to NULL
Stets the data to a method of string
sets the previous pointer to NULL
*/
Node::Node()
{
    next = NULL;              
    data =  valueType();        
    previous = NULL;            
}       

/*
sets the pointer next  to NULL 
setting input parameter to data
sets the pointer previous to NULL 
*/
Node::Node(const valueType& init_data = valueType())
{
    next = NULL;            
    data = init_data;       
    previous = NULL;    
}

/*
setting the variables below to the 3 input parameters. 
*/
Node::Node(const valueType& init_data, Node* Previous, Node* Next)
{
    data = init_data;           
    previous = Previous;        
    next = Next;               
}

//Destructor sets the pointers to null and clears the memory off the heap
Node::~Node()
{
    next = NULL;       
    previous = NULL;     
}

// setter for data 
void Node::set_data(const valueType& new_data) 
{
    data = new_data;          
}

// setter for Next pointer
void Node::set_next(Node* next_link)               
{
    next = next_link;               
}
            

// setter for previous
void Node::set_previous(Node* previous_link)       
    {
        previous = previous_link;   
    }
            
// Getter for data 
Node::valueType Node::get_data() const           
{ 
    return data;     
} 

// Getter for Previous pointer            
Node* Node::get_previous() const            
{
    return previous;     
}
// Getter for Next pointer            
Node* Node::get_next() const                
{
    return next;       
}








 





