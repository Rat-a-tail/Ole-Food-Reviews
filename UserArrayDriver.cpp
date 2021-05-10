#include <iostream>
using namespace std;
#include "UserArray.h"


int main(){
    /*
    outgoing_mem_size = 30000;
    UserArrayP sto;
    User celia("celia", "purple");
    User pol("poll", "magenta");
    User maker;
    sto.addUser(maker);
    sto.addUser(celia);
    sto.addUser(pol);
    //sto.display();
    //cout <<sto.checking("celia", "purple") << endl;
    cout << "store :" << endl;
    //sto.store_global(5);
    sto.clear();
    cout << "get_from" << endl;
    sto.get_from_global(5);
    */
    std::ifstream f("Userinfo.txt");
    UserArrayP sto(f);
    //sto.get_from_global(5);
    //sto.display();
    char answer1;
    char user[20];
    char pass[20];
    bool follow = 1;
    while (follow){
       // sto.display();
        cout << "are you a new user? y/n" << endl;
        cin >> answer1;
        if (answer1 == 'y'){
            cout << "enter your st olaf username: " <<endl;
            cin >> user;
            cout << "make your password: " <<endl;
            cin >> pass;
            User *version = new User(user, pass);
            sto.addUser(*version);
            cout << "You are successfully registered" <<endl;
        }
        else if (answer1 == 'n'){
            cout << "enter your username: " <<endl;
            cin >> user;
            cout << "enter your password: " <<endl;
            cin >> pass;
            bool com = sto.checking(user, pass);
            if (com == 1){
                cout << "Login Sucessful!!!!" <<endl;
                follow = 0; 
            }
            else {
                cout << "Incorrect Username or Password" <<endl;
            }
        }
    }
    sto.print_to_file("Userinfo.txt");

}
