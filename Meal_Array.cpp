#include <iostream>
#include "Meal_Array.h"
#include <string>
#include <string.h>
using namespace std;


Meal::Meal(){
       rating = 0;
       name = new char[1];
       name[0] = 0;
       meal_index = 0;
    }
Meal::Meal(const char *n, int r){
            int len =0;
            while(n[len]!= 0){
            ++len;
            }
            name = new char[len+1];
            for(int i = 0; i < len+1; ++i){
            name[i] = n[i];
            }
            rating = r;

             meal_index = 0;
    }

char *Meal::getname(){
    return name;
}
int Meal::getrating(){
    return rating;
}

void Meal::display(){ 
    cout << "You selected: " << getname() << " with a star rating:  " << getrating() << endl;
}


Meal &Meal::operator= (const Meal &food){ 
    meal_index = food.meal_index;
    rating = food.rating;
    int len = 0;
    while(food.name[len] !=0){
      ++len;
    }
    delete [] name;
    name = new char[len+1];
    for(int i =0;  i < len+1; ++i){
        name[i] = food.name[i];
    }
    return *this;
}


Meal::~Meal(){
    delete [] name;
}

int Meal::put_in_global_mem(int name_offset) {
        meal_index = name_offset;//
        string q = name;
        int len = q.length();
        _put_int(name_offset, len); // storing location and what you what you need to store
        _put_raw(name_offset+4, name);// puttting, as many bytes as length of string
        int num_bytes = 4 + len; // storing number of bytes; add lenght of reviews.. 
        return num_bytes;
}


/*Meal::Meal(std::istream &is): Meal(){
     string q = name;
    int len = q.length();
     is >> len;
     for (int i =0; i < len; ++i){
        is >> q[i];
     }
     cout << q << endl;
 }*/


 // pass to it a default value;





