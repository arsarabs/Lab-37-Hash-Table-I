#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//STEP 0a: Function Prototypes
//-we need  sum_ascii() that receives a single string and returns the sum of that string's character's ASCII values. 
int sum_ascii(const string& input);


int main() {
    //DELCARE & INITIALIZE VARIBALES
    string test1 = "536B9DFC93AF";
    string test2 = "1DA9D64D02A0";
    string test3 = "666D109AA22E";
    string test4 = "E1D2665B21EA";

    const string DATA_FILE = "lab-37-data.txt"; // Constant for the data file name
    ifstream infile(DATA_FILE);
    string line;
    long long grandTotal = 0; // Using long long to accommodate large sums
    int lineCount = 0; // and of course, we keep track of the number of processed lines


    char a = 'A';
    cout << "Char a: "<< a << endl;
    cout << static_cast<int>(a) << endl;
    int b = 66; 
    cout << "Int b: " << b << endl;
    cout << static_cast<char>(b) << endl;

    cout << "----------------------------------------------" << endl;

    //STEP 1 (TEST)
    cout << "just testing...." << endl;

    cout << "Sum of ASCII values in \"" << test1 << "\": "
         << sum_ascii(test1) << endl; // expecting 729

    cout << "Sum of ASCII values in \"" << test2 << "\": "
        << sum_ascii(test2) << endl;  // expecting 692


    cout << "Sum of ASCII values in \"" << test3 << "\": "
        << sum_ascii(test3) << endl; // expecting 683


    cout << "Sum of ASCII values in \"" << test4 << "\": "
        << sum_ascii(test4) << endl;  // expecting 696

    //STEP 2: Need to process a large dataset
    
    if (!infile.is_open()) {
        cerr << "Error! Couldn't open file '" << DATA_FILE << endl;
        cerr << "ensure file exists in the correct directory/or try again." << endl;
        return 1; // Exit the program with an error code
    }

    while (getline(infile, line)) {
        // Calculate the ASCII sum for the current line and add it to grand_total
        grandTotal += sum_ascii(line);
        lineCount++;
    }
    infile.close(); //close file

    //OUTPUT
    cout << "Grand Total of ASCII sums: " << grandTotal << endl; // expecting 69893419
    cout << "Number of lines processed: " << lineCount << endl;
    
    return 0;
}
 
//STEP 0b: Function Defintions
//-we need  sum_ascii() that receives a single string and returns the sum of that string's character's ASCII values. 
int sum_ascii(const string& input) {
    int total = 0;
    for (char c : input) {
        total += static_cast<int>(c); // this willl cast char to int 
    }
    return total; //forgot to return total haha
}