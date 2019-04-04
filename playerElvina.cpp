#include <iostream>
#include "Player.hpp"

using namespace std;

void Player::Kill(Chicken chicken) {
  int idx = AnimalArray<Chicken>::getNearbyAnimal(getI(), getJ());
  AnimalArray<Chicken>::removeMember(idx);
  FPInventory.add(new ChickenMeat);
}

void Player::Kill(Cow cow) {
  int idx = AnimalArray<Cow>::getNearbyAnimal(getI(), getJ());
  AnimalArray<Cow>::removeMember(idx);
  FPInventory.add(new CowMeat);
}

void Player::Kill(Pig pig) {
  int idx = AnimalArray<Pig>::getNearbyAnimal(getI(), getJ());
  AnimalArray<Cow>::removeMember(idx);
  FPInventory.add(new PigMeat);
}

void Player::Kill(Rabbit rabbit) {
  int idx = AnimalArray<Rabbit>::getNearbyAnimal(getI(), getJ());
  AnimalArray<Cow>::removeMember(idx);
  FPInventory.add(new RabbitMeat);
}

bool isBisaDiinjek(int i, int j) {
  return (((Display::checkLand(i,j,1) || Display::checkLand(i,j,2) || Display::checkLand(i,j,3))) && (AnimalArray::getNearbyAnimal(i,j) == -999));
}

void Player::Walk(char walk) {
  if (walk == 'U' || walk == 'u') {
    if ((getJ() < 11) && (isBisaDiinjek(getI(), getJ()+1))) {
      setJ(J+1);
    }
  }
  else if (walk == 'D' || walk == 'd') {
    if ((getJ() > 0) && (isBisaDiinjek(getI(), getJ()-1))) {
      setJ(J-1);
    }
  }
  else if (walk == 'L' || walk == 'l') {
    if ((getI() > 0) && (isBisaDiinjek(getI()-1, getJ()))) {
      setI(I-1);
    }
  }
  else if (walk == 'R' || walk == 'r') {
    if ((getI() < 11) && (isBisaDiinjek(getI()+1, getJ()))) {
      setI(I-1);
    }
  }
  else {
    throw("Input tidak valid");
  }
}

void Player::Grow() {
  if ((Display::checkLand(getI(),getJ(),1) || Display::checkLand(getI(),getJ(),2) || Display::checkLand(getI(),getJ(),3)) && !Display::checkGrassy(getI(),getJ())) {
    Display::modifyGrassy(getI(),getJ());
  }
  else {
    throw("Tidak bisa menumbuhkan rumput");
  }
}
