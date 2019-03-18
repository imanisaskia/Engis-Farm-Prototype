#ifndef PRODUCTS_HPP
#define PRODUCTS_HPP

/* ---------- FARM PRODUCTS ---------- */
class FarmProduct {
    public:
        /*virtual function to get FarmProduct type*/
        virtual int getType()=0;

        /*virtual function to get FarmProduct price*/
        virtual int getPrice()=0;
};

class ChickenEgg : public FarmProduct {
    private:
        int type;   //ChickenEgg type = 1
        int price;  //ChickenEgg price

    public:
        ChickenEgg();   //constructor

        /*return ChickenEgg type*/
        int getType();

        /*return ChickenEgg price*/
        int getPrice();
};

class DuckEgg : public FarmProduct {
    private:
        int type;   //DuckEgg type = 2
        int price;  //DuckEgg price

    public:
        DuckEgg();      //constructor

        /*return DuckEgg type*/
        int getType();

        /*return DuckEgg price*/
        int getPrice();
};

class CowMilk : public FarmProduct {
    private:
        int type;   //CowMilk type = 3
        int price;  //CowMilk price

    public:
        CowMilk();      //constructor

        /*return CowMilk type*/
        int getType();

        /*return CowMilk price*/
        int getPrice();
};

class GoatMilk : public FarmProduct {
    private:
        int type;   //GoatMilk type = 4
        int price;  //GoatMilk price

    public:
        GoatMilk();      //constructor

        /*return GoatMilk type*/
        int getType();

        /*return GoatMilk price*/
        int getPrice();
};

class ChickenMeat : public FarmProduct {
    private:
        int type;      //ChickenMeat type = 5
        int price;      //ChickenMeat price

    public:
        ChickenMeat();      //constructor

        /*return ChickenMeat type*/
        int getType();

        /*return ChickenMeat price*/
        int getPrice();
};

class CowMeat : public FarmProduct {
    private:
        int type;      //CowMeat type = 6
        int price;     //CowMeat price

    public:
        CowMeat();      //constructor

        /*return CowMeat type*/
        int getType();

        /*return CowMeat price*/
        int getPrice();
};

class PigMeat : public FarmProduct {
    private:
        int type;   //PigMeat type = 7
        int price;  //PigMeat price

    public:
        PigMeat();      //constructor

        /*return PigMeat type*/
        int getType();

        /*return PigMeat price*/
        int getPrice();
};

class RabbitMeat : public FarmProduct {
    private:
        int type;   //RabbitMeat type = 8
        int price;  //RabbitMeat price

    public:
        RabbitMeat();      //constructor

        /*return RabbitMeat type*/
        int getType();

        /*return RabbitMeat price*/
        int getPrice();
};


/* ---------- SIDE PRODUCTS ---------- */
class SideProduct {
    public:
        /*virtual function to get SideProduct price*/ 
        virtual int getPrice()=0;

        /*virtual function to get Ingredient1 type*/
        virtual int getIngredient1()=0;

        /*virtual function to get Ingredient2 type*/
        virtual int getIngredient2()=0;
};

class BeefStew : public SideProduct {
    private:
        int price;          //BeefStew price
        int ingredient1;    //Ingredient1 type
        int ingredient2;    //Ingredient2 type

    public:
        /*return BeefStew price*/
        int getPrice();

        /*return Ingredient1 type*/
        int getIngredient1();

        /*return Ingredient2 type*/
        int getIngredient2();
};

class PorkStew : public SideProduct {
    private:
        int price;          //PorkStew price
        int ingredient1;    //Ingredient1 type
        int ingredient2;    //Ingredient2 type

    public:
        /*return PorkStew price*/
        int getPrice();

        /*return Ingredient1 type*/
        int getIngredient1();

        /*return Ingredient2 type*/
        int getIngredient2();
};

class Omlette : public SideProduct {
    private:
        int price;          //Omlette price
        int ingredient1;    //Ingredient1 type
        int ingredient2;    //Ingredient2 type

    public:
        /*return Omlette price*/
        int getPrice();

        /*return Ingredient1 type*/
        int getIngredient1();

        /*return Ingredient2 type*/
        int getIngredient2();
};

class ChickenAndEggSkewer : public SideProduct {
    private:
        int price;          //ChickenAndEggSkewer price
        int ingredient1;    //Ingredient1 type
        int ingredient2;    //Ingredient2 type

    public:
        /*return ChickenAndEggSkewer price*/
        int getPrice();

        /*return Ingredient1 type*/
        int getIngredient1();

        /*return Ingredient2 type*/
        int getIngredient2();
};

#endif