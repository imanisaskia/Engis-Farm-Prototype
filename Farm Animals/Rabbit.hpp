#ifndef RABBIT_HPP
#define RABBIT_HPP

#include "MeatProducingAnimal.hpp"

class Rabbit : public MeatProducingAnimal {
    public:
        std::string getNoise();      // returns animal's noise (rabbit = "purrrrr")
        int getAllowedLand();       // returns index of allowed land type (grassland = 1)
};

#endif