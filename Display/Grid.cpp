#include "Grid.hpp"
#include <iostream>

int Grid::getType(){
    return Type;
}
bool Grid::getGrassy(){
    return Grassy;
}
bool Grid::getLand(){
    return Land;
}

bool Grid::getFacility(){
    return Facility;
}

int Grid::getUsedTruck(){
    return UsedTruck;
}

void Grid::setType(int T){
    Type = T;
}

void Grid::setGrassy(bool G){
    Grassy = G;
}

void Grid::setLand(bool L){
    Land = L;
}

void Grid::setFacility(bool F){
    Facility = F;
}

void Grid::setUsedTruck(int UT){
    UsedTruck = UT;
}


//Mengurangi nilai variabel UsedTruck jika nilai UsedTruck > 0
void Grid::lessenTruck(){
    if (UsedTruck >0){
        UsedTruck -= 1;
    }
}

//Menambah nilai variabel UsedTruck saat Truck dipakai
bool Grid::useTruck(){
    if (UsedTruck != 0){
        setUsedTruck(5);
        return true;
    } else{
        throw("Cannot use the Truck that fast man ! Truck driver is still tired");
        return false;
    }
}