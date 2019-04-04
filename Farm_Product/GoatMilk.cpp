#include "GoatMilk.hpp"

/*constructor*/
GoatMilk::GoatMilk(){
    type=4;
    price=12;
}

/*destructor*/
GoatMilk::~GoatMilk(){
}

/*return GoatMilk type*/
int GoatMilk::getType(){
    return type;
}

/*return GoatMilk price*/
int GoatMilk::getPrice(){
    return price;
}
