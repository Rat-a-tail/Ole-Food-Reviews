#include<iostream>
using namespace std;
#include "ReviewArray.h"

int main() {
    Review newreview(3, "12/12/12", "martin52", "pizza");
    Review newreview2(2, "2/2/2", "tululu2", "tofu");
    Review_Array test(4);
    test[2].test_display();
    test.edit_entry(2, newreview);
    test[2].test_display();
    /*test.add_entry(newreview2);
    test[2].test_display();*/
}