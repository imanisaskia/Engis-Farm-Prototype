#ifndef CHICKEN_HPP
#define CHICKEN_HPP

#include "EggProducingAnimal.hpp"
#include "MeatProducingAnimal.hpp"

class Chicken : public EggProducingAnimal, public MeatProducingAnimal {
    public:
        /* creates new chicken at default position I, J */
        Chicken();

        /* returns animal's noise (chicken = "Bok bok bok!") */
        std::string getNoise();
        
        /* returns index of allowed land type (coop = 3) */
        int getAllowedLand();
        
        /* returns rate of hunger increase (chicken = 1) */
        float getHungerRate();
};

#endif