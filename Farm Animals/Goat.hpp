#ifndef GOAT_HPP
#define GOAT_HPP

#include "MilkProducingAnimal.hpp"
#include "MeatProducingAnimal.hpp"

class Goat : public MilkProducingAnimal, public MeatProducingAnimal {
    private:
        int I, J;           /* animal position */
        float Hunger;       /* animal hunger level: 0...10; if >5, hungry */
        bool Productive;    /* animal's availibility to produce */
        
    public:
        /* creates new goat at default position I, J */
        Goat();

        /* returns animal's noise (goat = "Meh-eh-eh!") */
        std::string getNoise();
        
        /* returns index of allowed land type (barn = 2) */
        int getAllowedLand();
        
        /* returns rate of hunger increase (goat = 0.3) */
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
        void Eat(Grid** Map);
};

#endif