//############
// Predicates
//############

/*
- Many algorithms call a function on each element which returns bool
    - find() calls the == operator for each element to compare it to the value we are searching for
- This function is called a "predicate"
- These algorithms allow us to supply our own predicate
- We can pass a callable object as an optional extra argument to the algorithm call
*/

//############
// std::sort
//############

/*
- The sort algorithm works by comparing pairs of elements
- The comparison is done by calling the element's < operator on each pair of elements
- sort() moves the smallest elements to the front and the largest to the back of the container

    - (By a clever choice of which pairs to compare, the sort can be very efficient)
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
// Define a predicate function
bool is_shorter (const string &lhs, const string &rhs){
    return lhs.size() < rhs.size();
}

//Define a predicate as a functor
class IsShorter{
    public:
        // overloaded () operator
        // Takes two strings as arguments
        // Return true / false depending on relative string length
        bool operator() (const string &lhs, const string &rhs) const{
            return lhs.size() < rhs.size();
        }
};

int main(){
    vector<string> names{"Dilbert", "PHB", "Dogbert", "Asok", "Ted", "Alice", "Wally"};

    cout << "Vector before sort()\n";
    for (auto name : names)
        cout << name << ", ";

    cout << endl << endl;

    // Sort the data in alphabetical order
    sort(begin(names), end(names));
    cout << "Sorted alphabetically" << endl;
    for (auto name : names)
        cout << name << ", ";
    cout << endl << endl;

    // Sort the data, passing the function pointer as a predicate
    sort(begin(names), end(names), is_shorter);

    cout << endl << "Sorted by length" << endl;
    for (auto name : names)
        cout << name << ", ";
    cout << endl << endl;

    // Sort the data, passing the functor as a predicate
    sort(begin(names), end(names), IsShorter());

    cout << endl << "Sorted by length" << endl;
    for (auto name : names)
        cout << name << ", ";




}
