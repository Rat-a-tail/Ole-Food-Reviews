#include <iostream>
#include "User.h"
#include "../react.h"
#include <fstream>

class UserArrayP{
    int userlstlen;
    User **userlist;
    static const int Default_size = 3000;

public: 
    UserArrayP();
    UserArrayP(std::istream &is);
    ~UserArrayP();


//Methods
    void Program();
    bool checking(const char *user, const char *pass);
    void addUser(const User &h);
    int getlenarray(const char *word);
    void print_to_file();
    void display();
    void destroy(User **n);
    void clear();
    void store_global(int offset);
    void get_from_global(int offset);
    void print_to_file(const char *filename)const;

};
