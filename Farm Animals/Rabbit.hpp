#ifndef RABBIT_HPP
#define RABBIT_HPP

#include "MeatProducingAnimal.hpp"

class Rabbit : public MeatProducingAnimal {
    public:
        Rabbit();                   // creates new rabbit at default position I, J
        std::string getNoise();     // returns animal's noise (rabbit = "purrrrr")
        int getAllowedLand();       // returns index of allowed land type (grassland = 1)
        int getHungerRate();        // returns rate of hunger increase (rabbit = 0.5)
};

#endif