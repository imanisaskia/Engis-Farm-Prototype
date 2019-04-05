#include <string>
#include "Duck.hpp"
#include "../Display/Display.hpp"
using namespace std;

#define DEFAULT_I 2
#define DEFAULT_J 2

Duck::Duck() {
    Hunger = 0;
    I = DEFAULT_I;
    J = DEFAULT_J;
    Productive = false;
};

Duck& Duck::operator=(Duck& D) {
    Hunger = D.Hunger;
    I = D.I;
    J = D.J;
    Productive = D.Productive;
    return *this;
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

void Duck::setI(int x) {
    I = x;
}
void Duck::setJ(int x) {
    J = x;
}

void Duck::setUnproductive() {
    Productive = false;
};

void Duck::GetHungrier() {
    if (Hunger < 5) {
        Hunger = Hunger + getHungerRate();
    } else {
        Hunger = Hunger + 1;
    }
};

void Duck::Eat(Display& D) {
    if (D.checkGrassy(I,J)) {
        D.modifyGrassy(I,J);
        Hunger = 0;
        Productive = true;
    }
};