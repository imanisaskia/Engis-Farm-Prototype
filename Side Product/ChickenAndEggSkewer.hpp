#include "SideProduct.hpp"

#ifndef CHICKENANDEGGSKEWER_HPP
#define CHICKENANDEGGSKEWER_HPP

class ChickenAndEggSkewer : public SideProduct {
    private:
        int price;          //ChickenAndEggSkewer price
        int ingredient1;    //Ingredient1 type
        int ingredient2;    //Ingredient2 type

    public:
        /*constructor*/
        ChickenAndEggSkewer();

        /*return ChickenAndEggSkewer price*/
        int getPrice();

        /*return Ingredient1 type*/
        int getIngredient1();

        /*return Ingredient2 type*/
        int getIngredient2();
};

#endif