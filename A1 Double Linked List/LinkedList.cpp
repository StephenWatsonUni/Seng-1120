/*
 * File name: LinkedList.cpp
 * Stephen Watson C3339952
 * Seng1120 Assignment 1 LinkedList
 */
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<string>
#include <sstream>
#include "LinkedList.h" 

using namespace std;  
//Creating an empty List.
 LinkedList::LinkedList()
 {
	 //Setting the head to Null.
	 head = NULL;    
	 //Setting the tail to Null.
	 tail = NULL; 	 
	 //Setting Current to Null. 
	 current = NULL; 
	 //Setting the list Length to 0.
	 list_length = 0; 
 }

void LinkedList::add(const valueType& data)
{
	istringstream iss(data);
	//Tokenising the input and using getline function to help match a name.
	string word;
	while (getline(iss, word, ' ')) 
	{
		/*Creating a new LinkedList with data
		and method allows adding to the head.
		*/
		//If the head to Null.
		if (head == NULL)	
		{  
			//Creating a new node based on a word match which will be our data on the heap.
			head = new Node(word);
			// Assigning tail to point to the same node.
			tail = head;	
			//Assigning the current pointer to the first node.
			current = head; 
			// Increasing the count as 1 node is created.
			list_length = 1; 
		}
		/*Creating a new LinkedList with data.
		and method allows adding to the tail.
		*/
		else
		{	//Creating a new node based on a word match which will be our data.
			Node* temp = new Node(word);
			//Setting tail next pointer to the new tail and set new nodes previous. 
			tail->set_next(temp);
			temp->set_previous(tail);
			//Setting tail to the new node.
			tail = temp; 
			//Assigning temp to Null.
			temp = NULL; 
			//Increase the List.
			list_length++; 
		}
	}
}
//passes any valid data that validates with the parameter to a function to be stored.
LinkedList::LinkedList(const valueType& data)
{
	add(data);   
}

void LinkedList::remove(const string name)
{
	// moving the current to the head of the list
	go_to_head();
	// checking if the current node is not NULL					
	while (current != NULL)   
	{	//Checking for a node match via name using compare to function.
		if (current->get_data().compare(name) == 0  && current == head)				 
		{	//// creating a temp pointer and setting it to the head pointer
			Node* temp = head;
			// moving the head to next node.				
			head = head->get_next();
			
			//setting the previous head pointer node to NULL.		
			head->set_previous(NULL);
			
			// setting the previous on temp node to NULL		
			temp->set_previous(NULL);		
			
			// setting next pointer on the temp node to NULL
			temp->set_next(NULL);		
			//delete the temp node
			delete temp; 					 
			// decrase the count
			list_length--; 					
			//Assigning head pointer  to current pointer
			current = head;   				
		}	

		//Checking for a node match via name using compare to function.
		else if (current->get_data().compare(name) == 0 && current == tail)
		{
			//Assigning current pointer to new temp pointer
			Node* temp = current; 
			
			//moving the current pointer back one node on the linked list
			current = current->get_previous(); 	
			//setting the next pointer to NULL.
			current->set_next(NULL);				 
			//Assigning the tail pointer to the current pointer. 
			tail = current; 						 
			//setting the temp previous pointer to NULL
			temp->set_previous(NULL);		
			//setting the next pointer on the temp node to NULL
			temp->set_next(NULL);		
			//delete the temp node
			delete temp;
			// decrase the count  				 
			list_length--;					
		}
		
		// Internal node temp removal 
		//Checking for a node match via name using compare to function.
		else if (current->get_data().compare(name) == 0) 	
		{
			//Assigning the current pointer the newly created temp pointer
			Node* temp = current; 				
			//Move to the next node with current pointer
			Traversing();						
			
			//setting the current nodes previous tp the temp pointers previous node
			current->set_previous(temp->get_previous()); 	
			
			//Getting the node before temp previous and setting the current pointer to that next.
			temp->get_previous()->set_next(current);	
			
			//setting the temp nodes next pointer node to NULL 
			temp->set_previous(NULL);		
			
			//delete the temp node
			delete temp; 					
			
			//Move to the next node with current pointer
			Traversing(); 					
			
			//Decrease the count
			list_length--; 				
		}
		else 
		{	//Move to the next node with current pointer
			Traversing();					
		}
	}
}

