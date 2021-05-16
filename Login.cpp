#include"../react.h"
#include "UserArray.h"
#include "User.h"
#include "ReviewArray.h"
#include "Meal_Array.h"
#include "Station_Array.h"


int main() {
  _init();
  std::ifstream f("Userinfo.txt");
  UserArrayP sto(f);
  //sto.store_global(300);
  
  if (_just_starting()) {
    cerr << "just_starting" <<endl;
    add_yaml("welcome.yaml");
    cerr <<"after add_yaml" <<endl;
    _put_raw(20, "Ole Food Reviews");
    _put_raw(0, "Username:");  // null bye appended automatically
    _put_raw(10, "Password:");
    _put_raw(40, "submit");
    _put_raw(50, "New User");
    _put_raw(60, "Today's Meals");
    _put_raw(80, "Archive");
    _put_raw(90, "St Olaf username: ");
    _put_raw(110, "Create Password: ");
    _put_raw(130, "Succesfully Registered");
    _put_raw(160, "Incorrect Username or Password");
    _put_raw(190, "Login");
    _put_raw(200, "Login Successful");
    _put_raw(220, "Register");
    _put_raw(230, "");
    _put_raw(250, "");
    _put_raw(270, "");
    cerr <<"after put raw statement" <<endl;
  }
  if (_received_event()) {
    cerr <<"received_event" <<endl;
    if (_event_id_is("login")){
      add_yaml("Login.yaml");
    }
    else if (_event_id_is("submit")) {
      cerr<< "submit" <<endl;
      char *s = &(_global_mem[230]);
      char *q = &(_global_mem[250]);
    	bool a = sto.checking(s, q);
	
      if (a){
	      cerr << "correct" <<endl;
        add_yaml("mainpage.yaml");
      }
      
      else{
        add_yaml("Login.yaml");
      }
    }
    else if (_event_id_is("register")){
      char *s = &(_global_mem[230]);
      char *q = &(_global_mem[250]);
      add_yaml("mainpage.yaml");
      User input(s, q);
      //input.display();
      sto.addUser(input);
      //sto.store_global(5);
      sto.print_to_file("Userinfo.txt");
    }
    
    else if (_event_id_is("newuser")) {
      add_yaml("newuser.yaml");
    }
    
    else if(_event_id_is("today")){
        add_yaml("today.yaml");
    }

    else if(_event_id_is("archive")){
        add_yaml("archive.yaml");
    }
  }
  _quit();
}


