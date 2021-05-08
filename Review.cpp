#include<iostream>
using namespace std;


int getlenstring(const char *word){
    int len = 0;
    while (word[++len] != 0){}
    return len+1;
}

Review::Review(int s, char *d, char *u, char *m) {
        cerr << "Review constructor initialized" << endl;
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
        int userlen = getlenstring(u);
        int meallen = getlenstring(m);
        date = new char[datelen];
        for (int i = 0; i < datelen; ++i) {
            date[i] = d[i];
        }
        username = new char[userlen];
        for (int i = 0; i < userlen; ++i) {
            username[i] = u[i];
        }
        meal = new char[meallen];
        for (int i = 0; i < meallen; ++i) {
            meal[i] = m[i];
        }
    }

Review::Review() {
        cerr << "Review default constructor initialized" << endl;
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
        username = new char[8];
        for (int i = 0; i < 7; ++i) {
            username[i] = 'x';
        }
        username[8] = 0;
        meal = new char[8];
        for (int i = 0; i < 7; ++i) {
            meal[i] = 'x';
        }
        meal[8] = 0;
    }

Review::Review(const Review &input) {
        cerr << "Review copy constructor initialized" << endl;
        int datelen = getlenstring(input.date);
        int userlen = getlenstring(input.username);
        int meallen = getlenstring(input.meal);
        stars = input.stars;
        date = new char[datelen];
        for (int i = 0; i < datelen; ++i) {
            date[i] = input.date[i];
        }
        username = new char[userlen];
        for (int i = 0; i < userlen; ++i) {
            username[i] = input.username[i];
        }
        meal = new char[meallen];
        for (int i = 0; i < meallen; ++i) {
            meal[i] = input.meal[i];
        }
    }

Review::~Review() {
        cerr << "Review destructor initialzied" << endl;
        delete [] date;
        delete [] username;
        delete [] meal;
    }

    int Review::get_stars() {return stars;}
    char *Review::get_date() {return date;}
    char *Review::get_username() {return username;}
    char *Review::get_meal() {return meal;}

    void Review::set_stars(int s) {stars = s;}
    void Review::set_date(char *d) {
        delete [] date;
        date = new char[getlenstring(d)];
        for (int i = 0; i < getlenstring(d); ++i) {
            date[i] = d[i];
        }
    }
    void Review::set_username(char *u) {
        delete [] username;
        username = new char[getlenstring(u)];
        for (int i = 0; i < getlenstring(u); ++i) {
            username[i] = u[i];
        }
    }
    void Review::set_meal(char *m) {
        delete [] meal;
        meal = new char [getlenstring(m)];
        for (int i = 0; i < getlenstring(m); ++i) {
            meal[i] = m[i];
        }
    }
    void Review::test_display() {cerr << get_stars() << " " << get_date() << " " << get_username() << " " << get_meal() << endl;}

