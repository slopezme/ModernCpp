//###########
//# Base Class and Modeling
//###########

/*
Typically, base classes model abstract concepts such as "shape" or "vehicle"

- Concrete derived classes model concrete entities such as "circle" or "aeroplane"

*/

//###########
//# interface and Implementation
//###########

/*
- The base class is the interface ot the class hierarchy
- Its public virtual member functions provide all the functionality that is commoon to the hierarchy
    - Any shape object can be drawn, rotated, etc
- The derived classes override these functions
- They implement this interface in a concrete way that is specific to each class
    - A circle object can draw a circle shape, rotate it, etc

The derived classes override these functions
They implement this interface in a concrete way what is specific ti each class
    - A circle object draw a circle shape, rotate it, etc

*/

//###########
//# Virtual Functions in Base Class
//###########

/*
Often, the base class's virtual member functions cannot do anything useful
    - Each derived class will implement the functionality as appropriate

- these member functions can be left empty
- or we can use C++ sintax to indicate they are not impelemented here
- this helps express the idea of a base class

*/

//###########
//# Pure Virtual function
//###########

/*
we can make the base class's virtual functions "pure virtual"

This is done by putting "= 0"  instead of the function body

class Shape {
    public:
        virtual void draw() const = 0; // Pure virtual function
        virtual void rotate(int angle) = 0; // Pure virtual function
        virtual ~Shape() = default;
};

This means that shape doest not implement draw()
This makes it clear that the virtual function is not part of the implementation

*/

//###########
//# Abstract base Class
//###########

/*
- A class with a pure virtual member function cannoot be instantiated

    Shape shape; // Error! Cannot instantiate an abstract class

This is known as an "abstract base class"
    - Similar to an "interface" in other languages

- If we derive from an abstract base class, we must override all its pure virtual functions
    - Otherwise, the derived class will also be an abstract class

*/


#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Shape {
    public:
        virtual void draw() const = 0; // Pure virtual function
};

class Circle : public Shape {
    public:
        void draw() const override {
            cout << "Drawing a circle" << endl;
        }
};

class Triangle : public Shape {
    public:
        void draw() const override {
            cout << "Drawing a triangle" << endl;
        }
};

void example1() {

    // Shape shape; // Error! Cannot instantiate an abstract class
    Triangle triangle;
}

//###########
//# Object Slicing
//###########

/*
- if we have a function that takes a base class object by value 
    void drawShape(Shape s) ;               // Function taking shape by value

And we pass a derived class object to it
    drawShape(Circle);                      // Pass derived class object by balue as a Shape

This will  call Shape's copy constructor 
    - s will be a copy of the Shape object
    - In effect, the Circle part of the argument has been "sliced off"

This is known as "object slicing"
    
*/


class Shape2 {
    public:
        //virtual void draw() const { cout << "Drawing a generic shape" << endl; }    // Empty virtual function
        virtual void draw() const = 0; // Pure virtual function
};

class Circle2 : public Shape2 {
    public:
        void draw() const override { cout << "Drawing a circle" << endl; }
};

// Function taking base class by balue

// void drawShape(Shape2 s) {
//     s.draw();                   // Always calls Shape::draw()
//     (&s)->draw();               // Always calls Shape::draw()
// }

void drawShape(const Shape2& s) {
    s.draw();                   
    (&s)->draw();               
}


void example2() {
    Circle2 circle;
    drawShape(circle);          // Calls draw() on a Shape. Prints out "Drawing a generic shape"
}

//###########
//# Abstract Base Class as Function Argument
//###########

/*
An abstract base class cannot be passed by value
    -// Does not compile - cannot declare parameter of abstract type
    void drawShape(Shape s) ;

It can only be passed by reference or by address
In the function body, dynamic binding will be used

void drawShape(const Shape& s) {
    s.draw();                   // Calls draw() on the dynamic type of s
}

*/

int main() {

    cout << "Example 1" << endl;
    example1();

    cout << "Example 2" << endl;
    example2();
}