#include <string>
#include "Duck.hpp"
#include "../Display/Display.hpp"
using namespace std;

#define DEFAULT_I 0
#define DEFAULT_J 0

Duck::Duck() {
    Hunger = 0;
    I = DEFAULT_I;
    J = DEFAULT_J;
    Productive = false;
};

string Duck::getNoise() {
    return "Quack!";
};

int Duck::getAllowedLand() {
    return 3;
};

float Duck::getHungerRate() {
    return 0.75;
};

int Duck::getI() {
    return I;
};
int Duck::getJ() {
    return J;
};
int Duck::getHunger() {
    return Hunger;
};
bool Duck::isProductive() {
    return Productive;
};

void Duck::turnProductive() {
    Productive = true;
};

void Duck::GetHungrier() {
    if (Hunger < 5) {
        Hunger = Hunger + getHungerRate();
    } else {
        Hunger = Hunger + 1;
    }
};

void Duck::Eat(Grid** Map) {
    if (checkGrassy(I,J)) {
        modifyGrassy(I,J);
        Hunger = 0;
        Productive = true;
    }
}