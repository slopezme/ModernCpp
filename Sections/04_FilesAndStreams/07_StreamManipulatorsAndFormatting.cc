

//############
// Stream Manipulators
//############

/*
We can push a "manipulator" onto the stream to affect the stream's behaviour

- we have already met std::flush and std::endl
- The C++ library defines a number of manipulators which alter the way the stream behaves

- Most are in <iostream>
- Some manipulators whick take arguments are in <iomanip> 
*/

//############
// Printing Booleans
//############

/*
- Bool is an integer type with two possible values, true (stored as 1)  and false (stored as 0)
- Contional expressions have type bool

bool is_negative = x < 0;

- we can print out bool values by using the boolalpha manipulator

cout << boolalpha << is_negative << endl; 
*/

#include <iostream>

using namespace std;

int main(){

    bool is_negative = -1 < 0;
    cout << boolalpha << is_negative << endl;

    return 0;
}

//############
// Formatting Output
//############

/*
By default, output streams do not format the data

cout << "Penguins " << 5 << endl;
cout << "Polar Bears " << 3 << endl;

The output looks like this:

Penguins 5
Polar Bears 3

- Sometimes we want to present out results in the form of a table
- To make the output line up, we need to make all the output fileds the same width
- the setw() manipulator will pad the output filed to make it the width of its argument
    - setw() takes an argument, which is the width of the following data output filed
    - setw()  only affects the next data item on the stream
    - setw() is defined in <iomanip>

*/

#include <iomanip>

int main2(){

    cout << setw(15) << "Penguins" << setw(5) << 5 << endl;
    cout << setw(15) << "Polar Bears" << setw(5) << 3 << endl;

    return 0;
}

//############
// left manipulator
//############

/*
- we can use the left manipulator to make the output left justified
- the stream will add padding blanks at the right

cout << left << setw(15) << "Penguins" << setw(5) << 5 << endl;
cout << left << setw(15) << "Polar Bears" << setw(5) << 3 << endl;

the output will look like this:

Penguins       5
Polar Bears    3

- this manipulator is "sticky"
- To restore the default setting, apply the right manipulator

*/

int main3(){

    cout << left << setw(15) << "Penguins" << setw(5) << 5 << endl;
    cout << left << setw(15) << "Polar Bears" << setw(5) << 3 << endl;

    cout << right;

    return 0;
}

//############
// "Sticky" Manipulators
//############

/*
- Most manipualtors change the state of the stream
    - the stream will remain in this state
    - to restore the stream's original state, we need to push another manipulator
    which has the opposite effect

- These manipulators are "sticky"
- A "non-sticky" manipulator only affect the next output operation on the stream
- The only non-sticky manipulator is setw()

*/

//############
// setfill() Manipulators
//############

/*
The setfill() manipulator from <iomanip>  sets the padding character to its argument


cout << setfill('#');
cout << left << setw(15) << "Penguins" << 5 << "\n";
cout << left << setw(15) << "Polar Bears" << 3 << "\n";
cout << setfill(' ');  

The output will look like this:

Penguins#######5
Polar Bears####3

*/

int main4(){

    cout << setfill('#');
    cout << left << setw(15) << "Penguins" << 5 << "\n";
    cout << setw(15) << "Polar Bears" << 3 << "\n";
    cout << right;   // Restore the default setting
    cout << setfill(' ');

    return 0;

}


