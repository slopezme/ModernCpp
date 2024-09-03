//###########
//# Overloading Member Functions
//###########

/*
- We can overload inherited member functions
- We write a new member functions which has the same name but a different signature

class Vehicle {
    public:
        void accelerate() {...};
};

class Aeroplane : public Vehicle {
    public:
            void accelerate(int height);        // Overloaded member function
    };

*/

#include <iostream>

using namespace std;

class Vehicle {
    public:
        void accelerate() {
            cout << "Vehicle accelerating" << endl;
        }
};

class Aeroplane : public Vehicle {
    public:
        void accelerate(int height) {
            cout << "Aeroplane accelerating to " << height << " feet" << endl;
        }
};

void example() {
    Aeroplane plane;
    plane.accelerate(35000);    // Calls accelerate(int height) on an Aeroplane. Prints out "Aeroplane accelerating to 35000 feet"
    cout << "----------------" << endl;
}

//###########
//# Hidden member Functions
//###########

/*
- If we olverload an inherited function in the child class, it will "hide" al the other inherited member functions with that name
    - Those functions cannot be called on the child class

- This is incosistent with OO design principles
    - The parent class represents the interface of the hierarchy
    - Child classes should extend the interface, not obscure it


-- Older solution

- One solution is to define the inherited functions in the child class
    - we add an accelerate member function to Aeroplane that call the Vehicle member function
    - This requieres one member function in Aeroplane for each hidden verions of the function

class Aeroplane : public Vehicle {
    void accelerate() { Vehicle::accelerate(); }            // Call parent version of accelerate()
    void accelerate(int height) ;                           // Aeroplanes overload of accelerate()
        
*/

class Aeroplane2 : public Vehicle {
    public:
        void accelerate() { Vehicle::accelerate(); }            // Call parent version of accelerate()
        void accelerate(int height) {
            cout << "Aeroplane accelerating to " << height << " feet" << endl;
        }
};



void example2() {
    Aeroplane2 plane;
    plane.accelerate();         // Calls accelerate() on an Aeroplane. Prints out "Vehicle accelerating"
    plane.accelerate(35000);    // Calls accelerate(int height) on an Aeroplane. Prints out "Aeroplane accelerating to 35000 feet"
    cout << "----------------" << endl;
}

//###########
//# Hidden member Functions - modern Solution
//###########

/*
From C++11 we can tell the child class to "use" the parents version
    using Vehicle::accelerate;              // make Vehicles version of accelerate()  available here
    void accelerate(int height);            // Aeroplanes overload of accelerate()

This will make all the hidden versions of the function available in the child class

*/

class Aeroplane3 : public Vehicle {
    public:
        using Vehicle::accelerate;              // make Vehicles version of accelerate()  available here
        void accelerate(int height) {
            cout << "Aeroplane accelerating to " << height << " feet" << endl;
        }
};

void example3() {
    Aeroplane3 plane;
    plane.accelerate();         // Calls accelerate() on an Aeroplane. Prints out "Vehicle accelerating"
    plane.accelerate(35000);    // Calls accelerate(int height) on an Aeroplane. Prints out "Aeroplane accelerating to 35000 feet"
    cout << "----------------" << endl;
}


int main() {

    cout << "Overloading Member Functions" << endl;
    example();

    cout << "Hidden Member Functions" << endl;
    example2();

    cout << "Hidden Member Functions - modern Solution" << endl;
    example3();
    return 0;
}
