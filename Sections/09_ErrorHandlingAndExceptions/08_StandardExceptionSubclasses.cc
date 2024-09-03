/*####################
# std::exception subclasses
####################*/

/*
- bad_alloc
    - thrown when a memory allocation fails
- bad_cast
    - thrown when a dynamic_cast fails
- logic_error
    - parent class for error conditions resulting from faulty logic
- runtime_error
    - parent class for error conditions beyond the programer's control
- out_of_range
    - attempting to access an element outside a defined range
    - e.g. vector.at()
- invalid_argument
    - The argument to a function is not acceptable
    - e.g.  passing a non-numeric argument to stoi()
- domain_error
    - The argument to a function is outside the domain of applicable values
    - e.g. invalid date field
- length_error
    - The length limit of an object has been exceeded
    - e.g. appending too many elements to a string
- overflow_error
    - The reuslt of a computation is too large for the result variable
- underflow_error
    - The result of a computation is too small for the result variable
- range_error
    - An internal computation gives a value which cannot be represented by the
     result variable

*/

/*####################
# C++ Standard Library and Exceptions
####################*/

/*
- Surprisingly, the standard library  makes little use of exception
- sqrt() doest not throw std::domain_error when given -1 as an argument
    -// Code that "should throw an std::domain_error 
    sqrt(-1);           -// Returns "nan" (not a number)

- Instead, it returns the value NaN (not a number)

*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    try {
        cout << sqrt(-1) << endl;
    }
    catch (const std::exception &e) {
        cout << "Standard exception: " << e.what() << endl;
    }


}