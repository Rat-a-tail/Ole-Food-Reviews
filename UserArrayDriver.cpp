#include <iostream>
using namespace std;
#include "UserArray.h"


int main(){
    UserArrayP sto;
    User celia("celia", "purple");
    User pol("poll", "magenta");
    User maker;
    sto.addUser(maker);
    sto.addUser(celia);
    sto.addUser(pol);
    //sto.display();
    cout <<sto.checking("celia", "purple") << endl;
    /*
    bool cont = 1;
    while(cont){
        std::cout << "Are you a new User? Y/N" <<std::endl;
        char answer1;
        std::cin >> answer1;
        if (answer1 == 'Y'){
            char *user;
            char *pass;
            cout << "Username: " <<endl;
            //cin >> user;
            cout << "Password: " <<endl;
            //cin >>pass;
            User a(user, pass);
            sto.addUser(a);
            cout >> "You are in the system!" >>endl;
            cont = 0;
        }
        else{
            //sto.check();
        }
    */

    
    
    
}
