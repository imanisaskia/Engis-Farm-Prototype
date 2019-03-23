#include <string>
#include "Duck.hpp"
using namespace std;

#define DEFAULT_I 0
#define DEFAULT_J 0

Duck::Duck() : FarmAnimal(DEFAULT_I, DEFAULT_J) {
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