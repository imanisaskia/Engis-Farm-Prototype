#ifndef COW_HPP
#define COW_HPP

#include "MilkProducingAnimal.hpp"
#include "MeatProducingAnimal.hpp"

class Cow : public MilkProducingAnimal, public MeatProducingAnimal {
    private:
        int I, J;           /* animal position */
        float Hunger;       /* animal hunger level: 0...10; if >5, hungry */
        bool Productive;    /* animal's availibility to produce */
        
    public:
        /* creates new cow at default position I, J */
        Cow();

        /* assignment operator */
        Cow& operator=(Cow& C);
        
        /* returns animal's noise (cow = "Moo!") */
        std::string getNoise();
        
        /* returns index of allowed land type (barn = 2) */
        int getAllowedLand();

        /* returns rate of hunger increase (cow = 0.2) */
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