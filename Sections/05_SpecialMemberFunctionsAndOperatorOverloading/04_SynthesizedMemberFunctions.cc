
//############
// Synthesized Member Functions
//############

/*
If we do not define special member functions, the compiler will often " synthesize " them for us
- Constructor
- Copy Constructor
- Assignment Operator
- Some new member functions in modern C++ fro move oeprations
- Destructor

*/

//############
// Traditional C++ Rules
//############

/*
If no constructor or copy constructor is defined, the compiler will synthesize a default constructor 
- this takes no arguments
- this will cal the default constructor for each data member

If no copy constructor is defined, the compiler will synthesize a copy constructor
- this calls the copy constructor for each data member

If no assignment operator is defined, the compiler will synthesize an assignment operator
- This calls the assignment operator for each data member

If no destructor is defined, the compiler will synthesize a destructor
- this does nothing

*/

//############
// Modern C++ Rules
//############

/*
The rules became mucho more complext with the addition of new special member functions
- There are now five special member functions instead of three
- Some special member functions are only synthesized if certain other special member functions are not defined
*/

#include <iostream>
#include <string>

using namespace std;

class Test{
    int i;
    string str;
    public:
    Test(int i, const string& str): i{i}, str{str} {}
    // Test() {}
    // Test(const Test& other) : i {other.i}, str {other.str} {}
    // Test& operator=(const Test& other) {
    //     i = other.i;
    //     str = other.str;
    // }
    ~Test() {}

    void print() {cout << "i = " << i << ", str = " << str << endl;}

};

int main() {
    Test test(5, "Hello"s);
    //Test test;
    cout << "test after default constructor: ";
    test.print();

    Test test2(10, "Goodbye"s);
    cout << "test2 after default constructor: ";
    test2.print();

    Test test3  = test; 
    cout << "test3 after copy constructor: ";
    test3.print();

    test = test2;
    cout << "test after assignment operator: ";
    test.print();
}

//############
// Drawback of synthesized functions
//############

/*
These synthesized functions are usually good enough, but sometimes the can be disastrous
- Built in type members are default initialized
- Pointer members are "shallow copied"

In the cases, we need to implement the functions ourselves to make sure the correct operations are performed
- Implement a default constructor which initializes built in members
- Implement copy constructor and assignment operator which make a "deep copy" of pointer members

*/