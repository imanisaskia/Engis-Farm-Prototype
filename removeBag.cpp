#include "Bag.hpp"

using namespace std;


/* remove value with type tipe from ItemList*/
template <>
void Bag<FarmProduct*>::typeBasedRemove(int tipe, bool success){
	if(size!=0){
		Node<FarmProduct*> *i =head;	//berfungsi sebagai iterator
		int j =0;
		bool found=false;
		while(j<size && not(found)){
			 if((i->value)->getType() == tipe ){
				found=true;
			}else{
				j++;
				i = i->next;
			}
		}
		if(found){
			remove(i->value);
			success=true;
		}else{
			success=false;
		}
	}			
}

/* remove value with ingredient1 and ingredient2 from ItemList*/
template <>
void Bag<SideProduct*>::ingredientBasedRemove(int ingredient1, int ingredient2, bool success){
	if(size!=0){
		Node<SideProduct*> *i =head;	//berfungsi sebagai iterator
		int j =0;
		bool found=false;
		while(j<size && not (found)){
			 if((i->value)->getIngredient1() == ingredient1 && (i->value)->getIngredient2() == ingredient2){
				found=true;
			}else{
				j++;
				i = i->next;
			}
		}
		if(found){
			remove(i->value);
			success=true;
		}else{
			success=false;
		}
	}			
}
