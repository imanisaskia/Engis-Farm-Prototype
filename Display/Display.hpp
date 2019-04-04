#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "Grid.hpp"
#include "..\Farm Animals\FarmAnimal.hpp"
#include "..\Farm Animals\AnimalArray.hpp"
#include <string>
#include <iostream>

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
	
		bool checkGrassy(int i, int j);
		//Check Grassy
	
		bool checkUsedTruck(int i, int j);
		//Check UsedTruck
	
		void modifyGrassy(int i, int j);
		//modify Grassy
	
		void modifyUsedTruck(int i, int j);

		void Clear();
		//Makes all Grid as default (empty)
		/*
		Engi's Farm yayyy !

		_____________________________________________________________________________________________________
		| [o] | [o] | [o] | [o] | [-] | [-] | [-] | [-] | [-] | [-] | [-] | Inventory:                       |
		+-----+-----+-----+-----|-----|-----|-----|-----|-----|-----|-----|__________________________________|
		|  C  |  c  | [o] | [o] | [-] | [-] | [-] | [-] | [-] | [-] |  #  | Farm Product:                    |
		+-----+-----+-----+-----|-----|-----|-----|-----|-----|-----|-----| -                                |
		| [o] | [o] | [o] | [o] | [-] | [-] | [-] | [-] | [-] | [-] |  #  | -                                |
		+-----+-----+-----+-----|-----|-----|-----|-----|-----|-----|-----| -                                |
		| [o] | [o] | [o] | [o] | [-] | [-] | [-] |  #  | [-] | [-] |  #  | -                                |
		+-----+-----+-----+-----|-----|-----|-----|-----|-----|-----|-----| -                                |
		| [o] | [o] | [o] | [o] | [-] |  P  | [-] |  #  |  #  | [-] | [-] | -                                |
		|_____|_____|_____|_____|_____|_____|-----|-----|-----|-----|-----|__________________________________|
		| [x] | [x] | [x] | [x] | [x] | [x] | [-] | [-] | [-] | [-] | [-] | Side Product:                    |
		+-----+-----+-----+-----+-----+-----|-----|-----|-----|-----|-----| -                                |
		| [x] | [x] | [x] |  G  |  g  | [x] | [-] | [-] |  H  | [-] | [-] | -                                |
		+-----+-----+-----+-----+-----+-----|-----|-----|-----|-----|-----| -                                |
		| [x] | [x] | [x] | [x] | [x] | [x] | [-] | [-] |  h  | [-] | [-] | -                                |
		+-----+-----+-----+-----+-----+-----|-----|-----|-----|-----|-----| -                                |
		| [x] | [x] | [x] | [x] | [x] | [x] | [-] | [-] | [-] | [-] | [-] | -                                |
		+-----+-----+-----+-----+-----+-----|-----|-----|-----|-----|-----|__________________________________|
		| [x] | [x] | [x] | [x] | [x] | [x] | [-] | [-] | [-] | [-] | [-] | Money:                           |
		+-----+-----+-----+-----+-----+-----|-----|-----|-----|-----|-----|__________________________________|
		| [x] | [x] | [x] | [x] | [x] | [x] | [-] | [-] | [T] | [M] | [W] | Water:                           |
		|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|__________________________________|
		|Command : 		                                                                                       |
		|                                                                                                    |
		|____________________________________________________________________________________________________|
		*/
		bool checkAnimal(AnimalArray<FarmAnimal> X);

		void updateMap();
		//Check what's in every grid of the map

		void Print(Player P);
		//Print every Grid in Map and what's in it with specified layout

		void printSentences(std::string);
		//	Print any sentences from the game that's need to be printed in a specified area
		// e.g : print sound of the animals

		std::string getCommand();		
		//read User input

    private:
        Grid **Map ; //From external file 
        std::string Command;     // user input
};


#endif
