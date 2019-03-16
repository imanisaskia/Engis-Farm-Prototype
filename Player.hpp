#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Bag.hpp"
#include "Products.hpp"

class Player {
    private:
        Bag<FarmProduct> FPInventory; //FarmProduct inventory
        Bag<SideProduct> SPInventory; //SideProduct inventory
        int Money;
        int Water;
        int I,J;   // player position

}; 

#endif