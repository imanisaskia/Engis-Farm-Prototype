#include "FarmProduct.hpp"

#ifndef CHICKENMEAT_HPP
#define CHICKENMEAT_HPP

class ChickenMeat : public FarmProduct {
    private:
        int type;      /*ChickenMeat type = 5*/
        int price;      /*ChickenMeat price*/

    public:
        ChickenMeat();      /*constructor*/
        ~ChickenMeat();		/*destructor*/

        /*return ChickenMeat type*/
        int getType();

        /*return ChickenMeat price*/
        int getPrice();
};

#endif
