#include <string>
#include "Goat.hpp"
#include "../Display/Display.hpp"
using namespace std;

#define DEFAULT_I 7
#define DEFAULT_J 2

Goat::Goat() {
    Hunger = 0;
    I = DEFAULT_I;
    J = DEFAULT_J;
    Productive = false;
};

Goat& Goat::operator=(Goat& G) {
    Hunger = G.Hunger;
    I = G.I;
    J = G.J;
    Productive = G.Productive;
    return *this;
};

string Goat::getNoise() {
    return "Meh-eh-eh!";
};

int Goat::getAllowedLand() {
    return 2;
};

float Goat::getHungerRate() {
    return 0.3;
};

int Goat::getI() {
    return I;
};
int Goat::getJ() {
    return J;
};
int Goat::getHunger() {
    return Hunger;
};
bool Goat::isProductive() {
    return Productive;
};

void Goat::setUnproductive() {
    Productive = false;
};

void Goat::GetHungrier() {
    if (Hunger < 5) {
        Hunger = Hunger + getHungerRate();
    } else {
        Hunger = Hunger + 1;
    }
};

void Goat::Eat(Display& D) {
    if (D.checkGrassy(I,J)) {
        D.modifyGrassy(I,J);
        Hunger = 0;
        Productive = true;
    }
};