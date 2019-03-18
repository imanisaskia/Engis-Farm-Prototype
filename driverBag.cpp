#include "Bag.hpp"
#include <algorithm>
#include <list>

int main(){
    try{
		Bag<int> a;
		cout<<"isEmpty"<<a.isEmpty()<<endl;
		a.add(5);
		a.add(3);
		cout<<"find"<<a.find(5)<<endl;
		cout<<"get"<<a.get(1)<<endl;
		a.remove(5);
		cout<<a.find(5)<<endl;
	}
	catch(char const* a){
		cout<<a<<endl;
	}


    return 0;
}
