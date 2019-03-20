#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "Grid.hpp"
#include "../Farm Animals/FarmAnimal.hpp"
#include "../Farm Animals/AnimalArray.hpp"
#include "../Player.hpp"
#include <string>

template <class T>
class Display {
	public:
		Display(std::string);
		//Fill Map from an external file
		//string input is the name of the external file
		//Command is set to ""

		bool checkLand(int i, int j, int type);
		//Check Land or not
	
		bool checkFacility(int i, int j, int type);
		//Check Facility
	
		void modifyGrassy(int i, int j);
		//modify Grassy
	
		void modifyUsedTruck(int i, int j);
	
		void Clear();
		//Makes all Grid as default (empty)

		bool checkAnimal(AnimalArray<T>);

		void updateMap();
		//Check what's in every grid of the map

		void Print();
		//Print every Grid in Map and what's in it with specified layout

		void printSentences(std::string);
		//	Print any sentences from the game that's need to be printed in a specified area
		// e.g : print sound of the animals

		void std::string getCommand();		
		//read User input

    private:
        Grid **Map ; //From external file 
        std::string Command;     // user input
};


#endif
