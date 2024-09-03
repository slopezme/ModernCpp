//###########
//# Base Ckass and Derived Class Example
//###########

/*
we will create s imple hierarchy which has a vechicle class and Aeroplane class



*/

//###########
//# Deriving a Class
//###########

/*
- To define a derived class, we put a colon : after its name, followed by the public keyword and the name of the base class

class Aeroplane :pulibc Vehicle {
    // class definition
};
- The derived class will be able to call the non private member functions of the base class
- It can also access any non private data members
- Optionally, the derived class can replace the base class's member functions with its own version


*/

//###########
//# Derived Class Memory Layout
//###########

/*
- A derived class object is stored in memory as a base class object followed by the derived class part
- When a derived clas object is created, the base class constructor is called first, the the derived class constructor
- When it is destroyed, the derived class destructor is called boefore the base class

*/

//###########
//# Constructors
//###########

/*
- the derived class constructor calls the base class's consctructor to initilize the base class part of the object

- We use the same initilizer syntax as for a class member

class Aeroplane : public Vehicle {
    public:
        Aeroplane() : Vehicle() {
            // constructor code
        }
};

*/

//###########
//# Constructor with arguments
//###########

/*
In effect, each class initilizes its own members

class Vehicle {
    Vehicle(int maxSpeed) : maxSpeed(maxSpeed) {
        // constructor code
    }
};

class Aeroplane : public Vehicle {
    -// Initilize the Vehicle part of the object, then initialize maxAltitude

    Aeroplane(int maxSpeed, int maxAltitude) : Vehicle(maxSpeed), maxAltitude(maxAltitude) {
        // constructor code
    }
};
        

*/

#include <iostream>

using namespace std;

class vehicle {
    int maxSpeed;

    public:
        vehicle(int maxSpeed) : maxSpeed(maxSpeed) {
            cout << "Vehicle constructor" << endl;
        }

        // .... member functions
};

class Aeroplane : public vehicle {
    int maxAltitude;

    public:
        Aeroplane(int maxSpeed, int maxAltitude) : vehicle(maxSpeed), maxAltitude(maxAltitude) {
            cout << "Aeroplane constructor" << endl;
        }

        // .... member functions
};


//###########
//# Deriving from a derived Class
//###########

/*
- We can use a derived class as the base class of another derived class

- Clas Aeroplane : public Vehicle {
    // class definition
};

- Class FighterPlane : public Aeroplane {
    // class definition
};

- Aeroplane is the "parent" class of FighterPlane
- FighterPlane is the "child" class of Aeroplane
- Vehicle is the "parent" class of Aeroplane
- Aeroplane is the "child" class of Vehicle

*/

int main() {

    cout << "Creating a Vehicle object" << endl;
    vehicle v(100);

    cout << "Creating an Aeroplane object" << endl;
    Aeroplane a(100, 10000);
    return 0;
}

