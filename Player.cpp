#include "Player.hpp"
#include <string>
#include <iostream>

Bag<FarmProduct*> FPInventory; /*FarmProduct inventory*/
Bag<SideProduct*> SPInventory; /*SideProduct inventory*/
int Money;  /*Player's amount of money*/
int Water;  /*Player's amount of water*/
int I,J;   /* Player's position*/

/*constructor*/
Player::Player(){
    Money = 0;
    Water = 50;
    I = 5;
    J = 5;
}

/*getter*/
int Player::getMoney() const{
    return Money;
}
int Player::getWater() const{
    return Water;
}
int Player::getI() const{
    return I;
}
int Player::getJ() const{
    return J;
}
Bag<FarmProduct*> Player::getBagFP(){
	return FPInventory;
}
Bag<SideProduct*> Player::getBagSP(){
	return SPInventory;
}

/*setter*/
void Player::setMoney(int money){
    Money = money;
}
void Player::setWater(int water){
    Water = water;
}
void Player::setI(int i){
    I = i;
}
void Player::setJ(int j){
    J=j;
}

 /*Check FarmAnimal position and Land type
if exist and valid for Interact, return animal type and index (Chicken=1, Duck=2, Cow=3, Goat=4)
else return type -999 or idx -999*/
void checkInteractPosition(AnimalArray<Chicken> arrChicken, AnimalArray<Duck> arrDuck, AnimalArray<Cow> arrCow, AnimalArray<Goat> arrGoat,Display display, char direction, int& type, int& idx){
	int ich,idu,ico,igo;

	type=-999;
	idx=-999;
	if((direction =='u' || direction =='U')&& I-1>=0){
		ich = arrChicken.getNearbyAnimal(I-1,J);
		idu = arrDuck.getNearbyAnimal(I-1,J);
		ico = arrCow.getNearbyAnimal(I-1,J);
		igo = arrGoat.getNearbyAnimal(I-1,J);
		if(ich !=-999){
			idx=ich;
			if(display.checkLand(I-1,J,3)){
				type=1;
			}
		}else if(idu !=-999){
			idx=idu;
			if(display.checkLand(I-1,J,3)){
				type=2;
			}
		}else if(ico !=-999){
			idx=ico;
			if(display.checkLand(I-1,J,2)){
				type=3;
			}
		}else{
			idx=igo;
			if(display.checkLand(I-1,J,2)){
				type=4;
			}
		}
	}else if((direction =='d' || direction =='D')&& I+1<=10){
		ich = arrChicken.getNearbyAnimal(I+1,J);
		idu = arrDuck.getNearbyAnimal(I+1,J);
		ico = arrCow.getNearbyAnimal(I+1,J);
		igo = arrGoat.getNearbyAnimal(I+1,J);
		if(ich !=-999){
			idx=ich;
			if(display.checkLand(I+1,J,3)){
				type=1;
			}
		}else if(idu !=-999){
			idx=idu;
			if(display.checkLand(I+1,J,3)){
				type=2;
			}
		}else if(ico !=-999){
			idx=ico;
			if(display.checkLand(I+1,J,2)){
				type=3;
			}
		}else{
			idx=igo;
			if(display.checkLand(I+1,J,2)){
				type=4;
			}
		}
	}else if((direction =='l' || direction =='L')&& J-1>=0){
		ich = arrChicken.getNearbyAnimal(I,J-1);
		idu = arrDuck.getNearbyAnimal(I,J-1);
		ico = arrCow.getNearbyAnimal(I,J-1);
		igo = arrGoat.getNearbyAnimal(I,J-1);
		if(ich !=-999){
			idx=ich;
			if(display.checkLand(I,J-1,3)){
				type=1;
			}
		}else if(idu !=-999){
			idx=idu;
			if(display.checkLand(I,J-1,3)){
				type=2;
			}
		}else if(ico !=-999){
			idx=ico;
			if(display.checkLand(I,J-1,2)){
				type=3;
			}
		}else{
			idx=igo;
			if(display.checkLand(I,J-1,2)){
				type=4;
			}
		}
	}else if((direction =='r' || direction =='R')&& J+1<=10){
		ich = arrChicken.getNearbyAnimal(I,J+1);
		idu = arrDuck.getNearbyAnimal(I,J+1);
		ico = arrCow.getNearbyAnimal(I,J+1);
		igo = arrGoat.getNearbyAnimal(I,J+1);
		if(ich !=-999){
			idx=ich;
			if(display.checkLand(I,J+1,3)){
				type=1;
			}
		}else if(idu !=-999){
			idx=idu;
			if(display.checkLand(I,J+1,3)){
				type=2;
			}
		}else if(ico !=-999){
			idx=ico;
			if(display.checkLand(I,J+1,2)){
				type=3;
			}
		}else{
			idx=igo;
			if(display.checkLand(I,J+1,2)){
				type=4;
			}
		}
	}
}

