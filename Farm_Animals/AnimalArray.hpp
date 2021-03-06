#ifndef ANIMALARRAY_HPP
#define ANIMALARRAY_HPP

#include <vector>
#include <stdlib.h>
#include <iostream>
#include "FarmAnimal.hpp"
#include "../Display/Display.hpp"
using namespace std;

/* This class is the only class instantiated at the main program.
*  Class T is one of Chicken, Duck, Cow, Goat, Pig, and Rabbit.
*  For every type of class T, a new animal array is instantiated. */
template <class T>
class AnimalArray {
    private:
        std::vector<T> Member;  /* vector of elements/members */
        int length;                         /* number of elements */
    
    public:
        /* initialize array */
        AnimalArray<T>() {
            length = 0;
        };               

        /* create a new member and add to vector, increase length */
        void newMember() {
            T newAnimal;
            Member.push_back(newAnimal);
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

        void MoveArray(Display& D, int playerI, int playerJ) {
            for (int n = 0; n < length; n++) {
                int move = rand() % 10;
                if (move == 0) {
                    
                    int i, j;


                    int iType = rand() % 3;
                    int jType = rand() % 3;

                    if ((iType == 1) && (Member[n].getI() < 11)) {
                        i = Member[n].getI() + 1;
                    } else if ((iType == 2) && (Member[n].getI() > 0)) {
                        i = Member[n].getI() - 1;
                    } else {
                        i = Member[n].getI();
                    }
                    
                    if ((jType == 1) && (Member[n].getJ() < 11)) {
                        j = Member[n].getJ() + 1;
                    } else if ((jType == 2) && (Member[n].getJ() > 0)) {
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

                    if (!D.checkLand(i, j, Member[n].getAllowedLand())) {
                        occupied = true;
                    }
                    if ((playerI == i) && (playerJ == j)) {
                        occupied = true;
                    }

                    if (!occupied) {
                        Member[n].setI(i);
                        Member[n].setJ(j);
                    }
                }
            }
        }

        /* For every tick:
        *   - Moves every member;
        *   - Increases hunger of every member, removes dead members; and
        *   - Makes every hungry member eat grass on its grid if possible. */
        void TickArray(Display& D, int playerI, int playerJ) {
            /* moving */
            MoveArray(D, playerI, playerJ);
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
                if (Member[i].getHunger() > 5) {
                    Member[i].Eat(D);
                }
            }
        };

        void Print() {
            for (int i = 0; i < length; i++) {
                cout << "(" << Member[i].getI() << "," << Member[i].getJ() << ") - ";
                cout << Member[i].getHunger() << " - ";
                if (Member[i].isProductive()) {
                    cout << "Productive" << endl;
                } else {
                    cout << "Unproductive" << endl;
                }
            }
        }
};

#endif
