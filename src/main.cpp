#include "songClass.hpp"
#include <iostream>

using namespace std;

int main() {
    cout << "=== TEST CASE 5: Empty and Whitespace Inputs ===" << endl;
    
    cout << "Testing with empty inputs (just press enter):" << endl;
    Song song1;
    cout << "Result: " << song1 << endl;
    
    cout << "\nTesting with whitespace-only inputs:" << endl;
    Song song2;
    cout << "Result: " << song2 << endl;
    
    return 0;
}