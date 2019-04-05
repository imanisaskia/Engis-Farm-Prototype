#include<iostream>
#include "Farm_Product\FarmProduct.hpp"
#include "Side_Product\SideProduct.hpp"
using namespace std;

#ifndef BAG_HPP
#define BAG_HPP

#define MAX_BAG 6

template <class T>
struct Node{
	T value;
	Node<T> *next;
};

template <class T>
class Bag{
    private:
        Node<T> *head;	/* pointer to first element*/
        Node<T> *tail;	/* pointer to last element*/
        int size;
    
    public:
        Bag(); /*constructor*/
        
        ~Bag();	/*destructor*/

		/*getter size*/
		int getSize();

        /* return value's index, -1 if not found*/
        int find(T value);
        
        /* return True if Bag empty*/
        bool isEmpty();

        /* add value as the last member of Bag*/
        void add(T value);

        /* remove element with value from Bag*/
        void remove (T value);
        
        /* remove FarmProduct element with type tipe from Bag*/
		void typeBasedRemove(int tipe, bool success);

		/* remove SideProduct element with ingredient1 and ingredient2 from Bag*/
		void ingredientBasedRemove(int ingredient1, int ingredient2, bool success);

        /* return a member of Bag on index*/
        T get(int index);
        
};
#endif

/* ---------- IMPLEMENTATION OF BAG CLASS ---------- */

/*constructor*/
template <class T>
Bag<T>::Bag(){
	head = 0;
	tail = 0;
	size = 0;
}

/*destructor*/
template <class T>
Bag<T>::~Bag(){
	Node<T> *temp=head;
	Node<T> *Next;
	for(int i=0;i<size;i++){
		Next = temp->next;
		delete (temp->value);	/*diperlukan karena nanti elemennya adalah pointer*/
		delete temp;
		temp = Next;
	}
	size = 0;
}

/*getter size*/
template <class T>
int Bag<T>::getSize(){
	return size;
}

/* return value's index, -1 if not found*/
template <class T>
int Bag<T>::find(T val){
	int index=0;
	bool found;
	Node<T> * i = head;	/*berfungsi sebagai iterator*/
    while(index<size && not(found)){
		if(i->value==val){
			found=true;
		}else{
			index++;
			i=i->next;
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
    if(size==0){
		return true;
	}else{
		return false;
	}
}

/* add value as the last member of ItemList
If the bag is full, throw message*/
template <class T>
void Bag<T>::add(T val){
	Node<T> *temp = new(Node<T>);
	temp->value = val;
	temp->next = 0;
	if(size != MAX_BAG && size != 0){
		tail->next = temp;
		tail=temp;
		size+=1;
	}else if(size==0){
		head = temp;
		tail = temp;
		size+=1;
	}else{
		throw "Your bag is full.";
	}
}

/* remove element with value from ItemList*/
template <class T>
void Bag<T>::remove (T val){
	int index = find(val);
	if(index!=-1){	/*nilai val ditemukan*/
		if(index==0){	/*elemen pertama*/
			Node<T> *temp = head;
			if(size == 1){	/*hanya 1 elemen*/
				tail = 0;
			}
			head = temp->next;
			delete(temp->value);
			delete(temp);
			size-=1;
		}else if(index == size-1){	/*elemen terakhir*/
			Node<T> *temp = tail;
			Node<T> *i = head;	/*berfungsi sebagai iterator*/
			while(i->next != tail){
				i= i->next;
			}
			tail = i;
			tail->next=0;
			delete(temp->value);
			delete(temp);
			size -=1;
		}else{	/*bukan elemen akhir maupun awal*/
			Node<T> *temp;
			Node<T> *i = head;	/*berfungsi sebagai iterator*/
			for(int j=0; j<index-1;j++){
				i = i->next;
			}
			temp = i->next;
			i->next = temp->next;
			delete(temp->value);
			delete(temp);
			size -=1;
		}
	}
}


/* return a value of ItemList on index*/
template <class T>
T Bag<T>::get(int index){
	Node<T> *i = head;	/*berfungsi sebagai iterator*/
    for(int j=0;j<index;j++){
		i=i->next;
	}
	return i->value;	
}
