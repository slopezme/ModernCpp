//###########
//# Override and Overload of Virtual Functions
//###########

/*
- A child class can define a member function with the same name as a virtual function in the parent class
- override
    - Same signature as the parent class
    - Circle and Triangle override the virtual draw() member function

- overload
    - Different signature from the parent class
    - Prevents dynamic binding
    - may hide the parent class's member function

- it is easy to overload by mistake
    - Editing error when defining child function
    - parent function's signature changes

*/

//###########
//# The override keyword
//###########

/*
C++11 introduced the "override" keyword
- We can add this to the definition of a member function in a child class

    void draw() const override;         // Child class overrides Shape::draw()

- the compiler will check wheter this member functions overrides a virtual member function in the parent class
- The compiler will give an error if the functions does not override

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
    using Shape::draw; // Inherit draw() from Shape
        void draw() const override {
            cout << "Drawing a circle" << endl;
        }
        // void draw(int radius) const override; // Error! draw(int) does not override a virtual function in Shape
};

int main() {
    Circle circle;
    circle.draw();
}

//###########
//# The final keyword
//###########

/*
C++11 also intruduced the "final" keyword
    - A final class cannot be derived from
    - A final member function cannot be overridden in a child class

Libraries often use "final" 
    - the library can provide a class hierarchy, or use one internally
    - user of the library cannot extend this class hierarchy

*/

/*

class Circle final : public Shape {
    public:
        void draw() const override {
            cout << "Drawing a circle" << endl;
        }
};

class DeluxeCircle : public Circle {
    public:
        void draw() const override; // Error! Circle::draw() is final
};

*/


//###########

/*
class Circle : public Shape {
    public:
        void draw() const override final; 
};

class DeluxeCircle : public Circle {
    public:
        void draw() const override; // Error! Circle::draw() is final
};

*/
