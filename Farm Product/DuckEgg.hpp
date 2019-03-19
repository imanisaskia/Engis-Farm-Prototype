#include "FarmProduct.hpp"

#ifndef DUCKEGG_HPP
#define DUCKEGG_HPP

class DuckEgg : public FarmProduct {
    private:
        int type;   //DuckEgg type = 2
        int price;  //DuckEgg price

    public:
        DuckEgg();      //constructor

        /*return DuckEgg type*/
        int getType();

        /*return DuckEgg price*/
        int getPrice();
};

#endif