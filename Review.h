#ifndef _Review_A_
#define _Review_A_
#include<iostream>
using namespace std;

int getlenstring(const char *word);

class Review {
    int stars;
    char *date;

public:
    Review(int s, char *d);
    Review();
    Review(const Review &input);
    ~Review();
    int get_stars();
    char *get_date();
    void set_stars(int s);
    void set_date(char *d);
    //void global_mem_tests();
    void to_global_mem(int reviews_start);
    void test_display();
};

#endif // _Review_A