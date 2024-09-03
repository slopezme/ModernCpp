//###########
//# polymorphism
//###########

/*
- Polymorphism(gr) = "many forms"

- In programming , polymorphism means that different types have the same interface
    - i.e. they have the same behaviour

- STL containers are an example of polymorphism
    - vector<int> is a different type from vector<string>
    - they have the same interface, regardless of the element type

- this is known as "parametric polymorphism", because the element type is a parameter of the vector
*/

//###########
//# polymorphism and Inheritance
//###########

/*
- The classes in an inheritance hierarchy have the same interface
    - Shape, Circle and Triangle all have a draw() member function

- This is known as "subtype polymorphism"

- An object of a type can be replaced by an object of its subtype
    - The Liskov Substitution Principle
    - One of the fundamental concepts in object-oriented programming

*/

//###########
//# Importance of Polymorphism
//###########

/*
- Polymorphism is a very useful programming technique
- When we have related types, we can write one set of code which handles all of them
    - Avoids duplicated code
- We can add new types without having to write extra code to handle them
    - Saves programmer time

- however, it still respects the individual properties of a particular type
    - Ensure correct behaviour


*/

//###########
//# Subtype Polymorphism in C++
//###########

/*
In C++, subtype polymorphism is implemented using pointers or references to the base class and calling
virtual functions on them

vector<Shape*> shapes;
...
for (auto s : shapes)
    s->draw();                  // Uses dynamic binding to call Circle::draw(), etc

This allows us to use the same code to handle different classes, but still keep type safety

    - The program will work out the correct way to draw each shape in the container
    - Alternatively, each Shape in the container "knows" how to draw itself


*/


//###########
//# polymorphism in C++
//###########

/*
- Subtype polymorphism
    - run time overhead
    - May requiere memory managment
    - No control over child classes
    - Can result in large, unmaintainable inheritance hierarchies

- Parametric polymorphism
    - Compile time binding
    - No run time overhead
    - No memory allocation
    - More control over which types are instantiated

*/


//###########
//# When to use Inheritance
//###########

/*
- Inheritance is often over used
- Many problems are better solved by composition
    - To use a class Interface, make it a data member

- the trend in C++ is a away from subtype polymorphism towrds parametric polymorphism
- Only use inheritance if you need an "is-a" relationship

*/

