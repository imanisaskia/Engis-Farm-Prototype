#ifndef ANIMALARRAY_HPP
#define ANIMALARRAY_HPP

#include <vector>
#include "FarmAnimal.hpp"
#include "../Display/Display.hpp"
using namespace std;

#define MAX_ANIMAL 3

/* This class is the only class instantiated at the main program.
*  Class T is one of Chicken, Duck, Cow, Goat, Pig, and Rabbit.
*  For every type of class T, a new animal array is instantiated. */
template <class T>
class AnimalArray {
    private:
        std::vector<T> Member;  /* vector of elements/members */
        int length;             /* number of elements */
    
    public:
        /* initialize array */
        AnimalArray<T>() {
            length = 0;
        };               

        /* create a new member and add to vector, increase length */
        void newMember() {
            T newAnimal();
            Member[length] = newAnimal;
            length++;
        };

        /* remove member at index x, decrease length */
        void removeMember(int x) {
            if ((x >= 0) && (x < length)) {
                Member.erase(Member.begin()+x);
                length--;
            }
        };

        /* returns element on index x */       
        T getMember(int x) {
            return Member[x];
        };

        /* returns length of array */
        int getLength() {
            return length;
        }

        /* returns index of element in i, j */
        int getNearbyAnimal(int i, int j) {
            int nearest = -999;
            for (int k = 0; k < length; k++) {
                if ((Member[k].getI() == i) && (Member[k].getJ() == j)) {
                    nearest = k;
                }
            }
            return nearest;
        };

        void MoveArray(int playerI, int playerJ) {
            for (int n = 0; n < length; n++) {
                int i, j;
                int iType = this->rand() % 3;
                int jType = this->rand() % 3;

                if (iType == 1) {
                    i = Member[n].getI() + 1;
                } else if (iType == 2) {
                    i = Member[n].getI() - 1;
                } else {
                    i = Member[n].getI();
                }
                
                if (jType == 1) {
                    j = Member[n].getJ() + 1;
                } else if (jType == 2) {
                    j = Member[n].getJ() - 1;
                } else {
                    j = Member[n].getJ();
                }

                bool occupied = false;
                for (int k = 0; k < length; k++) {
                    if ((Member[k].getI() == i) && (Member[k].getJ() == j)) {
                        occupied = true;
                    }
                }

                if ((playerI == i) && (playerJ == j)) {
                    occupied = true;
                }

                if (!occupied) {
                    Member[n].setI(i);
                    Member[n].setJ(i);
                }
            }
        }

        /* For every tick:
        *   - Moves every member;
        *   - Increases hunger of every member, removes dead members; and
        *   - Makes every hungry member eat grass on its grid if possible. */
        void TickArray(Display& D, int playerI, int playerJ) {
            /* moving */
            MoveArray(playerI, playerJ);

            /* getting hungry */
            for (int i = 0; i < length; i++) {
                Member[i].GetHungrier();
            }
            for (int i = 0; i < length; i++) {
                if (Member[i].getHunger() >= 10) {
                    removeMember(i);
                }
            }

            /* eating grass */
            for (int i = 0; i < length; i++) {
                Member[i].Eat(D);
            }
        };

};

#endif