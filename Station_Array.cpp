#include <iostream>
#include "Station_Array.h"
#include <string>
#include <string.h>
using namespace std;
#include <fstream>
#include"../react.h"

// station class
station::station(){
       num_meals = 0;
       meal_array = 0; 
       station_index = 0; 
    }

station::station( Meal* M, int n_m){
    station_index =0;
        num_meals = n_m;
        meal_array = new Meal[num_meals];
        for(int i = 0; i < num_meals; ++i){
            meal_array[i] = M[i];
        }
    }

void station::add_meal(Meal &d){

        if(meal_array == 0){
            meal_array = new Meal[1];
            meal_array[0] = d;
            ++num_meals;
        } else{ 
            Meal* temp = meal_array;
            meal_array = new Meal[num_meals+1];
            for(int i =0; i < num_meals; ++i) {
                meal_array[i] = temp[i]; //old data
            }
            delete [] temp;
            num_meals +=1;
            meal_array[num_meals-1] = d; /// 
        }
    }

void station::display(){ 
        for(int i =0; i < num_meals; ++i){
             meal_array[i].display();
        }
    }

Meal &station::getmeal_array(int h){
    return meal_array[h]; 
}

char *station::getmeal_name(int y){ // k value 
    return meal_array[y].getname();
}

int station::getmeal_rating(int p){
    
       //rating.return_stars(p)
    return meal_array[p].getReview(p); // returns a number.
    //int tmp = getmeal_array(p);      //edit_entry(int p, Review data);
    //cout << tmp << endl;
}

// get name fo meal function; returns strings, call get meal array
int station::getnum_meals(){
    return num_meals;
}

station::~station(){
    delete [] meal_array;
}

bool station::compare(int j, string output, station **arr2, int q){
    string str1 = arr2[j]->getmeal_array(q).getname();
    string str2 = output;
    bool A = (str1.compare(str2) == 0);
 return A;            
}

void station::retrieve_information(int n_s,station **arr1){ // pass in information here  input and num of station
    bool done = 0;
    while(!done){ 
        string input = "What meal rating are you looking for ?: "; 
        string output;  
        cout << input << endl;
        std::getline (std::cin,output);
        //output = "Pasta" ;
        //cin >>  output;  
        if(!output.std::string::compare("end")){ // use strcmp in context with nothing else....
            done =1;
            break;
        }
        else{ // array of pointer to stations... 
        bool found_Meal = 0;
            int i; 
             
            for( i = 0; i < n_s; ++i) {  // station number 
                int k;
                for(k =0; k < arr1[i]->getnum_meals(); k++){ // meal number // revist this
                    if (compare(i, output, arr1, k)){  // int j, string output, station **arr2, int q

                        char *name_of_meal = (arr1[i]->getmeal_name(k));  
        
                        int rating_of_meal = (arr1[i]->getmeal_rating(k)); // look at this line
                        //cout << "here " << endl;
                        arr1[i]->getmeal_array(k).print_to_file_meal("Meal2.txt"); // meant to get acess to meal and print to file //getmeal_rating(int p)
                        cout << "You selected: "<< name_of_meal << " with a meal rating of " << rating_of_meal << endl;
            
                        found_Meal = 1; 
                        print_to_file("Station.txt", arr1,n_s); 
                        break;
                    } // perhaps call print_to_file function here
                } 
            }        
            if (!found_Meal){ 
             cout << "Sorry, the meal rating cannot be found" << endl;
             break;
            }
        } 
        break; // need to get out at some point;
    }
}

void print_to_file(const char *filename, station **array_of_stations, int num_stationss){
    ofstream f(filename);
     f << "Here is your information as requested" << endl;
        for (int i =0; i < num_stationss; ++i){ // need to iterate through stations and meal array
            for(int k = 0; k < i; ++k){
                string n = array_of_stations[i]->getmeal_name(k);
                //int r = (array_of_stations[i]->getmeal_rating(k));
                f << n << " "  << endl;
            }
        }
    f.close();
    }

//station put in global mem
int station::put_in_global_mem(int station_offset){
         // num_bytes // storing number of bytes; add lenght of reviews.. 
        station_index = station_offset;
        int current_offset = station_offset; // keeps track of space taken by last meal.
        for(int i =0; i < num_meals; ++i){ 
            int num_bytes_meal = meal_array[i].put_in_global_mem(current_offset); 
            // think about its contents 
            current_offset += num_bytes_meal; // keep strack where each station starts
            // test that things in global mem can be got out again;...little by little...
        }  
        return current_offset - station_offset; 
}

/*int station::get_from_in_global_mem(int station_offset){
         // num_bytes // storing number of bytes; add lenght of reviews.. 
        station_offset = ;
        int current_offset = station_offset; // keeps track of space taken by last meal.
        for(int i =0; i < num_meals; ++i){ 
            int num_bytes_meal = meal_array[i].put_in_global_mem(current_offset); 
            // think about its contents 
            current_offset += num_bytes_meal; // keep strack where each station starts
        }
        return current_offset - station_offset; 
}*/

// need to know exactly where everything is stored as well;
// create new member varibales in classes to store where each indexes are stores. iterate through meals and stations
// creating separate function for station array....

int put_stationarray_in_global_mem(int offset_for_stations, station **array_of_stations, int num_stations){ // keep track in main
    int curr_offset = offset_for_stations; // keep track of this number;
    for (int i =0; i < num_stations; ++i){
        int nm_bytes_stations = array_of_stations[i]->put_in_global_mem(curr_offset);
        curr_offset += nm_bytes_stations; // keeping track from one station to the next.
    }
    return curr_offset - offset_for_stations; // returns the last place where the station was placed.
}


/*station::station(std::ofstream &is){  
     //station_index = 0;
//cout << "i got here " << endl;
// std::ofstream x ("test.txt"); // read*/ 

/*char* n = "hello";
    is  >> n;
        

 }*/


/*void read_to_file()*/



  





/*std::ofstream file;
  file.open ("test.txt");
  file << " hhrbfh3n  vgvuhgug" << endl;
  file << "here" << endl;  
  file << "here" << endl;  
  file.close();*/

/*fstream filename;
    filename.open("test.txt", ios::out);
    if (!filename) {
		cout << "File not created!";
	}
	else {
		cout << "File created successfully!";
		filename << "Guru99";
		filename.close();
	}*/

//archive should print whatver is in txt file name and reviews...