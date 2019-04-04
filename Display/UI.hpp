#include "../Farm Animals/FarmAnimal.hpp"
#include "../Farm Animals/AnimalArray.hpp"
#include "../Side_Product/SideProduct.hpp"
#include "../Farm_Product/FarmProduct.hpp"
#include "../Bag.hpp"
#include <string>
#include <iostream>

class UI{
        public :
                void Clear();

                void UI::updateMap(int m, int w, Bag<SidePoduct*> sp, Bag<FarmProduct*> fp, AnimalArray<Chicken> c, AnimalArray<Cow> s, AnimalArray<Duck> d, AnimalArray<Rabbit> r, AnimalArray<Pig> p, AnimalArray<Goat> g);
                //Check what's in every grid of the map

                void UI::Print(int ip, int jp, Display D);
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

};