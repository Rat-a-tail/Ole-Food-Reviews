#include"../react.h"
#include "Messages.h"
#include <iostream>

int main() {
  _init();
  Messages m;
  m.get_from_global_mem(100, 1000);

  m.display();
  _print_raw(0); // Prints the prompt (Hopefully, no way to tell);

  _put_raw(0, "u1");
  _user_input(3); 
  _rput("server1");
}

