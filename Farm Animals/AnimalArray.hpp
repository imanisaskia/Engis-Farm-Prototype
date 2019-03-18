#ifndef ANIMALARRAY_HPP
#define ANIMALARRAY_HPP

#include <vector>

#define MAX_ANIMAL 3

/* This class is the only class instantiated at the main program.
*  Class T is one of Chicken, Duck, Cow, Goat, Pig, and Rabbit.
*  For every type of class T, a new animal array is instantiated. */
template <class T>
class AnimalArray {
    private:
        std::vector<T> Member;         // vector of elements
        int length;
    
    public:
        AnimalArray<T>();               // vector default size MAX_ANIMAL
        void newMember<T>();               // create a new member and add to vector, increase length
        void removeMember(int x);       // remove member at index x, decrease length
        T getMember(int x);             // returns element on index x
        T getNearby(int i, int j);      // returns element nearest to position i, j

        void Tick<T>();
        /* For every tick:
        *   - Moves every member;
        *   - Increases hunger of every member, removes dead members; and
        *   - Makes every hungry member eat grass on its grid if possible. */
};

#endif