/*
File Name: HTable.hpp
Stephen Watson c3339952 
Seng 1120 Assignment 3 - binary tree & hashtable 
*/ 
using namespace std;

//Default Constructors
template <class valueType>
HTable<valueType>::HTable()
{
	//Establishing the tablesize of 150
	for(int i = 0; i < 150; i++)
	{
		//Storing tablesize into interger array
		array[i] = 0;						
	}
}

// Destructors
template <class valueType>
HTable<valueType>::~HTable()
{ 
	//Looping through the table 
	for(int i = 0; i < 150; i++)
	{
		//Setting string variables to empty
		name[i] = '\0';					
		//Setting storage array to 0
		array[i] = 0;						
	}
}

// add Function
template <class valueType>
void HTable<valueType>::add(valueType key)
{
	//Variables are hashed and given a value which is stored in that bucket in the data table
	name[hashfun(key)] = key;

	//If the storage array is not empty and has a value 1 it indicates that position has stored data 
	array[hashfun(key)] = 1;
}																								

//Remove Function
template <class valueType>
void HTable<valueType>::remove(valueType key)
{ 
	//Variables are hashed and that bucket is set to empty within the hashtable 
	name[hashfun(key)] = '\0'; 
	//That position in the storage array is also set to empty 
	array[hashfun(key)] = 0;
}	
	 																							
// Search Function
template <class valueType>
bool HTable<valueType>::search(valueType key)
{ 
	//key data is hashed to check if its value is inside the name array in the haashtable
	if(name[hashfun(key)] == key)
	{																		
		//If there is a match of values this value is returned true
		return true;																						
	}
	else
	{
		//If there is no match of values this is returned false
		return false;
	}
}

//Get data function
template <class valueType>
valueType HTable<valueType>::getData(int key)
{ 
	//If the storage array equals one it has a name key allocated 
	if(array[key] == 1)
	{ 
		//Return the name key data inside the array
		return name[key];	
	}									
	else
	{ 
		//If the storage array is not equal to one the key value should be empty and just return empty string
		return string(); 
	}								
}

//Hash function used to take strings and return the value of the strings
template <class valueType>
int HTable<valueType>::hashfun(string value)
{ 
	//Initialising addResult to 0;
	int addResult = 0;
	//If the string value is not empty, increase the value length 
	for(int i = 0; value[i] != '\0'; i++)
	{	
		//Assigning the length of value to int addResult every time it loops through
		addResult = addResult + value[i];
	}
	//Retruning the sum of the string value to addResult which becomes an int
	return addResult % 150; 
}

//Operator overloading
template <class valueType>
ostream& operator <<(ostream& out, HTable<valueType>& Table)
{
	//Looping through the table
	for(int i = 0; i < 150; i++)
	{
		//If templated temp is assigned the hashtables data 
		valueType temp = Table.getData(i);																	
		//If temp is not an empty string 
		if(temp != std ::string())
		{
			//Print temp
			out << temp << " ";
		}																	
	}
	//Return the stream
	return out;									    													
}