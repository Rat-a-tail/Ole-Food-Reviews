#include"../react.h"

int main() {
  _init();

  add_yaml("Login.yaml");
  if (_just_starting()) {
    _put_raw(20, "Ole Food Reviews");
    _put_raw(0, "Username:");  // null bye appended automatically
    _put_raw(50, "");
    _put_raw(10, "Password:");
    _put_raw(100, "");
  } else {
    char *s = &(_global_mem[50]);
    _put_raw(50, s);
    char *q = &(_global_mem[100]);
    _put_raw(100, q);
  }

  _quit();
}
