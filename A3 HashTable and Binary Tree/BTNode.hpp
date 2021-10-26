/*
File Name: BTNode.hpp
Stephen Watson c3339952 
Seng 1120 Assignment 3 - binary tree & hashtable 
*/ 

#include <cstdlib>
#include <iostream>

using namespace std;

//Default constructor
template <class valueType>
BTNode<valueType>::BTNode()
{
  //Initalise data as NULL
  data = NULL;
  //Initalise root as NULL
  root = NULL;
  //Initalise left child as NULL
  left = NULL;
  //Initalise right child as NULL                                                    
  right = NULL;
}

//parameterised constructor
template <class valueType>
BTNode<valueType>::BTNode(const valueType& initialData)
{
  //Initalise data as the input
  data = initialData;
  //Initalise root as NULL
  root = NULL;
  //Initalise left child as NULL
  left = NULL;                                                    
  //Initalise Right child as NULL
  right = NULL;
}

//Destructor
template <class valueType>
BTNode<valueType>::~BTNode()
{
  //Setting the root to NULL
  root = NULL;
  //Setting the left to NULL
  left = NULL;
  //Setting the right to NULL                                                   
  right = NULL;
}

//Setter function for data
template <class valueType>
void BTNode<valueType>::setData(const valueType& newData)
{
  //Assigning data entered to data
  data = newData;                                                 
}

//Setter function for root
template <class valueType>
void BTNode<valueType>::setroot(BTNode<valueType>* newroot)
{
  //Assigning root pointer
  root = newroot;
}

//Setter function for left child
template <class valueType>
void BTNode<valueType>::setLeft(BTNode<valueType>* newLeft)
{
  //Assigning left pointer
  left = newLeft;                                                 
} 

//Setter function for the right child
template <class valueType>
void BTNode<valueType>::setRight(BTNode<valueType>* newRight)
{
  //Assigning right pointer
  right = newRight;          
}

//Getter for data
template <class valueType>
valueType BTNode<valueType>::getData()
{
  //returns the data stored
  return data;                                                    
}

//Getter for root
template <class valueType>
BTNode<valueType>* BTNode<valueType>::getroot()
{
  //returns the root
  return root;                                                    
}

//Getter for left child data
template <class valueType>
BTNode<valueType>* BTNode<valueType>::getLeft()
{
  //Returns left child
  return left;                                                    
}

//Getter for right child data
template <class valueType>
BTNode<valueType>* BTNode<valueType>::getRight()
{
  //Returns right child
  return right;                                                         
}

//checking for leaf nodes
template <class valueType>
valueType BTNode<valueType>::findSmallest() 
{ 
    // If there are no no more leaf nodes return currents data
    if(left == NULL)
    { 
      return data; 
    }     
    else
    { 
      //keep checking for leaf nodes until there are none
      return left->findSmallest(); 
    }      
}

template <class valueType>
BTNode<valueType>* BTNode<valueType>::remove(valueType data, BTNode<valueType> *root) 
{
  //Checks the left of the tree
  if (data < this->data) 
  {
    //If the left side is not NULL it moves down the tree
    if(left != NULL)
    { 
      //removes the data on the left
      return left->remove(data, this); 
    }            
    else
    { 
      //Nothing to return
      return NULL; 
    }             
  } 
  //Checks the left of the tree
  else if (data > this->data) 
  {                                          
    //If the right side is not NULL
    if(right != NULL)
    { 
      //removes the data on the right
      return right->remove(data, this); 
    }        
    else
    { 
      return NULL; 
    }                  
  } 
  else 
  {
    //Checking bothsides are not NULL for two children
    if(left != NULL && right != NULL) 
    {                            
      //Assigning current nodes data to the smallest child on the right 
      this->data = right->findSmallest();
      //The data from the smallest child is removed                           
      return right->remove(this->data, this);                
    } 
    // remove this node and set its child to its positin
    else if (root->left == this) 
    {                                
      //If the left is not NULL
      if(left != NULL) 
      { 
        //Assigning left to roots left
        root->left = left;
      }                  
      else 
      { 
        //Assign right to roots left
        root->left = right; 
      }
      //Return this to console
      return this;
    } 
    //remove this node and set its child to its positin
    else if (root->right == this)
    {                               
      //If the left is not NULL
      if(left != NULL) 
      { 
        //Assign left to root right
        root->right = left; 
      } 
      else 
      { 
        //Assign right to roots right
        root->right = right; 
      }
    //Return this to console
    return this;
    }
  }
  //Return this to console
  return this;                                                          
}