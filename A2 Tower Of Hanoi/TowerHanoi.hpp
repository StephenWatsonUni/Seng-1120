
//File name: TowerHanoi.hpp
//Stephen Watson C3339952
//Seng1120 Assignment 2 Template
 
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include "DiscInt.h"
#include "DiscString.h"
#include "TowerHanoi.h"

using namespace std;
//Default constructor
template<class data_type>
TowerHanoi<data_type>::TowerHanoi() 
{
	//creating RodOne on the heap 
	RodOne = new LStack<data_type>();
	//creating RodTwo on the heap
	RodTwo = new LStack<data_type>();
	//creating RodThree on the heap
	RodThree = new LStack<data_type>();

	//initialising the number of discs
	numberOfDiscs = 0; 
}
//Parametrised Constructor
template<class data_type>
TowerHanoi<data_type>::TowerHanoi(int data) 
{
	//creating RodOne on the heap
	RodOne = new LStack<data_type>();
	//creating RodTwo on the heap
	RodTwo = new LStack<data_type>();
	//creating RodThree on the heap
	RodThree = new LStack<data_type>();
	//initialising the number of discs 
	//Assigning the numberOfDiscs to data
	numberOfDiscs = data;

	//Switch statement that is loading all the discs
	//allows the game to play between 1 to 5 discs  
	switch (data) 
	{
	case 1:
		RodOne->push(1);
		break;
	case 2:
		RodOne->push(2);
		RodOne->push(1);
		break;
	case 3:
		RodOne->push(3);
		RodOne->push(2);
		RodOne->push(1);
		break;
	case 4:
		RodOne->push(4);
		RodOne->push(3);
		RodOne->push(2);
		RodOne->push(1);
		break;
	case 5:
		RodOne->push(5);
		RodOne->push(4);
		RodOne->push(3);
		RodOne->push(2);
		RodOne->push(1);
		break;

	default:
		break;
	}
}
// destructor
template<class data_type>
TowerHanoi<data_type>::~TowerHanoi() 
{
	//Sets the rods to Null
	RodOne = NULL;
	RodTwo = NULL;
	RodThree = NULL;

	//Deletes the rods
	delete RodOne;
	delete RodTwo;
	delete RodThree;
}
//Getter for RodOne
template<class data_type>
LStack<data_type>* TowerHanoi<data_type>::get_RodOne() 
{
	//Returns RodOne
	return RodOne;
}
//Getter for RodTwo
template<class data_type>
LStack<data_type>* TowerHanoi<data_type>::get_RodTwo() 
{
	//Returns RodTwo
	return RodTwo;
}
//Getter for RodThree
template<class data_type>
LStack<data_type>* TowerHanoi<data_type>::get_RodThree() 
{
	//Returns RodThree
	return RodThree;
}
//Getter for the discs
template<class data_type>
int TowerHanoi<data_type>::getDiscs() const 
{
	//Returns numnberOfDiscs
	return numberOfDiscs;
}
//Move function
template<class data_type>
void TowerHanoi<data_type>::move(int rodFrom, int rodTo) 
{
	//If RodFrom to RodTo are equal
	if (rodFrom == rodTo)
	{
		//Invalid move message 
		cout << "Invalid move! Disc staying on this rod"<< endl;
		//line spacing for improved looks of the game
		cout <<"\n" << endl;
		return;
		
	}
	//The confirmed move method is called to check all moves made are valid moves
	else if(Confirm_move(rodFrom, rodTo)) 
	{
		//if users selects to move from RodOne to RodTwo
		if (rodFrom == 1 && rodTo == 2) 
		{
			//temp is created and returns head node data of RodONe 
			data_type temp = RodOne->top();
			//The chosen disc is loaded onto RodTwo
			RodTwo->push(temp);
			//RodOnes data is taken from the head and RodOne head node is removed
			RodOne->pop();
				
		} 
		//if users selects to move from RodTwo to RodOne
		else if (rodFrom == 2 && rodTo == 1) 
		{	
			//RodTwo data is taken from the head and RodTwo head node is removed
			data_type temp = RodTwo->pop();
			//The chosen disc is loaded onto RodOne
			RodOne->push(temp);
		} 
		//if users selects to move from RodTwo to RodThree
		else if (rodFrom == 2 && rodTo == 3) 
		{
			//RodTwo data is taken from the head and RodTwo head node is removed
			data_type temp = RodTwo->pop();
			//The chosen disc is loaded onto RodThree
			RodThree->push(temp);
		} 
		//if users selects to move from RodThree to RodTwo
		else if (rodFrom == 3 && rodTo == 2) 
		{
			//RodThree data is taken from the head and RodThree head node is removed
			data_type temp = RodThree->pop();
			//The chosen disc is loaded onto RodTwo
			RodTwo->push(temp);
		} 
		//if users selects to move from RodThree to RodOne
		else if (rodFrom == 3 && rodTo == 1) 
		{
			//RodThree data is taken from the head and RodThree head node is removed
			data_type temp = RodThree->pop();
			//The chosen disc is loaded onto RodOne
			RodOne->push(temp);
		} 
		//if users selects to move from RodOne to RodThree
		else if (rodFrom == 1 && rodTo == 3) 
		{
			//RodOne data is taken from the head and RodOne head node is removed
			data_type temp = RodOne->pop();
			//The chosen disc is loaded onto RodThree
			RodThree->push(temp);
		}
	} 
	else 
	{
		return;
	}
	//line spacing for improved looks of the game
	cout <<"\n" << endl;
}
//Check Win function 
template<class data_type>
bool TowerHanoi<data_type>::checkWin() const 
{
	if (RodThree->length()==numberOfDiscs) 
	{
		//If RodThree has all the discs check win returns true
		return true;
	}
	else
	{	
		// any other condition will return false
		return false;
	}
	
}
//Confirm move function
template<class data_type>
bool TowerHanoi<data_type>::Confirm_move(int rodFrom, int rodTo) const 
{
	
	//convert to stack
	LStack<data_type>* From;
	LStack<data_type>* To;
	
	//Condition to ensure no numners outside of 1 -5 can not be selected
	if(0 < rodFrom && rodFrom < 4 && 0 < rodTo && rodTo < 4)
	{
		//line spacing for improved looks of the game
		cout <<"\n" << endl;

		//Switch statement for the three rodfroms
		switch (rodFrom) 
		{
		case 1:
			From = RodOne;
			break;
		case 2:
			From = RodTwo;
			break;
		case 3:
			From = RodThree;
			break;
		}
		
		//Switch statement for the three rodTos
		switch (rodTo) 
		{
		case 1:
			To = RodOne;
			break;
		case 2:
			To = RodTwo;
			break;
		case 3:
			To = RodThree;
			break;
		}
		//if the from length is 0
		if(From->length() == 0) 
		{
			//No discs on the rod messaqge alert
			cout << "Invalid move! No discs available in rod "<< rodFrom << endl;
			//Extra line for spacing to improve game looks
			cout <<"\n" << endl;
			//retrun this condition as false
			return false;
		}
		//if the returned disc size on from is greater than the retrurned disc size of To
		//and To does has discs on it
		else if(From->peek() > To->peek() && To->peek()!=0)
		{
			//message alert to say you can not put larger disc on a smaller disc
			cout << "Invalid move! Cannot place a larger disc onto a smaller disc" << endl;
			//Extra spacing line to improve game looks
			cout <<"\n" << endl;
			//Return this condition as false
			return false;
		}
		else
		{
			//Otherwise every other move is valid 
			cout << "vaild move" << endl;
			//Extra spacing line to improve game looks
			cout <<"\n" << endl; 
			//This condition is returned true and therefore excepted by the switch
			return true;
		}
		//Return all this back to the console
		//all this code will exacute first as it is inside the initial if statement
		return true;	
	}
	//Any other condition that is possible out side of the above if will return this else
	else 
	{
		//Extra spacing line to improve game looks
		cout <<"\n" << endl;
		//Invalid move message alert as an incorrect input was chosen
		cout << " Invalid move!! Input must be Rod 1, Rod  2, Rod  3 " << endl;
		//Extra spacing line to improve game looks
		cout <<"\n" << endl;
		//Return this condition as false
		return false;
	}	
}
//Operator
template<class data_type>
std::ostream& operator<<(std::ostream& stream, TowerHanoi<data_type> tower) 
{
	//Creating 3 tower objects
	LStack<data_type> temp1 = LStack<data_type>(tower.get_RodOne());
	LStack<data_type> temp2 = LStack<data_type>(tower.get_RodTwo());
	LStack<data_type> temp3 = LStack<data_type>(tower.get_RodThree());

	//Assigning the lengths as ints
	int length1;	
	int length2;
	int length3;
	
	//Assigning the lengths to objects
	length1 = temp1.length();
	length2 = temp2.length();
	length3 = temp3.length();
	data_type data;

	//if x equals towers get discs and x is greater than zero decrease x
	for (int x = tower.getDiscs(); x > 0; x--) 
	{
		//Stream oit the string and spacing
		stream << " "; 

		if (length1 == x) 
		{
			//stream temp1 returned data and print
			stream << temp1.top().print(1);
			//Get the data from temp1 head node then remove head node
			temp1.pop();
			//Decrease the length
			length1--;

		} 
		else 
		{	//else the Rod is empty and stream the empty Rod
			//This is set spacing so everything lines up
			stream << "     |    ";
		}
		
		if (length2 == x) 
		{
			//stream temp2 returned data and print
			stream << temp2.top().print(1);
			//Get the data from temp2 head node then remove head node
			temp2.pop();
			//Decrease the length
			length2--;
		} 
		else 
		{
			//else the Rod is empty and stream the empty Rod
			//This is set spacing so everything lines up
			stream << "     |    ";
		}

		if (length3 == x) 
		{
			//stream temp3 returned data and print
			stream << temp3.top().print(1);
			//Get the data from temp3 head node then remove head node
			temp3.pop();
			//Decrease the length
			length3--;
		} 
		else 
		{
			//else the Rod is empty and stream the empty Rod
			//This is set spacing so everything lines up
			stream << "     |    ";
		}
		// end the stream
		stream << endl;
	}
	//Stream the flat line for looks
	stream << "_________________________________" << endl;
	//Stream the Rod numbers and have rods line up with those numbers 
	stream << "      1         2         3 " << endl;
	//Return the stream
	return stream;
}