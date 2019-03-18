#ifndef FARMANIMAL_HPP
#define FARMANIMAL_HPP

#include <string>

class FarmAnimal {
    private:
        int I, J;       // animal position
        int Hunger;     // animal hunger level: 0...10; if >5, hungry

    public:
        FarmAnimal();

        int getI();         // returns animal row position
        int getJ();         // returns animal column position
        int getHunger();    // returns animal hunger
        int getNAnimal();   // returns number of animals

        void Move();        // move an animal one grid
        void GetHungrier(); // increase hunger
        void Eat();         // animal eats grass from its grid
};

#endif
