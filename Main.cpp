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
    while (!over){
        valid = true;
        command = ui.getCommand();
        if (command == "TALK"){
            ui.printSentences(command);
            cout << command;
            cin >> x;
        } else 
        if (command == "INTERACTUP" ){
                        bool success;
            int type, idx;
            P.checkInteractPosition(Chickens, Ducks, Cows, Goats, D, 'U', type, idx);
            if(type!=-999 && idx!=-999){
                if(type==1){
                    P.Interact((Chickens.getMember(idx)),success);
                    if(success){
                        ui.printSentences("You took ChickenEgg");
                    }
                }else if(type==2){
                    P.Interact(Ducks.getMember(idx),success);
                    if(success){
                        ui.printSentences("You took DuckEgg");
                    }
                }else if(type==3){
                    P.Interact(Cows.getMember(idx),success);
                    if(success){
                        ui.printSentences("You took CowMilk");
                    }
                }else if(type==4){
                    P.Interact(Goats.getMember(idx),success);
                    if(success){
                        ui.printSentences("You took GoatMilk");
                    }
                }if(not(success)){
                    ui.printSentences("Interact failed");
                }
            }else{
                P.InteractWell(D,'U',success);
                if(success){
                    ui.printSentences("You took water");
                }else{
                    P.InteractTruck(D,'U',success);
                    if(success){
                        ui.printSentences("You sold products");
                    }else{
                        ui.printSentences("Interact failed");
                    }
                }
            }
        } else 
        if (command == "INTERACTDOWN" ){
            bool success;
            int type, idx;
            P.checkInteractPosition(Chickens, Ducks, Cows, Goats, D, 'D', type, idx);
            if(type!=-999 && idx!=-999){
                if(type==1){
                    P.Interact(Chickens.getMember(idx),success);
                    if(success){
                        ui.printSentences("You took ChickenEgg");
                    }
                }else if(type==2){
                    P.Interact(Ducks.getMember(idx),success);
                    if(success){
                        ui.printSentences("You took DuckEgg");
                    }
                }else if(type==3){
                    P.Interact(Cows.getMember(idx),success);
                    if(success){
                        ui.printSentences("You took CowMilk");
                    }
                }else if(type==4){
                    P.Interact(Goats.getMember(idx),success);
                    if(success){
                        ui.printSentences("You took GoatMilk");
                    }
                }if(not(success)){
                    ui.printSentences("Interact failed");
                }
            }else{
                P.InteractWell(D,'D',success);
                if(success){
                    ui.printSentences("You took water");
                }else{
                    P.InteractTruck(D,'D',success);
                    if(success){
                        ui.printSentences("You sold products");
                    }else{
                        ui.printSentences("Interact failed");
                    }
                }
            }
        } else 
        if (command == "INTERACTRIGHT" ){
            bool success;
            int type, idx;
            P.checkInteractPosition(Chickens, Ducks, Cows, Goats, D, 'R', type, idx);
            if(type!=-999 && idx!=-999){
                if(type==1){
                    P.Interact(Chickens.getMember(idx),success);
                    if(success){
                        ui.printSentences("You took ChickenEgg");
                    }
                }else if(type==2){
                    P.Interact(Ducks.getMember(idx),success);
                    if(success){
                        ui.printSentences("You took DuckEgg");
                    }
                }else if(type==3){
                    P.Interact(Cows.getMember(idx),success);
                    if(success){
                        ui.printSentences("You took CowMilk");
                    }
                }else if(type==4){
                     P.Interact(Goats.getMember(idx),success);
                    if(success){
                        ui.printSentences("You took GoatMilk");
                    }
                }if(not(success)){
                    ui.printSentences("Interact failed");
                }
            }else{
                P.InteractWell(D,'R',success);
                if(success){
                    ui.printSentences("You took water");
                }else{
                    P.InteractTruck(D,'R',success);
                    if(success){
                        ui.printSentences("You sold products");
                    }else{
                        ui.printSentences("Interact failed");
                    }
                }
            }
        } else 
        if (command == "INTERACTLEFT" ){
            bool success;
            int type, idx;
            P.checkInteractPosition(Chickens, Ducks, Cows, Goats, D, 'L', type, idx);
            if(type!=-999 && idx!=-999){
                if(type==1){
                    P.Interact(Chickens.getMember(idx),success);
                    if(success){
                        ui.printSentences("You took ChickenEgg");
                    }
                }else if(type==2){
                    P.Interact(Ducks.getMember(idx),success);
                    if(success){
                        ui.printSentences("You took DuckEgg");
                    }
                }else if(type==3){
                    P.Interact(Cows.getMember(idx),success);
                    if(success){
                        ui.printSentences("You took CowMilk");
                    }
                }else if(type==4){
                     P.Interact(Goats.getMember(idx),success);
                    if(success){
                        ui.printSentences("You took ChickenEgg");
                    }
                }if(not(success)){
                    ui.printSentences("Interact failed");
                }
            }else{
                P.InteractWell(D,'L',success);
                if(success){
                    ui.printSentences("You took water");
                }else{
                    P.InteractTruck(D,'L',success);
                    if(success){
                        ui.printSentences("You sold products");
                    }else{
                        ui.printSentences("Interact failed");
                    }
                }
            }
        } else 
        if (command == "KILL" ){

        } else 
        if (command == "GROW" ){
           P.Grow(D);
        } else 
        if (command == "MIX" ){
            bool success1, success2, success3, success4;
            command = ui.getCommand();
            if(command == "BEEF STEW"){
                BeefStew *BS = new BeefStew();
                P.Mix(D,BS,'U',success1);
                P.Mix(D,BS,'D',success2);
                P.Mix(D,BS,'L',success3);
                P.Mix(D,BS,'R',success4);                
                if(not(success1)&&not(success2)&&not(success3)&&not(success4)){
                    delete BS;
                    ui.printSentences("Mix failed");
                }else{
                    ui.printSentences("You made BeefStew");
                }
            }else if(command == "CHICKEN AND EGG SKEWER"){
                ChickenAndEggSkewer *CA = new ChickenAndEggSkewer();
                P.Mix(D,CA,'U',success1);
                P.Mix(D,CA,'D',success2);
                P.Mix(D,CA,'L',success3);
                P.Mix(D,CA,'R',success4);                
                if(not(success1)&&not(success2)&&not(success3)&&not(success4)){
                    delete CA;
                    ui.printSentences("Mix failed");
                }else{
                    ui.printSentences("You made ChickenAndEggSkewer");
                }
            }else if(command == "OMLETTE"){
                Omlette *OM = new Omlette();
                P.Mix(D,OM,'U',success1);
                P.Mix(D,OM,'D',success2);
                P.Mix(D,OM,'L',success3);
                P.Mix(D,OM,'R',success4);                
                if(not(success1)&&not(success2)&&not(success3)&&not(success4)){
                    delete OM;
                    ui.printSentences("Mix failed");
                }else{
                    ui.printSentences("You made Omlette");
                }
            }else if(command == "PORK STEW"){
                PorkStew *PS = new PorkStew();
                P.Mix(D,PS,'U',success1);
                P.Mix(D,PS,'D',success2);
                P.Mix(D,PS,'L',success3);
                P.Mix(D,PS,'R',success4);                
                if(not(success1)&&not(success2)&&not(success3)&&not(success4)){
                    delete PS;
                    ui.printSentences("Mix failed");
                }else{
                    ui.printSentences("You made PorkStew");
                }
            }else{
                ui.printSentences("Side dish not available");
            }
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