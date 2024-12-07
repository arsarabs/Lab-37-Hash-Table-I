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
    string test2 = "536B9DFC93AF";
    string test3 = "536B9DFC93AF";
    string test4 = "536B9DFC93AF";

    return 0;
}

/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
//STEP 1b: Function Defintions
//-we need  sum_ascii() that receives a single string and returns the sum of that string's character's ASCII values. 
int sum_ascii(const string& input) {
    int total = 0;
    for (char c : input) {
        total += static_cast<int>(c); // this willl cast char to int 
    }
}