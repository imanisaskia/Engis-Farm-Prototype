#include "Omlette.hpp"

/*constructor*/
Omlette::Omlette(){
    price = 18;
    ingredient1 = 1;
    ingredient2 = 2;
}

/*destructor*/
Omlette::~Omlette(){
}

/*return Omlette price*/
int Omlette::getPrice(){
    return price;
}

/*return Ingredient1 type*/
int Omlette::getIngredient1(){
    return ingredient1;
}

/*return Ingredient2 type*/
int Omlette::getIngredient2(){
    return ingredient2;
}
