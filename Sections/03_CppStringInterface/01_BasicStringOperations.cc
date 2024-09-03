//Basic String Operations

/*
Assgnment
s1 = s2; //assigns s2 to s1

Appending
s1 += s2; //appends s2 to s1

Concatenation
s1 + s2; //returns a new string that is the concatenation of s1 and s2

Comparison

s1 cmp s2; //where cmp is one of ==, !=, <, <=, >, >=

Compatibility with C stryle strings

std::string has member functions c_str() and data() that return a pointer to a
null-terminated array of characters.

const char *[Char = str.c_str(); //returns a pointer to a null-terminated array of characters

this is useful for passing C++ string to functions that take C string
*/

//#########
// substr()
//#########

/*
the substr() member fuction returns a substring. The substring
starts at the index corresponding to its argument
*/

#include <iostream>
#include <string>

int main(){
    std::string str{"Hello World!"};
    str[1] = 'a';

    std::string s1 = str.substr(6);
    std::string s2 = str.substr(6,2);

    std::cout << "str: " << str << std::endl;
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;

    return 0;
}


//############
// Constructor
//############

//Defauilt constructor
std::string s1; //s1 is an empty string

//Constructor with a string literal

std::string hi{"Hello"}; //hi is a string initialized with "Hello"

// Constrcutor with a count and an initial value

std::string truple_x(3,'x'); //triple_x is a string with 3 x's

//Constructor with an initializer list

std::string howdy{'H','o','w','d','y'}; //howdy is a string initialized with 'H','o','w','d','y'

//we can also initialize a string variable from a substring

std::string hello1(hi,1);      // "ello"
std::string hello2(hi,1,3);    // "ell"
