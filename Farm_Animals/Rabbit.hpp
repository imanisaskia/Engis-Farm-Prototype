#ifndef RABBIT_HPP
#define RABBIT_HPP

#include "MeatProducingAnimal.hpp"

class Rabbit : public MeatProducingAnimal {
    private:
        int I, J;           /* animal position */
        float Hunger;       /* animal hunger level: 0...10; if >5, hungry */
        bool Productive;    /* animal's availibility to produce */
        
    public:
        /* creates new rabbit at default position I, J */
        Rabbit();

        /* assignment operator */
        Rabbit& operator=(Rabbit& R);
        
        /* returns animal's noise (rabbit = "Purr") */
        std::string getNoise();
        
        /* returns index of allowed land type (grassland = 1) */
        int getAllowedLand();
        
        /* returns rate of hunger increase (rabbit = 0.5) */
        float getHungerRate();

        /* returns animal row position */
        int getI();
        /* returns animal column position */
        int getJ();
        /* returns animal hunger */
        int getHunger();
        /* returns animal's availability to produce */
        bool isProductive();

        /* sets productivity to false */
        void setUnproductive();

        /* if animal not hungry, increase by certain value; if hungry, increase by 1 */
        void GetHungrier();
        
        /* animal eats grass from its grid, hunger = 0, animal turns productive */
        void Eat(Display& D);
};

#endif