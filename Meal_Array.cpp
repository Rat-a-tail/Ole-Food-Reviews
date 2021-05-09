#include <iostream>
#include "Meal_Array.h"
#include <string>
#include <string.h>
using namespace std;


Meal::Meal(){
       rating = 0;
       name = new char[1];
       name[0] = 0;
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

