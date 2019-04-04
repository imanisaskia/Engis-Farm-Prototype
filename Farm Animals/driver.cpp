#include <string>
#include <iostream>
using namespace std;

#include "AnimalArray.hpp"
#include "FarmAnimal.hpp"
#include "EggProducingAnimal.hpp"
#include "MeatProducingAnimal.hpp"
#include "MilkProducingAnimal.hpp"
#include "Chicken.hpp"
#include "Duck.hpp"
#include "Cow.hpp"
#include "Goat.hpp"
#include "Pig.hpp"
#include "Rabbit.hpp"

int main() {
    AnimalArray<Chicken> Chickens();
    AnimalArray<Duck> Ducks();
    AnimalArray<Cow> Cows();
    AnimalArray<Goat> Goats();
    AnimalArray<Pig> Pigs();
    AnimalArray<Rabbit> Rabbits();
    String command;

    do {
        cin << command;
        if (command == "t") {
            Chickens.TickArray();
            Ducks.TickArray();
            Cows.TickArray();
            Goats.TickArray();
            Pigs.TickArray();
            Rabbits.TickArray();
        }
        if (command == "g") {
            int i, j;
            cin << i;
            cin << j;

        }
        
    } while (command != "q");

    return 0;
}