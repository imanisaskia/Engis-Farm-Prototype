#include <string>
#include "Cow.hpp"
using namespace std;

#define DEFAULT_I 0
#define DEFAULT_J 0

Cow::Cow() : FarmAnimal(DEFAULT_I, DEFAULT_J) {
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