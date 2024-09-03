#include <iostream>


// ##################
// ### Namespaces ###
// ##################

/*
A namespace is used to group together logically related symbols
- typically done within libraries

The C++ standard Library defines the std namespace

The groups together the names of all the functions, types and variables defined by it
*/

// Why Namespaces?

/*
Large programs often include several libraries
- this can lead to name conflicts
- eg two libraries could define a class Test

One solution is to add a library - scepcific prefix to the name
- class abc_Test;               // In the Alpha Beta Corporation library
- class xyz_Test;               // In the Xylophone Zebra library

Putting in these prefixes is tedious and error-prone
C++ addresses this by using namespaces

We create a namespace using the namespace keyword, followed by the namespace name
we wish to use for the namespace

namespace abc {
    class Test {
        ...
    };
}

we puth the symbols we want to declare in this namespace inside the braces

Every symbol declared inside the namespace is part of the namespace, so will have the
namespace name automatically prefixed to it by the compiler

abc::Test t; // Declares a variable of type Test in the abc namespace

If we cant to use a symbol outside the namespace, we put abc:: in front of it


*/


// ########################
// ### Global namespace ###
// ########################

/*
if a name is not in any namespace, it is said to be in the "global namespace"
- if we define a symbol which is not in any namespace, the compiler assume
 it is in the global namespace

The global namespace has no name

If we want to specify that we are referring to the global namespace,
we use :: on its own before the name

class Test{...}   // Another definition of class Test (not in a namespace)

::Test t;          // Refers to the global namespace version of Test
 */


// ###########################
// ### Namespace Splitting ###
// ##########################


//namespaces can be split over different parts of the code, and even differente files

using namespace std;
namespace abc {
    class Test {                    // Definition of class Test in header
        private:
            int value;

        public:
            Test(int value);            // Declaration of constructor
            int doTest(int value) const;   // Corrected declaration of member function with return type
    };
}

namespace abc {
    Test::Test(int value) : value(value) {} // Definition of constructor in source file

    int Test::doTest(int value) const {     // Definition of member function in source file
        return value * 2;
    }
}

// when a symbol is defined a namespace, it "hides" any symbols outside the namespace with the same name

int x = 23;                         // x defined in the global namespace

namespace abc {
    int x = 42;                     // x defined in the abc namespace

    void func(){
        int x = 5;                  // x defined in the function
        cout << x << endl;          // Prints out 5
        cout << abc::x << endl;     // Prints out 42
        cout << ::x << endl;        // Prints out 23
    }

}


// ###########################
// ### Using Declarations ###
// ##########################

// A "using" declaration will bring a particular version of class Test into the global namespace

using abc::Test; // Now "Test" will refer to the abc::Test class

// This will make abc::Test available as "Test"

// Test        // Refers to abc::Test
// xyz::Test   // Refers to Xylophone Zebra Test
// ::Test      // Refers to the global namespace Test

//This takes effect from the using declaration until the end of the scope

// ###########################
// ### Using Directive   ###
// ##########################

// A "using" directive will bring everything from a namespace into the global namespace
// not food practive as it contradicts the point of having namespaces

using namespace std;       // Bring in all names from std namespace

// Now we can refer to std::cout as cout, and so on

void main(){
    cout<< "Hello, World!" << endl;
}
