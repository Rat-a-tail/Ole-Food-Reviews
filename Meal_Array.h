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

class station{
    Meal* meal_array;
    int num_meals;
    static const int  default_num_meals = 10;
    public:
    station();
    station( Meal* M, int n_m);
    void add_meal(Meal &d);
    void display();
    Meal &getmeal_array(int h);
    char *getmeal_name(int y);
    int getmeal_rating(int p);
    int getnum_meals();
    bool compare(int j, string output, station **arr2, int q);
    void retrieve_information(int n_s,station **arr1);
    ~station();
};

#endif 