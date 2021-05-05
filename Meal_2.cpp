#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Meal{
    char *name; 
    int rating;

    public:
    Meal(){
       rating = 0;
       name = new char[1];
       name[0] = 0;
    }
    Meal(const char *n, int r){
            int len =0;
            while(n[len]!= 0){
            ++len;
            }
            name = new char[len+1];
            for(int i = 0; i < len+1; ++i){
            name[i] = n[i];
            }
            rating = r;
    }
    char *getname(){
        return name;
    }
    int getrating(){
        return rating;
    }

void display(){ 
    cout << "You selected: " << getname() << " with a star rating:  " << getrating() << endl;
}

Meal &operator= (const Meal &food){ 
    rating = food.rating;
    int len = 0;
    while(food.name[len] !=0){
      ++len;
    }
    delete [] name;
    name = new char[len+1];
    for(int i =0;  i < len+1; ++i){
        name[i] = food.name[i];
    }
    return *this;
}


~Meal() { 
    delete [] name;
    //cout << "looking for crash" << endl; 
    // shouldn't delete twice
}
};

class station{
    Meal* meal_array;
    int num_meals;
   // static const int  default_num_meals = 10;

    public:
    station(){
       num_meals = 0;
       meal_array = 0;
    }

    station( Meal* M, int n_m){
        num_meals = n_m;
        meal_array = new Meal[num_meals];
        for(int i = 0; i < num_meals; ++i){
            meal_array[i] = M[i];
        }
    }
    
    void add_meal(Meal &d){
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
bool compare(int i, string output){
    bool A = (strcmp(meal_array[i].getname(), output.c_str()) == 0);
    cout << meal_array[i].getname() << endl;
    //cout << output.c_str() << endl;
    //cout << A<< endl; // incorretc 
 return A;
 
}

void retrieve_information(){
    while(true){
    string input = "What meal rating are you looking for ?: "; 
    string output;  
        cout << input << endl;
        cin >>  output; 
        if(output == "done"){ // use strcmp in context with nothing else....
            break;
        } else {
           int i;
            for(i =0; i < num_meals; i++){
                cout << num_meals <<  " here" << endl;
                if (compare(i, output)){ // ask prof olaf about this line.
                    //cout << "are you here" << endl;
                    cout << "You selected:   "<< output << "with a meal rating of "<<  meal_array[i].getrating() << endl;
                    break;
                } 
            } 
            /*if (i == num_meals){
             cout << "Sorry, the meal rating cannot be found" << endl;
            } */ 
        } // try erasing output but also try calling the function elsewhere, also consider creating anotehr variable...
        /*int i;
        for(i =0; i < num_meals; i++){
            if (strcmp(meal_array[i].getname(), output.c_str()) == 0){
                 cout << "are you here" << endl;
                cout << "You selected:   "<< output << "with a meal rating of "<<  meal_array[i].getrating() << endl;
                break;
            } 
        }*/  
        /*else (i == num_meals){
            cout << "Sorry, the meal rating cannot be found" << endl;
            }*/
    }
            // loops around again and checks for meal...
} // go through all meals, check output == meal.name, if so, print meal . rating.
    

void display(){
        for(int i =0; i < num_meals; ++i){
             meal_array[i].display();
        }
    }

~station(){
    delete [] meal_array;
    //cout << "deallocation" << endl;
}
// work on terminal display.....

/*station(const station &d, int n_m) { // copy constructor
     num_meals = d.num_meals;
    int len;
    while(d.Meal.[len] != 0){
        ++len;
    }
        meal_array = new Meal[len+1];
        for (int j = 0; j < len+1; ++j) {
        meal_array[j] = d.meal_array[j];
        }
}

station &operator=(const station &f){ 
    num_meals = f.num_meals;
    delete [] meal_array;
    meal_array = new Meal[num_meals];
    for(int i =0;  i < num_meals; ++i){
        meal_array[i] = f.meal_array[i];
    }
    return *this;
}*/

};

int main() {
    Meal* arr;
    arr = new Meal[2]; // default contructor called here, first built the stations empty then fill themw ith the meal information:
     // might need a method(add) to do the thing above.--> station.
//arr[0] = m; 
    //m.display();
   // arr[0].display();
//arr[1] = p;
    //arr[1].display();
    //p.display();
    
    
//arr[3] = q;
    //arr[3].display();

    
//arr[5] = r;
    //arr[5].display();
    //Soup station
    Meal a("Yoda's pork and Lentil Soup" , 1);
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




















/*class Meal_Array{
     char *station;
public:
Meal_Array(const char *M_N) { // constructor
        int len = 0; 
        for (int j = 0; M_N[j] !=0; ++j ){
            len = j;
        }
        station_name = new char[len+1];
        for(int i = 0; i < len+1; ++i) {
        station_name[i] = M_N[i];
        }
}
 void display() {
  std::cerr  << "You selected " << ": " << station_name <<  " station" << std::endl;
}

const char *getstation_name() {
    return station_name;
}

~Meal_Array (){
    //std::cerr << "Segmentation fault not here" << std::endl;
   // delete [] station_name;
    
}
};

class Grill : public Meal_Array{
     char *meal_name; 
    int student_rate; 

    public:
    Grill(int r, const char *sr) : Meal_Array(sr){
    student_rate = r;
        int len =0;
        while(sr[len]!=0){
        ++len;
        }
       sr = new char[len+1];
       for ( int i = 0; i < len+1; ++i ) {
        meal_name[i]= sr[i];
        // having segmentation fault error after this line:
         std::cerr << "Segmentation fault not here" << std::endl;
        }
    }

void display() {
    std::cerr  << "Rating is " << ":"<< student_rate  <<  " " << getstation_name() <<  " station "<<  std::endl;
}
~Grill(){
   // delete [] meal_name;
}
};

int main () {
Grill G1(3, "Grill");
G1.display();
}*/