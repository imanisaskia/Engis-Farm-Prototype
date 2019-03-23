#ifndef FARMANIMAL_HPP
#define FARMANIMAL_HPP

#include <string>
#include "../Display/Grid.hpp"
#include "AnimalArray.hpp"

class FarmAnimal {
    private:
        int I, J;           /* animal position */
        float Hunger;       /* animal hunger level: 0...10; if >5, hungry */
        bool Productive;    /* animal's availibility to produce */

    public:
        /* creates new animal with hunger = 0; position I, J; Productive = false */
        FarmAnimal(int i, int j);

        /* returns animal row position */
        int getI();
        /* returns animal column position */
        int getJ();
        /* returns animal hunger */
        int getHunger();
        /* returns animal's availability to produce */
        bool isProductive();

        virtual string getNoise() = 0;      /* returns noise of animal */
        virtual int getAllowedLand() = 0;   /* returns type of land animal is allowed to move to */
        virtual float getHungerRate() = 0;  /* returns the hunger rate of animal */

        /* sets productivity to true */
        void turnProductive();

        /* move an animal */
        void Move(AnimalArray AR);

        /* if animal not hungry, increase by certain value; if hungry, increase by 1 */
        void GetHungrier();
        
        /* animal eats grass from its grid, hunger = 0, animal turns productive */
        void Eat(Grid** Map);
};

#endif
