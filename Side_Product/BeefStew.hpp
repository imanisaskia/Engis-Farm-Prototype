#include "SideProduct.hpp"

#ifndef BEEFSTEW_HPP
#define BEEFSTEW_HPP

class BeefStew : public SideProduct {
    private:
        int price;          //BeefStew price
        int ingredient1;    //Ingredient1 type
        int ingredient2;    //Ingredient2 type

    public:
        /*constructor*/
        BeefStew();
        /*destructor*/
        ~BeefStew();

        /*return BeefStew price*/
        int getPrice();

        /*return Ingredient1 type*/
        int getIngredient1();

        /*return Ingredient2 type*/
        int getIngredient2();
};

#endif
