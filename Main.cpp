#include "Display/UI.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

int main(){
    int x;
    bool over,valid;
    over = false;
    string command;
    AnimalArray<Chicken> Chickens;
    AnimalArray<Duck> Ducks;
    AnimalArray<Cow> Cows;
    AnimalArray<Goat> Goats;
    AnimalArray<Pig> Pigs;
    AnimalArray<Rabbit> Rabbits;
    Player P;
    Display D;
    UI ui;
    ui.printTitle();
    ui.Print(P.getI(), P.getJ(), D);
    ui.updateMap(P.getMoney(), P.getWater(), P.getBagSP(), P.getBagFP(), Chickens, Cows , Ducks, Rabbits, Pigs, Goats);
    cout << "test";
    while (!over){
        valid = true;
        command = ui.getCommand();
        if (command == "TALK"){
            ui.printSentences(command);
            cout << command;
            cin >> x;
        } else 
        if (command == "INTERACT UP" ){

        } else 
        if (command == "INTERACT DOWN" ){

        } else 
        if (command == "INTERACT RIGHT" ){

        } else 
        if (command == "INTERACT LEFT" ){

        } else 
        if (command == "KILL" ){

        } else 
        if (command == "GROW" ){
            P.Grow(D);
        } else 
        if (command == "MIX" ){

        } else 
        if (command == "MOVE UP" ){

        } else 
        if (command == "MOVE DOWN" ){

        } else 
        if (command == "MOVE RIGHT" ){

        } else 
        if (command == "MOVE LEFT" ){

        } else {
            valid = false;
        }
        if (valid){
            ui.Print(P.getI(), P.getJ(), D);
            ui.updateMap(P.getMoney(), P.getWater(), P.getBagSP(), P.getBagFP(), Chickens, Cows , Ducks, Rabbits, Pigs, Goats);
        } else {
            ui.Print(P.getI(), P.getJ(), D);
            ui.updateMap(P.getMoney(), P.getWater(), P.getBagSP(), P.getBagFP(), Chickens, Cows , Ducks, Rabbits, Pigs, Goats);
            ui.printSentences("Command not valid");
        }
        /* tick */
        over = (Chickens.getLength() == 0 && Cows.getLength() == 0 && Ducks.getLength() == 0 && Rabbits.getLength() == 0 && Pigs.getLength() && Goats.getLength() == 0);
    }
    ui.printOver();
    return 0; 
}