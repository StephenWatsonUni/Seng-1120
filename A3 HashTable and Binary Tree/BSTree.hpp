/*
File Name: BStree.hpp
Stephen Watson c3339952 
Seng 1120 Assignment 3 - binary tree & hashtable 
*/ 
#include <cstdlib>
#include "BTNode.h"
#include "BSTree.h"

#include <iostream>

//Default Constructor
template <class valueType>
BSTree<valueType>::BSTree()
{
  // Set Root Node pointer to NULL
  rootNode = NULL;    
  //Sets Length to NULL
  Length = 0;           
}

//Destructor
template <class valueType>
BSTree<valueType>::~BSTree()  
{
  //Node Remove
  Node_Remove(rootNode);         
}

//Validating function
template <class valueType>
void BSTree<valueType>::Seeker(BTNode<valueType>* Node)
{
  // makes sure root Node isnt null
  if(Node != NULL)
  { 
    //recrusive Checking left child
    Seeker(Node->getLeft());                                                     
    //recrusive Checking right child
    Seeker(Node->getRight());
    //prints Node data string
    cout << Node->getData() << " ";                                             
                                                      
  }            
}

//Checking data is valid and stored
template <class valueType>
bool BSTree<valueType>::dataCheck(const valueType& data, BTNode<valueType>* previous)
{
  //Creates temp Node to add to the tree
  BTNode<valueType>* temp;                                
  if(data > previous->getData())
  { 
    //Checks if the right side is NULL                             
    if(previous->getRight() == NULL)
    {
      //Add the data to temp Node if it is NULL
      temp = new BTNode<valueType>(data);              
      //Assigning the right child to temp 
      previous->setRight(temp);                        
      //Increase the length of tree
      Length++;
      //Return true to console
      return true;                                        
    }
    else
    {
      //If Not Null move down the tree and repeat
      return dataCheck(data, previous->getRight());         
    }
  }
  else
  {       
    // Checks if the side is NULL
    if(previous->getLeft() == NULL)
    {                    
      //Add the data to temp Node if it is NULL
      temp = new BTNode<valueType>(data);
      //Assigning the left child to temp           
      previous->setLeft(temp);
      //Increasing the length
      Length++;
      //Return true to console
      return true;
    }
    else
    {
      //If Not Null move down the tree and repeat
      return dataCheck(data, previous->getLeft());        
    }
  }
}

//Adding function
template <class valueType>
void BSTree<valueType>::add(const valueType& data)
{
  //If the rootNode is NULL
  if(rootNode == NULL)
  {
    //Creates new rootNode
    rootNode = new BTNode<valueType>(data);        
    return;
  }   
  else
  {
    //Repeats the InputCheck function  
    dataCheck(data, rootNode);                         
  }
}

//Removing the data from the Node function
template <class valueType>
bool BSTree<valueType>::remove(valueType data) 
{
  //If the rootNode is NULL
  if(rootNode == NULL)
  { 
    //Return false to the console
    return false; 
  }                                                 
  else 
  {
    //If the rootNode has a data match with get data function
    if (data == rootNode->getData()) 
    {                                          
      //Makes a rootNew Node
      BTNode<valueType> rootNew("");                                      
      //The new rootNew Nodes left child is now oldRoot
      rootNew.setLeft(rootNode);                 
      //Removing the oldRoot Node
      BTNode<valueType>* rmNode= rootNode->remove(data, &rootNew);         
      //Assigning rootNew to rootnode
      rootNode = rootNew.getLeft();                                         
      if (rmNode != NULL) 
      {
        // Deletes Node
        delete rmNode;                                                  
        //Return true
        return true;                                                    
      }
      else
      { 
        //Return flase
        return false; 
      }                                                                
    } 
    else 
    {                                                                                     
      //Deleting the targeted Node with remove Node funtion
      BTNode<valueType>* rmNode = rootNode->remove(data, NULL);             
      //If the oldRoot is not NULL  
      if (rmNode != NULL) 
      {                                                 
        //Delete the required Node
        delete rmNode;
        //Return true
        return true;                                                    
      } 
      else
      { 
        //Return false
        return false; 
      }                                                                   
    }
  }
}   

//Removing the Node Function
template <class valueType>
void BSTree<valueType>::Node_Remove(BTNode<valueType>* Node)
{
  //If the Node has no Nodes
  if(Length < 1)
  {                                                                       
    //Return to console
    return;
  }   
  //If the tree has more than root node
  else if(Length > 1)
  {                                                                 
    //If the left Node is not NULL
    if(Node->getLeft() != NULL)
    {                                                 
      //Remove the data in left Node
      remove(Node->getLeft()->getData()); 
      //Remove left Node
      Node_Remove(Node->getLeft());                                       
    }
    //If the right Node is not NULL
    else if(Node->getRight() != NULL)
    {                                              
      //Remove the data in right Node
      remove(Node->getRight()->getData());
      //Remove right Node
      Node_Remove(Node->getRight());
    }
  }
  //RootNode deleted
  delete rootNode;  
  //Set root to NULL                                                          
  rootNode = NULL;   
  //Decrease tree length                                             
  Length--;              
  //Return to console                 
  return;
}

//Print function
template <class valueType>
void BSTree<valueType>::print()
{
  //Recrusive Function and Printing everything in the tree
  Seeker(rootNode);                                                       
}

//Overload operator
template <class valueType>
ostream& operator<<(ostream& stream, BSTree<valueType>& Tree)
{
  //Calling print function to stream
  Tree.print();
  //return the stream                                        
  return stream;                     
} 