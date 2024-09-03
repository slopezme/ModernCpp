//############
// library Function Objects
//############

/*
- The C++ library provides some functions objects
- these are generic operators for arithmetic, logical and relational operations
- They are implemented as templated functors
*/

//############
// less - than operator
//############

/*
- // Pseudo - code for less - than operator
template <typename T>
class less{
    public:
        bool operator()(T arg1, T arg2) {
            return arg1 < arg2;
        }
};

- // use less-than operator as predicate for std::sort()

vector<string> names = {"John", "Paul", "George", "Ringo"};
sort(begin(names), end(names), less<string>());             // pass an object of the functor
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    vector<string> names = {"John", "Paul", "George", "Ringo" , "John" , "Paul" , "George" , "Ringo"};
    vector<string> names2{names};

    cout << endl << endl;
    cout << "Before sorting: " << endl;
    for (const auto& name : names) {
        cout << name << " ";
    }
    cout << endl << endl;

    // Sort by default  - Ascending order
    sort(begin(names2), end(names2));             // pass an object of the functor

    cout << "After sorting by default: " << endl;
    for (const auto& name : names2) {
        cout << name << " ";
    }
    cout << endl << endl;

    // sort the names in ascending order - Alphabetical order
    sort(begin(names), end(names), less<string>());             // pass an object of the functor

    cout << "After sorting with less than functor " << endl;
    for (const auto& name : names) {
        cout << name << " ";
    }
    cout << endl << endl;

    // Sort the names in descending order - Reverse alphabetical order

    sort(begin(names), end(names), greater<string>());             // pass an object of the functor

    cout << "After sorting in descending order: " << endl;
    for (const auto& name : names) {
        cout << name << " ";
    }
    cout << endl << endl;

    return 0;
}



//############
// Arithmetic operators
//############

/*
- std::plus             x + y
- std::minus            x - y
- std::multiplies       x * y
- std::divides          x / y
- std::modulus          x % y
- std::negate           -x
*/

//############
// Relational operators
//############

/*
- std::equal_to         x == y
- std::not_equal_to     x != y
- std::greater          x > y
- std::greater_equal    x >= y
- std::less             x < y
- std::less_equal       x <= y
*/

//############
// logical and Bitwise Operators
//############

/*
- std::logical_and      x && y
- std::logical_or       x || y
- std::logical_not      !x

- std::bit_and          x & y
- std::bit_or           x | y
- std::bit_xor          x ^ y
- std::bit_not          ~x   (C++14)

*/