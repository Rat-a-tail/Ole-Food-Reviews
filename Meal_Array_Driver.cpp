#include <iostream>
using namespace std;
#include "Meal_Array.h"

int main() {
    cerr << "*** Driver program for Meal_Array class ***" << endl;
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

