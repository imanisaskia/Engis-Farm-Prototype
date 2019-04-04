#include "SideProduct.hpp"

#ifndef PORKSTEW_HPP
#define PORKSTEW_HPP

class PorkStew : public SideProduct {
    private:
        int price;          //PorkStew price
        int ingredient1;    //Ingredient1 type
        int ingredient2;    //Ingredient2 type

    public:
        /*constructor*/
        PorkStew();
        /*destructor*/
        ~PorkStew();

        /*return PorkStew price*/
        int getPrice();

        /*return Ingredient1 type*/
        int getIngredient1();

        /*return Ingredient2 type*/
        int getIngredient2();
};

#endif
