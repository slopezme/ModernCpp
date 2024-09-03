
#include <iostream>

using namespace std;

int main() {
    double pi{3.141'592'653'5};
    cout << pi << endl;             //Displays 3.14159

    double c{299'792'458};
    cout << c << endl;              //Displays 2.99792e+008
}

//############
// Scientific Notation
//############

/*
- In scientific notation, digits are displayed with the mantissa and exponent

- this is known as the " mantissa"

- it is followed by an "exponent" which gives the magnitude of the number as a power of 10
    - 2.99792e+008 represents 2.99792 x 10^8 which is 299,792,000
    - 1.00000e-006 represents 1.00000 x 10^-6 which is 0.000001
    - 3.14159e+000 represents 3.14159 x 10^0 which is 3.14159
*/

//############
// Scientific Manipulator
//############

/*
- The scientific manipulator forces the stream to use scientific notation
- This shows seven significant figures, with the decimal point after the first one

cout << scientific << c << endl;    //Displays 2.99792e+008

- The uppercase manipulator changes the 'e' to 'E'

cout << uppercase << scientific << c << endl;    //Displays 2.99792E+008
*/

//############
// Fixed point Output
//############

/*
- The fixed manipulator will cause floating point numbers to be displayed as fixed point numbers
- The numbers will be displayed to 6 decimal places. truncating or padding with zeros as necessary

cout << fixed << c; // Padded - displays 299792.458000
double e{1.602e-19};
cout << fixed << e; // Truncated - displays 0.000000

*/

//############
// Restoring Floating - point Defauls
//############

/*
- These manipulators are all sticky: they permanently change the behavior of the stream
- if other programmers use floating point output later on in the program, they may not get 
the results they expect
- when we have finished out output, we should restore the stream to its default state

*/

//############
// Floating - point Precision
//############

/*
- Floating point precision determines the number of digits that are displayed
    - For defaultfloat and fixed formats, the default precision is 6

- the setprecision manipulator sets the precision of the stream

cout << setprecision(3) << pi << endl; // Displays 3.14

*/