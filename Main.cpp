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
    command = ui.getCommand();
    while (!over){
        valid = true;
        if (command == "TALKUP"){
            D.setCommand(P.Talk(P.getI()-1, P.getJ(), chicken, cow, duck, rabbit, pig, goat, Chickens, Ducks, Cows, Goats, Rabbits, Pigs));
        } else 
        if (command == "TALKDOWN"){
            D.setCommand(P.Talk(P.getI()+1, P.getJ(), chicken, cow, duck, rabbit, pig, goat, Chickens, Ducks, Cows, Goats, Rabbits, Pigs));
        } else
        if (command == "TALKLEFT"){
            D.setCommand(P.Talk(P.getI(), P.getJ()-1, chicken, cow, duck, rabbit, pig, goat, Chickens, Ducks, Cows, Goats, Rabbits, Pigs));
        } else
        if (command == "TALKRIGHT"){
            D.setCommand(P.Talk(P.getI(), P.getJ()+1, chicken, cow, duck, rabbit, pig, goat, Chickens, Ducks, Cows, Goats, Rabbits, Pigs));
            
        } else
        if (command == "INTERACTUP" ){
            bool success;
            int type, idx;
            P.checkInteractPosition(Chickens, Ducks, Cows, Goats, D, 'U', type, idx);
            if(type!=-999 && idx!=-999){
                if(type==1){
                    P.Interact((Chickens.getMember(idx)),success);
                    if(success){
                        D.setCommand("You took ChickenEgg");
                    }
                }else if(type==2){
                    P.Interact(Ducks.getMember(idx),success);
                    if(success){
                        D.setCommand("You took DuckEgg");
                    }
                }else if(type==3){
                    P.Interact(Cows.getMember(idx),success);
                    if(success){
                        D.setCommand("You took CowMilk");
                    }
                }else if(type==4){
                    P.Interact(Goats.getMember(idx),success);
                    if(success){
                        D.setCommand("You took GoatMilk");
                    }
                }if(not(success)){
                    D.setCommand("Interact failed");
                }
            }else{
                P.InteractWell(D,'U',success);
                if(success){
                    D.setCommand("You took water");
                }else{
                    P.InteractTruck(D,'U',success);
                    if(success){
                        D.setCommand("You sold products");
                    }else{
                        D.setCommand("Interact failed");
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
                        D.setCommand("You took ChickenEgg");
                    }
                }else if(type==2){
                    P.Interact(Ducks.getMember(idx),success);
                    if(success){
                        D.setCommand("You took DuckEgg");
                    }
                }else if(type==3){
                    P.Interact(Cows.getMember(idx),success);
                    if(success){
                        D.setCommand("You took CowMilk");
                    }
                }else if(type==4){
                    P.Interact(Goats.getMember(idx),success);
                    if(success){
                        D.setCommand("You took GoatMilk");
                    }
                }if(not(success)){
                    D.setCommand("Interact failed");
                }
            }else{
                P.InteractWell(D,'D',success);
                if(success){
                    D.setCommand("You took water");
                }else{
                    P.InteractTruck(D,'D',success);
                    if(success){
                        D.setCommand("You sold products");
                    }else{
                        D.setCommand("Interact failed");
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
                        D.setCommand("You took ChickenEgg");
                    }
                }else if(type==2){
                    P.Interact(Ducks.getMember(idx),success);
                    if(success){
                        D.setCommand("You took DuckEgg");
                    }
                }else if(type==3){
                    P.Interact(Cows.getMember(idx),success);
                    if(success){
                        D.setCommand("You took CowMilk");
                    }
                }else if(type==4){
                     P.Interact(Goats.getMember(idx),success);
                    if(success){
                        D.setCommand("You took GoatMilk");
                    }
                }if(not(success)){
                    D.setCommand("Interact failed");
                }
            }else{
                P.InteractWell(D,'R',success);
                if(success){
                    D.setCommand("You took water");
                }else{
                    P.InteractTruck(D,'R',success);
                    if(success){
                        D.setCommand("You sold products");
                    }else{
                        D.setCommand("Interact failed");
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
                        D.setCommand("You took ChickenEgg");
                    }
                }else if(type==2){
                    P.Interact(Ducks.getMember(idx),success);
                    if(success){
                        D.setCommand("You took DuckEgg");
                    }
                }else if(type==3){
                    P.Interact(Cows.getMember(idx),success);
                    if(success){
                        D.setCommand("You took CowMilk");
                    }
                }else if(type==4){
                     P.Interact(Goats.getMember(idx),success);
                    if(success){
                        D.setCommand("You took ChickenEgg");
                    }
                }if(not(success)){
                    D.setCommand("Interact failed");
                }
            } else{
                P.InteractWell(D,'L',success);
                if(success){
                    D.setCommand("You took water");
                }else{
                    P.InteractTruck(D,'L',success);
                    if(success){
                        D.setCommand("You sold products");
                    }else{
                        D.setCommand("Interact failed");
                    }
                }
            }
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
            bool success1, success2, success3, success4;
            command = ui.getCommand();
            if(command == "BEEFSTEW"){
                BeefStew *BS = new BeefStew();
                P.Mix(D,BS,'U',success1);
                P.Mix(D,BS,'D',success2);
                P.Mix(D,BS,'L',success3);
                P.Mix(D,BS,'R',success4);                
                if(not(success1)&&not(success2)&&not(success3)&&not(success4)){
                    delete BS;
                    D.setCommand("Mix failed");
                }else{
                    D.setCommand("You made BeefStew");
                }
            }else if(command == "CHICKENANDEGGSKEWER"){
                ChickenAndEggSkewer *CA = new ChickenAndEggSkewer();
                P.Mix(D,CA,'U',success1);
                P.Mix(D,CA,'D',success2);
                P.Mix(D,CA,'L',success3);
                P.Mix(D,CA,'R',success4);                
                if(not(success1)&&not(success2)&&not(success3)&&not(success4)){
                    delete CA;
                    D.setCommand("Mix failed");
                }else{
                    D.setCommand("You made ChickenAndEggSkewer");
                }
            }else if(command == "OMLETTE"){
                Omlette *OM = new Omlette();
                P.Mix(D,OM,'U',success1);
                P.Mix(D,OM,'D',success2);
                P.Mix(D,OM,'L',success3);
                P.Mix(D,OM,'R',success4);                
                if(not(success1)&&not(success2)&&not(success3)&&not(success4)){
                    delete OM;
                    D.setCommand("Mix failed");
                }else{
                    D.setCommand("You made Omlette");
                }
            }else if(command == "PORKSTEW"){
                PorkStew *PS = new PorkStew();
                P.Mix(D,PS,'U',success1);
                P.Mix(D,PS,'D',success2);
                P.Mix(D,PS,'L',success3);
                P.Mix(D,PS,'R',success4);                
                if(not(success1)&&not(success2)&&not(success3)&&not(success4)){
                    delete PS;
                    D.setCommand("Mix failed");
                }else{
                    D.setCommand("You made PorkStew");
                }
            }else{
                D.setCommand("Side dish not available");
            }
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
            valid = false;
        }
        if (valid){
            ui.Print(P.getI(), P.getJ(), D);
            ui.updateMap(P.getMoney(), P.getWater(), P.getBagSP(), P.getBagFP(), Chickens, Cows , Ducks, Rabbits, Pigs, Goats);
        } else {
            ui.Print(P.getI(), P.getJ(), D);
            ui.updateMap(P.getMoney(), P.getWater(), P.getBagSP(), P.getBagFP(), Chickens, Cows , Ducks, Rabbits, Pigs, Goats);
            D.setCommand("Command not valid");
        }
        D.setCommand("");
        command = ui.getCommand();
        Chickens.TickArray(D,P.getI(), P.getJ());
        Cows.TickArray(D,P.getI(),P.getJ());
        Ducks.TickArray(D,P.getI(),P.getJ());
        Rabbits.TickArray(D,P.getI(),P.getJ());
        Pigs.TickArray(D,P.getI(),P.getJ());
        Goats.TickArray(D,P.getI(),P.getJ());
        D.lessenTruck();
        //over = (Chickens.getLength() == 0 && Cows.getLength() == 0 && Ducks.getLength() == 0 && Rabbits.getLength() == 0 && Pigs.getLength() && Goats.getLength() == 0);
    }
    ui.printOver();
    return 0; 
}