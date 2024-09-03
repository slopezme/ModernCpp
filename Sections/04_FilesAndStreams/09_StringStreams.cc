//############
// Stream Types
//############

/*
The basic C++ stream is represented by std::ios
- iostream
   - ostream (cout)
    - istream (cin)

- fstream
    - ofstream (file stream for writing)
    - ifstream (file stream for reading)

- stringstream
    - istringstream (string stream for reading)
    - ostringstream (string stream for writing)
*/


//############
// stringstream
//############

/*
stringstream are defined in <sstream>
- the stringstream class has an std::string data member
- it has the same member functions as the other stream classes
- In effect, it is wrapper around std::string that makes it look like a stream object
*/

//############
// ostringstream
//############

/*
- An ostringstream han an empty std::string object
- we can store data in this string, using the same operations as for otheroutput streams
- The str() member function will return a copy of the stream's string
*/

//############
// to_string implementation
//############

//we can use ostringstream to implement to_string()

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

string To_String(int i){
    ostringstream os;
    os << i;
    return os.str();
}

// In fact, we can do this for any type that has an overloaded << operator

template <typename T>
string To_String(const T& t){
    ostringstream os;
    os << t;
    return os.str();
}

int main(){

    string hello{"Hello, "};
    string pi{To_String(3.14159)};
    hello += pi;
    cout << hello << endl;
}

//############
// ostringstream example
//############

#include <iostream>
#include <iomanip>
#include <sstream>

void example(){
    ostringstream ostr;

    string text;
    cout << " Please enter a word \n";
    cin >> text;
    ostr << setw(8) << text;
    cout << "Please enter another word \n";
    cin >> text;
    ostr << setw(4) << text;

    // Call str() to access the output string
    cout << ostr.str() << endl;
}

// Separating the processing of the text from the output statement makes the code easier
// to read and edit

//############
// istringstream
//############

/*
-An istringstream object uses a copy of an existing string 
   - This string is passed to the istringstream constructor

- We can then read the data from the string, using the same operations as for other input streams
- This is usefull for processing input
   - e.g. breaking up a line of text into words or numbers
*/

//############
// working with istringstream
//############

/*
- Read the input into an std::string object
- validate the input data
  - Check for incomplete, missing or corrupt data
  - check data is in the correct format
  - etc
  - handle errors

- Bind the string object to an istringstream object
- Read the data from the istringstream object

*/


int main2(){

    std::ifstream infile("file.txt");

    if (!infile){
        cout << "Error opening file" << endl;
        return -1;
    }

    string line;
    vector<int> numbers;

    while(getline(infile, line)){
        istringstream is{line};
        int number;
        while(is >> number){
            numbers.push_back(number);
        }
    }

    double sum{0.0};
    for (auto n : numbers){
        cout << n << endl;
        sum += n;
    }

    cout << "Average is " << sum / numbers.size() << endl;
}

//############
// Applications fo stringstreams
//############

/*
ostringstreams are useful when interfacing to systems that expect strings in particular formats
- e.g, operating system, third party libraries, etc

- istringstreams can be used with getline()  to process input more easily than with the >> operator

*/