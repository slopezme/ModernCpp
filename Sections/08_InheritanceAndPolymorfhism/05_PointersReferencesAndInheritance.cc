//###########
//# Pointers and Inheritance
//###########

/*
Normally a pointer must point to a variable of the same type
However, a pointer to a base class can point to any object in the same hierarchy

class Shape{}
class Circle : public Shape{};

Circle circle;
Shape* shape = &circle;     // OK

However, we cannot go in the other direction

Shape shape;
Circle* circle = &shape;    // Error!

*/

//###########
//# Derived Class memory
//###########

/*
This works because the memory layout of a derived class object is the same as a base class object followed by the derived class part

However, a shape object may not necessarily be part of a Circle object
    - It could be a basic Shape object
    - or part of some other derived class object

*/

#include <iostream>

using namespace std;

class Shape {
    public:
        void draw() { std::cout << "Drawing a shape" << std::endl; }
};

class Circle : public Shape {
    public:
        void draw() { std::cout << "Drawing a circle" << std::endl; }
        void area() { std::cout << "Calculating area of a circle" << std::endl; }
};

void example1() {
    Circle circle;
    Shape* shape = &circle;

    shape->draw();      // Calls draw() on a Circle. Prints out "Drawing a circle"
    // shape->area();      // Error! shape is a pointer to a Shape, which does not have an area() member function
}


//###########
//# Member Function Overriding
//###########

/*
- We can call any public member function of a base class on a derived class object
    - This will call shapes version 

- We cannot call any public member functions of Circle, even though the object is "really" a Circle
    - pshape -> draw();         // Calls draw() on a Shape. Prints out "Drawing a shape"
    - pshape -> area();         // Error! pshape is a pointer to a Shape, which does not have an area() member function

This is because the compiler ses pshape as pointing to a Shape object
To do object oriented programming, we need to be able to use phsape as a pointer to a Circle

*/

void drawShape(Shape& s) {
    s.draw();
}

void drawShape(Circle& c) {
    c.draw();
}


void example2() {
    Circle circle;
    Shape& rshape = circle;

    drawShape(circle);      // Calls draw() on a Circle. Prints out "Drawing a circle"
    drawShape(rshape);      // Calls draw() on a Circle. Prints out "Drawing a circle"
}

#include <vector>

void example3() {
    vector<Shape*> shapes;

    // Create a pointer to a child class of Shape and append it to the vector
    shapes.push_back(new Circle);

    for (auto s : shapes) 
        s->draw();

    for (auto s: shapes)
        delete s;
}

void example4() {
    vector<Shape*> shapes;

    // Create a pointer to a child class of Shape and append it to the vector
    shapes.push_back(new Circle);

    for (auto s : shapes) 
        static_cast<Circle*>(s)->draw();        // Calls Shape::draw() 

    for (auto s: shapes)                        // Release memory
        delete s;
}

int main() {

    cout << "Pointers and Inheritance" << endl << endl;
    example1();
    cout << "------------- " << endl;

    cout << "Member Function Overriding" << endl << endl;
    example2();
    cout << "------------- " << endl;

    cout << "Derived Class memory" << endl << endl;
    example3();
    cout << "------------- " << endl;

    cout << "Derived Class memory" << endl << endl;
    example4();
    cout << "------------- " << endl;
    return 0;
}