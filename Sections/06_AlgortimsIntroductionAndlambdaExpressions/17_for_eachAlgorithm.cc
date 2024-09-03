//############
// for_each()
//############

/*
- for_each()  calls a function on every element in an iterator range

    - // Print each character in str on a separate line
    string str{"A test string"};
    for_each(cbegin(str), cend(str), [](const char c) { cout << c << ", "; });

- The ssame code can be written more simply using a range-for loop
    
    -// Range for loop
    for(auto c : str)
        cout << c << ", ";
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void for_eachExample() {
    string str{"A test string"};

    cout << "\nPrinting each character in a string using for_each():" << endl;
    for_each(cbegin(str), cend(str), [](const char c) { cout << c << ", "; });
    cout << endl << endl;

    cout << "Printing each character in a string using range-for loop:" << endl;
    for (auto c : str)
        cout << c << ", ";
    cout << endl << endl;
}

//############
// for_each() and Modification
//############

/*'
- The element can be passed by reference to the function
- This allows us to change the elemtns

for each(begin(vec), end(vec), [](char &c) { c = toupper(c); });

- Again, this can be written more simply as a range for loop

    for (auto &c : vec)
        c = toupper(c);

*/

 void for_eachModificationExample() {
    // Print each character in str on a separate line
    string str{"A test string"};

    cout << " str: " << str << endl;
    cout << "Printing each character in a string using for_each():" << endl;

    // Convert each character to uppercase
    for_each(begin(str), end(str), [](char &c) { c = toupper(c); });

    cout << " str: " << str << endl;
    cout << endl;

 }

//############
// for_each() vs Loops
//############

/*
- range for loop were introduced in C++11
- Before the, for_each() was a convenient way of applying a function to the elements of a container
- now, it is usually better to write a range-for loop
    - Clearer code than for_each()
    - opportunity to terminate the loop with a break or return statement
*/

//############
// Applications of for_each()
//############

/*
- However, for_each() is still useful
- Can be applied to a sub-range of elements
- Single path through code makes it easier to optmize
- Useful stop-gap when implementations are lacking
    - visual C++ did not support range-for loops until 2015
    - Many C++17 parallel algorithms are not implemented yet
*/


int main() {    
    cout << "\nfor_each() Algorithm" << endl;
    for_eachExample();
    cout << "\nfor_each() and Modification" << endl;
    for_eachModificationExample();

    return 0;
}