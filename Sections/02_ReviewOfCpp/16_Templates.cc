
#include <iostream>
#include <vector>

// ###############################
// ### Why are templates usedfull?
// ###############################

/*
we often need to write code which is functionally the same,
but operates on different types of data
- vector of int
- vector of double
- vector of string

C++ templates allow us to write generic code that works with any type of data

this is known as "generic programming"
*/


// ##########################
// ### Template Instantiation
// ##########################

/*
when we use the tempalte with data of a particular type, the compiler will
generate the code needed for that type
- eg vector<int> will cause the compiler to define a class that is a vector of ints
- the compiler will insert the source code for the class definition into the
translation unit
- this code will then be compiled as a part of the program

- This is called an " instantiation" of the template
- it happens automatically when the compiler sees vector<int> in the code

- For this to be possible, the compiler must be able to see the full definition
of the vector template class in the translation unit
*/


// ######################
// ### Writing a template
// ######################

/*
when we write a template, we use a "dummy" type to show the compiler what the code looks like
This dummy type is called a "template parameter"
A template can be either a function template or a class template
*/

// Function template for finding the maximum of two values

template <class T> // T is the template parameter
T max(const T& x, const T& y) {
    return (x > y) ? x : y;
}

// when we call Max() the compiller will instantiate the function from the template code,
// with T replaced by the type of the arguments

int main() {
    std::cout << max(3, 5) << std::endl; // max<int>(3, 5)
    std::cout << max(3.5, 5.2) << std::endl; // max<double>(3.5, 5.2)
}

// the compiler deduces that the argument type is double, so it instantiates the function
// the compiller will generate a definition of the Max function, in which T is replaced by double

/*
double Max(const double& x, const double& y) {   // Replace "T" with "double"
    return (x > y) ? x : y;
}
*/

// ###################################
// ### Templates and Code Organization
// ###################################

/*
With a regular function, the compiler only need to be able to see its declaration when it is called
- the compiler has to check that the types are used correctly in the call

For a template function, the compiler must be able to see the full definition when it is called
- The compiler has to generate the instantiated code for that call

Most programmers write the template definition in the header file, so it is included automatically

Some programmers put all their templated in a separate ".inc" file and include that file separately
*/

// ##################
// ### Class Template
// ##################

// we can write classes that work with data of any type

template <class T>
class Test{
    T data;
    Test(const T& data) : data(data) {}
};

// to create an instance of this class, we puth the type in angle brackets

Test<std::string> test("Hello");

class Test_xcakljha{                // Instantiated with unique name
    std::string data;
    Test(const std::string& data) : data(data) {}
};

// ###########################################
// ### Constructor Argument Deduction in C++17
// ###########################################

/*
when we create an object of a template class, the c++17 compiler
can deduce the parameter type
*/

std::vector<int> vec{1,2,3};     // C++17 - deduced as vector<int>
std::vector vec{1,2,3};          // C++17 - deduced as vector<int>

/*
This is known as "CTAD"
- Constructor Template Argument Deduction
- similar to calling a templated function
- the declaration must be initialized
- the compiler will deduce the type from the initializer

CTAD makes many declarations simpler
*/

// #############
// ###  typename
// #############


/*
originally, the class keyword had to be used for a template parameter
template<class T>
...


the typename keyword was added in C++98
template<typename T>
...

The "class" keyword was felt to be confusing as templates instantiated
for built-in types as well as classes

However, many programmers still use "class" for template parameters

*/
