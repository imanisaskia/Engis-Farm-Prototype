#ifndef GOAT_HPP
#define GOAT_HPP

#include "MilkProducingAnimal.hpp"
#include "MeatProducingAnimal.hpp"

class Goat : public MilkProducingAnimal {
    public:
        Goat();                     // creates new goat at default position I, J
        std::string getNoise();     // returns animal's noise (goat = "meh-eh-eh-eh")
        int getAllowedLand();       // returns index of allowed land type (barn = 2)
        int getHungerRate();        // returns rate of hunger increase (goat = 0.3)
};

#endif