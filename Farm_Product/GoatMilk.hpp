#include "FarmProduct.hpp"

#ifndef GOATMILK_HPP
#define GOATMILK_HPP

class GoatMilk : public FarmProduct {
    private:
        int type;   /*GoatMilk type = 4*/
        int price;  /*GoatMilk price*/

    public:
        GoatMilk();      /*constructor*/
        ~GoatMilk();

        /*return GoatMilk type*/
        int getType();

        /*return GoatMilk price*/
        int getPrice();
};

#endif
