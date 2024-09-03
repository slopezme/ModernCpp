//############
// lambda expression introduction
//############

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//Define a functor for the predicate
class is_odd{
    public:
        bool operator() (const int n) const{return (n % 2 == 1); }
};

void main1() {
    vector<int> vec{ 3, 1, 4, 1, 5, 9};

    // pass a functor object
    auto odd_it = find_if(cbegin(vec), cend(vec), is_odd());

    // odd_it will be an interator to the first odd element (if there is one)
    if (odd_it != cend(vec))
        cout << "First odd element is: " << *odd_it << endl;
}

//############
// lambda expression 
//############

/*
- modern C++ has lambda expressions
- These can be thought of as anoniymous local functions
- Similar to "closures" in other languages
*/

//############
// implementation of Lambda expression
//############

/*
- When the compiler enconters a lambda expression, it will generate code that defines a functor
    - This function will have a unique name chosen by the compiler
    - This function call operator of the functor will have the same body as the lambda expression
    - It will have the same return type as the lambda expression

- The compiler will add code to create a functor object

*/

//############
// lambda Expression Syntax
//############

/*
- lambda exrepssions are anonymous and defined inline
- To define a lambda expression, we put[] for the function name
- we write the functions arguments in the usual way
- we write the function body the same way as for an inline function
- if we write this as a single statement that returns a valie, 
the compiler will always be able to deduce the return type

[](int n){return n % 2 == 1;}   //Return type deduces as bool

- This statment causes the compiler to create a functor object
- The functor will be quievalent to is_odd
*/

//############
// Example of lambda expression
//############

// Sort the data, using lambda expression as the predicate

//auto odd_it = find_if(cbegin(vec), cend(vec), [](int n){return n % 2 == 1;});

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void main2(){
    vector<int> vec{3, 1, 4, 1, 5, 9};

    // pass a lambda expression
    auto odd_it = find_if(cbegin(vec), cend(vec), [](int n){return n % 2 == 1;});

    // odd_it will be an iterator to the first odd element (if there is one)
    if (odd_it != cend(vec))
        cout << "First odd element is: " << *odd_it << endl;
}

//############
// lambda expression Return Type
//############

/*
- In C++11, the return type is only deduced if the lambda expression is a single statement that returns a value
    - Otherwise, the return type is deduced as void
- For more complex expressions, we need to provide a trailing return type
    [](int n) -> bool{...
    }
- In later version, the return type is always deduced automatically
    - In C++14, it must be the same in all return paths
    - In C++17, this is no longer requiered
*/


int main(){
    cout << endl << "main1" << endl;
    main1();
    cout << endl << endl << "main2" << endl;
    main2();
    cout << endl;
    return 0;
}
