#include"../react.h"
#include "Messages.h"
  
int main() {
  _init();

  string receiver;
  Messages m;
  if (_just_starting()) {
    m.append_message("Hello World");
    receiver = "u1";
  }

  _put_raw(0, "> ");  // prompt
  m.put_in_global_mem(100, 1000);
  if (receiver != ""){
    _rput(receiver.c_str());
     } 
  else {
    cerr << "Received: " << &(_global_mem[3]) << endl;
  }
}

