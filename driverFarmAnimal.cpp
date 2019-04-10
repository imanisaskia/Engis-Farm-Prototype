#include "Display/UI.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

int main(){
    int x;
    string command;
    AnimalArray<Chicken> Chickens;
    AnimalArray<Duck> Ducks;
    AnimalArray<Cow> Cows;
    AnimalArray<Goat> Goats;
    AnimalArray<Pig> Pigs;
    AnimalArray<Rabbit> Rabbits;
    Player P;
    Display D;

    Chickens.newMember();
    Ducks.newMember();
    Cows.newMember();
    Goats.newMember();
    Pigs.newMember();
    Rabbits.newMember();

    cin >> command;

    while (command != "q") {
        cout << "CHICKENS" << endl;
        Chickens.Print();
        cout << "DUCKS" << endl;
        Ducks.Print();
        cout << "COWS" << endl;
        Cows.Print();
        cout << "GOATS" << endl;
        Goats.Print();
        cout << "PIGS" << endl;
        Pigs.Print();
        cout << "RABBITS" << endl;
        Rabbits.Print();

        Chickens.TickArray(D,P.getI(), P.getJ());
        Cows.TickArray(D,P.getI(),P.getJ());
        Ducks.TickArray(D,P.getI(),P.getJ());
        Rabbits.TickArray(D,P.getI(),P.getJ());
        Pigs.TickArray(D,P.getI(),P.getJ());
        Goats.TickArray(D,P.getI(),P.getJ());

        cin >> command;

    } 
    return 0; 
}