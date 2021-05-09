#ifndef _Meal_Array_H_
#define _Meal_Array_H_
#include<iostream>
#include <string>
#include <string.h>

using namespace std;


class Meal{
    char *name; 
    int rating;
public:
    Meal();
    Meal(const char *n, int r);
    char *getname();
    int getrating();
    void display();
    Meal &operator= (const Meal &food);
   ~Meal() ;
};
#endif 
