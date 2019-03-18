#ifndef COW_HPP
#define COW_HPP

#include "MilkProducingAnimal.hpp"
#include "MeatProducingAnimal.hpp"

class Cow : public MilkProducingAnimal, public MeatProducingAnimal {
    public:
        Cow();                      // creates new cow at default position I, J
        std::string getNoise();     // returns animal's noise (cow = "moo-oo-oo")
        int getAllowedLand();       // returns index of allowed land type (barn = 2)
        int getHungerRate();        // returns rate of hunger increase (cow = 0.2)
};

#endif