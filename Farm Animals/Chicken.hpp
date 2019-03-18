#ifndef CHICKEN_HPP
#define CHICKEN_HPP

#include "EggProducingAnimal.hpp"
#include "MeatProducingAnimal.hpp"

class Chicken : public EggProducingAnimal, public MeatProducingAnimal {
    public:
        std::string getNoise();     // returns animal's noise (chicken = "bok bok bok") 
        int getAllowedLand();       // returns index of allowed land type (coop = 3)
};

#endif