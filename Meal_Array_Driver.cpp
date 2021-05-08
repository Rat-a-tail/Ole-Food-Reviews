#include <iostream>
using namespace std;
#include <string>
#include <string.h>
#include "Meal_Array.h"


int main() {
    Meal* arr;
    arr = new Meal[20]; // default contructor called here, first built the stations empty then fill themw ith the meal information:
     // might need a method(add) to do the thing above.--> station.

    //Soup station
    Meal a("Pea Soup" , 2);
    Meal b("Jar Jar Binks California Meldley", 4);
    //Home station
    Meal c("Tautaun (Beef) Red Wine Braised Pot Roast", 5);
    Meal d(" Carbonite Roasted Spicy Potatoes", 0.2);
    Meal e ("Jakku Noodles", 2);
    // Tortilla station
    Meal f("Sofrito Pinto Beans",3);
    Meal g("Chipotle Black Beans",3);
    Meal h("Achiote chicken Pinto Tinga",0);
    Meal i("Arroz Amarillo",1);

    //Pizza station
    Meal j("Wampa Sausage and Swiss Chard Pizza",3);
    Meal k("Rancor Pepperoni Pizza with Hastings Dairy", 5);
    Meal l("Pizza",0);
    // Pasta station
    Meal m("Roasted Chicken",0);
    Meal n("Pasta",2);
    Meal o("Roasted Local Vegetables",4);
    Meal p("Sauce Marinara",1);
    Meal q("Garlic Peppercorn Sauce",2);
    //delete [] arr;
}























