#ifndef PIG_HPP
#define PIG_HPP

#include "MeatProducingAnimal.hpp"

class Pig : public MeatProducingAnimal {
    private:
        int I, J;           /* animal position */
        float Hunger;       /* animal hunger level: 0...10; if >5, hungry */
        bool Productive;    /* animal's availibility to produce */

    public:
        /* creates new pig at default position I, J */
        Pig();

        /* assignment operator */
        //Pig& operator=(Pig& P);

        /* returns animal's noise (pig = "Oink oink!") */
        std::string getNoise();

        /* returns index of allowed land type (grassland = 1) */
        int getAllowedLand();

        /* returns rate of hunger increase (pig = 0.6) */
        float getHungerRate();

        /* returns animal row position */
        int getI();
        /* returns animal column position */
        int getJ();
        /* returns animal hunger */
        int getHunger();
        /* returns animal's availability to produce */
        bool isProductive();

        /* sets animal position I and J */
        void setI(int);
        void setJ(int);

        /* sets productivity to false */
        void setUnproductive();

        /* if animal not hungry, increase by certain value; if hungry, increase by 1 */
        void GetHungrier();

        /* animal eats grass from its grid, hunger = 0, animal turns productive */
        void Eat(Display& D);
};

#endif
