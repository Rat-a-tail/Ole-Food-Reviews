#include<iostream>
using namespace std;
#include "ReviewArray.h"

int main() {
    Review newreview(3, "12/12/12", "martin52", "pizza");
    Review newreview2(2, "2/2/2", "tululu2", "tofu");
    Review newreview3(newreview2);
    newreview3.set_stars(1);
    newreview3.set_date("4/4/04");
    newreview3.set_username("bernard12");
    newreview3.set_food("beans");
    Review_Array test(4);
    test[2].test_display();
    test.edit_entry(2, newreview);
    test[2].test_display();
    test.add_entry(newreview2);
    test[2].test_display();
}