#include "ChickenEgg.hpp"

/*constructor*/
ChickenEgg::ChickenEgg(){
    type=1;
    price=5;
}

/*return ChickenEgg type*/
int ChickenEgg::getType(){
    return type;
}

/*return ChickenEgg price*/
int ChickenEgg::getPrice(){
    return price;
}
