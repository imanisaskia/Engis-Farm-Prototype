#include <string>
#include "FarmAnimal.hpp"
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

void FarmAnimal::Move(AnimalArray AR) {
    int i, j;
    int iType = rand() % 3;
    int jType = rand() % 3;

    if (int iType == 1) {
        i = I + 1;
    } else if (int iType == 2) {
        i = I - 1;
    } else {
        i = I;
    }
    
    if (int jType == 1) {
        j = J + 1;
    } else if (int jType == 2) {
        j = J - 1;
    } else {
        j = J;
    }

    bool occupied = false;
    for (int k = 0; k < AR.getLength(); k++) {
        if ((AR.getMember(k).getI() == i) && (AR.getMember(k).getJ() == j)) {
            occupied = true;
        }
    }

    if (!occupied) {
        I = i;
        J = j;
    }
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
    }
};
