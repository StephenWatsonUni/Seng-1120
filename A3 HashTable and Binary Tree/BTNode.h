/*
File Name: BTNode.h
Stephen Watson c3339952 
Seng 1120 Assignment 3 - binary tree & hashtable 
*/ 
#ifndef Steve_BTNode
#define Steve_BTNode

#include <cstdlib>
using namespace std;


	template <class valueType>
	class BTNode
	{
		public:
			//Constructors
			BTNode();
			
			//parameterised constructor
			BTNode(const valueType& initialData = valueType());
			
			//Destructor
			~BTNode();
			
			//Pre-condition: A node is created and is NULL
			//Post-condition: The data that is inputed is set inside the node. 
			void setData(const valueType& newData);

			//Pre-condition: Input is vaild
			//post-condition: root node is set
			void setroot(BTNode<valueType>* newroot);

			//Pre-condition: Input is valid
			//Post-condition: Left child is set
			void setLeft(BTNode<valueType>* newLeft);

			//Pre-condition: Input is a valid
			//Post-condition: Right child is set
			void setRight(BTNode<valueType>* newRight); 
			
			//Pre-condition: Node is holding inputted data
			//Post-condition: Returns the data in the node			 
			valueType getData(); 

			//Pre-condition: root child is holding data
			//post-condition: root childs data is returned
			BTNode<valueType>* getroot(); 
			
			//Pre-condition: Left child is holding data
			//Post-condition: Left childs data is returned 
			BTNode<valueType>* getLeft();

			//Pre-condition: Right child is holding data 
			//Post-condition: Returns the data in the right node
			BTNode<valueType>* getRight();

			//Pre-condition: Children are attached to the current node
			//Post-condition: Returns minimum value
			valueType findSmallest();

			//Pre-condition: Find and compare the node you want to removed.
			//Post-condition: Remove the node if the key matches the name.
			BTNode<valueType>* remove(valueType value, BTNode<valueType> *root);
			
		private:
			//Variable to store the data
			valueType data;			
			//Left BTNode pointer
			BTNode<valueType>* left;   
			//Right BTNode pointer
			BTNode<valueType>* right; 
			//root Node Pointer
			BTNode<valueType>* root;

	};
#include "BTNode.hpp"
#endif