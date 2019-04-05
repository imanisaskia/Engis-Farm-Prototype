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

Chicken& Chicken::operator=(Chicken& C) {
    Hunger = C.Hunger;
    I = C.I;
    J = C.J;
    Productive = C.Productive;
    return *this;
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

void Chicken::setI(int x) {
    I = x;
}
void Chicken::setJ(int x) {
    J = x;
}

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

void Chicken::Eat(Display& D) {
    if (D.checkGrassy(I,J)) {
        D.modifyGrassy(I,J);
        Hunger = 0;
        Productive = true;
    }
};