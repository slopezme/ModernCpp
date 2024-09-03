

//############
// Other cases of copy elision
//############

/*
A conversion operator is a member function that converts an object of one class to an object of another class

- A class can be define a conversion operator
- Member function which converts an object to some other type
- The conversion operator below will be  called whenever the object is used when an int is expected

class Test{
    int i;
public: 
    operator int() const { return i; }    // Conversion operator to int
    ...
    };

*/

//############
// Function Calls and Conversions
//############

/*
When we call a function, the compiler has to find a function that resolves the call

Test test;
int x = test +5;

First it tries to find an exact match
- There is no + operator that takes a Test and an int

Then it tries to convert the arguments
- Test can be converted to int
- There is a + operator that takes an int and an int

int x = test + 5;          // Caled as test.operator int() + 5

*/

#include <iostream>
#include <string>

using namespace std;

class Test{
    int i{42};
    string str;
public:
    operator int() const { return i; }    // Conversion operator to int
};

void main1() {
    Test test;
    cout << "test = " << test << endl;
}


//############
// implicit Conversion
//############

/*
This is an implicit conversion
Implicit conversions are often surprising, with undesirable results

In older versions of C++, whis would compile

int i = 99;
cin << i;   //Really??

- streams have an operator bool() used to check the stream
- cin is implicitly converted to a bool
- the result is the coerced to int
- The non-overloaded << operator for int is called
*/

//############
// Explicit Conversion Operators
//############

/*
- In modern C++, we can make the conversion operator explicit
- Implicit conversions will now cause a compiler error
- if we want the conversion, we must explicitly ask for it by using a cast

class Test{
    int i{42};
public 
    explicit operator int() const { return i; }    // Conversion operator to int
};

Test test;
cout << test << endl;                       // Error: no match for operator <<
cout << static_cast<int>(test) << endl;    // Explicit conversion


*/

//############
// Conditionals
//############

/*
however, we dont neet to use a cast in a conditional

class Test{
    ...
    explicit operator bool() const { return i != 0; }    // Conversion operator to bool
};

if (test) { cout << "True" << endl; }    // OK
*/

//############
// Implicit Conversion and Constructors
//############

/*
- A constructor with a single argument acts as an implcit conversion operator

class Test{
    int i;
    public:
    Test(int i): i{i} {}
};

Test test = 4;

- This can cause unexpected behaviour
- e.g, when passing a Test object as a function argument


*/

//############
// Explicit Constructors
//############

/*
We can prevent this by making the constructor explicit

class Test{
    int i;
    public:
    explicit Test(int i): i{i} {}
};

Test test = 4;    // Error: no matching constructor for initialization of 'Test'
Test test = Test(4);    // Must explicitly create the object
*/

class Test2 {
    int i;
    public:
    explicit Test2(int i): i{i} {}
};

void main2() {
    //Test2 test = 4;    // Error: no matching constructor for initialization of 'Test'
    Test2 test2 = Test2(4);    // Must explicitly create the object
}

int main() {
    cout << "main1" << endl;
    main1();

    cout << "\n main2" << endl;
    main2();
    return 0;
}

