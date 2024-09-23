/*####################
#  Function Arguments and Move Semantics
####################*/

/*
Pass by value
    - Copy constructor is called
    - Functions has its own copy of the caller's object
    - Caller's object is unmodified

Pass by const reference
    - Function has read-only access to the caller's object
    - Caller's object is unmodified

Pass by non-const reference and pass by address
    - Function has full access to caller's object
    - Caller's object can be modified

Pass by move
    - Move constructor called
    - Function now owns the caller object's data
    - caller's object is unusable (until re-assigned)
*/

/*####################
#  Older C++ Advice
####################*/

/*
When passing an object to a function which will not modify it, the most efficient way is to:
    - pass built-in types and small object by value
    - pass larger objects by const reference

- Does this still apply in C++11?
*/

/*####################
#  Consructor Argument
####################*/

/*
- We want to initialize the std::string member of this class using both lvalues and rvalues
- What is the most efficient way to do this?

    class Test {
        string m_str;
    public:
        Test(/*???* /) {...}        // Takes a string argument which initilizes the str member
        ...                         // Other member functions
    };
*/

/*####################
# pass by const reference
####################*/

/*
- The argument is bound to the passed object
- The argumetn is copied into the data member

    Test::Test(const string& str) : m_str{str} {}

    string name;
    Test ltest{name};       // lvalue passed - str binds to name
                            -// str is copied into m_str

    Test rtest{std::move(name)};    // rvalue passed - str binds to temporary
                                    -// str is copied into m_str


*/

#include <iostream>
#include <string>

using namespace std;

class Test {
    string m_str;
public:
    Test(string str) : m_str{std::move(str)} {}
};

/*####################
# pass by Rvalue reference
####################*/

/*
- Lvalues cannot be bound to an rvalue reference
- Rvalues are passed by move
    - The passed object is moved into str

    Test::Test(string&& str) : m_str{std::move(str)} {}

    string name;
    Test ltest{name};               // lvalue passed - name is copied into str
                                    // str is copied into m_str

    Test rtest{std::move(name)};    // rvalue passed - name is moved into str


*/

/*####################
# Relative Costs
####################*/

/*
pass by const reference
    - Lvalue object passed - 1 copy
    - Rvalue object passed - 1 copy

Pass by value / pass by move
    - Lvalue object passed - 2 copies
    - Rvalue object passed - 1 move + 1 copy

Pass by value the move
    - Lvalue object passed - 1 copy + 1 move
    - Rvalue object passed - 2 moves

Pass by rvalue reference
    - Lvalue object passed - not allowed
    - Rvalue object passed - 1 move

*/

/*####################
# Constructor Argument
####################*/

/*
- The most efficient way to write the cosntructors for this class is to:
    - pas lvalue by const reference
    - Pass rvalue by rvalue reference

    class Test {
        string m_str;
    public:
        Test(const string& str) : m_str{str} {}                 // Called when lvalue passed
        Test(string&& str) : m_str{std::move(str)} {}           // Called when rvalue passed
    };

- However,  this requieres writing two identical functions
    
*/

int main() {
    string name;
    Test ltest{name};               // lvalue passed - name is copied into str
                                    // str is copied into m_str
    Test rtest{std::move(name)};    // rvalue passed - name is moved into str
                                    // str is moved into m_str
}