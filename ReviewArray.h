#ifndef _ReviewArray_A_
#define _ReviewArray_A_
#include "../react.h"
#include "Review.h"
#include<iostream>
using namespace std;

class Review_Array {
    int length; 
    Review *review_array;

public:
    Review_Array(int l);
    Review_Array();
    ~Review_Array();
    Review & operator[] (int i);
    int return_stars(int i);
<<<<<<< HEAD
=======
    char * return_date(int i);
>>>>>>> a418374001bc1399640e3a0b1ad13e02d11c5f9a
    void edit_entry(int i, Review newdata);
    void add_entry(Review latest);
    void delete_entry(int i);
    int to_global_mem(int reviews_start);
    void test_display();
    int get_length();
};

#endif // _ReviewArray_A