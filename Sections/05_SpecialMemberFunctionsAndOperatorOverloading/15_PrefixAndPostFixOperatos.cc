
//############
// prefix and Postfix operators
//############

/*
- The prefix and postfix ++ operators increment their argument
- The prefix version returns the incremented argument
++p;            // Equivalent to p  += 1;  p;

- The postfix version returns the unincremented argument
p++;            // Equivalent to p;  p += 1; temp;

- There are also decrement operators
--p;            // Equivalent to p -= 1; p;
p--;            // Equivalent to p; p -= 1; temp;
*/

//############
// ++ Operators and Arrays
//############

/*
- When we have a pointer to an array element, the ++operator will move the pointer
to the address of the next element

- We can use this to iterate over the elements of an array

int arr[] = {4,3,2,1};
int* p =  pa;       // p points to the first element of arr

for (int i = 0; i < 4; ++i) {
    cout << *p << endl;             // Deference the element
    ++p;                            // move p to the address of the next element
}

- we can also use this with iteratos to container elements

*/

//############
// Postfix ++ operator
//############

/*
- With the postfix operator, we can deference and increment in a single statment
cout << *p++ << endl;       // Deference p, then increment p

- The increment is performed first, because the ++ operator has higher precedece than the *

- The postfix operator moves p to the next element, then resturn the original address, which is the deferenced
*/

//############
// Postfix ++ operator adn Loops
//############

/*
- Either operator can be used to increment the counter in a for loop
    - The counter is always increment at the end of the loop
- using the postfix oeprator makes an unnecessary copy of the loop counter

for (int i = 0; i < 10; i++) {
    cout << i << endl;
}

-// Executed as 

while (i < 4) { ...; int temp = i; i += 1; temp; }
- however, modern compilers should optimize this away

*/

//############
// Overloading the Prefix ++ Operator
//############

/*
- if we are writing a class that supports arithmetical operations, we usually need to implement these operators
- The prefix oeprator performs the increment and returns a reference to the incremented object

Test&  Test::operator++() {
    ++value;                // Perform the increment operation
    return *this;           // Return the incremented object
}

- Tje prefix -- operator is implemented similarly
*/

//############
// Overloading the postfix ++ Operator
//############

/*
- The postfix operator makes a copy of the object, performs the increment and returns the unmodified object
- The postfix oeprator takes a dummy argument, to give it a different signature from the prefix operator

Test Test::operator++(int t) {          // t is a dummy argument
    Test temp(*this);                   // Make a copy of the object
    ++value;                            // Perform the increment operation
    return temp;                        // Return the unmodified object
}
    
*/

#include <iostream>

using namespace std;

class Complex {
    double real;
    double imag;
public:
        Complex(double real, double imag) : real{real}, imag{imag} {}

        Complex& operator++();              // Prefix increment ++ operator
        Complex operator++(int);            // Postfix increment ++ operator
        Complex& operator--();              // Prefix decrement -- operator
        Complex operator--(int);            // Postfix decrement -- operator

        void print() { cout << real << " + " << imag << "i" << endl; };
};

// Prefix ++ operator

Complex& Complex::operator++() {
    ++real;
    return *this;
}

// Postfix ++ operator

Complex Complex::operator++(int) {
    Complex temp(*this);
    ++real;
    return temp;
}

// Prefix -- operator

Complex& Complex::operator--() {
    --real;
    return *this;
}

// Postfix -- operator

Complex Complex::operator--(int) {
    Complex temp(*this);
    --real;
    return temp;
}

int main(){
    Complex c(5,6);
    cout << "Initial value of c: ";
    c.print();

    ++c;
    cout << "After calling ++c: ";
    c.print();

    Complex d = c++;
    cout << "After calling c++: ";
    c.print();
    cout << "Value of d: ";
    d.print();

    --c;
    cout << "After calling --c: ";
    c.print();

    d = c--;
    cout << "After calling c--: ";
    c.print();


};
