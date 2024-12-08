// COMSC-210 | Lab 38 | Anthony R. Sarabia
// IDE used: Visual Studio

//yes ok it works :)

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

//new prototypes for our interactive menu
void print_entries(const map<int, list<string>>& hash_table);
bool search_key(const map<int, list<string>>& hash_table, const string& key);
void add_key(map<int, list<string>>& hash_table, const string& key);
bool remove_key(map<int, list<string>>& hash_table, const string& key);
bool modify_key(map<int, list<string>>& hash_table, const string& old_key, const string& new_key);
bool load_data(const string& filename, map<int, list<string>>& hash_table, long long& grandTotal, int& lineCount);
bool save_data(const string& filename, const map<int, list<string>>& hash_table);

int main() {
    //DELCARE & INITIALIZE VARIBALES
    const string DATA_FILE = "lab-37-data.txt"; // Constant for the data file name
    ifstream infile(DATA_FILE);
    string line;
    long long grandTotal = 0; // Using long long to accommodate large sums
    int lineCount = 0; // and of course, we keep track of the number of processed lines
    int entriesDisplayed = 0;
    int choice;
    string input_key, new_key;

    //STEP 3: Creating/populating hash table
    map<int, list<string>> hash_table;
    

    // Load data from file
    if (!load_data(DATA_FILE, hash_table, grandTotal, lineCount)) {
        cerr << "Error loading data. Exiting program." << endl;
        return 1;
    }

    do {

    } while (choice != 6);
    
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

void print_entries(const map<int, list<string>>& hash_table) {
    int entriesDisplayed = 0;

    // Iterate through each key-value pair in the hash table
    for (auto it = hash_table.begin(); it != hash_table.end() && entriesDisplayed < MAX_DISPLAY; ++it) {
        // 'it->first' is the hash index, and 'it->second' is the list of codes associated with that index
        
        // Iterate through each code in the list associated with the current hash index
        for (const auto& code : it->second) {
            cout << "Hash Index: " << it->first << " | Code: " << code << endl; 
            entriesDisplayed++; // increment  counter as we've displayed another entry

            //and if we've reached the maximum number of entries to display, exit the inner loop
            if (entriesDisplayed >= MAX_DISPLAY) {
                break;
            }
        }
    }

    // If no entries were displayed 
    if (entriesDisplayed == 0) {
        cout << "No entries to display" << endl;
    }
}
bool search_key(const map<int, list<string>>& hash_table, const string& key) {
    //generate hash index for the given key
    int hash_index = gen_hash_index(key); 

    //attempt to find index in table
    auto it = hash_table.find(hash_index);

    //checkc if index exits (in table) & use std 'find' to search for key 
    if (it != hash_table.end()) {
        const list<string>& codes = it->second;

        //right, need to 'find' 
        return find(codes.begin(), codes.end(), key) != codes.end();
    }

    //return bool (assuming key doesnt exist)
    return false;
}
void add_key(map<int, list<string>>& hash_table, const string& key) {
    //generate hash index for the given key
    int hash_index = gen_hash_index(key);

    //all we need to do different is we need to check to see if key already exists to avoid duplicates. if it doesnt exist,
    //add it to the list, and if it does exist, then inform user
    if (!search_key(hash_table, key)) {
        hash_table[hash_index].push_back(key); // add it using push back
    }else {
        cout << "Key: " << key << " already exists in hash table" << endl;
    }

}
bool remove_key(map<int, list<string>>& hash_table, const string& key) {
    // Generate the hash index for the given key using the hashing function
    int hash_index = gen_hash_index(key);

    // Attempt to find the hash index in the hash table
    auto it = hash_table.find(hash_index);

    // Check if the hash index exists in the hash table
    if (it != hash_table.end()) {
        list<string>& codes = it->second; // Retrieve the list of codes associated with the hash index

        // Use the standard library's 'find' function to locate the key within the list of codes
        auto code_it = find(codes.begin(), codes.end(), key);

        // If the key is found within the list
        if (code_it != codes.end()) {
            codes.erase(code_it); // Remove the key from the list

            // After removal, check if the list is empty
            if (codes.empty()) {
                hash_table.erase(it); // If empty, remove the hash index from the map to clean up
            }

            return true; // Indicate that the key was successfully removed
        }
    }

    // If the hash index or the key within it was not found, return false
    return false;

}
bool modify_key(map<int, list<string>>& hash_table, const string& old_key, const string& new_key) {
   //testing this
    if (remove_key(hash_table, old_key)) {
        add_key(hash_table, new_key);
        return true; //indicate mod is a success
    }
    return false; // indicate mod fails
}
bool load_data(const string& filename, map<int, list<string>>& hash_table, long long& grandTotal, int& lineCount) {
    ifstream infile(filename);
    string line;

    if (!infile.is_open()) {
        cout << "Error! Couldn't open file '" << filename << "'\n";
        cout << "Ensure the file exists in the correct directory and try again.\n";
        return false;
    }

    while (getline(infile, line)) {
        // Validate length of line
        if (line.length() != 12) {
            cout << "Warning: Skipping invalid line " << (lineCount + 1)
                << " (Incorrect length: " << line.length() << ")\n";
            continue;
        }

        // Generate hash index for the current line
        int hash_index = gen_hash_index(line);

        // Add the line to the hash table
        hash_table[hash_index].push_back(line);
        lineCount++;

        // Calculate the ASCII sum for the current line and add it to grandTotal
        grandTotal += sum_ascii(line);
    }
    infile.close(); // Close the file
    return true;
}
bool save_data(const string& filename, const map<int, list<string>>& hash_table) {
    ofstream outfile(filename, ios::trunc); // Open file for writing 

    if (!outfile.is_open()) {
        cout << "Error! Couldn't open file '" << filename << "' for writing.\n";
        return false;
    }

    for (const auto& pair : hash_table) {
        for (const auto& code : pair.second) {
            outfile << code << "\n";
        }
    }
    outfile.close(); // Close the file
    return true;
}