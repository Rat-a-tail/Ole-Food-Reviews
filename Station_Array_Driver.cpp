#include <iostream>
using namespace std;
#include <string>
#include <string.h>
#include "Station_Array.h"
#include "Meal_Array.cpp"
#include<fstream>

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

    station Pizza;
    Pizza.add_meal(j);
    Pizza.add_meal(k);
    Pizza.add_meal(l);
    
    station Pasta;
    Pasta.add_meal(m);
    Pasta.add_meal(n);
    Pasta.add_meal(o);
    Pasta.add_meal(p);
    Pasta.add_meal(q);
    
    station **array_of_stations;
    int num_stations = 5;
    array_of_stations = new station*[num_stations];
    array_of_stations[0] = &Soup;
    array_of_stations[1] = &Home;
    array_of_stations[2] = &Tortilla;
    array_of_stations[3] = &Pizza;
    array_of_stations[4] = &Pasta;

    Soup.retrieve_information(num_stations, array_of_stations); 
    Home.retrieve_information(num_stations, array_of_stations); 
    Tortilla.retrieve_information(num_stations, array_of_stations); 
    Pizza.retrieve_information(num_stations, array_of_stations); 
    Pasta.retrieve_information(num_stations, array_of_stations); 

    put_stationarray_in_global_mem(0, array_of_stations, 5); 

    /*std::ifstream x("test.txt");
    Meal z(x);
    z.display();*/

}























