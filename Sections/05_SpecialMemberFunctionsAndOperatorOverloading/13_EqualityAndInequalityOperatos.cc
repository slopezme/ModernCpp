//############
// Equality Operator Summary
//############

/*
- Prototype
    bool operator ==(const T& lhs, const T& rhs);
- How to invoke it
    a == b;
- Called as
    operator ==(a, b);
- Returns true if the two objects are equal, false otherwise

*/

//############
// Inequality Operator Summary
//############

/*
Prototype
    bool operator !=(const T& lhs, const T& rhs);
How to invoke it
    a != b;
Called as
    operator !=(a, b);
Returns true if the two objects are not equal, false otherwise

*/

//############
// Equality and Inequality Operators
//############

/*
- If a class defines one of these operators, it should also define the other one
- This is easy to do, as they are the inverse of each other

bool operator !=(const T& lhs, const T& rhs) {
    return !(lhs == rhs);      //Call equality operator and invert the result
}
*/

//############
// Student Class
//############

/*
- We will use a basic student class to illustrate these operators

class student {
    string name;        // Student name not necessarily unique
    int id;             // Student ID, unique to each student
    ...
    };
*/

//student.h


//student.cc