
//File name: Node.hpp
//Stephen Watson C3339952
//Seng1120 Assignment 2 Template
 
    #include <cstdlib>
    #include <iostream>
    #include <sstream>
    #include <string>
   
    using namespace std;
    
    //default constructor template
    template <class data_type>
    Node<data_type>::Node(const data_type& Data, Node* Next, Node* Previous)
    {
        // Setter for previous
        previous = Previous; 
        // Setter for data
        data = Data; 
        // Setter for next      
        next = Next; 
        
    }
    //Destructor sets the pointers to null and clears the memory off the heap
    template <class data_type>
    Node<data_type>::~Node()
    {        
       
        previous = NULL;  
        next = NULL; 
    }
    //setter for data
    template <class data_type>
    void Node<data_type>::setData(const data_type& Data)
    {
        data = Data; 
    }
    //Setter for the next pointer
    template <class data_type>
    void Node<data_type>::setNext(Node* Next)
    {
        next = Next;  
    }
    //setter for previous pointer
    template <class data_type>
    void Node<data_type>::setPrevious(Node* Previous)
    {
        previous = Previous;  
    }
    //Getter for data 
    template <class data_type>
    data_type Node<data_type>::getData() const
    {
        return data;  
    }
    //Getter for Previous pointer   
    template <class data_type>
    Node<data_type>* Node<data_type>::getPrevious () const
    {
        return previous;  
    }
    // Getter for Next pointer 
    template <class data_type>
    Node<data_type>* Node<data_type>::getNext() const
    {
        return next;  
    }
    // Returns data size
    template <class data_type>
    int Node<data_type>::get_data_size()
    {
        return data.get_size();
    }