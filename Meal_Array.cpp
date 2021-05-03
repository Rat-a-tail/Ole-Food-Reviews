#include <iostream>
#include "Meal_Array.h"
using namespace std;

Meal_Array::Meal_Array(const char *M_N) { // constructor
        int len = 0; 
        for (int j = 0; M_N[j] !=0; ++j ){
            len = j;
        }
        meal_name = new char[len+1];
        for(int i = 0; i < len+1; ++i) {
        meal_name[i] = M_N[i];
       // cout  << station_name << endl; 
        }
}

void Meal_Array::display() {
   // cout  << "got this far" << endl;
    std::cerr  << "testing printing" << "   "<< meal_name <<  std::endl;
    //need to figure out printing meal names within subclass
}

const char *Meal_Array::getMealname() {
    return meal_name;
}

Meal_Array::~Meal_Array (){
    delete [] meal_name;
   // std::cerr  << "deallocation complete" << std::endl;
}

Grill::Grill(int r, const char *sr) : Meal_Array(sr), student_rate(r){
        }
void Grill::display() {
   // cout  << "got this far" << endl;
    std::cerr  << "Rating is " << ":"<< student_rate  <<  " " << getMealname() <<  std::endl;
    }
Soup::Soup(int r, const char *sr) : Meal_Array(sr){
        student_rate = r;
       // cout  << station_name << endl;
        }

Pasta::Pasta(int r, const char *sr) : Meal_Array(sr){
        student_rate = r;
       // cout  << station_name << endl;
        }
Pizza::Pizza(int r, const char *sr) : Meal_Array(sr){
        student_rate = r;
       // cout  << station_name << endl;
        }
Bowl::Bowl(int r, const char *sr) : Meal_Array(sr){
        student_rate = r;
       // cout  << station_name << endl;
       }
Deserts::Deserts(int r, const char *sr) : Meal_Array(sr){
        student_rate = r;
       // cout  << station_name << endl;
        } 
Home::Home(int r, const char *sr) : Meal_Array(sr){
        student_rate = r;
       // cout  << station_name << endl;
        }
Tortilla::Tortilla(int r, const char *sr) : Meal_Array(sr){
        student_rate = r;
       // cout  << station_name << endl;
        }
Grains::Grains(int r, const char *sr) : Meal_Array(sr){
        student_rate = r;
       // cout  << station_name << endl;
        }
Salad::Salad(int r, const char *sr) : Meal_Array(sr){
        student_rate = r;
       // cout  << station_name << endl;
        }



