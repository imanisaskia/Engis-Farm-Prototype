#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <list>

class Player {
    private:
        list<FarmProduct> Inventory1;   // max capacity?
        list<SideProduct> Inventory2;
        int Money;
        int Water;
        int X, Y;   // player position

};

#endif