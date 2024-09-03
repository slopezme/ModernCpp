//############
// What is an algortihm?
//############

/*
- An alogirthm is a set of steps uset to solve a problem, similar to a recipe in cooking.
- In computing, this often refers to techniques which are used to search or sort data
    - it can also mean a technique to solve a specific problem

- The C++ STL defines a number of function in <algorithm> 
- These implement classic algorithms as well as a number of other useful routines
*/

//############
// Why use algorithms?
//############

/*
- Wide range of useful features (over 100 algorithms functions)
- shorter, clearer code - avoid explicit loops
- highly flexible - programmer can customize the functionality
- Code reuse
    - Coded and tested as part of the standard library
    - More accurate and more effcient ( can use internal compilear features)
    - Saves development time
*/

//############
// Generic Algorithms
//############

/*
- std::string has a find() member function
- fhis can perform searching, but only on string objects
- the STL algorithms are global functions which will work with any kind of STL container
    - The container elements can also have any type
- These are known as "generic algorithms"
*/

//############
// Typical Algorithm
//############

/*
- Tipically, an STL algorithm is passed an iterator range
- These specify which elements in the container will be processed by the algorithm
    - Often begin() and end(), to process the entiere container
- The algortihm will iterate over this range of elements and call a function on each element

- The algorithm will return either
    - An iterator representing a particular element
    - A value containing the result of some operation on the elements


*/

//############
// Searching with an Algorithm
//############

/*
- string::find() member function returns an index
- std::find() returns an iterator
    - some containers do not have the concept of an index
- it the character is not found, the algorithm will return the iterator for the 
"one after last" element

string str("Hello world");

auto res = find(str.begin(), str.end(), 'w');           // search for 'w'

-// Check if we found it
if (res != str.end())
    cout << "Match at index: " << distance(cbegin(str), res) << endl;  // Access the result
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string str{"Hello world"};
    cout << "String: ";

    for (auto c : str)
        cout << c << ", ";
    cout << endl; 


    auto res = find(cbegin(str), cend(str), 'l');           // search for 'l'

    //Check if we found it

    if (res != cend(str))
        // Access the result
        cout << "Found a matching element at index: " << res - str.cbegin() << endl;
}


//############
// pseudo-code for std::find()
//############

/*
Accepts any container with elements of any type
Iter = type of container's iterator, Elem = type of container elements

iter find(iter begin, iter end, Elem target){   // Loop over range, stopping before "end"
    for (iter it = begin; it != end; ++it)      // Is this the value we are looking for?
        if (*it == target)                      // It is - stop looping and return the caller
            return it;

- We have reached the end of the loop without finding the target
return end;
}
*/