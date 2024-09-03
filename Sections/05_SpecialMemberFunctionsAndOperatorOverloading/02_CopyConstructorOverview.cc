
//############
// Copy Constructor Overview
//############

/*
The copy constructor is a specialized version of the constructor
it only takes one argument
- an object of the same class

It uses the axisting object of the class to create a new object

Test(const Test& other);

the copy constructor is automatically invoked when we initialize a new object 
from an existing object of the same class

Test test1(x,y); // Create Test object test1 by calling the Test's constructor

Test test2{test1}; // Create Test object test2 and initialize it with test1
Test test3 = test1; // Create Test object test3 and initialize it with test1

*/

//############
// Copy Constructor and Function Calls
//############

/*
The copy constructor may also be invoked in function calls
When we pass an argument by value
- A new object is created on the called functions stack which is a copy of the argument

When we return a local variable by value
- A new object is created in the function's return space which is a copy of the local variable

However, compilers can perform optimizations which reduce the amount of copying in function calls
- The copy constructor may not be called in some cases


*/

//############
// When to write a Copy constructor
//############


/*
if we do not implement a copy constructor for our class, the compiler will
" sinthesize " one for us
- this will copy all the data members
- Usually, this is sufficient

we only need to wirte a copy constructor ourselves is we need something different from this default

This usually applies when the class manages resources
- the new object needs to have its own version of the resource
- this involves acquiring a new resource and copying the data from the old resource to the new resource
*/

//Example of synthesizing a copy constructor

/*
class Test{
int i;
string s;
public:
...

Compiler generated copy constructor
initialize "this" by copying i
and calling std::String copy constructor for str
Test(const Test&  arg): i{arg.i}, s{arg.s} {}

};
*/  

#include <iostream>
#include <string>

using namespace std;
using namespace std::string_literals;

class String {
    string s;
    public:
    // Constructor
    String(const string& s): s{s} {}

    //Copy Constructor
    String(const String& arg): s{arg.s} {}

    void print(){cout << s << endl;}
};

int main() {
    String w("World"s);   //Calls constructor
    String bang{w};       //Calls copy constructor
    String ban2 = w;      //Calls copy constructor

    cout << "w = "; w.print();
    cout << "bang = "; bang.print();
    cout << "bang2 = "; ban2.print();
}


