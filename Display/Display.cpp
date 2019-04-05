#include "Display.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

#define defSize 11

Display::Display(){
/*Fill Map from an external file
string input is the name of the external file*/
    char str[100];
    string line[defSize];
    int i,j;

    Map = new Grid*[defSize];
    for (i = 0; i < defSize; i++){
        Map[i] = new Grid[defSize];
    }

    bool compatible;
    int x;
    compatible = true;
    cout << "Enter name of file external: ";
    cin.get(str, 100, '\n');
    ifstream infile;
    infile.open(str);
    i = 0;
    while(!infile.eof() && compatible) {
        getline(infile,line[i]);
        if (line[i].size() != defSize){
            compatible = false;
            cout << "Map format isn't compatible on line " << i+1 << endl;
        } else {
            i++;
        }
    }
    if (compatible){
        i =0;
        while (i < defSize && compatible) {
            j = 0;
            while (j < defSize && compatible) {
                if (line[i][j] == 'o'){
                    Map[i][j].setLand(true);
                    Map[i][j].setFacility(false);
                    Map[i][j].setType(3);
                    Map[i][j].setGrassy(false);
                    Map[i][j].setUsedTruck(-999);
                } else 
                if (line[i][j] == '='){
                    Map[i][j].setLand(true);
                    Map[i][j].setFacility(false);
                    Map[i][j].setType(3);
                    Map[i][j].setGrassy(true);
                    Map[i][j].setUsedTruck(-999);
                } else 
                if (line[i][j] == 'x'){
                    Map[i][j].setLand(true);
                    Map[i][j].setFacility(false);
                    Map[i][j].setType(2);
                    Map[i][j].setGrassy(false);
                    Map[i][j].setUsedTruck(-999);
                } else 
                if (line[i][j] == '$'){
                    Map[i][j].setLand(true);
                    Map[i][j].setFacility(false);
                    Map[i][j].setType(2);
                    Map[i][j].setGrassy(true);
                    Map[i][j].setUsedTruck(-999);
                } else 
                if (line[i][j] == '-'){
                    Map[i][j].setLand(true);
                    Map[i][j].setFacility(false);
                    Map[i][j].setType(1);
                    Map[i][j].setGrassy(false);
                    Map[i][j].setUsedTruck(-999);
                } else 
                if (line[i][j] == '#'){
                    Map[i][j].setLand(true);
                    Map[i][j].setFacility(false);
                    Map[i][j].setType(1);
                    Map[i][j].setGrassy(true);
                    Map[i][j].setUsedTruck(-999);
                }else
                if (line[i][j] == 'W'){
                    Map[i][j].setLand(false);
                    Map[i][j].setFacility(true);
                    Map[i][j].setType(1);
                    Map[i][j].setGrassy(false);
                    Map[i][j].setUsedTruck(-999);
                }else
                if (line[i][j] == 'M'){
                    Map[i][j].setLand(false);
                    Map[i][j].setFacility(true);
                    Map[i][j].setType(2);
                    Map[i][j].setGrassy(false);
                    Map[i][j].setUsedTruck(-999);
                } else
                if (line[i][j] == 'T'){
                    Map[i][j].setLand(false);
                    Map[i][j].setFacility(true);
                    Map[i][j].setType(3);
                    Map[i][j].setGrassy(false);
                    Map[i][j].setUsedTruck(0);
                    iTruck = i;
                    jTruck = j;
                } else {
                    cout << "Map not compatible on line " << i << " column " << j;
                    break;
                }
                j++;
            }
            i++;
        }
    }
}


Grid Display::getMap(int i, int j){
    return Map[i][j];
}

bool Display::checkLand(int i, int j, int type){
/*Check Land with Type = type*/
    if (Map[i][j].getLand() && Map[i][j].getType() == type) {
        return true;
    }else {
        return false;
    }
}


bool Display::checkFacility(int i, int j, int type){
/*Check Facility*/
    if (Map[i][j].getFacility() && Map[i][j].getType() == type){
        return true;
    } else {
        return false;
    }
}


bool Display::checkGrassy(int i, int j){
/*Check Grassy*/
    if (Map[i][j].getGrassy()){
        return true;
    }else {
        return false;
    }
}

bool Display::checkUsedTruck(int i, int j){
/*Check if Truck can be used*/
    if (Map[i][j].getUsedTruck() == 0 ){
        return true;
    }else {
        return false;
    }
}

void Display::modifyGrassy(int i, int j){
/*modify Grassy*/
    Map[i][j].setGrassy(!Map[i][j].getGrassy());
}

void Display::modifyUsedTruck(int i, int j){
    Map[i][j].useTruck();
}

void Display::lessenTruck(){
/*Mengurangi nilai variabel UsedTruck jika nilai UsedTruck > 0*/
    if (Map[iTruck][jTruck].getUsedTruck() >0){
        Map[iTruck][jTruck].setUsedTruck(Map[iTruck][jTruck].getUsedTruck()-1);
    }
}