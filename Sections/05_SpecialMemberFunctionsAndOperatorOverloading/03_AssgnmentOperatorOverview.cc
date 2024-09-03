
/*
The assignment operator is a member fucntion
oeprator =

it is invoked when we assign two objects of the class

y = z  // called as y.operator=(z;

After this statement has been executed, the member of y will be the same as the members of z
The assignment operator takes its argument by const reference
It return the modified object y = z;

*/

//############
// Multiple Assignment
//############

/*
We can do multiple assignment in C++
x = y = z;
This will be processed from right to left

x = (y = z);

start at the right 
y = z;

the assignment operator will return the new value of y
*/

//############
// Multiple Assignment Contd
//############

/*

 this new value of y is then used as the argument to the next assignment

 x = (y=z);

 after this statement is executed, the member of x and y will have the same value as in z

*/

//############
// Signature of Assignment Operator
//############

/*
The assignment operator returns by reference
Not by const reference
- Occasionally it is desirable to modify the returned value
- Standard library containters requiere this
- if we try to store an object in a container, and ist assignment operator returns
a const reference, the code will not compile.

The correct signature of the assignment operator is:

Test& Test::operator=(const Test&);

*/

//############
// Return value of Assignment Operator
//############

/*
operator = is a member function
It is passed a hidden pointer "this" to the object it was called 
We can get the modified object by deferencing the "this" pointer after performing the assignment
The compiler will return the object by reference

return *this;      // "this" is the address of the object being assigned to

*/

//############
// When to write an Assignment Operator
//############

/*
if we do not implement an assignment operator for our class, the compiler will "synthesize" one for us
- This will call the assignment operator of all the data members
- Usually, this is sufficient

We only need to write an assignment operator ourselves if we need something different from this default

This usually applies when the class manages resources
- The assiged class already has an object of the resource, which needs to be released properly
- if we just copy over it, there will be a resource leak
*/

//############
// Example of Synthesizied Assignment Operator
//############

/*
class Test{
int i;
string str;
public:
...

Compiler generated assignment operator
Assign to "this" by assigning to i
and calling std::string's assignment operator for str
returns the assigned-to object bv reference

Test& operator=(const Test& arg) {
    i = arg.i;
    str = arg.str;
    return *this;
}
};
*/


#include <iostream>
#include <string>

using namespace std;

class String{
    string s;
    public:
    // Constructor
    String(): s{""} {}
    String(const string& s): s{s} {}

    //Copy Constructor
    String(const String& arg): s{arg.s} {}

    //Assignment Operator
    String& operator=(const String& arg) {
        s = arg.s;
        return *this;
    }

    void print() {cout << s << endl;}
};

int main() {
    String w("World"s);   //Calls constructor
    String bang("Bang"s); //Calls constructor
    String bang2;
    bang = w;               
    bang2 = w;

    w.print();
    bang.print();
    bang2.print();

    return 0;
}




