#include "Bag.hpp"
#include "Farm_Product\ChickenEgg.hpp"
#include "Farm_Product\CowMeat.hpp"
#include "Side_Product\BeefStew.hpp"
#include "Side_Product\Omlette.hpp"
#include <iostream>
using namespace std;

int main(){
    try{
		//mencoba dengan elemen int
		/*Bag<int> a;
		cout<<"isEmpty"<<a.isEmpty()<<endl;
		a.add(5);
		a.add(3);
		cout<<"find 5 "<<a.find(5)<<endl;
		cout<<"find 3 "<<a.find(3)<<endl;
		cout<<"get idx 1"<<a.get(1)<<endl;
		a.remove(5);
		cout<<"remove(5)"<<endl;
		cout<<"find 5 "<<a.find(5)<<endl;*/
		
		bool success=false;
		
		/*------- FarmProduct------*/
		cout<<"FARM PRODUCT"<<endl;
		/*cara add*/
		Bag<FarmProduct*> bag;
		FarmProduct *CE = new ChickenEgg();
		FarmProduct *CM = new CowMeat();
		bag.add(CE);
		bag.add(CM);
		cout<<bag.get(0)->getType()<<endl;
		cout<<bag.get(0)->getPrice()<<endl;
		
		/*cara remove ChickenEgg*/
		
		cout<<bag.find(CE)<<endl;
		bag.typeBasedRemove(1,success);	//cari element yang tipenya 1 lalu remove
		
		cout<<"removed"<<endl;
		cout<<bag.find(CE)<<endl;
		cout<<bag.find(CM)<<endl;
		cout<<bag.get(0)->getType()<<endl;
		cout<<bag.get(0)->getPrice()<<endl;
		
		/*-----SideProduct-----*/
		cout<<endl;
		cout<<"SIDE PRODUCT"<<endl;
		/*cara add*/
		Bag<SideProduct*> bagSP;
		SideProduct *BS = new BeefStew();
		SideProduct *OM = new Omlette();
		bagSP.add(BS);
		bagSP.add(OM);
		cout<<bagSP.get(0)->getIngredient1()<<endl;
		cout<<bagSP.get(0)->getPrice()<<endl;
		
		/*cara remove Omlette*/
		
		cout<<bagSP.find(OM)<<endl;
		bagSP.typeBasedRemove(1,2,success);	//cari element yang ingredient 1, ingredient 2 lalu remove
		
		cout<<"removed"<<endl;
		cout<<bagSP.find(BS)<<endl;
		cout<<bagSP.find(OM)<<endl;
		cout<<bagSP.get(0)->getIngredient1()<<endl;
		cout<<bagSP.get(0)->getIngredient2()<<endl;
		cout<<bagSP.get(0)->getPrice()<<endl;
		
	}
	catch(char const* a){
		cout<<a<<endl;
	}


    return 0;
}
