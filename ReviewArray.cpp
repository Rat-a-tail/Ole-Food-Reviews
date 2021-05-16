#include <iostream>
using namespace std;
#include "ReviewArray.h"
#include "Review.h" // aded this bit

Review_Array::Review_Array(int l) {
        //cerr << "Review_Array constructor initialized" << endl;
        length = l;
        review_array = new Review[length];
        }
        
Review_Array::Review_Array() {
        //cerr << "Review_Array default constructor initialized" << endl;
        length = 0;
        review_array = new Review[length];
    }
Review_Array::~Review_Array() {
        //cerr << "Review_Array destructor initialized" << endl;
        delete [] review_array;
    }
Review & Review_Array::operator[](int i) {
        return review_array[i];
    }

int Review_Array::return_stars(int i) {
    return review_array[i].get_stars();
}

int Review_Array::get_length(){
    return length;
}

char * Review_Array::return_date(int i) {
    return review_array[i].get_date();
}

void Review_Array::add_entry(Review latest) {
        int i = length;
        while (review_array[i - 1].get_stars() == -1) {
            cerr << i << endl;
            --i;
        }
        edit_entry(i, latest);
    }

void Review_Array::edit_entry(int i, Review newdata) {
        review_array[i].set_stars(newdata.get_stars());
        review_array[i].set_date(newdata.get_date());
    }

void Review_Array::delete_entry(int i) {
        //deletes the entry at the corresponding index, deallocates the old array and copies the contents into a new array that's one index shorter, so the index of every entry after the entry that was deleted is decreased by one
        Review blank;
        edit_entry(i, blank);
    }

int Review_Array::to_global_mem(int reviews_start) {
    int offset = reviews_start;
    for (int i = 0; i < length; ++i) {
        review_array[i].to_global_mem(offset);
        offset += 12;
    }
    return offset;
}

void Review_Array::test_display() {
        //displays the entire contents of the array
        for (int i = 0; i < length; ++i) {
            review_array[i].test_display();
        }
    }

