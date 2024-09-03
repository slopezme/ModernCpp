

//############
// initializations from temporary variable
//############

/*
Consider the following code:

int x{7};
int y{x};


compilers can easily optmize this to

int y{7};    // Initialize y directly wihout creating variable x
*/


//############
// initializations from temporary object
//############

/*
string temp{"Initializer"};
string perm{temp};

Can be optimized to
string perm{"Initializer"};

Before 
- Call to string's constructor when creating temp
- call to string's copy constructor when creating perm
- Call to string's destructor when destroying temp

After
- Call to string's constructor when creating perm
*/

//############
// Copy Elision
//############

/*
copy elision means that the compiler is allowed to skip over a call to the copy constructor in some cases

this usually occurs when copying temporary variables during function calls

This applies even if the copy constructor has

Modern compilers will almost apply copy elision if they can
- most compilers supply an option to siable it -fno-elide-constructors
- however, for visual C++ it requieres diabling all optimizations /Od
*/

#include <iostream>

using namespace std;

class Test{
    public:
    Test() {cout << "Constructor called" << endl;}
    Test(const Test& other) {cout << "Copy Constructor called" << endl;}
};

Test func() {
    return Test();
}   

void main1() {
    cout << "Calling func" << endl;
    Test test = func();
    cout << " Returned from func" << endl;  
}

//############
// Explanation of behaviour of func()
//############

/*
- The reason is that copy elision hast taken place, twice
- The copy of the temporary object into the function's return space has been elided
    - This is known as "Return Value Optimization" (RVO)
- The copy initialization of the variable test has been elided
*/

//############
// Return Value Optimization (RVO)
//############

/*
Return value optmiization is when the copy of a returned temporary object is elided
- return Test();

Without elision
- Create a temporary object, copy it into the return space and destroy the temporary object

With elision
- Create the temporary object directly in the return space
- Avoids one call to copy constructor and one call to destructor

*/

//############
// initialization elision
//############

/*
Similarly, copy elision took place when the varaible was created

Test test = func();             // returned Test object copied into variable test

without elision
- Call the copy contructor with the temporary object as the argument, initialize 
the variable and destroy the temporary object

With elision
- Create the object directly in the variable's memory space
- Avoids one call to copy constructor and one call to destructor
*/

//############
// Named Return Value Optimization (NRVO)
//############

/*
A similar process occurs when a local varaible is returned by value

Test func2() {
    Test test;
    return test;
}

This is know as "Named Return Value Optimization" (NRVO)
- harder for compilers to do than for temporaries
- may not be done in all cases
*/

Test func2() {
    Test test;
    return test;
}   

void main2() {
    cout << "Calling func" << endl;
    Test test = func2();
    cout << " Returned from func" << endl;  
}


//############
// Other cases of copy elision
//############

/*
Copy elision can also occur when a temporary object is passed by value
func3(Test test) {
    test.print();
}

-// Call function with temporary object as argument
func3(Test());

*/

int main() {
    cout << "main1" << endl;
    main1();

    cout << "\n main2" << endl;
    main2();
    return 0;
}