#ifndef FARMANIMAL_HPP
#define FARMANIMAL_HPP

#include <string>
#include <vector>

#define MAX_ANIMAL 3

class FarmAnimal {
    private:
        int I, J;       // animal position
        int Hunger;     // animal hunger level: 0...10; if >5, hungry

    public:
        FarmAnimal();
        FarmAnimal& operator= (FarmAnimal& FA);

        int getI();         // returns animal row position
        int getJ();         // returns animal column position
        int getHunger();    // returns animal hunger
        int getNAnimal();   // returns number of animals

        void Move();        // move an animal one grid
        void GetHungrier(); // increase hunger
        void Eat();         // animal eats grass from its grid
};

class EggProducingAnimal : public FarmAnimal {
    public:
        int getAllowedLand();       // returns index of allowed land type (coop = 3)
};

class MilkProducingAnimal : public FarmAnimal {    
    public:
        int getAllowedLand();       // returns index of allowed land type (barn = 2)
};

class MeatProducingAnimal : public FarmAnimal {
    public:
        int getAllowedLand();       // returns index of allowed land type (grassland = 1)
};

/* ---------- EGG-PRODUCING ANIMALS ---------- */
class Chicken : public EggProducingAnimal, public MeatProducingAnimal {
    public:
        std::string getNoise();      // returns animal's noise (chicken = "bok bok bok") 
};

class Duck : public EggProducingAnimal, public MeatProducingAnimal {
    public:
        std::string getNoise();      // returns animal's noise (duck = "quack quack")
};

/* ---------- MILK-PRODUCING ANIMALS ---------- */
class Cow : public MilkProducingAnimal, public MeatProducingAnimal {
    public:
        std::string getNoise();      // returns animal's noise (cow = "moo-oo-oo")
};

class Goat : public MilkProducingAnimal, public MeatProducingAnimal {
    public:
        std::string getNoise();      // returns animal's noise (goat = "meh-eh-eh-eh")
};

/* ---------- MEAT-PRODUCING ANIMALS ---------- */
class Pig : public MeatProducingAnimal {
    public:
        std::string getNoise();      // returns animal's noise (pig = "oink oink")
};

class Rabbit : public MeatProducingAnimal {
    public:
        std::string getNoise();      // returns animal's noise (rabbit = "purrrrr")
};

/* ---------- ANIMAL ARRAY ---------- */
/* This class is the only class instantiated at the main program.
*  Class T is one of Chicken, Duck, Cow, Goat, Pig, and Rabbit.
*  For every type of class T, a new animal array is instantiated. */
template <class T>
class AnimalArray {
    private:
        std::vector<T> Member;         // vector of elements
        int length;
    
    public:
        AnimalArray<T>();               // vector default size MAX_ANIMAL
        void newMember();               // create a new member and add to vector, increase length
        void removeMember(int x);       // remove member at index x, decrease length
        T getMember(int x);             // returns element on index x
        T getNearby(int i, int j);      // returns element nearest to position i, j

        void Tick();
        /* For every tick:
        *   - Moves every member;
        *   - Increases hunger of every member, removes dead members; and
        *   - Makes every hungry member eat grass on its grid if possible. */
};

#endif
