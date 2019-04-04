#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Bag.hpp"
#include "Farm Animals\Chicken.hpp"
#include "Farm Animals\Duck.hpp"
#include "Farm Animals\Cow.hpp"
#include "Farm Animals\Goat.hpp"
#include "Farm Animals\Pig.hpp"
#include "Farm Animals\Rabbit.hpp"
#include "Farm Animals\FarmAnimal.hpp"
#include "Farm Product\ChickenEgg.hpp"
#include "Farm Product\DuckEgg.hpp"
#include "Farm Product\CowMilk.hpp"
#include "Farm Product\GoatMilk.hpp"
#include "Display\Display.hpp"
#include "Side Product\SideProduct.hpp"
#include "Farm Product\FarmProduct.hpp"

#define MAX_WATER 100

class Player {
    private:
        Bag<FarmProduct*> FPInventory; //FarmProduct inventory
        Bag<SideProduct*> SPInventory; //SideProduct inventory
        int Money;  //Player's amount of money
        int Water;  //Player's amount of water
        int I,J;   // Player's position

    public:
        Player(); //constructor

        //getter
        int getMoney() const;
        int getWater() const;
        int getI() const;
        int getJ() const;

        //setter
        void setMoney(int money);
        void setWater(int water);
        void setI(int i);
        void setJ(int j);

        /*Take ChickenEgg procedure
        throw message if the chicken hasn't produced egg*/
        void Interact(Chicken chicken);

        /*Take DuckEgg procedure
        throw message if the duck hasn't produced egg*/
        void Interact(Duck duck);

        /*Take CowMilk procedure
        throw message if the cow hasn't produced milk*/
        void Interact(Cow cow);

        /*Take GoatMilk procedure
        throw message if the goat hasn't produced milk*/
        void Interact(Goat goat);

        /*Take Water procedure*/
        void InteractWell(Display<FarmAnimal> display);

        /*Sell all products procedure
        throw message if the truck hasn't ready for the next sell*/
        void InteractTruck(Display<FarmAnimal> display);

        /*Mix to get SideProduct
        throw message if ingredient not found, */
        void Mix(Display<FarmAnimal> display, SideProduct* sideproduct);

        //ambil daging
        //input = binatangnya
        //output = binatang ilang satu, inventori nambah sesuai binatangnya
        void Kill(Chicken chicken);
        void Kill(Cow cow);
        void Kill(Duck duck);
        void Kill(Goat goat);
        void Kill(Pig pig);
        void Kill(Rabbit rabbit);

        //player jalan
        //parameter = menentukan mau jalan ke mana (U = Up, D = Down, L = Left, R = Right)
        //output = I dan J dari player berubah sesuai parameter
        void Walk(char walk);

        // numbuhin rumput di koordinat <i,j> di map/grid
        void Grow();
};

#endif
