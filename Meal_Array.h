#ifndef _Meal_Array_H_
#define _Meal_Array_H_
#include<iostream>
#include <string>
#include <string.h>
#include"../react.h"
//#include "ReviewArray.cpp"
#include "ReviewArray.h"
#include<fstream>
using namespace std;


class Meal{
    char *name; 
    Review_Array *rating; //need to make this a part of the meal class.
    int meal_index; // stores length of string and string;
    int num_reviews;

    // make a meal object  
    // add all review arrays for items in meal...
public:
    Meal();
    Meal(const char *n, Review_Array &rate);   
    char *getname();
    //int getrating();
    void display();
    Meal &operator= (const Meal &food);
   ~Meal() ;  
   int put_in_global_mem(int name_offset);
   void print_to_file_meal(const char *filename);
   int getReview(int h);
   void add_review(Review_Array &f);
   
    /*void put_in_global_mem(int num_offset, int name_offset);
    void print_to_file(const char *filename) const;
    Meal(std::istream &is);*/
};
#endif 

// where to put adam's tsuff
// tweak those functions 
// pass next index to adam's function... space taken up....