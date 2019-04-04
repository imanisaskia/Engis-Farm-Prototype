#include "Bag.hpp"
#include "Farm_Product\ChickenEgg.hpp"
#include "Farm_Product\CowMeat.hpp"
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
		bag.typeBasedRemove(1,success);
		
		//cari element yang tipenya 1 lalu remove
		
		cout<<"removed"<<endl;
		cout<<bag.find(CE)<<endl;
		cout<<bag.find(CM)<<endl;
		cout<<bag.get(0)->getType()<<endl;
		cout<<bag.get(0)->getPrice()<<endl;

	}
	catch(char const* a){
		cout<<a<<endl;
	}


    return 0;
}
