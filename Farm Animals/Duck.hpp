#ifndef DUCK_HPP
#define DUCK_HPP

#include "EggProducingAnimal.hpp"
#include "MeatProducingAnimal.hpp"

class Duck : public EggProducingAnimal {
    public:
        Duck();                     // creates new duck at default position I, J
        std::string getNoise();     // returns animal's noise (duck = "quack quack")
        int getAllowedLand();       // returns index of allowed land type (coop = 3)
        float getHungerRate();        // returns rate of hunger increase (duck = 0.75)
};

#endif