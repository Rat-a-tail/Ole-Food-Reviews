#ifndef _Meal_Array_H_
#define _Meal_Array_H_
#include<iostream>
#include <string>
#include <string.h>
#include"../react.h"
#include<fstream>
using namespace std;


class Meal{
    char *name; 
    int rating;
    int meal_index; // stores length of string and string;
public:
    Meal();
    Meal(const char *n, int r);
    char *getname();
    int getrating();
    void display();
    Meal &operator= (const Meal &food);
   ~Meal() ;
   int put_in_global_mem(int name_offset);
    /*void put_in_global_mem(int num_offset, int name_offset);
    void print_to_file(const char *filename) const;
    Meal(std::istream &is);*/
};
#endif 
