#ifndef _ReviewArray_A_
#define _ReviewArray_A_
#include "Review.h"
#include "../react.h"
#include<iostream>
using namespace std;

class Review_Array {
    int length;
    Review *review_array;

public:
    Review_Array(int l) : length(l);
    Review_Array();
    ~Review_Array();
    Review &operator[](int i);
    void edit_entry(int i, Review newdata);
    //void add_entry(Review latest);
    void delete_entry(int i) ;
    void test_display();
};

#endif // _ReviewArray_A