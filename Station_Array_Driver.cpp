#include <iostream>
using namespace std;
#include <string>
#include <string.h>
#include "Station_Array.h"
#include "ReviewArray.h"
#include <fstream>
//#include "Meal_Array.cpp"
#include<fstream>


int main() {
    Meal* arr;
    arr = new Meal[20]; // default contructor called here, first built the stations empty then fill themw ith the meal information:
     // might need a method(add) to do the thing above.--> station.
    //Soup station
    Review_Array Arr;
    Meal a("Pea Soup", Arr); 
    Meal b("Jar Jar Binks California Meldley", Arr);
    //Home station
    Meal c("Tautaun (Beef) Red Wine Braised Pot Roast", Arr);
    Meal d(" Carbonite Roasted Spicy Potatoes", Arr );
    Meal e ("Jakku Noodles", Arr);
    // Tortilla station
    Meal f("Sofrito Pinto Beans", Arr);
    Meal g("Chipotle Black Beans", Arr);
    Meal h("Achiote chicken Pinto Tinga", Arr);
    Meal i("Arroz Amarillo", Arr);

    //Pizza station
    Meal j("Wampa Sausage and Swiss Chard Pizza", Arr);
    Meal k("Rancor Pepperoni Pizza with Hastings Dairy", Arr);
    Meal l("Pizza",Arr);
    // Pasta station
    Meal m("Roasted Chicken", Arr);
    Meal n("Pasta", Arr);
    Meal o("Roasted Local Vegetables", Arr);
    Meal p("Sauce Marinara", Arr);
    Meal q("Garlic Peppercorn Sauce", Arr);
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
    a.print_to_file_meal("Meal2.txt");

    
    //print_to_file("Meal.txt",array_of_stations, 5);
     
    
    
     //write
    /*std::ofstream x ("test.txt"); // write
    x << "putting to x" << endl;

    x.close();*/
    //cout << "Main here" << endl;

/*std::ifstream f("Meal.txt"); 
f<< num_meals << endl;
    for(int k = 0; k < num_meals; ++k){

        
    }*/


/*std::ofstream file;
  file.open ("test.txt");
  file << " hhrbfh3n  vgvuhgug" << endl;

  
  file << "here" << endl;  
  file.close();*/
  
    //station test(x);
    //test.print_to_file("test.txt"); 
    //test.display();           
}























