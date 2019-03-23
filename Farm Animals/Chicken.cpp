#include <string>
#include "Chicken.hpp"
using namespace std;

#define DEFAULT_I 0
#define DEFAULT_J 0

Chicken::Chicken() : FarmAnimal(DEFAULT_I, DEFAULT_J) {
};

string Chicken::getNoise() {
    return "Bok bok bok!"
};

int Chicken::getAllowedLand() {
    return 3;
};

float Chicken::getHungerRate() {
    return 1;
};