/*Take ChickenEgg procedure
karena method ini dipakai setelah checkInteractPosition, sudah pasti bukan MeatProducingAnimal*/
void Player::Interact(Chicken& chicken, bool& success){
    if(chicken.isProductive()){
        chicken.setUnproductive();
        FPInventory.add(new ChickenEgg);
        success=true;
    }else{
        success=false;
	}
}

/*Take DuckEgg procedure
karena method ini dipakai setelah checkInteractPosition, sudah pasti bukan MeatProducingAnimal*/
void Player::Interact(Duck& duck, bool& success){
    if(duck.isProductive()){
        duck.setUnproductive();
        FPInventory.add(new DuckEgg);
        success=true;
    }else{
        success=false;
    }
}

/*Take CowMilk procedure
karena method ini dipakai setelah checkInteractPosition, sudah pasti bukan MeatProducingAnimal*/
void Player::Interact(Cow& cow, bool& success){
    if(cow.isProductive()){
        cow.setUnproductive();
        FPInventory.add(new CowMilk);
        success=true;
    }else{
        success=false;
    }
}

/*Take GoatMilk procedure
karena method ini dipakai setelah checkInteractPosition, sudah pasti bukan MeatProducingAnimal*/
void Player::Interact(Goat& goat,bool& success){
    if(goat.isProductive()){
        goat.setUnproductive();
        FPInventory.add(new GoatMilk);
        success=true;
    }else{
        success=false;
    }
}

/*Take Water procedure*/
void Player::InteractWell(Display display, char position, bool& success){
    bool Facility=false;
    if((position=='U' || position =='u') && I-1>=0){
		Facility=display.checkFacility(I-1,J,1);
	}else if((position=='D' || position =='d') && I+1<=10){
		Facility=display.checkFacility(I+1,J,1);
	}else if((position=='L' || position =='l') && J-1>=0){
		Facility=display.checkFacility(I,J-1,1);
	}else if((position=='R' || position=='r') && J+1<=10){
		Facility=display.checkFacility(I,J+1,1);
	}
    if(Facility && Water!= MAX_WATER){
        if(Water <= MAX_WATER-30){
            Water +=30;
            success=true;
        }else{
            Water = MAX_WATER;
            success=true;
        }
    }else{
       success=false;
    }
}

/*Sell all products procedure*/
void InteractTruck(Display& display, char direction, bool& success){
	bool Facility=false;
	bool check=false;
	int i,j;
    if((direction=='U' || direction =='u') && I-1>=0){
		Facility=display.checkFacility(I-1,J,3);
		check = display.checkUsedTruck(I-1,J);
		i=I-1;
		j=J;
	}else if((direction=='D' || direction =='d') && I+1<=10){
		Facility=display.checkFacility(I+1,J,3);
		check = display.checkUsedTruck(I+1,J);
		i=I+1;
		j=J;
	}else if((direction=='L' || direction =='l') && J-1>=0){
		Facility=display.checkFacility(I,J-1,3);
		check = display.checkUsedTruck(I,J-1);
		i=I;
		j=J-1;
	}else if((direction=='R' || direction=='r') && J+1<=10){
		Facility=display.checkFacility(I,J+1,3);
		check = display.checkUsedTruck(I,J+1);
		i=I;
		j=J+1;
	}
	if(Facility && check){
		display.modifyUsedTruck(i,j);
		//jual semua barang
		for(int i=0; i<FPInventory.getSize();i++){
			Money += (FPInventory.get(i))->getPrice();
			FPInventory.remove(FPInventory.get(i));
		}
		for(int i=0; i<SPInventory.getSize();i++){
			Money +=(SPInventory.get(i))->getPrice();
			SPInventory.remove(SPInventory.get(i));
		}
		success=true;
	}else{
		success=false;
	}
}

