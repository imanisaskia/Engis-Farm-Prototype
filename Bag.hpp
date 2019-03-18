#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

#ifndef BAG_HPP
#define BAG_HPP

#define MAX_BAG 50

template <class T>
class Bag{
    private:
        list <T> ItemList; // Linked list of FarmProduct or SideProduct
    
    public:
        Bag(); //constructor

        /* return element's index, -1 if not found*/
        int find(T element);
        
        /* return True if ItemList empty*/
        bool isEmpty();

        /* add element as the last member of ItemList*/
        void add(T element);

        /* remove element from ItemList*/
        void remove (T element);

        /* return a member of ItemList on index*/
        T get(int index);
};
#endif

/* ---------- IMPLEMENTATION OF BAG CLASS ---------- */

/*constructor*/
template <class T>
Bag<T>::Bag(){
}

/* return element's index, -1 if not found*/
template <class T>
int Bag<T>::find(T element){
	int index=0;
	bool found;
    typename list<T>::iterator i=ItemList.begin();
    while(i!=ItemList.end() && not(found)){
		if(*i==element){
			found=true;
		}else{
			index++;
			i++;
		}
	}
    if(found){
		return index;
	}else{
		return -1;
	}
}

/* return True if ItemList empty*/
template <class T>
bool Bag<T>::isEmpty(){
    return ItemList.empty();
}

/* add element as the last member of ItemList
If the bag is full, throw message*/
template <class T>
void Bag<T>::add(T element){
	if(ItemList.size() != MAX_BAG){
		ItemList.push_back(element);
	}else{
		throw "Your bag is full.";
	}
}

/* remove element from ItemList*/
template <class T>
void Bag<T>::remove (T element){
	ItemList.remove(element);
}

/* return a member of ItemList on index*/
template <class T>
T Bag<T>::get(int index){
    typename list<T>::iterator i = ItemList.begin();
	advance(i,index);
    return *i;
}
