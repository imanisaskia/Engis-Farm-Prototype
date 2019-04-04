#ifndef FARMANIMAL_HPP
#define FARMANIMAL_HPP

#include <string>
#include "../Display/Grid.hpp"
#include "AnimalArray.hpp"

class FarmAnimal {
    public:
        /* returns animal row position */
        virtual int getI() = 0;
        /* returns animal column position */
        virtual int getJ() = 0;
        /* returns animal hunger */
        virtual int getHunger() = 0;
        /* returns animal's availability to produce */
        virtual bool isProductive() = 0;

        virtual std::string getNoise() = 0; /* returns noise of animal */
        virtual int getAllowedLand() = 0;   /* returns type of land animal is allowed to move to */
        virtual float getHungerRate() = 0;  /* returns the hunger rate of animal */

        /* sets productivity to false */
        virtual void setUnproductive() = 0;

        /* if animal not hungry, increase by certain value; if hungry, increase by 1 */
        virtual void GetHungrier() = 0;
        
        /* animal eats grass from its grid, hunger = 0, animal turns productive */
        virtual void Eat(Grid** Map) = 0;
};

#endif