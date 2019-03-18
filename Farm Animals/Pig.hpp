#ifndef PIG_HPP
#define PIG_HPP

#include "MeatProducingAnimal.hpp"

class Pig : public MeatProducingAnimal {
    public:
        Pig();                      // creates new pig at default position I, J
        std::string getNoise();     // returns animal's noise (pig = "oink oink")
        int getAllowedLand();       // returns index of allowed land type (grassland = 1)
};

#endif