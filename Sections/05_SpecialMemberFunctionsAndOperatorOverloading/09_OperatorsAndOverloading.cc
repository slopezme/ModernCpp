//############
// operators for built in types
//############

/*
C++ defines operator for built-in types
- The + operator add two integers
- == compares two integers
*/

//############
// operators for standard library types
//############

/*
The C++ standard library defines operators for its types
- The + operator adds two strings
- == compares two strings
*/

//############
// unary and binary operators
//############

/*
- An operator which takes a signel argument is said to be unary
- An operator which takes two arguments is said to be binary

int a,b,c;

c = a + b;      // Binary operator
c = -a;         // Unary operator

The ir one ternary operator in C++

a ? b : c;      // Ternary operator
*/

//############
// Points to Note
//############

/*
- Operators take either one or two arguments
- Operator can be memeber functions or non-member functions
    - Unary operator are usually member functions
    - Binary operators are usually non-member functions

- A class in the standard library will usually have operator which act on objects of that class
     - The have the same syntaz as operator which act on built-in types
     - they behave siimilarly (" semantics")
*/

//############
// user Defined Operators
//############

/*
- When we write out own class, C++ does not provide operators for ir
- however, we can define operators if we wish
- Whis is called "overloading" the operator
    - We give a new meaning to an existing symbol
- We must use the same symbols as built-in operators
    - we are not allowed to invent new operators or new syntax
- These should have similar semantics to the built-in operators
*/

//############################
// Which Operator to Overload
//############################

//############
// useful Operator to Overload
//############

/*
the +,-,*,/ operators are only really useful for mathematical classes ( complex number, rational number)
- In general programming, the most useful operators are 
    - Assignment operator =
    - Equality operator ==
    - Inequality operator !=
    - Less than operator <
    - Function call operator ()
*/

//############
// operators which should not be overloaded
//############

/*
Logical AND and OR (&& and ||) 
- the built - in versions have a guaranteed order of execution
- the built - in versions have a guaranteed short-circuiting behaviour
- it is not possible to write user diened versions with the same behaviour

Addres of operator (&) and comma operator (,)
- Already defined for classes. Redeifning them would be confusing

Scope (::), .operator, .* operator and ternary operator (?:)
- C++ does not allow these to be overloaded
*/

//############
// Recommendations
//############

/*
- Think carefully before adding operators to a class
- Only provide operator which are needed or "add value" to the class
    - Does a database connector class need arithmetic operators?

- The return value should correspond to the C++ equivalent operator 
    - bool for logical and relational operators
    - the class type (by balue) for arithmetic operators
    - The left hand argument (by non const reference) for assignment operators

*/