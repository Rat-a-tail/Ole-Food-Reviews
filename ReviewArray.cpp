#include <iostream>
using namespace std;
#include "Review_Array.h"



Review_Array::Review_Array(int l) : length(l) {
        cerr << "Review_Array constructor initialized" << endl;
        review_array = new Review[length];
        }
Review_Array::Review_Array() {
        cerr << "Review_Array default constructor initialized" << endl;
        length = 0;
        review_array = new Review[length];
    }
Review_Array::~Review_Array() {
        cerr << "Review_Array destructor initialized" << endl;
        delete [] review_array;
    }
Review_Array::Review & operator[](int i) {
        return review_array[i];
    }

void Review_Array::edit_entry(int i, Review newdata) {
        review_array[i].set_stars(newdata.get_stars());
        review_array[i].set_date(newdata.get_date());
        review_array[i].set_username(newdata.get_username());
        review_array[i].set_meal(newdata.get_meal());
    }
void Review_Array::delete_entry(int i) {
        //deletes the entry at the corresponding index, deallocates the old array and copies the contents into a new array that's one index shorter, so the index of every entry after the entry that was deleted is decreased by one
    }

void Review_Array::test_display() {
        //displays the entire contents of the array
    }

