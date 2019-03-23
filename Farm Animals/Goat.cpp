#include <string>
#include "Goat.hpp"
using namespace std;

#define DEFAULT_I 0
#define DEFAULT_J 0

Goat::Goat() : FarmAnimal(DEFAULT_I, DEFAULT_J) {
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