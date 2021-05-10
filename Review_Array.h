#include<iostream>
#include "Review.h"
#include "../react.h"
using namespace std;

int getlenstring(const char *word);

class Review {
    Review(int s, char *d, char *u, char *m);
    Review();
    Review(const Review &input);
    ~Review();
    int get_stars();
    char *get_date();
    char *get_username();
    char *get_meal();

    void set_stars(int s);
    void set_date(char *d);
    void set_username(char *u);
    void set_meal(char *m);
    void test_display();
};

class Review_Array {
    Review_Array(int l);
    Review_Array();
    ~Review_Array();
    Review & operator[](int i);
    void edit_entry(int i, Review newdata);
    void add_entry(Review latest);
    void delete_entry(int i);
    void test_display();
};