#include <string>
#include "Chicken.hpp"
#include "../Display/Display.hpp"
using namespace std;

#define DEFAULT_I 0
#define DEFAULT_J 0

Chicken::Chicken() {
    Hunger = 0;
    I = DEFAULT_I;
    J = DEFAULT_J;
    Productive = false;
};

string Chicken::getNoise() {
    return "Bok bok bok!";
};

int Chicken::getAllowedLand() {
    return 3;
};

float Chicken::getHungerRate() {
    return 1;
};

int Chicken::getI() {
    return I;
};
int Chicken::getJ() {
    return J;
};
int Chicken::getHunger() {
    return Hunger;
};
bool Chicken::isProductive() {
    return Productive;
};

void Chicken::setUnproductive() {
    Productive = false;
};

void Chicken::GetHungrier() {
    if (Hunger < 5) {
        Hunger = Hunger + getHungerRate();
    } else {
        Hunger = Hunger + 1;
    }
};

void Chicken::Eat(Grid** Map) {
    if (checkGrassy(I,J)) {
        modifyGrassy(I,J);
        Hunger = 0;
        Productive = true;
    }
};