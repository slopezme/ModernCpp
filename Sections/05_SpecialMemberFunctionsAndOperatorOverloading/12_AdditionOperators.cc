
//############
// Plus Operator Summary
//############

/*
- Prototype: 
    T operator +(const T&  lhs, const T& rhs);

- How to invoke it
 a+b;

- Called as 
    operator +(a, b);

- Return Value
    - The sum of the two objects, returned by value

- This is defined as a non - member functions
*/

//############
// =+= Operator Summary
//############

/*
- Prototype: 
    T& operator +=(const T& rhs);

- How to invoke it
    a += b;

- Called as
    a.operator +=(b);

- Returns the modified first object by reference
- This is defined as a member function (why?)
*/

//############
// Plus Operator
//############

/*
- If a class needs to define either one of there operators, it will usually need the other one as well
- Both operators perform the same function, so this can result in duplicate code
- We can implement the + operator by delegating to the += operator

Type operator + ( const Type& lhs, const Type& rhs) {
    Type temp{lhs};                 // Make a copy of the lhs argument
    temp += rhs;                    // Call += operator to add the rhs argument to the copy
    return temp;                    // Return the result
}
*/

//############
// Plus Operator Contd
//############

/*
- This is an example of code reuse
- The code for doing the addition is only once, in the += member function
- If we later change our mind, for example by adding more data members, we only need 
to alter the += member function

*/

//############
// Basic Complex Number class
//############

/*
we will use a basic complex number class to illustrate this
- Form C++11, the Standard Library has a fully featured complex number class
-* Avoid Potential confusion with std::complex

class Complex{
private:
    double real{0.0};
    double imag{0.0};
public:
    Complex(double r, double i) : real(r), imag(i) {}
    }


*/

//############
// += Operator for Complex Class
//############

/*
- We define the += operator as a member function
- This adds the real and imaginary parts separately and returns the modified object

class Complex{
...
public:
    Complex& operator +=(const Complex& rhs) {
        real += rhs.real;
        imag += rhs.imag;
        return *this;
    }
    }
}

*/

//############
// + operator for Complex class
//############

/*
- we define the + operator as a non-member function
class Complex{
...
};

Complex operator +(const Complex& lhs, const Complex& rhs) {
    Complex temp{lhs};              // make a copy of the lhs argument
    temp += rhs;                    // Add the rhs argument to it
    return temp;                    // Return the result
}

*/

#include <iostream>

using namespace std;

// Avoid potential confusion with std::complex

class Complex {
    double real{0.0};
    double imag{0.0};
public:
    Complex(double r, double i) : real(r), imag(i) {}
    Complex(double r): real(r) {}

    // we define the += operator as a member function
    // This adds the real and imaginary parts separately and returns the modified object
    Complex& operator +=(const Complex& rhs) {
        real += rhs.real;
        imag += rhs.imag;
        return *this;
    }

    void print() {
        cout << real << " + " << imag << "i" << endl;
    }
};

Complex operator +(const Complex& lhs, const Complex& rhs) {
    Complex temp{lhs};              // make a copy of the lhs argument
    temp += rhs;                    // Add the rhs argument to it
    return temp;                    // Return the result
}

int main() {
    Complex c1{1, 2}, c2{3, 4};
    cout << "c1 = "; c1.print();
    cout << "c2 = "; c2.print();

    Complex c3 = c1 + c2;
    cout << "c3 = ";
    c3.print();

    c1 += c2;
    cout << "c1 = ";
    c1.print();
    return 0;

    Complex c4 = 1 + c2;
    cout << "c4 = ";
    c4.print();
}