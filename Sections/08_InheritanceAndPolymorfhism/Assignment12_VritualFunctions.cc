
/*
Write an inheritance hierarchy with three classes: Base, Child and Grandchild.
 Do not define any constructors or data members for these classes.

Child inherits from Base and Grandchild inherits from Child.

Give each class a print() member function which prints out the name of the class

Write a print_class() function which takes a Base argument by value

Create an object of each class and pass it to a call to print_class()

Questions for this assignment

1. Implement the program as described. Explain your results.

2. Change the print() member function to be virtual. 
Run the program again and explain your results.

3. Change print_function() so that its argument is passed by reference.
Run the program again and explain your results.

4. Add an integer member to the Base class. 
Give the Base class a constructor which initializes this member from its argument.
- Change the program so that the Base, Child and Grandchild objects are created using this argument.
- Why does the program not compile?

5. What is the best way to solve this problem?

*/

#include <iostream>

using namespace std;

class Base {
    int value;

    public:
        Base(int v) : value(v) {}
        virtual void print() const { cout << "Base: " << value << endl; }
};

class Child : public Base {
    public:
        Child(int v) : Base(v) {}
        void print() const { Base::print(); cout << "Child" << endl; }
};

class Grandchild : public Child {
    public:
        Grandchild(int v) : Child(v) {}
        void print() const { Child::print(); cout << "Grandchild" << endl; }
};

void print_class(Base& b) {
    b.print();
}

int main() {
    Base b(1);
    Child c(2);
    Grandchild g(3);

    print_class(b);
    print_class(c);
    print_class(g);
}