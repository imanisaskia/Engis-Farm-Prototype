#ifndef GOAT_HPP
#define GOAT_HPP

#include "MilkProducingAnimal.hpp"
#include "MeatProducingAnimal.hpp"

class Goat : public MilkProducingAnimal, public MeatProducingAnimal {
    public:
        /* creates new goat at default position I, J */
        Goat();

        /* returns animal's noise (goat = "Meh-eh-eh!") */
        std::string getNoise();
        
        /* returns index of allowed land type (barn = 2) */
        int getAllowedLand();
        
        /* returns rate of hunger increase (goat = 0.3) */
        int getHungerRate();
};

#endif