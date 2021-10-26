/*
 * File name: Node.h
 * Stephen Watson C3339952
 * Seng1120 Assignment 1 LinkedList
 */


//**this file has been influenced by labs 3 to 6 of the seng1120 course**

// Below is macroguard for Node class
#ifndef  Steve_Node
#define  Steve_Node
#include <cstdlib>

using namespace std;

class Node
{ 
public:
	public:
		typedef string valueType; 
			//Assigns a Type definition of 'string' to 'valueType. 
	
	//Default constructor which checks that both pointers are null and arguments passed are vaild.
	Node();
	
	//create nodes with 1 parameter being the data stored for the node 
	Node(const valueType& init_data);
	
	//creates an instance of Node with 3 parameters the node data, node next and node previous.
	Node(const valueType& init_data, Node* Previous, Node* Next);
	
	//Destructor used to delete nodes,their data and there pointers
	~Node();
	
	//Pre-Condition: The node is already created
	//Post-Condition:  The data that is inputed is set inside the node. 
	void set_data(const valueType& new_data);	
	
	//Pre-Condition: The node is created already. 
	//Post-Condition: The pointer is set to the input. 
	void set_next(Node* next_link);

	//Pre-Condition: The node is created already. 
	//Post-Condition: The pointer is set to the input.
	void set_previous(Node* previous_link);
	
	//Pre-Condition:The nodes data has been set inside the node. 
	//Post-Condition: The data stored within the node is returned to the console.
	valueType get_data() const;
	
	//Pre-Condition: The node is already created
	//Post-Condition: where the previous pointer is pointing is returned.
	Node* get_previous() const;
	
	//Pre-Condition: The node is already created
	//Post-Condition: where the next pointer is pointing is returned.
	Node* get_next() const; 

private:
	//Private members
	//Node previous
	Node* previous; 
	//string data
	valueType data;
	//Node previous 
	Node* next; 				
	
	};
#endif 

