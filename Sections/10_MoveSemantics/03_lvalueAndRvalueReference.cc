/*####################
#  lvalue Reference
####################*/

/*
- A reference to an lvalue is typically implemented as a pointer
- The compiler adds code to deference the pointer as needed

int x;
int& y = x;     // Equivalent to int*y = &x;
y = 3;          // Equivalent to *y = 3;

- This requires that x has a name and an address
    - i.e x must be an lvalue

- This is known as an "lvalue reference"
    


*/

/*####################
#  lvalue Reference to rvalue
####################*/

/*
- we cannot bind an lvalue reference to an rvalue ...

int& y = 3;     // Error: 3 is an rvalue

- unless the reference is const

const int& y = 3;   // OK

- The compiler will add code which makes this appear to work live a 
const reference to an lvalue

*/

/*####################
#  Rvalue Reference
####################*/

/*
- C++11 has the concept of an "rvalue reference"
- This is a syntatic device which indicates that a function argument must be
moveable rvalue

- An rvalue reference has '&&' after the type

void func(int&& x);         // func's argument is an "rvalue reference"

func(2);                    // 2 is an rvalue. OK

int y{3};                   
func(y);                    // y is an lvalue. Error

*/

#include <iostream>

using namespace std;

void func(int&& x) {
    cout << "Called with argument " << x << endl;
}



/*####################
#  Moving a function call argument
####################*/

/*
- A function argument can be an "rvalue reference"
- The passed object will be moved into the argument if
    - the object is an rvalue
    - and its type is moveable

- Otherwise, the call does not compile

- This allows us to overload the function to behave differently dependeing on whether
the passed object is an lvalue or an rvalue

*/

/*####################
#  std::move
####################*/

/*
- If we want to pass an lvalue to a function which takes an rvalue reference, we have to 
cast it to rvalue
- std::move() will cast its argument to rvalue

int y{2};
func(std::move(y));     // OK: y is cast to rvalue

- This will move y's data into the function argument x
- This sould only be done if y's data is expendable
    - After calling func(), y's data may be empty or unusuable
    - If we want to use y again, we must re-assing its data

*/

void test(const string& s) {
    cout << "lvalue reference version \n";
}

void test(string&& s) {
    cout << "rvalue reference version \n";
}

void moveExample() {
    
    string l{string{"Perm"}};
    string& lr{l};

    cout << " Temporary object: ";
    test(string{"Temp"});       // rvalue reference version

    cout << " Lvalue variable: ";
    test(l);                    // lvalue reference version

    cout << " Lvalue reference: ";
    test(lr);                   // lvalue reference version

    cout << "std::move(): ";
    test(std::move(l));         // rvalue reference version
    cout << "\n";

    string&& r{string{"Temp"}};

    cout << "Rvalue variable: ";
    test(r);                    // rvalue reference version
    cout << "std::move(): ";
    test(std::move(r));         // rvalue reference version
}

/*####################
#  Argument type Summary
####################*/

/*
Lvalue
    - We can pass an lvalue
    - The function has a copy of the passed objects data
    - Or we can pass a moveable rvalue
    - The function now onwns passed object's data

Lvalue reference
    - We can pass an lvalue, but no an rvalue
    - The function can modify the passed object's data through the reference

Const lvalue reference
    - We can pass an lvalue or an rvalue
    - The function cannot modify the passed object's data through the reference

Rvalue reference
    - We can pass a moveable rvalue, but not an lvalue
    - The function now owns the passed object's data

*/


int main() {
    func(2);            // OK: 2 is an rvalue
    int y{3};
    // func(y);         // Error: y is an lvalue


    moveExample();
}