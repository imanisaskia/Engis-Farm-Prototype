#include "BeefStew.hpp"

/*constructor*/
BeefStew::BeefStew(){
    price = 40;
    ingredient1 = 6;
    ingredient2 = 3;
}

/*return BeefStew price*/
int BeefStew::getPrice(){
    return price;
}

/*return Ingredient1 type*/
int BeefStew::getIngredient1(){
    return ingredient1;
}

/*return Ingredient2 type*/
int BeefStew::getIngredient2(){
    return ingredient2;
}
