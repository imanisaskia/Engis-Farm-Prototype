#ifndef FARMANIMAL_HPP
#define FARMANIMAL_HPP

class FarmAnimal {
    private:
        int X, Y;
        int Hunger;
        static int N_Animals;

};

class EggProducingAnimal {

};

class MilkProducingAnimal {

};

class MeatProducingAnimal {

};

/* ---------- EGG-PRODUCING ANIMALS ---------- */
class Chicken : public EggProducingAnimal, public MeatProducingAnimal {

};

class Duck : public EggProducingAnimal, public MeatProducingAnimal {

};

/* ---------- MILK-PRODUCING ANIMALS ---------- */
class Cow : public MilkProducingAnimal, public MeatProducingAnimal {

};

class Goat : public MilkProducingAnimal, public MeatProducingAnimal {

};

/* ---------- MEAT-PRODUCING ANIMALS ---------- */
class Pig : public MeatProducingAnimal {

};

class Rabbit : public MeatProducingAnimal {

};

#endif