void LinkedList::remove_data(const valueType data)
{
 //Removing from head
 //Checking if current is not NULL.
 while (current != NULL) 	
	{
	// checking if the both datas match and the head is assigned to current.
	if (data == get_current_data() && current == head)			
	{
		// creating a temp and assigning that to the head.
		Node* temp = head;				
		// moving to the next node and assigning head.
		head = head->get_next();       
		//Setting the head pointer previous to NULL. 
		head->set_previous(NULL);		
		//Setting the temp nodes next pointer to NULL.
		temp->set_previous(NULL);		
		//Setting the temp nodes previous pointer to NULL.
		temp->set_next(NULL);			
		//delete the temp node.
		delete temp; 
		//Decreasing the list count.
		list_length--;
		//Assigning head to current.
		current = head; 				
		//Moving through the nodes with the pointer (going to next node).
		Traversing();						
		}
		//Checking that data matches currents data and if current is the tail
		
		//Removing from tail
		else if (data == get_current_data() && current == tail)	
		{
		//Creating a temp pointer and assigning it to current.
		Node* temp = current;						
		//current pointer back one node.
		current = current->get_previous();       
		//setting the current nodes next pointer to NULL.
		current->set_next(NULL);
		//Assigning current to the tail.
		tail = current; 
		//Setting the temp nodes previous pointer to NULL. 
		temp->set_previous(NULL);		
		//setting the next pointer on the temp node to NULL
		temp->set_next(NULL);		
		//Deleting the temp node.
		delete temp;  
		//Decreasing the list count.
		list_length--;
		//Moving through the nodes with the pointer (going to next node).
		Traversing();			
		}
		//Checking that data matches currents data and if current is the tail
		
		//Removing from current
		else if (data == get_current_data())					
		{	//Assigning current to temp.
			Node* temp = current;    							
			//Moving through the nodes with the pointer (going to next node).
			Traversing();											
			//Setting currents previous pointer node to node before temp.
			current->set_previous(temp->get_previous()); 		 
			//setting next current node and get the node before temp. 
			temp->get_previous()->set_next(current);			
			//Setting the previous on the temp node to NULL 
			temp->set_previous(NULL);
			// setting the next pointer on the temp node to NULL
			temp->set_next(NULL);								
			//Deleting the temp node.
			delete temp; 								 
			//Moving through the nodes with the pointer (going to next node).
			Traversing(); 									
			//Decreasing the list count.
			list_length--; 									 
			}
			else 
			{
			//Moving through the nodes with the pointer (going to next node).
			Traversing();										
			}
	 }
}	 

int LinkedList::count(const string name)
 {  //Setting the count to zero.
	int count = 0; 				
	//Moving to the head node.
	go_to_head();				 
	//Checking if the current node is not NULL.
	while (current != NULL)     
	{	//If the data is matched via name  
		if (current->get_data().compare(name) == 0)
		{	//Increasing the count
			count++;				
		
		}
		//Moving through the nodes by being assigned to the next node
		Traversing(); 		 
	}
	return count; //Returning the count.  
 }

// assigning the current pointer to the head pointer
void LinkedList::go_to_head()
{
 	current = head; 				
}

//Seeing if the current is NULL
bool LinkedList::confirm_current() const
{	
 	if (current == NULL) 			
		return true;
	else 
		return false; 
}

//Moving through the nodes by going to the next.
void LinkedList::Traversing()
{
	current = current->get_next();   
}

//Returning the data of current pointer 
LinkedList::valueType LinkedList::get_current_data() const
{
	return current -> get_data();
}			


/* moving the current of the RHS LinkedList to head of the LinkedList
checking if the current pointer within the RHS is NULL
*/
LinkedList& LinkedList::operator += (LinkedList& ll) 
 {
	ll.go_to_head();							
	while (ll.confirm_current() != true)			  
	{
		this->add(ll.get_current_data());	
		ll.Traversing();								
	}
	return *this;									
 }	 

ostream& operator <<(ostream& out, LinkedList& ll)
{	//Moving to the head node.
	ll.go_to_head();		
	//Checking if current is null.
	while (ll.confirm_current() != true)			 
	{
		//Outputting current node data + the add methods word function
		cout << ll.get_current_data() + " ";		
		//Moving through the nodes.
		ll.Traversing();			
	}
	//Returning the cout to the console.
	return out;
}

/*
LinkedList destructor removing the nodes and clearing the heap memory. 
*/
LinkedList::~LinkedList()
{
	//Assigning Null to current.
	current = NULL; 		
	//Checking the head is not assigned to null.
	while (head != NULL)	
	{
		//Creating a temp pointer and assigning it the head.
		Node* temp = head;		
			//Checking to see if there is only one node left.
			if (head == tail)		
			{
				//If so assign Null to the head.
				head = NULL;
				//If so assign Null to the tail.		 
				tail = NULL;		
				//Delete the last node.  
				delete temp;		
			}
			else 
			{
				//The folling node becomes the head.
				head = head->get_next(); 	
				//the head node previous is set to NULL.
				head->set_previous(NULL);	
				//Setting the deleted nodes next to NULL
				temp->set_next(NULL);		
				//The node and pointers are deleted
				delete temp; 				
			}
	}
	//Setting the list length to zero.
	list_length=0;
}

