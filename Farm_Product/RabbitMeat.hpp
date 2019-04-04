#include "FarmProduct.hpp"

#ifndef RABBITMEAT_HPP
#define RABBITMEAT_HPP

class RabbitMeat : public FarmProduct {
    private:
        int type;   //RabbitMeat type = 8
        int price;  //RabbitMeat price

    public:
        RabbitMeat();      //constructor
        ~RabbitMeat();		//destructor

        /*return RabbitMeat type*/
        int getType();

        /*return RabbitMeat price*/
        int getPrice();
};

#endif
