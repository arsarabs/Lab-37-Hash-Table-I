#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>

using namespace std;

//STEP 0a: Function Prototypes & Constants
//-we need  sum_ascii() that receives a single string and returns the sum of that string's character's ASCII values. 
int sum_ascii(const string& input);
int gen_hash_index(const string& input);

const int MODULUS = 97;   // prime number (for hashing)
const int MAX_DISPLAY = 100; // max map entries to display


int main() {
    //DELCARE & INITIALIZE VARIBALES
    const string DATA_FILE = "lab-37-data.txt"; // Constant for the data file name
    ifstream infile(DATA_FILE);
    string line;
    long long grandTotal = 0; // Using long long to accommodate large sums
    int lineCount = 0; // and of course, we keep track of the number of processed lines
    string test1 = "536B9DFC93AF";
    string test2 = "1DA9D64D02A0";
    string test3 = "666D109AA22E";
    string test4 = "E1D2665B21EA";

    //STEP 3: Creating/populating hash table
    map<int, list<string>> hash_table;
    int hash_index = gen_hash_index(line);

    //onto the code
    char a = 'A';
    cout << "Char a: "<< a << endl;
    cout << static_cast<int>(a) << endl;
    int b = 66; 
    cout << "Int b: " << b << endl;
    cout << static_cast<char>(b) << endl;

    cout << "----------------------------------------------" << endl;

    //STEP 1 (& and now 3)
    
    //TEST 1
    cout << "Sum of ASCII values in \"" << test1 << "\": "
         << sum_ascii(test1) << endl; // expecting 729
    cout << "Hash index for \"" << test1 << "\": "
        << gen_hash_index(test1) << endl; 

    //TEST 2
    cout << "Sum of ASCII values in \"" << test1 << "\": "
        << sum_ascii(test2) << endl; // expecting 729
    cout << "Hash index for \"" << test1 << "\": "
        << gen_hash_index(test2) << endl;

    //TEST 3
    cout << "Sum of ASCII values in \"" << test1 << "\": "
        << sum_ascii(test3) << endl; // expecting 729
    cout << "Hash index for \"" << test1 << "\": "
        << gen_hash_index(test3) << endl;

    //TEST 4
    cout << "Sum of ASCII values in \"" << test1 << "\": "
        << sum_ascii(test4) << endl; // expecting 729
    cout << "Hash index for \"" << test1 << "\": "
        << gen_hash_index(test4) << endl;

    cout << "----------------------------------------------" << endl;

    

    //STEP 2: Need to process a large dataset
    
    if (!infile.is_open()) {
        cerr << "Error! Couldn't open file '" << DATA_FILE << endl;
        cerr << "ensure file exists in the correct directory/or try again." << endl;
        return 1; // Exit the program with an error code
    }

    while (getline(infile, line)) {

        //first, validate length of line

        if (line.length() != 12) {
            cout << "Warning: Skipping invalid line " << (lineCount + 1)
                << " (Incorrect length: " << line.length() << ")" << endl;
            continue;
        }

        //next
        hash_table[hash_index].push_back(line); // this adds the current string 
        // (`line`) to the list corresponding to `hash_index` in the hash table
        lineCount++; //increment line count

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

int gen_hash_index(const string& input) {
    int ascii_sum = sum_ascii(input);
    return ascii_sum % MODULUS;
}