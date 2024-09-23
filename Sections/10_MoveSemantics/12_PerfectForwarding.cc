/*####################
#Forwarding
####################*/

/*
- A function that passes some or all of tis argument to another function is to "forward" them

void f(Test x) {
    g(x);       // f() forwards the argument x to g()
}

- With "perfect forwarding", the properties of the passed object(s) are preserved
    - If x is modifiable in f(), it is modifiable in g()
    - if x is unmodifiable in f(), it is unmodifiable in g()
    - If x was moved into f()'s argument, it will be moved into g()'s argument
*/

/*####################
# Applications of Perfect Forwarding
####################*/

/*
- Perfect forwarding is used to write functions which call constructors
    -e.g. make_pair()

- If a passed object is an rvalue, the more efficient move constructor will automatically be called
- perfect forwarding is also used by variadic templates to dispatch their arguments to functions
which process them
    - Retains the information wheter the passed object was an lvalue or an rvalue

*/

/*####################
# Forwarding Functions
####################*/

/*
We have threee overloads of g()

    void g(Test& x);                            // x is modifiable in g()
    void g(const Test& x);                      // x is unmodifiable in g()
    void g(Test&& x);                           // x is moved into g()

and three overloads of f() whoch forward to them

    void f(Test& x) { g(x); }                   // x is modifiable in f()
    void f(const Test& x) { g(x); }             // x is unmodifiable in f()
    void f(Test&& x) { g(std::move(x)); }       // x is moved into f()'s argument

Can we write f() as a template function with a forwarding reference?
*/

#include <iostream>

using namespace std;

class Test {};

void g(Test& x) {
    cout << "Modifiable version of g called" << endl;
}

void g(const Test& x) {
    cout << "Immutable version of g called" << endl;
}

void g(Test&& x) {
    cout << "Move version of g called" << endl;
}

template <class T>
void f(T&& x) {
    g(x);
}

/*####################
# move() problem
####################*/

/*
- the rvalue version of f() does not call the rvalue version of g()
    - it calls the lavlue version of g()
- The problem is that inside f(), x is an lvalue

    void f(Test&& x) {          // rvalue instantiation of f()
                                -// x had a name and an address - it is an lvalue
        g(x);                   // lvalue argument - calls g(Test&);
    }

- To call the move version of g(), we need to convert it to an rvalue

    void f(Test&& x) {              // rvalue instantiation of f()
           g(std::move(x));         // rvalue argument - calls g(Test&&);
     }
*/

template <class T>
void f2(T&& x) {
    g(std::move(x));
}

/*####################
# Conditional std::move() needed
####################*/

/*
- However, std::move() always casts its argument to an rvalue

    void f(Test&& x) {              // lvalue instantiation of f()
        g(std::move(x));            // rvalue argument - calls g(Test&&);
    }

- The move is also called when x is an lvalue reference!
- We need some way to avoid performing the cast in this case

*/

/*####################
# std::forward()
####################*/

/*
- std::forward() casts its argument to rvalue reference
    std::forward<T>(x);             // Equivalent to static_cast<T&&>(x)

- Reference collapising provides the desired behaviour
    - If x is of type T&, it will be left as an lvalue reference to T
    - if x is of type T or T&&, it will be cast to an rvalue reference to T

- std::forward() does not cast its argument if it is an lvalue reference
- NB std::forward<T> requires a parameter, while std::move does not
*/

template <class T>
void f3(T&& x) {
    g(std::forward<T>(x));
}

int main(){
    Test x;
    const Test cx;

    cout << " Calling f() with lvalue argument \n";
    f(x);
    cout << " Calling f() with const lvalue argument \n";
    f(cx);
    cout << " Calling f() with rvalue argument \n";
    f(std::move(x));

    cout << " Calling f2() with lvalue argument \n";
    f2(x);
    cout << " Calling f2() with const lvalue argument \n";
    f2(cx);
    cout << " Calling f2() with rvalue argument \n";
    f2(std::move(x));

    cout << " Calling f3() with lvalue argument \n";
    f3(x);
    cout << " Calling f3() with const lvalue argument \n";
    f3(cx);
    cout << " Calling f3() with rvalue argument \n";
    f3(std::move(x));


}
