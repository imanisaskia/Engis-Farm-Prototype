#include <iostream>
#include "Player.hpp"

using namespace std;

void Player::Talk(Chicken chicken, Display D) {
  D.printSentences(chicken.getNoise());
}
void Player::Talk(Cow cow, Display D) {
  D.printSentences(cow.getNoise());
}
void Player::Talk(Duck duck, Display D) {
  D.printSentences(duck.getNoise());
}
void Player::Talk(Goat goat, Display D) {
  D.printSentences(goat.getNoise());
}
void Player::Talk(Pig pig, Display D) {
  D.printSentences(pig.getNoise());
}
void Player::Talk(Rabbit rabbit, Display D) {
  D.printSentences(rabbit.getNoise());
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

bool Player::isBisaDiinjek(int i, int j, Display D, AnimalArray<FarmAnimal> arr) {
  return (((D.checkLand(i,j,1) || D.checkLand(i,j,2) || D.checkLand(i,j,3))) && (arr.getNearbyAnimal(i,j) == -999));
}

void Player::Walk(char walk, Display D, AnimalArray<FarmAnimal> arr) {
  if (walk == 'U' || walk == 'u') {
    if ((getJ() < 10) && (isBisaDiinjek(getI(), getJ()+1, D, arr))) {
      setJ(J+1);
    }
  }
  else if (walk == 'D' || walk == 'd') {
    if ((getJ() > 0) && (isBisaDiinjek(getI(), getJ()-1, D, arr))) {
      setJ(J-1);
    }
  }
  else if (walk == 'L' || walk == 'l') {
    if ((getI() > 0) && (isBisaDiinjek(getI()-1, getJ(), D, arr))) {
      setI(I-1);
    }
  }
  else if (walk == 'R' || walk == 'r') {
    if ((getI() < 10) && (isBisaDiinjek(getI()+1, getJ(), D, arr))) {
      setI(I-1);
    }
  }
  else {
    D.printSentences("Input tidak valid");
  }
}

void Player::Grow(Display& D) {
  if ((D.checkLand(getI(),getJ(),1) || D.checkLand(getI(),getJ(),2) || D.checkLand(getI(),getJ(),3)) && !D.checkGrassy(getI(),getJ())) {
    D.modifyGrassy(getI(),getJ());
    setWater(getWater()-1);
  }
  else {
    D.printSentences("Tidak bisa menumbuhkan rumput");
  }
}
