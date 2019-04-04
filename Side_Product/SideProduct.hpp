#ifndef SIDEPRODUCT_HPP
#define SIDEPRODUCT_HPP

class SideProduct {
    public:
		/*virtual destructor*/
		virtual ~SideProduct()=0;
    
        /*virtual function to get SideProduct price*/ 
        virtual int getPrice()=0;

        /*virtual function to get Ingredient1 type*/
        virtual int getIngredient1()=0;

        /*virtual function to get Ingredient2 type*/
        virtual int getIngredient2()=0;
};

#endif
