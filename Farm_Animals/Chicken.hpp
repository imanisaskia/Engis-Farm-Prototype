#ifndef CHICKEN_HPP
#define CHICKEN_HPP

#include "EggProducingAnimal.hpp"
#include "MeatProducingAnimal.hpp"

class Chicken : public EggProducingAnimal, public MeatProducingAnimal {
    private:
        int I, J;           /* animal position */
        float Hunger;       /* animal hunger level: 0...10; if >5, hungry */
        bool Productive;    /* animal's availibility to produce */
        
    public:
        /* creates new chicken at default position I, J */
        Chicken();

        /* assignment operator */
        Chicken& operator=(Chicken& C);

        /* returns animal's noise (chicken = "Bok bok bok!") */
        std::string getNoise();
        
        /* returns index of allowed land type (coop = 3) */
        int getAllowedLand();
        
        /* returns rate of hunger increase (chicken = 1) */
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