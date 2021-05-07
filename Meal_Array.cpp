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


Meal::~Meal(){
    delete [] name;
}

// station class
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
            meal_array[num_meals-1] = d; /// 
        }
    }


void station::display(){
        for(int i =0; i < num_meals; ++i){
             meal_array[i].display();
        }
    }

Meal &station::getmeal_array(int h){
    return meal_array[h]; 
}

char *station::getmeal_name(int y){ // k value 
    return meal_array[y].getname();
}

int station::getmeal_rating(int p){
    int tmp = getmeal_array(p).getrating();
    //cout << tmp << endl;
    return tmp; 
}
// get name fo meal function; returns strings, call get meal array
int station::getnum_meals(){
    return num_meals;
}

station::~station(){
    delete [] meal_array;
}

bool station::compare(int j, string output, station **arr2, int q){
    string str1 = arr2[j]->getmeal_array(q).getname();
    string str2 = output;
    bool A = (str1.compare(str2) == 0);
 return A;            
}

void station::retrieve_information(int n_s,station **arr1){ // pass in information here  input and num of station
    while(true){ 
        string input = "What meal rating are you looking for ?: "; 
        string output;  
        cout << input << endl;
        std::getline (std::cin,output);  
        if(output == "end"){ // use strcmp in context with nothing else....
            break;
        }else { // array of pointer to stations... 
            int i;
            for( i = 0; i < n_s; ++i) {  // station number 
                int k;
                for(k =0; k < arr1[i]->getnum_meals(); k++){ // meal number // revist this
                    if (compare(i, output, arr1, k)){  // int j, string output, station **arr2, int q
                        char *name_of_meal = (arr1[i]->getmeal_name(k));
                        int rating_of_meal = (arr1[i]->getmeal_rating(k));
                        cout << "You selected: "<< name_of_meal << " with a meal rating of " <<  rating_of_meal << endl;
                        break;
                    }
                 
                } 
            } 
                     
            if (i == n_s){
             cout << "Sorry, the meal rating cannot be found" << endl;
            } 
        } 
    }
}