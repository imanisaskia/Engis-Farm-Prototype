#include "CowMilk.hpp"

/*constructor*/
CowMilk::CowMilk(){
    type=3;
    price = 10;
}  

/*return CowMilk type*/
int CowMilk::getType(){
    return type;
}

/*return CowMilk price*/
int CowMilk::getPrice(){
    return price;
}