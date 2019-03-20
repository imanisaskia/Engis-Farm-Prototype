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

		Clear();
		//Makes all Grid as default (empty)

		checkAnimal(AnimalArray<T>);

		updateMap();
		//Check what's in every grid of the map

		Print();
		//Print every Grid in Map and what's in it with specified layout

		printSentences(std::string);
		//	Print any sentences from the game that's need to be printed in a specified area
		// e.g : print sound of the animals

		std::string getCommand();		
		//read User input

    private:
        Grid **Map ; //From external file 
        std::string Command;     // user input
};


#endif
