#include <iostream>
#include <string>



void main(){
using namespace std;
// Casting

/*
A cast perfgorms an explicit conversion
Casting can serve severl different purposes
- convert an expression to a different type
- convert a const expression to the non-const version
- convert data in a buffer to untyped binary data
- convert a pointer to a base class object to pointer to derived

Casting is rarely necessary in well wirtten C++ code
It is often a sign that something "suspicious" is going on
*/

//################
//### C-style cast
//################

// The C-Style cast puts the type in parentheses

int c = 'A';                // c is an integer with value 65, taken from the ASCII table
cout << c << endl;          // Prints out 65
cout << (char)c << endl;    // Prints out A

//This is easy to overlook when reading through code
// it fails to distinguish between the different types of casts

//C++98 Casts

/*
(Type)expr
Becomes xyz_cast<Type>(expr)
*/

//################
//### Static Cast
//################

//static_cast is used to convert an expression to a different type

cout <<static_cast<char>(c) << endl; // Prints out A

//################
//### const_cast
//################

//const_cast is used to convert a const expression to the non-const version

// May be needed to call functionts that aren't cont-correct (old or badly written code)

auto print = [](char *str) { cout << str << endl; };

const char *msg = "Hello";
print(msg);                    // Error: cannot convert const char* to char*
print(const_cast<char*>(msg)); // OK: const_cast removes the const qualifier

//Undefined behavior if print() does mutate str!

//####################
//### reinterpret_cast
//####################

/*
reinterpret_cast is used to convert data in a buffer to untyped binary data
Mainly used in low level work (communication with hardware, operating system, binary files)
*/

//################
//### dinamic_cast
//################

/*
dynamic_cast is used to convert a pointer to a base class object to a pointer to a derived class object
- also applies to references

unlike the other types, it is done at runtime

*/




}