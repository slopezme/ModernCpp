/*####################
#  Rvalue references and overloading
####################*/

/*
- We can overload a function so that it behaves differently 
depending on wheter its argument is moved

    void func(const myclass& obj);      // Called when we pass an lvalue
    void func(myclass&& obj);            // Called when we pass an rvalue

- Two of the mos useful functions to overload this way are the copy constructor
and assignment operator

    - These member functios typically copy all the member of the class. often
    they create a new copy of a resource
    - Moving instead of copying improves performance

*/

/*####################
#  move operators
####################*/

/*
- C++11 added new special member functions for this purpose   
        - Move constructor
        - Move assignment operator
- These are called automatically if the passed object is a moveable rvalue
- These are overloads of the copy constructor and assignment operator which 
take an rvalue reference

- The assignment operator now called the "copy assignment operator"
    - To avoid confusion with the move assignment operator

*/

/*####################
#  move operator syntax
####################*/

/*
    Test(const Test& arg);                      // Copy constructor
    Test(Test&& arg);                           // Move constructor

    Test& operator=(const Test& arg);           // Copy assignment operator
    Test& operator=(Test&& arg) noexcept;       // Move assignment operator

- The move operator argument cannot be const (it will be moved from)
- The move operator should not throw exceptions
    - No simple way to recover from a part-completed move
    - STL containers will only call an element's move operator if it is noexcept

- The move assignment operator returns the assgined-to object by lvalue reference


*/


/*####################
#  move operator Implementation
####################*/

/*
We will add move operator to this class

class Test{
    private:
        int i{0};           // Built-in member
        MyClass m;          // Class Member

    public:
        Test() = default;   // Default constructor

        
};

For built-in types, we just copy them
For class members, we call the corresponding move operator

*/

#include <iostream>

using namespace std;

class MyClass {};

// Class with move constructor

class Test{
    private:
        int i{0};           // Built-in member
        MyClass m;
    
    public:
        Test() = default;   // Default constructor

        // Copy constructor
        Test(const Test& arg) : i{arg.i}, m{arg.m} {
            cout << "Copy constructor called" << endl;
        }

        // Move constructor
        Test(Test&& arg) noexcept : i{arg.i}, m{move(arg.m)} {
            cout << "Move constructor called" << endl;
        }

        // Copy assignment operator
        Test& operator=(const Test& arg) {
            cout << "Copy assignment operator called" << endl;
            if (this != &arg) {
                i = arg.i;
                m = arg.m;
            }
            return *this;
        }

        // Move assignment operator
        Test& operator=(Test&& arg) noexcept {
            cout << "Move assignment operator called" << endl;
            if (this != &arg) {
                i = arg.i;
                m = move(arg.m);
            }
            return *this;
        }
};


/*####################
#  move operator for devied classes
####################*/

/*
- When writing a move operator for a derived class, we should call the corresponding
operator for the base class

- To do this, we must pass the argument as an rvalue

    - // Copy Constructor
        Derived(const Derived& arg) : Base(arg) {...}

    - // Move Constructor
        Derived(Derived&& arg) : Base(move(arg)) {...}
            
*/

/*####################
#  Compatibility with older versions of C++
####################*/

/*
- Classes written before semantics will behave the same way when compiled 
with a Modern C++ compiler as they did before
- If we copy an rvalue object which does not have a move constructor, the copy
constructor will be called instead
- If we assign an rvalue object which does not have a move assignment operator,
the copy assignment operator will be called instead

*/

int main() {
    Test test;                      // Call default constructor
    cout << "Copying: ";       
    Test test2 = test;              // Call copy constructor
    cout << " \nMoving temporary: ";
    Test test3 = Test();            // Call move constructor by using a temporary object
    cout << " \nMoving rvalue reference: ";
    Test test4(std::move(test));    // Call move constructor by casting test to rvalue

    cout << endl;

    Test test5;                     // Call default constructor
    cout << "\nAssigning: ";
    test5 = test2;                  // Call copy assignment operator

    Test test6;                     
    cout << "\nAssigning from temporary: ";
    test6 = Test();                 // Call move assignment operator
}