//###########
//# Static Type and Dynamic Type
//###########

/*
What is the type of pshape?

class Shape{}
class Circle : public Shape{}

Circle circle;
Shape* pshape = &circle;

- pshape is declared as a pointer to a Shape
- pshape is the address of a Circle object

C++ variables have two different types:
    - The static type is the type of the variable as declared
    - The dynamic type is the type of the object the variable points to

*/

//###########
//# Static Type 
//###########

/*
The static type is the type used in the varaible declaration

int x{5};                        // x has a static type of int
int* px = &x;                    // Static type pointer to int

Circle circle;                   // Static type Circle
Circle *pcircle = &circle;       // Static type pointer to Circle
Circle& pcircle = circle;        // Static type reference to Circle

Shape *pshape = &circle;         // Static type pointer to Shape
Shape& rshape = circle;          // Static type reference to Shape


*/

//###########
//# Dynamic Type 
//###########

/*
The dynamic type is the type of the variable in memory
- For most objects, this will be the same as the static type

int x{5};                        // x has a dynamic type of int
int* px = &x;                    // Dynamic type pointer to int

Circle circle;                   // Dynamic type Circle
Circle *pcircle = &circle;       // Dynamic type pointer to Circle
Circle& pcircle = circle;        // Dynamic type reference to Circle

However, it can be different for a pointer or reference to a base class

Shape *pshape = &circle;         // Dynamic type pointer to Circle
Shape& rshape = circle;          // Dynamic type reference to Circle

*/

//###########
//# Static vs dynamic Typing
//###########

/*
C++ almost always uses static typing
    - Type checking and function call resolution is done by the compiler
    - less rutime overhead
    - Better optimization

The dynamic type is only used for a pointer or reference to a base class
    - the compiler doest not decide which member function to a call
    - Instead, the member functions is chosen at runtime, using the object in memory

*/

//###########
//# using the Dyanmic Type
//###########

/*
To use the dynamic type, we declare the member function as "virtual" in the base class

When we call it through a pointer or reference to the base class, the dynamic type of the object will be used

class Shape {
    public:
        virtual void draw() {
            cout << "Drawing a shape" << endl;      // Declare Shape::draw() as virtual
        }
};

Shape* pshape =  new Circle();
pshape->draw();                     // Resolved at run time. Prints out "Drawing a circle"

*/

#include <iostream>
#include <vector>

using namespace std;

class Shape {
    public:
        virtual void draw() {
            cout << "Drawing a generic shape" << endl;
        }
};

class Circle : public Shape {
    public:
        void draw() {
            cout << "Drawing a circle" << endl;
        }
};

int main() {
    vector<Shape*> shapes;              // Vector of pointers to Shape objects

    // Create a pointer to a child class of Shape and append it to the vector
    shapes.push_back(new Circle());

    for (auto s : shapes) 
        s->draw();                      // Calls the draw() member function on the object pointed to by s

    for (auto s: shapes)                // Release memory
        delete s;
}