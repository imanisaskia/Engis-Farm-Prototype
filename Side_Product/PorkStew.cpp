#include "PorkStew.hpp"

/*constructor*/
PorkStew::PorkStew(){
    price = 38;
    ingredient1 = 4;
    ingredient2 = 7;
}

/*destructor*/
PorkStew::~PorkStew(){
}

/*return PorkStew price*/
int PorkStew::getPrice(){
    return price;
}

/*return Ingredient1 type*/
int PorkStew::getIngredient1(){
    return ingredient1;
}

/*return Ingredient2 type*/
int PorkStew::getIngredient2(){
    return ingredient2;
}
