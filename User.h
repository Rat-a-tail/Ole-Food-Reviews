#ifndef _User_A_
#define _User_A_
#include <iostream>

class User{
protected:
    char *username;
    char *password;
    //Review **userreviews; dont have a review class yet;

public:
    User(const char *user, const char *pass);
    ~User();

    int getlenstring(const char *word);

   // void adduserReview(Review &r);

    void changepass(const char *npass);

    void display();


};

#endif // _User_A_
