#ifndef FARMPRODUCT_HPP
#define FARMPRODUCT_HPP

class FarmProduct {
    public:
        /*virtual function to get FarmProduct type*/
        virtual int getType()=0;

        /*virtual function to get FarmProduct price*/
        virtual int getPrice()=0;
};

#endif