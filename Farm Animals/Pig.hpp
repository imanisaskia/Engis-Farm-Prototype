#ifndef PIG_HPP
#define PIG_HPP

#include "MeatProducingAnimal.hpp"

class Pig : public MeatProducingAnimal {
    public:
        /* creates new pig at default position I, J */
        Pig();
        
        /* returns animal's noise (pig = "Oink oink!") */
        std::string getNoise();
        
        /* returns index of allowed land type (grassland = 1) */
        int getAllowedLand();
        
        /* returns rate of hunger increase (pig = 0.6) */
        int getHungerRate();
};

#endif