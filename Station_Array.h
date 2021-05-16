#ifndef _Station_Array_H_
#define _Station_Array_H_
#include<iostream>
#include <string>
#include <string.h>
using namespace std;
#include <fstream>
#include "Meal_Array.h"
#include "ReviewArray.h"

class station{
    Meal* meal_array;
    int num_meals;
    static const int  default_num_meals = 10;
    int station_index; // keeping track of my starting index within global mem.
public:
    station();
    station( Meal* M, int n_m);
    void add_meal(Meal &d);
    void display();
    Meal &getmeal_array(int h);
    char *getmeal_name(int y);
    int getmeal_rating(int p);
    int getnum_meals();
    bool compare(int j, string output, station **arr2, int q);
    void retrieve_information(int n_s,station **arr1);
    ~station();
    int put_in_global_mem(int station_offset);
   
    station(std::ofstream &is);
};
int put_stationarray_in_global_mem(int offset_for_stations, station **array_of_stations, int num_stations);
void print_to_file(const char *filename, station **array_of_stations, int num_stationss);
#endif 

