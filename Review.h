#ifndef _Review_A_
#define _Review_A_
#include<iostream>
using namespace std;

class Review {
    int stars;
    char *date;
    char *username;
    char *meal;

public:
    Review(int s, char *d, char *u, char *m);
    Review();
    Review(const Review &input);
    ~Review();
    void set_username(char *u);
    void set_meal(char *m);
    void test_display();
};

#endif // _Review_A