/*####################
#  Move-only Class
####################*/

/*
- To make a move-only class, implement the move operators and make the copy operators
deleted

class Test{
    public:
        Test(const Test&) = delete;             // Deleted copy constructor
        Test& operator=(const Test&) = delete;  // Deleted copy assignment operator
        Test(Test&&) noexcept;                  // Move constructor
        Test& operator=(Test&&) noexcept;       // Move assignment operator
    ...
};

*/

/*####################
#  Move-only Types
####################*/

/*
- C++ has some types which cannot be copied, but can be moved
    - fsream, iostram
    - (Classes used in multithreading)
    - ("Smart pointers" class)

- These types follow the RAII idiom 
    - Only one object can own a given resource instance at a time
    - The object acquires ownership of the resource in the constructor
    - The object releases ownership of the resource in the destructor

- The ownership of the resource can be transferred from one object to another using
move semantics

*/

/*####################
#  fsream
####################*/

/*
- fstream has a file handle as a data member
- the fstream constructor opens the file
- the fstream destructor closes the file
- An fstream object cannot be copied, but it can be moved
    - The moved-from object no longer owns the file handle
    - It has a null file handle
    - the moved-to object becomes the owner of the file handle
    - The file will be closed when the moved-to object is destroyed
*/

/*####################
#  lambda capture and move-only objects
####################*/

/*
C++11 lambda expressions are not good capturing move-only objects

fstream.fs{"output.txt"};

-// Whant syntax do we use to capture fs?

[fs]                    // Capture by value - does not compile
[&fs]                   // Capture by reference - no transfer ownership
[???]                   // Capture by move - not supported in C++11

*/

/*####################
#  Capture by move
####################*/

/*
-C++14 has "generalized" lambda captures
- A variable in the outer scope can be moved into a lambda-local variable
    fstream fs{"output.txt"};
    [lfs = std::move(fs)]                // Now oned by lambda body's local variable lfs

-This allows capture by move
    - lfs is deduced as fstream
    - the move constructor is called to initialize lfs
    - lfs takes ownership of the file handle

- This was the 2nd most requested feature for C++14!


*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string>  strings(5);

    cout << "Capture by reference" << endl;
    [&strings]() {cout << "Size in lambda = " << strings.size() << endl; }();
    cout << "After callin lambda, size in main = " << strings.size() << endl;

    cout <<endl << "Capture by move" << endl;
    [vs = std::move(strings)]() {cout << "Size in lambda = " << vs.size() << endl; }();
    cout << "After calling lambda, size in main = " << strings.size() << endl << endl;


}
    