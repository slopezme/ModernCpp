#include <iostream>
#include <string>
#include <vector>

using namespace std;

// The auto keyword

/*
"auto" was originally introduced in C to specify that a variable should be created on the stack

in Modern C++, it is used to indicate that the compiler should deduce the type from the variable's 
initial value
*/

auto i{42}; // i is an integer
auto str1 = "Hello"; // str1 is a const char*
auto str2 = "Hello"s; // str2 is a std::string

//Using auto to simplify your code

/*
auto is useful for simplifying complex types
*/

vector<int> vec = {1, 2, 3, 4, 5};

vector<int>::iterator it = vec.begin(); // Verbose
auto it = vec.begin(); // Concise

//sometimes it is not easy to work out the type and to type it accurately!

// In modern C++, there are even situations in which it is impossible to know the type of a variable

//auto with qualifiers
//auto will only give the underlying type
// const, reference, etc are ignored

void main(){
    const int& x{42};
auto y = x; // y is an int, not a const int&

y++; 

cout << x << endl; // Prints out 42
cout << y << endl; // Prints out 43
}

// auto with function return value

//we can also use auto to capture the value returned by a function

int func(){
    return 42;
}

auto x= func(); // x is an int


//When to use auto

/*
- when the type doesn't matter
- when the type does not provide additional information
- when the code is clearer withou the type
auto it = vec.begin(); // Clearer than vector<int>::iterator it = vec.begin();

- when the type is difficult to determine
 - Template metaprogramming

- when the type is unknowable
 Compiler gererated class
*/

// Do not use auto
/*
- if you want a particular type
- if it makes the code less clear
  auto h = xyz(); // What is h?
*/