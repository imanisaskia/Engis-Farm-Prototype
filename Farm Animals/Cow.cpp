#include <string>
#include "Cow.hpp"
#include "../Display/Display.hpp"
using namespace std;

#define DEFAULT_I 0
#define DEFAULT_J 0

Cow::Cow() {
    Hunger = 0;
    I = DEFAULT_I;
    J = DEFAULT_J;
    Productive = false;
};

string Cow::getNoise() {
    return "Moo!";
};

int Cow::getAllowedLand() {
    return 2;
};

float Cow::getHungerRate() {
    return 0.2;
};

int Cow::getI() {
    return I;
};
int Cow::getJ() {
    return J;
};
int Cow::getHunger() {
    return Hunger;
};
bool Cow::isProductive() {
    return Productive;
};

void Cow::setUnproductive() {
    Productive = false;
};

void Cow::GetHungrier() {
    if (Hunger < 5) {
        Hunger = Hunger + getHungerRate();
    } else {
        Hunger = Hunger + 1;
    }
};

void Cow::Eat(Grid** Map) {
    if (checkGrassy(I,J)) {
        modifyGrassy(I,J);
        Hunger = 0;
        Productive = true;
    }
}