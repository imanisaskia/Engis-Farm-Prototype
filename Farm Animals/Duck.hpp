#ifndef DUCK_HPP
#define DUCK_HPP

#include "EggProducingAnimal.hpp"
#include "MeatProducingAnimal.hpp"

class Duck : public EggProducingAnimal, public MeatProducingAnimal {
    public:
        /* creates new duck at default position I, J */
        Duck();
        
        /* returns animal's noise (duck = "Quack!") */
        std::string getNoise();

        /* returns index of allowed land type (coop = 3) */
        int getAllowedLand();
        
        /* returns rate of hunger increase (duck = 0.75) */
        float getHungerRate();
};

#endif