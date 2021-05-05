#include <iostream>
using namespace std;
#include <string>
#include <string.h>
#include "Meal_Array.h"

int main() {
    Meal* arr;
    arr = new Meal[2]; // default contructor called here, first built the stations empty then fill themw ith the meal information:
     // might need a method(add) to do the thing above.--> station.

    //Soup station
    Meal a("Yoda's prok and Lentil Soup" , 1);
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
    Meal l("Five Cheese Pizza",2);
    // Pasta station
    Meal m("Pasta",0);
    Meal n("Roasted Chicken",2);
    Meal o("Roasted Local Vegetables",4);
    Meal p("Sauce Marinara",1);
    Meal q("Garlic Peppercorn Sauce",2);

    delete [] arr;

    station Soup;
    Soup.add_meal(a);
    Soup.add_meal(b);
    //Soup.display();

    station Home;
    Home.add_meal(c);
    Home.add_meal(d);
    Home.add_meal(e);
    //Home.display();

    station Tortilla;
    Tortilla.add_meal(f);
    Tortilla.add_meal(g);
    Tortilla.add_meal(h);
    Tortilla.add_meal(i);
    //Tortilla.display();

    station Pasta;
    Tortilla.add_meal(m);
    Tortilla.add_meal(n);
    Tortilla.add_meal(o);
    Tortilla.add_meal(p);
    Tortilla.add_meal(q);
    //Tortilla.display();
    Soup.retrieve_information();
    Home.retrieve_information();
    Pasta.retrieve_information();
    Tortilla.retrieve_information();
}














