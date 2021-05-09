#include<iostream>
using namespace std;
#include "Review.h"

int getlenstring(const char *word){
    int len = 0;
    while (word[++len] != 0){}
    return len+1;
}

Review::Review(int s, char *d) {
        //cerr << "Review constructor initialized" << endl;
        if (s < 1) {
            stars = 1;
        }
        if (s < 6) {
            stars = s;
        }
        else {
            stars = 5;
        }
        int datelen = getlenstring(d);
        date = new char[datelen];
        for (int i = 0; i < datelen; ++i) {
            date[i] = d[i];
        }
    }

Review::Review() {
        //cerr << "Review default constructor initialized" << endl;
        stars = -1; //NOTE: When implementing this on React, we should make it so that if a star rating is -1, it displays a special message to the effect of "NO REVIEW" or something.
        date = new char[8];
        date[0] = 'X';
        date[1] = 'X';
        date[2] = '/';
        date[3] = 'X';
        date[4] = 'X';
        date[5] = '/';
        date[6] = 'X';
        date[7] = 'X';
        date[8] = 0;
    }

Review::Review(const Review &input) {
        //cerr << "Review copy constructor initialized" << endl;
        int datelen = getlenstring(input.date);
        stars = input.stars;
        date = new char[datelen];
        for (int i = 0; i < datelen; ++i) {
            date[i] = input.date[i];
        }
    }

Review::~Review() {
        //cerr << "Review destructor initialzied" << endl;
        delete [] date;
    }

    int Review::get_stars() {return stars;}
    char *Review::get_date() {return date;}

    void Review::set_stars(int s) {stars = s;}
    void Review::set_date(char *d) {
        delete [] date;
        date = new char[getlenstring(d)];
        for (int i = 0; i < getlenstring(d); ++i) {
            date[i] = d[i];
        }
    }
    void Review::test_display() {cerr << get_stars() << " " << get_date() << " " << endl;}

