#include <iostream>
//#include <string.h>
using namespace std;

class Meal_Array{
     char *meal_name;

public:
Meal_Array(const char *M_N) { // constructor
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
 void display() {
   // cout  << "got this far" << endl;
    std::cerr  << "testing printing" << "   "<< meal_name <<  std::endl;
    //need to figure out printing meal names within subclass
}

const char *getMealname() {
    return meal_name;
}

~Meal_Array (){
    delete [] meal_name;
   // std::cerr  << "deallocation complete" << std::endl;
}
};

class Grill : public Meal_Array{
    int student_rate;
   // this class doesn't exists yet
    public:
    Grill(int r, const char *sr) : Meal_Array(sr), student_rate(r){
       // cout  << station_name << endl;
        }
    void display() {
   // cout  << "got this far" << endl;
    std::cerr  << "Rating is " << ":"<< student_rate  <<  " " << getMealname() <<  std::endl;
    }
};

class Soup : public Meal_Array{
    int student_rate;
    public:
    Soup(int r, const char *sr) : Meal_Array(sr){
        student_rate = r;
       // cout  << station_name << endl;
        }
};

class Pasta : public Meal_Array{
    int student_rate;
   // this class doesn't exists yet
    public:
    Pasta(int r, const char *sr) : Meal_Array(sr){
        student_rate = r;
       // cout  << station_name << endl;
        }
};

class Pizza : public Meal_Array{
    int student_rate;
   // this class doesn't exists yet
    public:
    Pizza(int r, const char *sr) : Meal_Array(sr){
        student_rate = r;
       // cout  << station_name << endl;
        }
};

class Bowl : public Meal_Array{
    int student_rate;
   // this class doesn't exists yet
    public:
    Bowl(int r, const char *sr) : Meal_Array(sr){
        student_rate = r;
       // cout  << station_name << endl;
        }
};

class Deserts : public Meal_Array{
    int student_rate;
   // this class doesn't exists yet
    public:
    Deserts(int r, const char *sr) : Meal_Array(sr){
        student_rate = r;
       // cout  << station_name << endl;
        }
};

class Home : public Meal_Array{
    int student_rate;
   // this class doesn't exists yet
    public:
    Home(int r, const char *sr) : Meal_Array(sr){
        student_rate = r;
       // cout  << station_name << endl;
        }
};

class Tortilla : public Meal_Array{
    int student_rate;
   // this class doesn't exists yet
    public:
    Tortilla(int r, const char *sr) : Meal_Array(sr){
        student_rate = r;
       // cout  << station_name << endl;
        }
};

class Grains : public Meal_Array{
    int student_rate;
   // this class doesn't exists yet
    public:
    Grains(int r, const char *sr) : Meal_Array(sr){
        student_rate = r;
       // cout  << station_name << endl;
        }
};

class Salad : public Meal_Array{
    int student_rate;
   // this class doesn't exists yet
    public:
    Salad(int r, const char *sr) : Meal_Array(sr){
        student_rate = r;
       // cout  << station_name << endl;
        }
};

int main () {
//char str[] = "Grill";
Meal_Array M1("Fried Chicken ");
M1.display();

Grill G1(3, "Panini");
G1.display();

Soup S1(4, "Soup");
S1.display();

Pasta P1(4, "Pasta");
P1.display();

Pizza PP1(4, "Pizza");
PP1.display();

Bowl B1(4, "Bowl");
B1.display();

Deserts D1(4, "Cake");
D1.display();

Home H1(4, "Home");
H1.display();

Tortilla T1(4, "Tortilla");
T1.display();

Grains G2(4, "Grains");
G2.display();

Salad S2(4, "Salads");
S2.display();
}