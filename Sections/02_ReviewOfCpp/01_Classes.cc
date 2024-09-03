#include <iostream>
#include <cstring>

//classes are private by default
class MyClass {
private:
    int id;
    char *name;
    double value;

public:
    // Constructor
    MyClass(int id = 0, const char *n = nullptr, double v = 0.0) : id(id), value(v) {
        if (n != nullptr) {
            name = new char[strlen(n) + 1];
            strcpy(name, n);
        } else {
            name = new char[1];
            *name = '\0';
        }
        std::cout << "Constructor called" << std::endl;
    }

    // Destructor
    // Called before the class members are released in memory
    ~MyClass() {
        //Release allocated memory, close the connection to the database, etc
        delete [] name;
        std::cout << "Destructor called" << std::endl;
    }

    // Copy Constructor
    MyClass(const MyClass &other) : id(other.id), value(other.value) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        std::cout << "Copy constructor called" << std::endl;
    }

    // Assignment Operator
    // Assigns an existing object to another existing object
    // Returns a reference to the object being assigned

    MyClass& operator=(const MyClass &other) {
        if (this != &other) {
            id = other.id;
            value = other.value;
            delete [] name;
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
            std::cout << "Assignment operator called" << std::endl;
        }
        return *this;
    }

    void print() const {
        std::cout << "ID: " << id << ", Name: " << name << ", Value: " << value << std::endl;
    }
};

int main() {
    MyClass obj1(1, "Object One", 10.5);

    MyClass obj2 = obj1;  // Copy constructor called

    MyClass obj3;
    obj3 = obj2;  // Assignment operator called

    obj1.print();
    obj2.print();
    obj3.print();

    return 0;
}
