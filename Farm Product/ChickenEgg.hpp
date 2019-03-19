#include "FarmProducts.hpp"

#ifndef CHICKENEGG_HPP
#define CHICKENEGG_HPP

class ChickenEgg : public FarmProduct {
    private:
        int type;   //ChickenEgg type = 1
        int price;  //ChickenEgg price

    public:
        ChickenEgg();   //constructor

        /*return ChickenEgg type*/
        int getType();

        /*return ChickenEgg price*/
        int getPrice();
};

#endif