#ifndef RABBIT_HPP
#define RABBIT_HPP

#include "MeatProducingAnimal.hpp"

class Rabbit : public MeatProducingAnimal {
    public:
        /* creates new rabbit at default position I, J */
        Rabbit();
        
        /* returns animal's noise (rabbit = "Purr") */
        std::string getNoise();
        
        /* returns index of allowed land type (grassland = 1) */
        int getAllowedLand();
        
        /* returns rate of hunger increase (rabbit = 0.5) */
        int getHungerRate();
};

#endif