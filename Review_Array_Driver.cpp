#include "Review_Array.h";
#include<iostream>
using namespace std;

int main() {
    Review newreview(3, "12/12/12", "martin52", "pizza");
    Review newreview2(2, "2/2/2", "tululu2", "tofu");
    Review newreview3(5, "7/4/15", "hubert9", "olives");
    Review_Array driver_test(10);
    cerr << "An uninitialized review_array:" << endl;
    driver_test.test_display();
    cerr << "Editing entries:" << endl;
    driver_test.edit_entry(0, newreview);
    driver_test.edit_entry(5, newreview2);
    driver_test.test_display();
    cerr << "Adding entries to the end of the array:" << endl;
    driver_test.add_entry(newreview3);
    driver_test.test_display();
    cerr << "Deleting entries:" << endl;
    driver_test.delete_entry(5);
    driver_test.test_display();
}