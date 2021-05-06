#include <iostream>
using namespace std;
#include "UserArray.h"
#include "User.cpp"
 


UserArrayP::UserArrayP(){
        userlist = new User*[3000];
        userlstlen = 0;
    }

UserArrayP::~UserArrayP(){
        for (int i = 0; i < userlstlen; i++){
            delete userlist[i];
        }
        delete [] userlist;
    }

void UserArrayP::addUser(const User &h){
        User *copy = new User;
		*copy = h;
        userlist[userlstlen] = copy;
        userlstlen+=1;
    }

int UserArrayP::getlenarray(const char *word){
        int len = 0;
        while (word[++len]){}
        return len;
    }

void UserArrayP::display(){
    cout<<"userlstlen: "<< userlstlen <<endl;
    for (int i = 0; i < userlstlen; i++){
       
        std::cout << "\tEntry: " << i<<std::endl; 
        userlist[i]->display();
    }
}

void UserArrayP::destroy(User **n){
        for (int i = 0; i < userlstlen; i++){
            delete n[i];
        }
    }


bool UserArrayP::checking(const char *user, const char *pass){

    int i = 0;
    int foundvalue;
    bool found =0 ;
    while ( i < userlstlen && found == 0){
        bool check = 1;
        int k = 0;
        while (check != 0 && k < getlenarray(user)){
            char *userfl = userlist[i]->getuser();
            if (user[k] != userfl[k]){
                check = 0;
            }
            if (k == getlenarray(user)-1){
                found = 1;
                foundvalue = i;
            }
            k++;

        }
        i++;
    }
    if (found == 0){
        return 0;

    }

    bool match = 1;
    char *passfl = userlist[foundvalue]->getpass();
    int c = 0;
        while (c < getlenarray(pass) && match == 1){
            if (pass[c] == passfl[c]){
                match = 1;
            }
            else {
                match = 0;
            }
            c++;
        }
    if (c == getlenarray(pass)){
        return 1;
    }
    else {
        return 0;
    }
}


/*
void UserArrayP::store_global(int offset){
    _put_short(0, userlstlen);
    for (int i = 0; i < userlstlen; i++) {
        User *copy = new User;
        copy = userlist[i];
        _put_raw(offset, &copy);
    }
}
/*
void UserArrayP::get_from_global(int offset){
	userlstlen = _get_short(0);
	for(int i = 0; i < userlstlen; i++){
        User *copy = new User;
        copy = userlist[i];
        _put_raw(offset, copy);
	}

}


void UserArrayP::print_to_file(const char *filename) const{
	ofstream f(filename);
	f<< userlstlen <<endl;
	for (int i = 0; i < userlstlen; ++i){
		f<< i << " " << *User[i]->display() << endl;
	}
	f.close();
}
*/
