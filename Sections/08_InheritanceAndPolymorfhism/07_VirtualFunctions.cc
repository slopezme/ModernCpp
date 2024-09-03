//###########
//# Static Binding
//###########

/*
- Normally when we call a member function of an object, the compiler will
decide which functions is called

- this is done using the static type of the object
- the decision is made at compile time

    Circle circle;                  // Derived class object
    Shape &rshape = circle;          // Reference to a base class, bound to a Circle object
    rhsape.draw();                   // Calls draw() on a Shape. Prints out "Drawing a shape"

This is known as "static binding" 
*/

//###########
//# Dynamic Binding
//###########

/*
- however, there are some cases where the compiler does not make the decision
- instead, it generates some code which is used to make the decision
- The program will use this code to decide, at run time, which function to call
- it will use the dyunamic type of the object
- this is known as "dynamic binding"

*/

//###########
//# Dynamic Binding Requirements
//###########

/*
Two conditions must apply for dyanmic binding to occur:
    - A member functions is called through a pointer or reference to a base class
    - The member functions was declared as "virtual" in the base class
*/

//###########
//# the Virtual Keyword
//###########

/*
To make a member function virtual, we put the virtual keyword before its declaration in the base class
    virtual void draw();        // Declare the member functions as virtual in the base class

- this virtual member function will be inherited in al sub classes
    - We do not need to write "virtual" again

- A child class which reimplments a virtual member function is said to "override" the function


*/

//###########
//# Vritual member function call
//###########

/*
class Shape{
    public:
        virtual void draw() const;              // Base class defines virtual draw() member function
        ...
};

class Circle : public Shape {
    public:
        void draw() const;                      // Derived class overrides draw() member function
        ...
};

Circle circle;
Shape &rshape = circle;                          // Reference to a base class, bound to a Circle object
rshape.draw();                                   // Calls draw() on a Circle. Prints out "Drawing a circle"


*/

//###########
//# Function Call Argument
//###########

/*
- Virtual functions solve the problem with function call arguments
- We pass a reference for the dynamic type of the object will be called
    -// The static type of d is reference to const Shape
    -// The dynamic type of d is reference to const {some class in Shape hierarchy}

    void drawShape(const Shape &d) {
        d.draw();                               // Calls draw() on the dynamic type of d
    }



*/

#include <iostream>

using namespace std;

class Shape {
    public:
        virtual void draw() const {
            cout << "Drawing a generic shape" << endl;
        }
};

class Circle : public Shape {
    public:
        void draw() const {
            cout << "Drawing a circle" << endl;
        }
};

void drawShape(const Shape &s) {                // Argument is a reference to a Shape
    s.draw();                                   // Calls draw member function of Circle etc
}

int main() {
    Circle circle;
    drawShape(circle);
}