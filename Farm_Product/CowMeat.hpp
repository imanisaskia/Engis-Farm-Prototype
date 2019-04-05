#include "FarmProduct.hpp"

#ifndef COWMEAT_HPP
#define COWMEAT_HPP

class CowMeat : public FarmProduct {
    private:
        int type;      /*CowMeat type = 6*/
        int price;     /*CowMeat price*/

    public:
        CowMeat();      /*constructor*/
        ~CowMeat();		/*destructor*/

        /*return CowMeat type*/
        int getType();

        /*return CowMeat price*/
        int getPrice();
};

#endif
