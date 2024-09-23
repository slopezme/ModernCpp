/*####################
#  lvalues and rvalues
####################*/

/*
- An object can either be an lvalue or an rvalue
- Originally, an lvalue could appear on the left of an assignment
- An rvalue could only appear on the right

x = 2;          // x is an lvalue, 2 is an rvalue
x = func();     // x is an lvalue, return value from func() is an rvalue

- In C++, an lvalue represents a named memory location
    - It has a name
    - we can take itrs address using the & operator
    - x is an lvalue        // name is x, &x is valid

-Anything else is an rvalue
    - 2 is an rvalue            // 2 han no name, &2 is not legal
    - func() is an rvalue       // return value from function call has no name
                               -// &func() is not legal

- lvalues and rvalues can behave differently when passed as function arguments


*/

/*####################
#  pass by value
####################*/

/*
- lvalues can be passed by value

    void func(int);             // Function taking int by value

    int x = 2;                  // x is an lvalue
    func(x);                    // The value of x is copied into the function argument - OK

- rvalues can also be passed by value

    func(2);                    // The value 2 is copied into the function argument - OK


*/

/*####################
#  pass by address
####################*/

/*
- lvalues can be passed by address

    void func(int*);           // Function taking int by address

    int x = 2;                  // x is an lvalue
    func(&x);                   // x is passed by address -OK

- rvalues cannot be passed by address

    func(&2);                   // Error: 2 is an rvalue

*/

/*####################
#  pass by Reference
####################*/

/*
- lvalues can be passed by reference

    void func(int&);            // Function taking int by reference

    int x = 2;                  // x is an lvalue
    func(x);                    // x is passed by reference - OK

- rvalues cannot be passed by reference
    
    func(2);                    // Error: 2 is an rvalue

*/

/*####################
#  Passing rvalue by const reference
####################*/

/*
- pass by address and pass by non-const reference are used when the function wants
to modify the argument

- this makes no sense for rvalues, so it is not allowed

- Pass by const reference is used as more efficient way of passing large objects by value
- Passing rvalues by const reference is allowed

int get(){return 2;}            // Function returning an int

void func(const int&);          // Function taking int by const reference
func(get());                    // return value from get() is an rvalue
                                -// The rvalue is passed by const reference - OK

*/

#include <iostream>

using namespace std;

int get() { return 2; }

void func(const int& ri) {
    cout << ri << endl;
}


/*####################
#  pass by Move
####################*/

/*
- In older C++, an argument is always copied by default
    void func(Type obj);        // obj is a copy of the argument

- In C++11, the argument can be moved if
    - obj is an rvalue
    - and Type is "moveable"
    - True for all C++ library types (except for...)

- Obj will be copied if
    - obj is an lvalue
    - or Type is not "moveable" (includes built-in types)

- This provides compatibility with old code


*/

int main() {
    int x = 2;
    func(x);
    func(2);
    func(get());
    return 0;
}