#include "RabbitMeat.hpp"

/*constructor*/
RabbitMeat::RabbitMeat(){
    type=8;
    price=17;
}

/*destructor*/
RabbitMeat::~RabbitMeat(){
}

/*return RabbitMeat type*/
int RabbitMeat::getType(){
    return type;
}

/*return RabbitMeat price*/
int RabbitMeat::getPrice(){
    return price;
}
