/*####################
#  When to Write Special Member Functions
####################*/

/*
The complete set of rules for the interaction between used - declared
 and compiler- declared is rather complex ( Howeard Hinnant, 2012)

*/

/*####################
#  Rule of Zero
####################*/

/*
- If a class does not need to delcare a destructor, it does not need to declare a copy or move operators either
- For most classes, the "Rule of Zero" is sufficient
    - Do not delcare any special member functions
    - The compiler- syntehsized defaults will be sufficient

- The compiler will also synthesize a defail constructor
    - unless we declare one ourselves
    - Sometimes useful to declare a default constructor which initializes the
    members with sensible values
*/

/*####################
#  Rule of Three / Five
####################*/

/*
- If we need a destructor, e.g to release memory, the compiler - generated copy operators will not be correct
- In this case, we need to provide our own
    - Destructor
    - Copy constructor
    - Copy assignment operator

- We will probably need to provide a constructor as well, e.g. to allocate memory
- For performance, we should also add move operators
    - Otherwise the copy operators will be used
*/

/*####################
#  Move-only Class
####################*/

/*
- Sometimes we need to delcare a destructor, but we do not want to copy the object
    - e.g. a class which manages a network connection
    - We do not want to create a duplicate of the connection
- In this case, make the class move - only


To make a class move-only, provide our own
    - Destructor
    - Move constructor
    - Move assignment operator

- We will probably need to provide a constructor as well, e.g. to open the connection
    - It may be useful to declare a default constructor which initializes an unconneted object

- The compiler will synthesize the copy operators as deleted
    - For clarity, we can explicity delcare the copy operators as = delete

*/

/*####################
#  immoveable Class
####################*/

/*
- We can make an class which is immoveable and uncopyable
    - Objects of this class cannot be passed to a function
    - Objects of this class cannot be returned by a function
    - e.g low-level concurrency objects which release a lock at the end of their scope

- To do this, delete the copy operators
    - The compiller will not synthesize the move operators
    - Any copy or move operation will invoke the copy operators, whoch are deleted


*/

#include <iostream>

using namespace std;

class Test {
    public:
    // Default constructor
    Test() = default;
    
    //The copy operators are delcared as deleted
   // Copy Constructor
   Test(const Test&other) = delete;

   // Copy assignment operator
    Test& operator=(const Test& other) = delete;
    
    /*
    // The compiler does not generate any move operators
    */

};

void moveOnlyExample(){
    Test test;                              // OK - uses default constructor 
    //Test test2(std::move(test));         // Error - copy constructor is deleted
    //Test test3(test);                       // Error - copy constructor is deleted
}

/*####################
#  Copy-only Class
####################*/

/*
- We can make a class which can be copied, but not moved
- To do this, we delcare the move operators as deleted

    Test(Test&& other) noexcept = delete;           // Move constructor
    Test& operator=(Test&& other) noexcept = delete; // Move assignment operator

- Even though an operator is deleted, the compiler can still choose it as the best match
- This can have surprising results
    Test test;                  // OK - uses default constructor
    Test test2(std::move(test)); // Does not fall back to copy operator

- For this reason, copy-only classes are not recommended

*/

class Test2 {
    public:
    // Default constructor
    Test2() = default;
    
    // copy constructor
    Test2(const Test2& other) {
        cout << "Copy constructor called" << endl;
    }

    // copy assignment operator
    Test2& operator=(const Test2& other) {
        cout << "Copy assignment operator called" << endl;
        return *this;
    }

    // The move operator are declared as deleted
    Test2(Test2&& other) noexcept = delete;           // Move constructor

    // Move assignment operator
    Test2& operator=(Test2&& other) noexcept = delete; // Move assignment operator

};

void copyOnlyExample(){
    Test2 test;                              // OK - uses default constructor 
    //Test2 test2(std::move(test));         // Error - move constructor is deleted
    Test2 test3(test);                       // OK - uses copy constructor
}

int main() {
    cout << "Move-only example" << endl;
    moveOnlyExample();

    cout << "\nCopy-only example" << endl;
    copyOnlyExample();
    return 0;
}
