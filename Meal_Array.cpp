#include <iostream>
#include "Meal_Array.h"
#include <string>
#include <string.h>
#include <fstream> 
#include "ReviewArray.h"
using namespace std;

Meal::Meal(){
       //rating = 0;
       name = new char[1];
       name[0] = 0;
       meal_index = 0;

    }
Meal::Meal(const char *n, Review_Array &rate){ 
            int len =0;
            while(n[len]!= 0){
            ++len;
            }
            name = new char[len+1];
            for(int i = 0; i < len+1; ++i){
            name[i] = n[i];
            }
            rating = new Review_Array(rate);  // calling copy constructor to make rating object
            //rate; 
            meal_index = 0;
    }

char *Meal::getname(){
    return name;
}

int Meal::getReview(int h){
    int sum = 0; // holds total of all stars;
    int avg = 0; // holds average of all reviews... aavg = sum // number of reviews;
    int i;
    cout << "here " << endl; 

    cout << rating->get_length() << endl;  // need to call the constructor
    
    for(i=0; i < rating->get_length(); ++i){ // iterating through array of reviews
         //cout << "here " << endl; 
         // trying to get to a specific index within array of reviews.
            sum = sum + rating->return_stars(i); // get sum of all stars at particular index.
            cout << "finding error" << endl; 
    }
          
    avg =   sum / rating->get_length();
    return avg;
}

void Meal::add_review(Review_Array &f){
    
    rating = new Review_Array[1];
    rating[0] = f;
    ++num_reviews;
    cerr << num_reviews << endl;
    
}


void Meal::display(){ 
    /*for(int i =0; i < rating->get_length(); ++i){
      int q = rating[i]->getReview();                                                // trying to get an integer number here...
    }*/
    //cout << "You selected: " << getname() << " with a star rating:  "  <<  getReview() << endl;  
}

// make a meal object  
// add all review arrays for items in meal...



Meal &Meal::operator= (const Meal &food){ 
    meal_index = food.meal_index;
    //rating = food.rating;
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
        cout << "num of bytes is   " << num_bytes << endl; // index needed by adam where am not utting anything anymore...

        return num_bytes;  
}

void Meal::print_to_file_meal(const char *filename){
    ofstream f(filename);
    f << "Here is your information as requested" << endl;
    for(int i=0; i < rating->get_length(); ++i){
        f << name << "  with " << rating->return_stars(i) << endl;  // returns the rating
    } 
    f.close();
}






