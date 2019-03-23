#include <string>
#include "Rabbit.hpp"
using namespace std;

#define DEFAULT_I 0
#define DEFAULT_J 0

Rabbit::Rabbit() : FarmAnimal(DEFAULT_I, DEFAULT_J) {
};

string Rabbit::getNoise() {
    return "Purr";
};

int Rabbit::getAllowedLand() {
    return 1;
};

float Rabbit::getHungerRate() {
    return 0.5;
};