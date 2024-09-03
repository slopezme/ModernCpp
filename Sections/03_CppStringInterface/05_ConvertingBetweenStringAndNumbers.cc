#include <iostream>
#include <string>

using namespace std;

/*
- C provided the functions aoti() and atof() to convert C-style strings to numbers.
- Many compilters provided non-standard itoa() et al for the opposite conversion.
- these were inherited by C++
-C++11 provides to_string()

- Returns its argument as an std::string
-Olverloads support all interger and floating-point types
*/

string pi {to_string(3.14159)};

// Converting Strings to Integers

// stoi() takes an std::string argument and returns an int

string str{"123"};
int i = stoi(str);   // i is 123

// Leading whitespace is ignored

string str2{"  123 456"};
int i2 = stoi(str2); // i2 is 123

//############
// Error Handling
//############

/*
An optional second argument gives the number of characters which were processed

- it there is no error, this is queal to the string size

- if the conversion is partially successful, this gives the index of the first non- numeric character

size_t n_processed;
auto i = stoi(str2, &n_processed); // i is 123, n_processed is 5

if(n_processed != str2.size()){
    ...

if the conversion fails, completely, it throws an exception

    stoi("abcdef"s); // Connot be converted - throws invalid_argument

*/

//############
// Base Conversion
//############

/*
The string is assumed to be decimal by defaul
An optional third argument gives the base

-can be 0-36
- Digits can be 0-9, a-z, or A-Z

cout << stoi("2a", nullptr, 16); // Output: 42
*/


//############
// Converting String to Floating - point
//############

/*
stod() returns double
there is no option to use different bases
- similar functions flo float and long double

coout << stoi(pi); // Output: 3
cout  << sod(pi); // Output: 3.14159

*/

void f4(){
    string pi{"3.14159"};

    cout << "pi = " << pi << endl;  // Output: "3.14159

    size_t n_processed;

    cout << "stoi:\n";                                  // Displays: stoi:
    cout << stoi(pi, &n_processed) << endl;             // Displays: 3
    cout << n_processed << "characters processed\n\n";  // Displays: 1 characters processed
    cout << "stod:\n";                                  // Displays: 3
    cout << stod(pi, &n_processed) << endl;             // Displays: 3.14159
    cout << n_processed << "characters processed\n\n";  // Displays: 7 characters processed
}
