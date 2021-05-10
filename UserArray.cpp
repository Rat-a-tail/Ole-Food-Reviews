#include <iostream>
using namespace std;
#include "UserArray.h"


UserArrayP::UserArrayP(){
        userlist = new User*[Default_size];
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
    bool found = 0;

    while ( i < userlstlen && found == 0){
        bool check = 1;
        int k = 0;
        //cout << "user length: "<< getlenarray(user) <<endl;
        while (check != 0 && k < getlenarray(user)){
            char *userfl = userlist[i]->getuser();
            //cout <<"k: " << user[k] << "==" <<userfl[k] <<endl;
            if (user[k] != userfl[k]){
                cout <<k <<": " << user[k] << "==" <<userfl[k] <<endl;
                check = 0;
            }
            else if (k == getlenarray(user)-1 && check == 1){
                found = 1;
                foundvalue = i;
            }
            k++;
        }
        //cout << "check = " << check << " found = " << found<< endl;
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

// Global mem starts with userlstlen at 5
//starting at 100 there will be a User every 100 bytes of global mem
//username at 100 *i and password at (100*i)+50

void UserArrayP::store_global(int offset){
    _put_short(5, userlstlen);
    for (int i = 0; i < userlstlen; i++) {
        char *useru = userlist[i]->getuser();
        cout << useru <<endl;
        char *passu = userlist[i]->getpass();
        cout <<passu <<endl;
        _put_raw(100+100*i, useru);
        _put_raw((150+100*i), passu);
    }
}

void UserArrayP::clear(){
    for (int i = 0; i < userlstlen; i++){
        delete userlist[i];
    }
    userlstlen = 0;
    }

void UserArrayP::get_from_global(int offset){
    clear();
	userlstlen = _get_short(5);
    cout << "userlstlen :" <<userlstlen <<endl;
	for(int i = 0; i < userlstlen; i++){
        int k= 100+100*i;
        int ulen = 0;
        
        cout <<endl;

        while (_get_char(k) != 0){ ulen++; k++;}
        char *user = new char[ulen+=1];


        int z = 100+100*i;
    //    *user = _get_char(z);
        for (int r = 0; r < ulen; r++){
            user[r] = _get_char(z);
            //cout <<  "char"<<r<<": " <<_get_char(z) <<  user <<endl;
            z++;
        }
    
        cout << "user :" <<  user <<endl;

        k = 150+100*i;
        int plen = 0;
        
        while (_get_char(k) != 0){ plen++; k++;}
        char *pass = new char[plen+=1];

        
        z = 150+100*i;
        for (int r = 0; r < plen; r++){
            pass[r] = _get_char(z);
            z++;
        }
        cout << "pass :" <<  pass <<endl;
        
        userlist[i] = new User;
        User &copy = *(userlist[i]);
        copy.changeuser(user);
        copy.changepass(pass);
        copy.display();
        
	}
}
/*
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
