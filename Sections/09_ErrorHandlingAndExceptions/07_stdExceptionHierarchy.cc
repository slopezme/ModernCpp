/*####################
# std::exception Hierarchy
####################*/

/*
C++ defines an std::exception class 
- This is the base class for an inheritance hierarchy
    - consistent interface for exception objects
    - Enables polymorphism - reduces the number of handlers needed


exception   
    - bad_alloc
    - logic_error
        - domain_error
        - invalid_argument
        - length_error
        - out_of_range
    - runtime_error
        - overflow_error
        - range_error
        - underflow_error
    - bad_cast

*/

/*####################
# Logic and Runtime Errors
####################*/

/*
- A logic error represents something that ins under the control of the programmer
    - e.g violating a precondtion
- A logic error could be prevented by the programmer
    - e.g. checking function arguments before processing them
- A runtime error represents something that is beyond the programmer's control
    - e.g. running out of memory

*/

/*####################
# std::exception Hierarchy Interface
####################*/

/*
- std::exception defines five public member functions
    - constructor
    - copy constructor
    - assignment operator
    - virtual member function what()
    - virtual destructor

- what() returns a C-style string
- what() cannot throw exceptions


*/

/*####################
# std::exception Hierarchy Constructor
####################*/

/*
- exception, bad_alloc and bad_cast have a default constructor
- The others do not have a defualt constructor, but have a constructor that takes a string
argument
    - This string can be either a C-style string or a std::string
    - It will be returned when what() is called
    - It should give information about the error condition


*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int at(const vector<int> &vec, int pos) {
    // Check index corresponds to a valid element
    // If not, throw an out_of_range exception with a suiatable error message

    if(vec.size() < pos + 1) {
        string str{" No element at index "s + to_string(pos)};
        throw std::out_of_range{str};
    }

    // Return the element
    return vec[pos];

}

int main(){
    vector<int> vec;
    //vector<int> vec{1, 2, 3};

    try {
        int el = at(vec,2);
        cout << "vec[2]: " << el << endl;
    }
    catch (const std::exception &e) {
        cout << "Standard exception: " << e.what() << endl;
    }

}

/*####################
# new subclasses in C++11
####################*/

/*
- exception
    - bad_alloc
        - bad_array_new_length
    - logic_error
        - future_error
    - runtime_error
        - system_error
            - ios_base::failure
    -bad_weak_ptr
    -bad_function_call

*/