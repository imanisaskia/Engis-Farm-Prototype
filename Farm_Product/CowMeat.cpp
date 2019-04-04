#include "CowMeat.hpp"

/*constructor*/
CowMeat::CowMeat(){
    type=6;
    price=20;
}

/*destructor*/
CowMeat::~CowMeat(){
}

/*return CowMeat type*/
int CowMeat::getType(){
    return type;
}

/*return CowMeat price*/
int CowMeat::getPrice(){
    return price;
}
