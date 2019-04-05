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
    Chicken chicken;
    Duck duck;
    Cow cow;
    Rabbit rabbit;
    Goat goat;
    Pig pig;
    Player P;
    Display D;
    UI ui;

    Chickens.newMember();
    Ducks.newMember();
    Cows.newMember();
    Goats.newMember();
    Pigs.newMember();
    Rabbits.newMember();

    ui.printTitle();
    ui.Print(P.getI(), P.getJ(), D);
    ui.updateMap(P.getMoney(), P.getWater(), P.getBagSP(), P.getBagFP(), Chickens, Cows , Ducks, Rabbits, Pigs, Goats);
    cout << "test";
    command = ui.getCommand();
    while (!over){
        valid = true;
        if (command == "TALKUP"){
            ui.printSentences(P.Talk(P.getI()-1, P.getJ(), chicken, cow, duck, rabbit, pig, goat, Chickens, Ducks, Cows, Goats, Rabbits, Pigs));
        } else 
        if (command == "TALKDOWN"){
            ui.printSentences(P.Talk(P.getI()+1, P.getJ(), chicken, cow, duck, rabbit, pig, goat, Chickens, Ducks, Cows, Goats, Rabbits, Pigs));
        } else
        if (command == "TALKLEFT"){
            cout <<"tes";
            ui.printSentences(P.Talk(P.getI(), P.getJ()-1, chicken, cow, duck, rabbit, pig, goat, Chickens, Ducks, Cows, Goats, Rabbits, Pigs));
        } else
        if (command == "TALKRIGHT"){
            ui.printSentences(P.Talk(P.getI(), P.getJ()+1, chicken, cow, duck, rabbit, pig, goat, Chickens, Ducks, Cows, Goats, Rabbits, Pigs));
            ui.printSentences("x");
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
        if (command == "KILLUP" ){
            P.Kill(P.getI()-1, P.getJ(), chicken, cow, rabbit, pig, Chickens, Cows, Rabbits, Pigs);
        } else 
        if (command == "KILLDOWN" ){
            P.Kill(P.getI()+1, P.getJ(), chicken, cow, rabbit, pig, Chickens, Cows, Rabbits, Pigs);
        } else 
        if (command == "KILLLEFT" ){
            P.Kill(P.getI(), P.getJ()-1, chicken, cow, rabbit, pig, Chickens, Cows, Rabbits, Pigs);
        } else 
        if (command == "KILLRIGHT" ){
            P.Kill(P.getI(), P.getJ()+1, chicken, cow, rabbit, pig, Chickens, Cows, Rabbits, Pigs);
        } else 
        if (command == "GROW" ){
            P.Grow(D);
        } else 
        if (command == "MIX" ){

        } else 
        if (command == "MOVEUP" ){
            P.Walk('L', D, Chickens, Ducks, Cows, Goats, Rabbits, Pigs);
        } else 
        if (command == "MOVEDOWN" ){
            P.Walk('R', D, Chickens, Ducks, Cows, Goats, Rabbits, Pigs);
        } else 
        if (command == "MOVERIGHT" ){
            P.Walk('U', D, Chickens, Ducks, Cows, Goats, Rabbits, Pigs);
        } else 
        if (command == "MOVELEFT" ){
            P.Walk('D', D, Chickens, Ducks, Cows, Goats, Rabbits, Pigs);
        } else {
//            valid = false;
        }
        if (valid){
            ui.Print(P.getI(), P.getJ(), D);
            ui.updateMap(P.getMoney(), P.getWater(), P.getBagSP(), P.getBagFP(), Chickens, Cows , Ducks, Rabbits, Pigs, Goats);
        } else {
            ui.Print(P.getI(), P.getJ(), D);
            ui.updateMap(P.getMoney(), P.getWater(), P.getBagSP(), P.getBagFP(), Chickens, Cows , Ducks, Rabbits, Pigs, Goats);
            ui.printSentences("Command not valid");
        }
        command = ui.getCommand();
        cout << command;
        cin >> x;
        /* tick */
        over = (Chickens.getLength() == 0 && Cows.getLength() == 0 && Ducks.getLength() == 0 && Rabbits.getLength() == 0 && Pigs.getLength() && Goats.getLength() == 0);
    }
    ui.printOver();
    return 0; 
}