/*Mix to get SideProduct*/
void Mix(Display& display, SideProduct* sideproduct, int direction, bool& succ){
	bool Facility=false;
	bool success=false;
    if((direction=='U' || direction =='u') && I-1>=0){
		Facility=display.checkFacility(I-1,J,2);
	}else if((direction=='D' || direction =='d') && I+1<=10){
		Facility=display.checkFacility(I+1,J,2);
	}else if((direction=='L' || direction =='l') && J-1>=0){
		Facility=display.checkFacility(I,J-1,2);
	}else if((direction=='R' || direction=='r') && J+1<=10){
		Facility=display.checkFacility(I,J+1,2);
	}
	if(Facility){
		int ing1 = sideproduct->getIngredient1();
		int ing2 = sideproduct->getIngredient2();
		/*remove ingredient in FPInventory*/
		FPInventory.typeBasedRemove(ing1, success);
		if(success){
			FPInventory.typeBasedRemove(ing2, success);
			if(success){
				SPInventory.add(sideproduct);
				succ=true;
			}else{
				succ=false;
			}
		}else{
			succ=false;
		}
	}else{
		succ=false;
	}
}

/*ambil daging
input = binatangnya
output = binatang ilang satu, inventori nambah sesuai binatangnya*/
std::string Player::Talk(int i, int j, Chicken chicken, Cow cow, Duck duck, Rabbit rabbit, Pig pig, Goat goat, AnimalArray<Chicken> arrChicken, AnimalArray<Duck> arrDuck, AnimalArray<Cow> arrCow, AnimalArray<Goat> arrGoat, AnimalArray<Rabbit> arrRabbit, AnimalArray<Pig> arrPig) {
  if (arrChicken.getNearbyAnimal(i,j) != -999) {
    return chicken.getNoise();
  }
  else if (arrCow.getNearbyAnimal(i,j) != -999) {
    return cow.getNoise();
  }
  else if (arrDuck.getNearbyAnimal(i,j) != -999) {
    return duck.getNoise();
  }
  else if (arrRabbit.getNearbyAnimal(i,j) != -999) {
    return rabbit.getNoise();
  }
  else if (arrGoat.getNearbyAnimal(i,j) != -999) {
    return goat.getNoise();
  }
  else if (arrPig.getNearbyAnimal(i,j) != -999) {
    return pig.getNoise();
  }
  else {
    return ("*sunyi*");
  }
}

std::string Player::Talk(Chicken chicken) {
  return (chicken.getNoise());
}
std::string Player::Talk(Cow cow) {
  return (cow.getNoise());
}
std::string Player::Talk(Duck duck) {
  return (duck.getNoise());
}
std::string Player::Talk(Goat goat) {
  return (goat.getNoise());
}
std::string Player::Talk(Pig pig) {
  return (pig.getNoise());
}
std::string Player::Talk(Rabbit rabbit) {
  return (rabbit.getNoise());
}


void Player::Kill(int i, int j, Chicken chicken, Cow cow, Rabbit rabbit, Pig pig, AnimalArray<Chicken>& arrChicken, AnimalArray<Cow>& arrCow, AnimalArray<Rabbit>& arrRabbit, AnimalArray<Pig>& arrPig) {
  if (arrChicken.getNearbyAnimal(i,j) != -999) {
    Kill(chicken, arrChicken);
  }
  else if (arrCow.getNearbyAnimal(i,j) != -999) {
    Kill(cow, arrCow);
  }
  else if (arrRabbit.getNearbyAnimal(i,j) != -999) {
    Kill(rabbit, arrRabbit);
  }
  else if (arrPig.getNearbyAnimal(i,j) != -999) {
    Kill(pig, arrPig);
  }
}

