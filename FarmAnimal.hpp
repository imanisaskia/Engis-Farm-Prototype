#ifndef FARMANIMAL_HPP
#define FARMANIMAL_HPP

#include <cstring>
#include <vector>

#define MAX_ANIMAL 3

class FarmAnimal {
    private:
        int I, J;       // animal position
        int Hunger;     // animal hunger level: 0...10; if >5, hungry

        static AnimalArray<Chicken> ChickenArray;   // array of chickens
        static AnimalArray<Duck> DuckArray;         // array of ducks
        static AnimalArray<Cow> CowArray;           // array of cows
        static AnimalArray<Goat> GoatArray;         // array of goats
        static AnimalArray<Pig> PigArray;           // array of pigs
        static AnimalArray<Rabbit> RabbitArray;     // array of rabbits

    public:
        FarmAnimal(int i, int j);   // new farm animal on position i, j
        ~FarmAnimal();              // destroy animal

        int getI();                 // returns animal row position
        int getJ();                 // returns animal column position
        int getHunger();            // returns animal hunger
        int getNAnimal();           // returns number of animals

        void Move();                // move an animal one grid
        void GetHungrier();         // increase hunger
        void Eat();                 // animal eats grass from its grid

        void Tick();                // determines what happens to each animal array during one tick; uses ArrayTick()
};

class EggProducingAnimal : public FarmAnimal {
    public:
        EggProducingAnimal();
        ~EggProducingAnimal();
        int getAllowedLand();       // returns index of allowed land type (coop = 3)
};

class MilkProducingAnimal : public FarmAnimal {    
    public:
        MilkProducingAnimal();
        ~MilkProducingAnimal();
        int getAllowedLand();       // returns index of allowed land type (barn = 2)
};

class MeatProducingAnimal : public FarmAnimal {
    public:
        MeatProducingAnimal();
        ~MeatProducingAnimal();
        int getAllowedLand();       // returns index of allowed land type (grassland = 1)
};

/* ---------- EGG-PRODUCING ANIMALS ---------- */
class Chicken : public EggProducingAnimal, public MeatProducingAnimal {
    public:
        Chicken();
        Chicken& operator= (Chicken&);
        ~Chicken();
        String getNoise();      // returns animal's noise (chicken = "bok bok bok") 
};

class Duck : public EggProducingAnimal, public MeatProducingAnimal {
    public:
        Duck();
        Duck& operator= (Duck&);
        ~Duck();
        String getNoise();      // returns animal's noise (duck = "quack quack")
};

/* ---------- MILK-PRODUCING ANIMALS ---------- */
class Cow : public MilkProducingAnimal, public MeatProducingAnimal {
    public:
        Cow();
        Cow& operator= (Cow&);
        ~Cow();
        String getNoise();      // returns animal's noise (cow = "moo-oo-oo")
};

class Goat : public MilkProducingAnimal, public MeatProducingAnimal {
    public:
        Goat();
        Goat& operator= (Goat&);
        ~Goat();
        String getNoise();      // returns animal's noise (goat = "meh-eh-eh-eh")
};

/* ---------- MEAT-PRODUCING ANIMALS ---------- */
class Pig : public MeatProducingAnimal {
    public:
        Pig();
        Pig& operator= (Pig&);
        ~Pig();
        String getNoise();      // returns animal's noise (pig = "oink oink")
};

class Rabbit : public MeatProducingAnimal {
    public:
        Rabbit();
        Rabbit& operator= (Rabbit&);
        ~Rabbit();       
        String getNoise();      // returns animal's noise (rabbit = "purrrrr")
};

/* ---------- ANIMAL ARRAY ---------- */
template <class T>
class AnimalArray {
    private:
        vector<T> Els;      // vector of elements
        int length;
    
    public:
        AnimalArray<T>();           // constructor of vector with default size MAX_ANIMAL
        void addEl(T);              // add element to vector, increase length
        void removeEl(int x);       // remove element at index x, decrease length
        int getN();                 // returns length
        T getEl(int x);             // returns element on index x
        T getNearby(int i, int j);  // returns element nearest to position i, j

        void ArrayTick();
        /* Does the following:
        *   - Move every animal on the vector
        *   - Increase the hunger of every animal on the vector; if =10, animal dies
        *   - Animals with hunger >5 eats grass from their grid if possible
        */
};

#endif