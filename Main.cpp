#include <iostream>
#include <string>
using namespace std;

//STEP 1a: Function Prototypes
//-we need  sum_ascii() that receives a single string and returns the sum of that string's character's ASCII values. 
int sum_ascii(const string& input);


int main() {
    char a = 'A';
    cout << "Char a: "<< a << endl;
    cout << static_cast<int>(a) << endl;
    int b = 66; 
    cout << "Int b: " << b << endl;
    cout << static_cast<char>(b) << endl;

    cout << "----------------------------------------------" << endl;
    //Declare/Initialize Variables for testing
    string test1 = "536B9DFC93AF";
    string test2 = "1DA9D64D02A0";
    string test3 = "666D109AA22E";
    string test4 = "E1D2665B21EA";

    cout << "just testing...." << endl;

    cout << "Sum of ASCII values in \"" << test1 << "\": "
         << sum_ascii(test1) << endl; // expecting 729

    cout << "Sum of ASCII values in \"" << test2 << "\": "
        << sum_ascii(test2) << endl;  // expecting 692


    cout << "Sum of ASCII values in \"" << test3 << "\": "
        << sum_ascii(test3) << endl; // expecting 683


    cout << "Sum of ASCII values in \"" << test4 << "\": "
        << sum_ascii(test4) << endl;  // expecting 696

    return 0;
}
 
//STEP 1b: Function Defintions
//-we need  sum_ascii() that receives a single string and returns the sum of that string's character's ASCII values. 
int sum_ascii(const string& input) {
    int total = 0;
    for (char c : input) {
        total += static_cast<int>(c); // this willl cast char to int 
    }
    return total; //forgot to return total haha
}