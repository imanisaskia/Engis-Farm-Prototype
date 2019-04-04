#include "Grid.hpp"
#include "..\Farm Animals\FarmAnimal.hpp"
#include "..\Farm Animals\AnimalArray.hpp"

#include "..\Bag.hpp"
#include <string>
#include <iostream>

class UI{
        public :
                void Clear();

                void updateMap(int m, int w, Bag<SidePoduct*> sp, Bag<FarmProduct*> fp);
                //Check what's in every grid of the map

                void Print(int i, int j);
                //Print every Grid in Map and what's in it with specified layout
                //i and j describes the player position

                void printSentences(std::string);
                //  Print any sentences from the game that's need to be printed in a specified area
                // e.g : print sound of the animals

                std::string getCommand();               
                //read User input

                void printTitle();
                //print Title

                void printOver();
                //print for game over

}