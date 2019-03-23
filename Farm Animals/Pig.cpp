#include <string>
#include "Pig.hpp"
using namespace std;

#define DEFAULT_I 0
#define DEFAULT_J 0

Pig::Pig() : FarmAnimal(DEFAULT_I, DEFAULT_J) {
};

string Pig::getNoise() {
    return "Oink oink!";
};

int Pig::getAllowedLand() {
    return 1;
};

float Pig::getHungerRate() {
    return 0.6;
};