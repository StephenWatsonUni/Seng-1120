
//File name: TowerHanoi.h
//Stephen Watson C3339952
//Seng1120 Assignment 2 Template


// Below is macroguard for TowerHanoi class
#ifndef Steve_Toh
#define Steve_Toh

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include "LStack.h"


using namespace std;

template <class data_type>
class TowerHanoi
{
	public: 
		
		//Default Constructor
		TowerHanoi();
		//Parametrised Constructor
		TowerHanoi(int data);
		//Destructor
		~TowerHanoi();
		
		//Pre-condition: rodOne has been set
		//Post-condition: Returns rodOne 
		LStack<data_type>* get_RodOne();
		
		//Pre-condition: RodTwo has been set
		//Post-condition: Returns RodTwo
		LStack<data_type>* get_RodTwo();
		
		//Pre-condition: RodThree has been set
		//Post-condition: Returns RodThree
		LStack<data_type>* get_RodThree();
		
		//Pre-condition: Discs have been initialised 
		//Post-condition Return the discs
		int getDiscs() const;
		
		//Pre-condition: A move has been requested
		//Post-condition A move has been made
		void move(int rodFrom, int rodTo);
		
		//Pre-condition: The game has finished and requested a check
		//Post-condition The games win has been approved 
		bool checkWin() const;
		
		//Pre-condition: A move has been requested
		//Post-condition The move has been confirmed as vaild and the move has been made
		bool Confirm_move(int RodFrom, int RodTo) const;
		 
	private: 
		//Private members
		//Number of discs  
		int numberOfDiscs;
		//RodOne
		LStack<data_type>* RodOne;
		//RodTwo
		LStack<data_type>* RodTwo;
		//RodThree
		LStack<data_type>* RodThree;
};

//Precondition: Towers are loaded
//Postcondition: Towers are printed  
template <class data_type>
std::ostream& operator<<(std::ostream& stream, TowerHanoi<data_type> tower);

#include "TowerHanoi.hpp"
#endif