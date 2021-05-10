#include <iostream>
#include "Meal_Array.h"
#include <string>
#include <string.h>
using namespace std;


Meal::Meal(){
       rating = 0;
       name = new char[1];
       name[0] = 0;
       meal_index = 0;
    }
Meal::Meal(const char *n, int r){
            int len =0;
            while(n[len]!= 0){
            ++len;
            }
            name = new char[len+1];
            for(int i = 0; i < len+1; ++i){
            name[i] = n[i];
            }
            rating = r;

             meal_index = 0;
    }

char *Meal::getname(){
    return name;
}
int Meal::getrating(){
    return rating;
}

void Meal::display(){ 
    cout << "You selected: " << getname() << " with a star rating:  " << getrating() << endl;
}


Meal &Meal::operator= (const Meal &food){ 
    meal_index = food.meal_index;
    rating = food.rating;
    int len = 0;
    while(food.name[len] !=0){
      ++len;
    }
    delete [] name;
    name = new char[len+1];
    for(int i =0;  i < len+1; ++i){
        name[i] = food.name[i];
    }
    return *this;
}


Meal::~Meal(){
    delete [] name;
}

int Meal::put_in_global_mem(int name_offset) {
        meal_index = name_offset;//
        string q = name;
        int len = q.length();
        _put_int(name_offset, len); // storing location and what you what you need to store
        _put_raw(name_offset+4, name);// puttting, as many bytes as length of string
        int num_bytes = 4 + len; // storing number of bytes; add lenght of reviews.. 
        return num_bytes;
}

/*_global_mem = new char[10000];
    int j = 0;
    for (int i = 0; i < 10000; ++i) {
        _global_mem[i] = '~';
        }
    }
*/

/*void Meal::put_in_global_mem(int num_offset, int name_offset) {
    int p = getnum_meals();
    _put_int(num_offset, p);
    num_offset +=4;
    
    string q = name->getname();
    for(int i = 0; i < p; ++i){
        _put_raw(name_offset+4, q.c_str());
        _put_int(name_offset);
        name_offset += q.length() +1;
         name_offset +=20;
    }    
}*/ 

void Meal::print_to_file(const char *filename) const{
    ofstream outfile(filename);
    outfile << p << endl;
    if(p>0){ // p == num_meals;
        for(int i =0; i < p; ++i){
            outfile << *name[i] << endl;
            cout << "i got here " << endl;
        }
    }
    outfile.close();
}
 Meal::Meal(std::istream &is): Meal(){
     int ss = getnum_meals();
     is >> ss;
     for (int i =0; i < ss; ++i){
        string str;
        string d = str->getname();
        is >> d;
     }
 }


 // pass to it a default value;





