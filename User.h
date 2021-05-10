#ifndef _User_A_
#define _User_A_
#include <iostream>
using namespace std;

class User{
protected:
    char *username;
    char *password;
    //Review **userreviews; dont have a review class yet;

public:
    User(); //Default
    User(const char *user, const char *pass); //Constructor
    User(const User &cp); //Copy Constructor
    ~User(); //Destructor

//Methods
    User &operator=(const User &cp); //=operator
    int getlen(const char *word); //length of strings
   // void adduserReview(Review &r);
    void changepass(char *npass); //change the password
    void changeuser(char *nuser); //change the username (not sure if we really need this one)
    void display(); //display Username and password;
    char *getuser();
    char *getpass();


};

#endif // _User_A_
