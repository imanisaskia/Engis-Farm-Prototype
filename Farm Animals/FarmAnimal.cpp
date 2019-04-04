#include <string>
#include "FarmAnimal.hpp"
#include "../Display/Display.hpp"
using namespace std;

FarmAnimal::FarmAnimal(int i, int j) {
    Hunger = 0;
    I = i;
    J = j;
    Productive = false;
};

int FarmAnimal::getI() {
    return I;
};
int FarmAnimal::getJ() {
    return J;
};
int FarmAnimal::getHunger() {
    return Hunger;
};
bool FarmAnimal::isProductive() {
    return Productive;
};

void FarmAnimal::turnProductive() {
    Productive = true;
};

void FarmAnimal::GetHungrier() {
    if (Hunger < 5) {
        Hunger = Hunger + getHungerRate();
    } else {
        Hunger = Hunger + 1;
    }
};

void FarmAnimal::Eat(Grid** Map) {
    if (checkGrassy(I,J)) {
        modifyGrassy(I,J);
        Hunger = 0;
        Productive = true;
    }
};
