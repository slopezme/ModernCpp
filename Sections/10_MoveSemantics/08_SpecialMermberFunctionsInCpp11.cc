/*####################
#  Move Operators
####################*/

/*
- C++11 has two new especial member functions
    - Move constructor
    - Move assignment operator
        - Optimized version of copy constructor and assignment operator
        - They move their argument instead of copying it
        - Automatically called when the argument is a moveable rvalue
*/

/*####################
#  Synthesized move operators
####################*/

/*
- The compiler will only synthesize a move operator if
    - The class does not define a copy constructor, assignment operator or destructor
    - Every data member of the class is either
        - Built-in type
        - user-defined type with move operators
        - Static data member (not moved)

- The synthesized move constructor will call the move constructor for each member
- The synthesized move assignment operator will cal the move assignment operator for 
each member

 */

/*####################
#  Synthesized copy operator in C++11
####################*/

/*
- if a class defines a move operator, both the copy operators will be synthesized as "deleted"
- The class should define its own copy operators if it needs them
- Otherwise, the class will be move-only
*/

/*####################
#  Rule of Five
####################*/

/*
- In C++11, the rule of Three becomes the "Rule of Five"
- If a class needs to implement a destructor to function correctly, then it probably need to implement
the copy and move operators as well

- e.g. a class which allocates memory with "new" in its constructor
    - Destructor to call "delete" when objects are destroyed
    - Copy constructor to perform a deep copy when copying
    - Assignment operator to perform a deep copy on assignment
    - move operator to set the arguments pointer to nullptr

*/

#include <iostream>

class Test {
    public:
    // Default constructor
    Test() = default;
    
    //In effect, the copy operators are declared as deleted
 

   // Copy Constructor
   Test(const Test&other) = delete;

   // Copy assignment operator
    Test& operator=(const Test& other) = delete;
    

   // Move constructor
    Test(Test&& other) noexcept {
         std::cout << "Move constructor called" << std::endl;
    }

    // Move assignment operator
    Test& operator=(Test&& other) noexcept {
        std::cout << "Move assignment operator called" << std::endl;
        return *this;
    }

};

int main() {
    Test test;                          // OK - uses default constructor
    Test test2{std::move(test)};        // OK - uses move constructor
    test2 = std::move(test);            // OK - uses move assignment operator
    //Test test4(test);                 // Error - copy constructor is deleted
}