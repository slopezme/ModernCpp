//############
// Less than operator Summary
//############

/*
Prototype
    bool operator <(const T& lhs, const T& rhs);
How to invoke it
    a < b;
Called as
    operator <(a, b);
Returns true if lhs is less than rhs, false otherwise
*/

//############
// Stanrd Library and < Operator
//############

/*
- The Standard Library uses the < operator for sorting and ordering
    - If we try to sort a container, and its elements do not implement the < operator,
     the code will not compile
    - Same problem when inserting elements into a sorted container

*/

//############
// logical Operations using the < Operator
//############

/*
The < operator is sufficient to perform all comparison operations
- a == b
    !(a < b) && !(b < a)
- a >= b
    !(a < b)
- a > b
    !(a < b) && !(b == a)
- etc.

*/

//############
// Constraints on Less Than Operator
//############

/*
The result of using the <  operator should be consistent with the equlity operators
- If a < b is true, then a == b is false and a != b is true
- If a < b is true, then a < b is false and b < a is false

*/

//############
// Sorting a vector
//############

/*
- C++ defines a sort() function in <algorithm> that sorts a container
- This sorts the elements in an iterator range
- To sort all the elements of a vector, we pass the return values from begin() and end()

    sort(begin(names), end(names));     // Sort all elements of names

- This will sort the elements in ascending order
    - The < operator of the elements will be used to determine the order
    - If the elements are std::string, the elements will be sorted in alphabetical order

*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    vector<string> names {"Dilbert", "PHB", "Alice", "Wally", "Dogbert", "Catbert"};

    cout << "vector before sort: " << endl;
    for (const auto& name : names) {
        cout << name << ", ";
    }
    cout << endl << endl;

    sort(begin(names), end(names));
    for (const auto& name : names) {
        cout << name << ", ";
    }
    cout << endl << endl;


}


//############
// Adding Less than operator to student class
//############

/*
We have to decide what it means for one student object to be " less than" another

- Comparing the names

bool operator <(const Student& lhs, const Student& rhs) {
    return lhs.name < rhs.name;         // Order by name (alphabetical sort)
}

- Comparing the IDs

bool operator <(const Student& lhs, const Student& rhs) {
    return lhs.id < rhs.id;         // Order by ID
}

*/