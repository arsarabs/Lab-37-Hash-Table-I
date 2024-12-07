#include <iostream>
#include <string>
using namespace std;

//STEP 1a: Function Prototypes
//-we need  sum_ascii() that receives a single string and returns the sum of that string's character's ASCII values. 
int sum_ascii(const string& input);


int main() {
    char a = 'A';
    cout << a << endl;
    cout << (int)a << endl;
    int b = 66; 
    cout << b << endl;
    cout << (char)b << endl;


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