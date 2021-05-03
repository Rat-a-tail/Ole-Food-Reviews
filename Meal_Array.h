#ifndef _Meal_Array_H_
#define _Meal_Array_H_
//#include <string>
#include<iostream>
using namespace std;

class Meal_Array{
    char *meal_name;
public:
Meal_Array(const char *M_N);
void display();
const char *getMealname();
~Meal_Array ();
}; 

class Grill : public Meal_Array{
    int student_rate;
    public:
    Grill(int r, const char *sr); 
    void display();
};

class Soup : public Meal_Array{
    int student_rate;
    public:
    Soup(int r, const char *sr);
};

class Pasta : public Meal_Array{
    int student_rate;
    public:
    Pasta(int r, const char *sr);
};

class Pizza : public Meal_Array{
    int student_rate;
   // this class doesn't exists yet
    public:
    Pizza(int r, const char *sr);
};

class Bowl : public Meal_Array{
    int student_rate;
   // this class doesn't exists yet
    public:
    Bowl(int r, const char *sr);
};

class Deserts : public Meal_Array{
    int student_rate;
   // Review class ---this class doesn't exists yet
    public:
    Deserts(int r, const char *sr);
};

class Home : public Meal_Array{
    int student_rate;
   // this class doesn't exists yet
    public:
    Home(int r, const char *sr);
};

class Tortilla : public Meal_Array{
    int student_rate;
   // this class doesn't exists yet
    public:
    Tortilla(int r, const char *sr);
};

class Grains : public Meal_Array{
    int student_rate;
   // this class doesn't exists yet
    public:
    Grains(int r, const char *sr);
};

class Salad : public Meal_Array{
    int student_rate;
   // this class doesn't exists yet
    public:
    Salad(int r, const char *sr);
};
#endif 