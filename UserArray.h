#include <iostream>
#include "User.h"

class UserArrayP{
    int userlstlen;
    User **userlist;

public: 
    UserArrayP();
    ~UserArrayP();


//Methods
    void Program();
    void addUser(const User &h);
    int getlenarray(const char *word);
    void print_to_file();
    void display();
    void destroy(User **n);
    //void print_to_file(const char *filename)const;

};
