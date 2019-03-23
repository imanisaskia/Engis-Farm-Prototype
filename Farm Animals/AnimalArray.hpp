#ifndef ANIMALARRAY_HPP
#define ANIMALARRAY_HPP

#include <vector>
#include "FarmAnimal.hpp"

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
        void newMember<T>() {
            T newAnimal = new T();
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
                if ((Member[k].getI == i) && (Member[k].getJ == j)) {
                    nearest = k;
                }
            }
            return nearest;
        };

        /* For every tick:
        *   - Moves every member;
        *   - Increases hunger of every member, removes dead members; and
        *   - Makes every hungry member eat grass on its grid if possible. */
        void TickArray<T>(Grid** Map) {
            /* moving */
            for (int i = 0; i < length; i++) {
                Member[i].Move(this);
            }

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
                Member[i].Eat(Map);
            }
        };
};

#endif