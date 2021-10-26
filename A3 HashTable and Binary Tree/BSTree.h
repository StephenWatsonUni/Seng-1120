/*
File Name: BSTree.h
Stephen Watson c3339952 
Seng 1120 Assignment 3 - binary tree & hashtable 
*/ 
#ifndef Steve_BSTree
#define Steve_BSTree

#include <cstdlib>
#include "BTNode.h"

using namespace std;

	template <class valueType>
	class BSTree
	{
		public:
			// Default Constructor
			BSTree();
			
			//Destructor
			~BSTree();

			//Precondition: The root Node exists
			//Postcondition: Everything in tree is printed 	
			void Seeker(BTNode<valueType>* Node);

            //Precondition: Data is valid
			//Postcondition: Data is stored
			bool dataCheck(const valueType& data, BTNode<valueType>* previous);
			 
			 //Precondition: Data is valid   
			 //Postcondition: DataCheck is used to position on the tree.  
			 void add(const valueType& data);

			//Precondition: Data is stored in the Node
			//Postcondition: Data is removed and everything is repositioned
			bool remove(valueType data);

			//Precondition: This Node and all of it's children exist
			//Postcondition: This Node and all it's children are deleted
			void Node_Remove(BTNode<valueType>* Node);

			//Precondition: The root Node exists and data is stored inside
			//Postcondition: The Node is deleted 			
			void deleteNode(const valueType& data, BTNode<valueType>* root);
			
			//Precondition: Tree is a valid tree 
			//Postcondition: The tree is printed in correct order	
			void print();

		private:
			//Private variables
			//Root Node 
			BTNode<valueType>* rootNode;		
        	//Tree size
        	int Length;		
	};

	//Overload operator
	template <class valueType>
	ostream& operator<< (ostream& stream, BSTree<valueType>& Tree);

#include "BSTree.hpp"
#endif