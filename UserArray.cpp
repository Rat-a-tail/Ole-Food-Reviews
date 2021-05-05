#include <iostream>
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
    
void UserArrayP::Program(){
    std::cout << "Are you a new User? Y/N" <<std::endl;
    char answer1;
    std::cin >> answer1;
}    

int UserArrayP::getlenarray(const char *word){
        int len = 0;
        while (word[++len]){}
        return len;
    }

/*
	ofstream f(filename);
	for (int i = 0; i < userlstlen; ++i){
		f<<i<<"."<<endl;
        f<< "Username: " << *User[i].get_Username(); << endl;
        f<< "Password: " << *User[i].get_Password(); << endl;
        f<<endl;
	}
	f.close();
}
*/

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