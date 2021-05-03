#include<iostream>
using namespace std;

int getlenstring(const char *word){
    int len = 0;
    while (word[++len] != 0){}
    return len+1;
}

class Review {
    int stars;
    char *date;
    char *username;

public:
    Review(int s, char *d, char *u) {
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
        date = new char[datelen];
        for (int i = 0; i < datelen; ++i) {
            date[i] = d[i];
        }
        username = new char[userlen];
        for (int i = 0; i < userlen; ++i) {
            username[i] = u[i];
        }
    }

    Review() {
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
    }

    Review(const Review &input) {
        cerr << "Review copy constructor initialized" << endl;
        int datelen = getlenstring(input.date);
        int userlen = getlenstring(input.username);
        stars = input.stars;
        date = new char[datelen];
        for (int i = 0; i < datelen; ++i) {
            date[i] = input.date[i];
        }
        username = new char[userlen];
        for (int i = 0; i < userlen; ++i) {
            username[i] = input.username[i];
        }
    }

    ~Review() {
        cerr << "Review destructor initialzied" << endl;
        delete [] date;
        delete [] username;
    }

    int get_stars() {return stars;}
    char *get_date() {return date;}
    char *get_username() {return username;}

    void set_stars(int s) {stars = s;}
    void set_date(char *d) {
        delete [] date;
        date = new char[getlenstring(d)];
        for (int i = 0; i < getlenstring(d); ++i) {
            date[i] = d[i];
        }
    }
    void set_username(char *u) {
        delete [] username;
        username = new char[getlenstring(u)];
        for (int i = 0; i < getlenstring(u); ++i) {
            username[i] = u[i];
        }
    }
    void test_display() {cerr << get_stars() << " " << get_date() << " " << get_username() << endl;}
};

class Review_Array {
public:
    Review_Array(int length) {
        //constructor
    }

    Review_Array() {
        //default constructor
    }

    Review_Array(const Review_Array & input) {
        //copy constructor
    }

    void add_entry(Review latest) {
        //adds new entry to the end of the array by deallocating the old array and copying the contents into a new array one index longer that contains the new entry at the end
    }

    void delete_entry(int i) {
        //deletes the entry at the corresponding index, deallocates the old array and copies the contents into a new array that's one index shorter, so the index of every entry after the entry that was deleted is decreased by one
    }

    void test_display() {
        //displays the entire contents of the array
    }
};

int main() {
    char username1[] = "martinad52";
    char username2[] = "guzman6";
    char username3[] = "xxzghvum69";
    char date1[] = "1/1/01";
    char date2[] = "12/6/12";
    char date3[] = "8/31/20";
    Review adam_artichokepizza(3, date1, username1);
    adam_artichokepizza.test_display();
    Review defaulty_rice;
    defaulty_rice.test_display();
    Review copycat_artichokepizza(adam_artichokepizza);
    copycat_artichokepizza.test_display();
    adam_artichokepizza.set_stars(4);
    adam_artichokepizza.set_username(username2);
    adam_artichokepizza.set_date(date2);
    adam_artichokepizza.test_display();
    Review tristan_bratwurst(2, date3, username3);
    tristan_bratwurst.test_display();
    Review *review_array = new Review[4];
    review_array[0] = adam_artichokepizza;
    review_array[1] = defaulty_rice;
    review_array[2] = copycat_artichokepizza;
    review_array[3] = tristan_bratwurst;
    delete [] review_array;
}