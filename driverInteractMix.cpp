#include <iostream>
#include "Player.hpp"

using namespace std;

int main(){
    Player Engi;
	cout<<"Money: "<<Engi.getMoney()<<endl;
	cout<<"Water: "<<Engi.getWater()<<endl;
	cout<<"Position: "<<Engi.getI()<<", "<<Engi.getJ()<<endl;
	cout<<endl;
	
	cout<<"Setter"<<endl;
	Engi.setMoney(10);
	Engi.setWater(11);
	Engi.setI(0);
	Engi.setJ(1);
	cout<<"Money: "<<Engi.getMoney()<<endl;
	cout<<"Water: "<<Engi.getWater()<<endl;
	cout<<"Position: "<<Engi.getI()<<", "<<Engi.getJ()<<endl;
	
	cout<<"checkInteractPosition"<<endl;
	AnimalArray<Chicken> arrchi;
	AnimalArray<Duck> arrdu;
	AnimalArray<Cow> arrco;
	AnimalArray<Goat> arrgo;
	arrchi.newMember();
	arrdu.newMember();
	arrco.newMember();
	arrgo.newMember();
	
	
}
