/*####################
# Nested References #
####################*/

/*
- Programmers cannot directly create a nested reference

int && x = y;       // Error: cannot bind an rvalue reference to an lvalue

- However, the compile can do this internally for a type alias or a template parameter

    using int_ref = int&;       // or typedef int& int_ref;

    int i{42};
    int_ref j{i};               // j is a reference to i
    int_ref& rj{j};             // rj is a reference to (reference to int)

- the type of the result is determined by "reference collapsing rules"
- The reference to (reference to int) "collapses" into reference to int

*/

#include <iostream>

using namespace std;

void func(int& x){
    cout << "function called with argument int& " << endl;
}

void example(){
    int i{42};
    // int& & ri = i;      // Error: cannot create a nested reference

    using int_ref = int&;   // or typedef int& int_ref;

    int_ref j{i};           // j is a reference to i
    int_ref& rj{j};         // rj is a reference to (reference to int)

    func(rj);               // func called with argument int&
}


/*####################
# Reference Collapsing Rules
####################*/

/*
- rvalue references can also appear in nested references
- The result is an rvalue reference only if they are both rvalue references

    using lvalue_ref = int&;
    using rvalue_ref = int&&;

lvalue_ref&  => int&
lvalue_ref&& => int&
rvalue_ref&  => int&
rvalue_ref&& => int&&
*/

/*####################
# &&  Argument Parameters
####################*/

/*
So far, the && argument has always been a specific type

    func(Test&& x);        

    -The type of the parameter x is rvalue reference to Test
    - It can only be bound to an rvalue (xvalue or prvalue)

*/

/*####################
# &&  Template Argument Parameters
####################*/

/*
&& has completely different effects if the argument is generic
    template<typename T>
    func(T&& x);

    - x is now a "forwarding" reference
    - It can be bound to an rvalue or lvalue

- When the compiler instantiates this function, how does it deduce the argument type?
    
*/

/*####################
# Template Argument Deduction
####################*/

/*
- When deducing the argument type for a forwarding reference, the compiler first examines
the value catefory

    template<typename T>
    func(T&& x);

- If an lvalue is passed to func(), T is deduced as lvalue reference to Test

    - Reference collapsing is then applied
    - T is Test& and x is T&& => Test& 

- If an rvalue is passed to func(), the original type is deduced for T

    - T is Test and x is T&& => Test&&
*/

class Test {};

template <class T>
void func(T&& x){
    cout << "Called with argument " << endl;
}

void example2(){
    Test t;
    Test& rt{t};

    // T is Test& and x is T&& => Test&
    func(t);                // Compiler instantiates func(Test& x)

    // T is Test& and x is T&& => Test&
    func(rt);               // Compiler instantiates func(Test& x)

    // T is Test and x is T&& => Test&&
    func(std::move(t));     // Compiler instantiates func(Test&& x)
}

/*####################
# Why Are Forwaring Reference useful?
####################*/

/*
- We found that the most efficient way to implement a constructor is to write two separate functions

    Test(const Test& obj);
    Test(Test&& obj);           // Apart from the argument type, these are identical

- Now if we have many parameters, or even a variable number ...
- With forwaring references, we only need to write the function once

    func(T&&);                  // The compiler will instantiate overloads as needed
*/

int main(){
    example();

    cout << "Template Argument deduction example" << endl;
    example2();
    return 0;
}