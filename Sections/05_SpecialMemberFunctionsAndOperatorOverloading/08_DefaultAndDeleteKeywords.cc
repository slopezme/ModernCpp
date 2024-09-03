
//############
// Default member functions
//############

/*
modern C++ allows programmers to foce the compiler to synthesize special member functions

this is done by putting = default after the function parameter list

class Test{
public
Test() = default;                               // Synthesize default constructor
Test(const Test& other) = default;              // Synthesize copy constructor
Test& operator=(const Test& other) = default;   // Synthesize assignment operator
];
...
};

*/

#include <iostream>

using namespace std;

class Test{
    public:
    Test() = default;
    Test(const Test& other) {cout << "Copy Constructor called" << endl;}
};

Test func() {
    return Test();
}

void main1() {
    cout << "Calling func" << endl;
    Test test = func();
    cout << "Returned from func" << endl;
}

//############
// Advantages of default member functions
//############

/*
- Easier to see which special member functions the class has
- Documents that the member functions has been deliberately defaulted
- Avoids writing tedious code
- If data members are added or removed, the compiler will automatically update the definition
*/

//############
// making a class uncopyable
//############

/*
In traditional C++, we could prevent objects from being copied by making the copy 
constructor and assignment operator private
*/

class Test2{
private:
    Test2(const Test2& other);
    Test2& operator=(const Test2& other);
public:
    Test2() {}
};

void main2() {
    Test2 t1, t2;
    //Test t3(t1);           // Error: copy constructor is private
    //t2 = t1;                // Error: assignment operator is private
}

//############
// Delete member functions
//############

/*
In modern C++, we can do this by declaring the copy constructor and assignment operator as "= delete"
*/

class Test3{
public:
    Test3() {}
    Test3(const Test3& other) = delete;
    Test3& operator=(const Test3& other) = delete;
};

void main3() {
    Test3 t1, t2;
    //Test3 t3(t1);           // Error: copy constructor is deleted
    //t2 = t1;                // Error: assignment operator is deleted
}

//############
// Deleted Functions
//############

/*
-A deleted function is defined, but cannot be called
- If a deleted functions is called, the compiler will give an error
- Unlike = default, any function can be deleted, even non-member functions
- however, mostly used for copy oeprators and default constructors
   - Sometimes used for conversion operators and overloaded member functions
*/

//############
// Special Functions syntehsized as deleted
//############

/*
- Sometimes the compiler is not able to synthesize the default constructor and copy operators with "= default"
- usually this is when the class has a member that does not support it
    - For the default constructor, if the class has a member that cannot be default initialized

Also if the class has a member whose destructor is deleted or inaccessible
- this prevent the creation of objects that cannot be destroyed

- If the default version doest not work, they will be synthesized with "= delete"

*/


//############

int main() {
    cout << "main1" << endl;
    main1();

    cout << "\n main2" << endl;
    main2();

    cout << "\n main3" << endl;
    main3();
    return 0;
}