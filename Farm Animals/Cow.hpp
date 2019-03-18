#ifndef COW_HPP
#define COW_HPP

#include "MilkProducingAnimal.hpp"
#include "MeatProducingAnimal.hpp"

class Cow : public MilkProducingAnimal, public MeatProducingAnimal {
    public:
        std::string getNoise();      // returns animal's noise (cow = "moo-oo-oo")
        int getAllowedLand();       // returns index of allowed land type (barn = 2)
};

#endif