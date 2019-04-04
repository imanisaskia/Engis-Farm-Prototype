#include "ChickenMeat.hpp"

/*constructor*/
ChickenMeat::ChickenMeat(){
    type=5;
    price=15;
}

ChickenMeat::~ChickenMeat(){
}

/*return ChickenMeat type*/
int ChickenMeat::getType(){
    return type;
}

/*return ChickenMeat price*/
int ChickenMeat::getPrice(){
    return price;
}
