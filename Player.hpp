#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Bag.hpp"
#include "Products.hpp"
#include "FarmAnimal.hpp"
#include "Display.hpp"

class Player {
    private:
        Bag<FarmProduct*> FPInventory; //FarmProduct inventory
        Bag<SideProduct*> SPInventory; //SideProduct inventory
        int Money;  //Player's amount of money
        int Water;  //Player's amount of water
        int I,J;   // Player's position

    public:
        Player(); //constructor
        
        /*Display all possible objects that can be interacted with for user's choice if there are several possible objects.
        If there is only one possible object, Interact(ObjectType object).
        If the object is farm animal, check it's position grid type, only display animal that produce milk or egg */
        void ShowInteractNearby(Display display, AnimalArray<Chicken> arrChicken, AnimalArray<Duck> arrDuck, AnimalArray<Cow> arrCow, AnimalArray<Goat> arrGoat, Well well, Truck truck);

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
        void Interact(Well well);

        /*Sell all products procedure
        throw message if the truck hasn't ready for the next sell*/
        void Interact(Truck truck);

        /*Mix to get SideProduct
        throw message if the mixer is unreachable or ingredient not found, */
        void Mix(Mixer mixer, SideProduct* sideproduct);
}; 

#endif
