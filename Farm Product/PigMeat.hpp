#include "FarmProduct.hpp"

#ifndef PIGMEAT_HPP
#define PIGMEAT_HPP

class PigMeat : public FarmProduct {
    private:
        int type;   //PigMeat type = 7
        int price;  //PigMeat price

    public:
        PigMeat();      //constructor

        /*return PigMeat type*/
        int getType();

        /*return PigMeat price*/
        int getPrice();
};

#endif