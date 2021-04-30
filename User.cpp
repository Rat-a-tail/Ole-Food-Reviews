#include "User.h"
#include <iostream>

User::User(const char *user, const char *pass){
        //userreviews = new Review*[0];
        int lenu = getlenstring(user);
        int lenp = getlenstring(pass);
        username = new char[lenu];
        password = new char[lenp];

        for (int i = 0; i < lenp; i++){
            password[i] = pass[i];
        }

        for (int i = 0; i < lenu; i++){
            username[i] = user[i];
        }
    }

User:: ~User(){
        delete [] username;
        delete [] password;
    }


int User::getlenstring(const char *word){
        int len = 0;
        while (word[++len] != 0){}
        return len+1;
    }

    /*
void User::adduserReview(Review &r){
        int lenusrlst = getlenarray(userreviews);
        char **templst = new User*[lenusrlst];
        for (int i = 0; i < lenusrlst, i++){
            templst[i]= userreviews[i];
        }
        delete [] userreviews;
        userreviews = new User*[lenusrlst+=1];
        for (int i = 0, i < lenuserlst, i++){
            userreviews[i] = templst[i];
        }
        delete [] templst;
        userreviews[i] = r;
    }
    */

void User::changepass(const char *npass){
        delete [] password;
        int len = getlenstring(npass);
        for(int i = 0; i < len; len++){
            password[i] = npass[i];
        }

    }

void User::display(){
        std::cerr << "Username: " << username <<std::endl;
        std::cerr << "Password: " << password <<std::endl;
    }

