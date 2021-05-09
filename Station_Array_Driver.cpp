#include <iostream>
using namespace std;
#include <string>
#include <string.h>
#include "Station_Array.h"
#include "Meal_Array.h"

int main() {
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
}



















