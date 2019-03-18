#ifndef CHICKEN_HPP
#define CHICKEN_HPP

#include "EggProducingAnimal.hpp"
#include "MeatProducingAnimal.hpp"

class Chicken : public EggProducingAnimal, public MeatProducingAnimal {
    public:
        Chicken();                  // creates new chicken at default position I, J
        std::string getNoise();     // returns animal's noise (chicken = "bok bok bok") 
        int getAllowedLand();       // returns index of allowed land type (coop = 3)
        float getHungerRate();        // returns rate of hunger increase (chicken = 1)
};

#endif