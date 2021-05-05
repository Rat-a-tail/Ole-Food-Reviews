#include <iostream>
#include "Meal_Array.h"
#include <string>
#include <string.h>
using namespace std;

Meal::Meal(){
       rating = 0;
       name = new char[1];
       name[0] = 0;
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


Meal::~Meal() { 
    delete [] name;
}

station::station(){
       num_meals = 0;
       meal_array = 0;
    }

station::station( Meal* M, int n_m){
        num_meals = n_m;
        meal_array = new Meal[num_meals];
        for(int i = 0; i < num_meals; ++i){
            meal_array[i] = M[i];
        }
    }
    
void station::add_meal(Meal &d){
        if(meal_array == 0){
            meal_array = new Meal[1];
            meal_array[0] = d;
            ++num_meals;
        } else{ 
            Meal* temp = meal_array;
            meal_array = new Meal[num_meals+1];
            for(int i =0; i < num_meals; ++i) {
                meal_array[i] = temp[i]; //old data
            }
            delete [] temp;
            num_meals +=1;
            meal_array[num_meals-1] = d; 
        }
    }
void station::retrieve_information(){
    while(true){
    string input = "What meal rating are you looking for ?: "; 
    string output;  
        cout << input << endl;
        cin >>  output; 
        if(output == "done"){
            break;
        } else {
           int i;
            for(i =0; i < num_meals; i++){
                if (strcmp(meal_array[i].getname(), output.c_str()) == 0){
                    //cout << "are you here" << endl;
                    cout << "You selected:   "<< output << "with a meal rating of "<<  meal_array[i].getrating() << endl;
                    break;
                } 
            }
            if (i == num_meals){
             cout << "Sorry, the meal rating cannot be found" << endl;
            }  
        }
    }
            // loops around again and checks for meal...
} // go through all meals, check output == meal.name, if so, print meal . rating.
    

void station::display(){
        for(int i =0; i < num_meals; ++i){
             meal_array[i].display();
        }
    }

station::~station(){
    delete [] meal_array;
}