void Player::Kill(Chicken chicken, AnimalArray<Chicken> &arrChicken) {
  int idx = arrChicken.getNearbyAnimal(getI(), getJ());
  arrChicken.removeMember(idx);
  FPInventory.add(new ChickenMeat);
}

void Player::Kill(Cow cow, AnimalArray<Cow> &arrCow) {
  int idx = arrCow.getNearbyAnimal(getI(), getJ());
  arrCow.removeMember(idx);
  FPInventory.add(new CowMeat);
}

void Player::Kill(Pig pig, AnimalArray<Pig> &arrPig) {
  int idx = arrPig.getNearbyAnimal(getI(), getJ());
  arrPig.removeMember(idx);
  FPInventory.add(new PigMeat);
}

void Player::Kill(Rabbit rabbit, AnimalArray<Rabbit> &arrRabbit) {
  int idx = arrRabbit.getNearbyAnimal(getI(), getJ());
  arrRabbit.removeMember(idx);
  FPInventory.add(new RabbitMeat);
}

bool Player::isBisaDiinjek(int i, int j, Display D, AnimalArray<Chicken> arrChicken, AnimalArray<Duck> arrDuck, AnimalArray<Cow> arrCow, AnimalArray<Goat> arrGoat, AnimalArray<Rabbit> arrRabbit, AnimalArray<Pig> arrPig) {
  return (((D.checkLand(i,j,1) || D.checkLand(i,j,2) || D.checkLand(i,j,3))) && (arrChicken.getNearbyAnimal(i,j) == -999) && (arrCow.getNearbyAnimal(i,j) == -999) && (arrDuck.getNearbyAnimal(i,j) == -999) && (arrGoat.getNearbyAnimal(i,j) == -999) && (arrRabbit.getNearbyAnimal(i,j) == -999) && (arrPig.getNearbyAnimal(i,j) == -999));
}

void Player::Walk(char walk, Display D, AnimalArray<Chicken> arrChicken, AnimalArray<Duck> arrDuck, AnimalArray<Cow> arrCow, AnimalArray<Goat> arrGoat, AnimalArray<Rabbit> arrRabbit, AnimalArray<Pig> arrPig) {
  if (walk == 'U' || walk == 'u') {
    if ((getJ() < 10) && (isBisaDiinjek(getI(), getJ()+1, D, arrChicken, arrDuck, arrCow, arrGoat, arrRabbit, arrPig))) {
      setJ(J+1);
    }
  }
  else if (walk == 'D' || walk == 'd') {
    if ((getJ() > 0) && (isBisaDiinjek(getI(), getJ()-1, D, arrChicken, arrDuck, arrCow, arrGoat, arrRabbit, arrPig))) {
      setJ(J-1);
    }
  }
  else if (walk == 'L' || walk == 'l') {
    if ((getI() > 0) && (isBisaDiinjek(getI()-1, getJ(), D, arrChicken, arrDuck, arrCow, arrGoat, arrRabbit, arrPig))) {
      setI(I-1);
    }
  }
  else if (walk == 'R' || walk == 'r') {
    if ((getI() < 10) && (isBisaDiinjek(getI()+1, getJ(), D, arrChicken, arrDuck, arrCow, arrGoat, arrRabbit, arrPig))) {
      setI(I+1);
    }
  }
  /* else {
     D.printSentences("Input tidak valid");
   }*/
}

void Player::Grow(Display& D) {
  if ((D.checkLand(getI(),getJ(),1) || D.checkLand(getI(),getJ(),2) || D.checkLand(getI(),getJ(),3)) && !D.checkGrassy(getI(),getJ())) {
    D.modifyGrassy(getI(),getJ());
    setWater(getWater()-1);
  }
  /* else {
     D.printSentences("Tidak bisa menumbuhkan rumput");
   }*/
}
