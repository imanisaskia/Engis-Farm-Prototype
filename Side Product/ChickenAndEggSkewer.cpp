#include "ChickenAndEggSkewer.hpp"

/*constructor*/
ChickenAndEggSkewer::ChickenAndEggSkewer(){
    price = 25;
    ingredient1 = 1;
    ingredient2 = 5;
}

/*return ChickenAndEggSkewer price*/
int ChickenAndEggSkewer::getPrice(){
    return price;
}

/*return Ingredient1 type*/
int ChickenAndEggSkewer::getIngredient1(){
    return ingredient1;
}

/*return Ingredient2 type*/
int ChickenAndEggSkewer::getIngredient2(){
    return ingredient2;
}
