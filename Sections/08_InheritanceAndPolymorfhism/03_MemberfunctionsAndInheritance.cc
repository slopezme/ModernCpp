//###########
//# Inheriting Member Functions
//###########

/*
- A child class "inherits" all the non private member functions of its parent class

class Vehicle {
    public:
        void start() {
            cout << "Vehicle started" << endl;
        }
};

class Aeroplane : public Vehicle {
    public:
        -/// void start() {
            cout << "Aeroplane started" << endl;                /// Inherited from Vehicle
        }
};

plane.start();          // Calls start() on an Aeroplane . Prints out "Engine started"

*/

#include <iostream>

using namespace std;

class Vehicle {
    public:
        void start() {
            cout << "Vehicle started" << endl;
        }
};

class Aeroplane : public Vehicle {
    public:
        /// void start(); Inherited from Vehicle  ///
};

void example() {
    Aeroplane plane;
    plane.start();          // Calls start() on an Aeroplane . Prints out "Engine started"
}


//###########
//# Reimplementing Member Functions
//###########

/*
- A child class can re-implement the parent class's member functions
- To make them more approppiate for the child

class Aeroplane : public Vehicle {
    public:
        void start() {
            cout << " Carrying out checks ... ";
            cout << "Ready for take off";

            }
};

plane.start();          // Calls start() on an Aeroplane . Prints out "Carrying out checks ... Ready for take off"

*/

class Aeroplane2 : public Vehicle {
    public:
        void start() {
            cout << "Carrying out checks ... ";
            cout << "Ready for take off";
        }
};

void example2() {
    Aeroplane2 plane;
    plane.start();          // Calls start() on an Aeroplane . Prints out "Carrying out checks ... Ready for take off"
    cout << endl;
}


//###########
//# Extending Member Functions
//###########

/*
The child class can also extend the parents member functions

class Aeroplane : public Vehicle {
    public:
        void start() {
            cout << "Carrying out checks ... ";           
            Vehicle::start();
            cout << "Ready for take off";
        }
};

plane.start();          // Calls start() on an Aeroplane . Prints out "Carrying out checks ... Vehicle started Ready for take off"

*/

class Aeroplane3 : public Vehicle {
    public:
        void start() {
            cout << "Carrying out checks ... ";           
            Vehicle::start();
            cout << "Ready for take off";
        }
};

void example3() {
    Aeroplane3 plane;
    plane.start();          // Calls start() on an Aeroplane . Prints out "Carrying out checks ... Vehicle started Ready for take off"
    cout << endl;
}

//###########
//# Public Access
//###########

/*
- A public member of a class is accessible from any part of the code
    - it is a part of the class's interface
- A child class will have access to all its parents public members
- A child class doest not have access to its parents private members
- Often, we cant to write member functions which are not part of the class's public interface, but are available to child classes
    - these member functions are part of the class's implementation

*/

//###########
//# Protected access
//###########

/*
- A parent class can make its members avaialble to its childer, but not to other code
    - This maintains encapsulation

- To do this, use the protected access specifier
    protected:
        int secret;                             // Protected data member - not that useful
        void kidsOnly() {                       // Can only be called by child classes
            cout << "Kids only" << endl;        
        }


*/

int main() {
    cout << " example() " << endl;
    example();

    cout << " example2() " << endl;
    example2();

    cout << " example3() " << endl;
    example3();
    return 0;
}