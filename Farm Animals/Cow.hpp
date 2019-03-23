#ifndef COW_HPP
#define COW_HPP

#include "MilkProducingAnimal.hpp"
#include "MeatProducingAnimal.hpp"

class Cow : public MilkProducingAnimal, public MeatProducingAnimal {
    public:
        /* creates new cow at default position I, J */
        Cow();
        
        /* returns animal's noise (cow = "Moo!") */
        std::string getNoise();
        
        /* returns index of allowed land type (barn = 2) */
        int getAllowedLand();

        /* returns rate of hunger increase (cow = 0.2) */
        int getHungerRate();
};

#endif