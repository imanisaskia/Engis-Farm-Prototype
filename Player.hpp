#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include "Bag.hpp"
#include "Farm_Animals\Chicken.hpp"
#include "Farm_Animals\Duck.hpp"
#include "Farm_Animals\Cow.hpp"
#include "Farm_Animals\Goat.hpp"
#include "Farm_Animals\Pig.hpp"
#include "Farm_Animals\Rabbit.hpp"
#include "Farm_Animals\FarmAnimal.hpp"
#include "Farm_Animals\AnimalArray.hpp"
#include "Farm_Product\ChickenEgg.hpp"
#include "Farm_Product\DuckEgg.hpp"
#include "Farm_Product\CowMilk.hpp"
#include "Farm_Product\GoatMilk.hpp"
#include "Farm_Product\ChickenMeat.hpp"
#include "Farm_Product\PigMeat.hpp"
#include "Farm_Product\CowMeat.hpp"
#include "Farm_Product\RabbitMeat.hpp"
#include "Display\Display.hpp"
#include "Side_Product\SideProduct.hpp"
#include "Farm_Product\FarmProduct.hpp"

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

        /*Check FarmAnimal position and Land type
        if exist and valid for Interact, return animal type and index (Chicken=1, Duck=2, Cow=3, Goat=4)*/
        void checkInteractPosition(AnimalArray<Chicken> arrChicken, AnimalArray<Duck> arrDuck, AnimalArray<Cow> arrCow, AnimalArray<Goat> arrGoat,Display display, int direction, int& type, int& idx);

        /*Take ChickenEgg procedure
        throw message if the chicken hasn't produced egg*/
        void Interact(Chicken& chicken, bool& success);

        /*Take DuckEgg procedure
        throw message if the duck hasn't produced egg*/
        void Interact(Duck& duck, bool& success);

        /*Take CowMilk procedure
        throw message if the cow hasn't produced milk*/
        void Interact(Cow& cow, bool& success);

        /*Take GoatMilk procedure
        throw message if the goat hasn't produced milk*/
        void Interact(Goat& goat, bool& success);

        /*Take Water procedure*/
        void InteractWell(Display display, char position, bool& success);

        /*Sell all products procedure
        throw message if the truck hasn't ready for the next sell*/
        void InteractTruck(Display& display, char direction, bool& success);

        /*Mix to get SideProduct
        throw message if ingredient not found, */
        void Mix(Display& display, SideProduct* sideproduct, int direction, bool& succ);

        // player ngajak ngomong animal
        // input = binatangnya & display yg dipake
        // output = binatangnya ngomong
        std::string Talk(Chicken chicken, Display D);
        std::string Talk(Cow cow, Display D);
        std::string Talk(Duck duck, Display D);
        std::string Talk(Goat goat, Display D);
        std::string Talk(Pig pig, Display D);
        std::string Talk(Rabbit rabbit, Display D);

        //ambil daging
        //input = binatangnya & array animal yg dipake
        //output = binatang ilang satu, inventori nambah sesuai binatangnya
        void Kill(Chicken chicken, AnimalArray<Chicken>&);
        void Kill(Cow cow, AnimalArray<Cow>&);
        void Kill(Pig pig, AnimalArray<Pig>&);
        void Kill(Rabbit rabbit, AnimalArray<Rabbit>&);

        bool isBisaDiinjek(int i, int j, Display D, AnimalArray<Chicken> arrChicken, AnimalArray<Duck> arrDuck, AnimalArray<Cow> arrCow, AnimalArray<Goat> arrGoat, AnimalArray<Rabbit> arrRabbit, AnimalArray<Pig> arrPig);

        //player jalan
        //parameter = menentukan mau jalan ke mana (U = Up, D = Down, L = Left, R = Right)
        //output = I dan J dari player berubah sesuai parameter
        void Walk(char walk, Display D, AnimalArray<Chicken> arrChicken, AnimalArray<Duck> arrDuck, AnimalArray<Cow> arrCow, AnimalArray<Goat> arrGoat, AnimalArray<Rabbit> arrRabbit, AnimalArray<Pig> arrPig);

        // numbuhin rumput di koordinat <i,j> di map/grid
        void Grow(Display& D);
};

#endif
