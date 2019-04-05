#include "FarmProduct.hpp"

#ifndef COWMILK_HPP
#define COWMILK_HPP

class CowMilk : public FarmProduct {
    private:
        int type;   /*CowMilk type = 3*/
        int price;  /*CowMilk price*/

    public:
        CowMilk();      /*constructor*/
        ~CowMilk();		/*destructor*/

        /*return CowMilk type*/
        int getType();

        /*return CowMilk price*/
        int getPrice();
};

#endif
