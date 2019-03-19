#ifndef FARMANIMAL_HPP
#define FARMANIMAL_HPP

#include <string>

class FarmAnimal {
    private:
        int I, J;           // animal position
        float Hunger;       // animal hunger level: 0...10; if >5, hungry
        bool Productive;    // animal's availibility to produce

    public:
        FarmAnimal(int i, int j);   // creates new animal with hunger = 0; position I, J; Productive = false

        int getI();             // returns animal row position
        int getJ();             // returns animal column position
        int getHunger();        // returns animal hunger
        bool getProductive();   // returns animal's availability to produce

        virtual string getNoise() = 0;      // returns noise of animal
        virtual int getAllowedLand() = 0;   // returns type of land animal is allowed to move to
        virtual float getHungerRate() = 0;  // returns the hunger rate of animal

        void turnProductive();  // sets productivity to true

        void Move();        // move an animal one grid
        void GetHungrier(); // if animal not hungry, increase by certain value; if hungry, increase by 1
        void Eat();         // animal eats grass from its grid, hunger = 0, animal turns productive
};

#endif
