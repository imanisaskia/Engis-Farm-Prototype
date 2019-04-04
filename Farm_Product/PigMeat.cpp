#include "PigMeat.hpp"

/*constructor*/
PigMeat::PigMeat(){
    type=7;
    price=18;
}

/*destructor*/
PigMeat::~PigMeat(){
}

/*return PigMeat type*/
int PigMeat::getType(){
    return type;
}

/*return PigMeat price*/
int PigMeat::getPrice(){
    return price;
}
