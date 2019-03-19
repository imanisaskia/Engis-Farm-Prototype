#include "SideProduct.hpp"

#ifndef OMLETTE_HPP
#define OMLETTE_HPP

class Omlette : public SideProduct {
    private:
        int price;          //Omlette price
        int ingredient1;    //Ingredient1 type
        int ingredient2;    //Ingredient2 type

    public:
        /*return Omlette price*/
        int getPrice();

        /*return Ingredient1 type*/
        int getIngredient1();

        /*return Ingredient2 type*/
        int getIngredient2();
};

#endif