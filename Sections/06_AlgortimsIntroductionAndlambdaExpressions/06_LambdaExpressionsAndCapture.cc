//############
// Lambda Expressions and Variables
//############

/*
- A lambda expression hass access to non local variables
- It aslo has access to static variables in the same scope
- By default, lambda expressions have very limited access to local variables
    - A lambda expression can access local variables which are references and were 
    initialized with a constant expression
    - A lambda expression can read, but not modify, local variables which are
    integers or enums and were initiliazed with a constant expression
    - Compilers often do not implement this properly
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int global{ 99};                                 // Non local variable

void main1(){                                      // Scope containing the lambda expression
    static int answer{42};                       // Static variable in containing scope 
    const int one{1};                            // Local Variable in containing scope    
    const int& r_one{one};                       // Local Variable in containing scope

    [] () {                                      // Lambda expression
        cout << global << endl;                  // Lambda body access non local variable
        cout << answer << endl;                  // Lambda body access static variable
        //Does not compile with visual C++
        // cout << one << endl;                  // Lambda body can read local variables, provided ...
        // Does not compile with visual C++, gcc or clang
        // cout << r_one << endl;                // Lambda body can read local variables, provided ...
        };                                       // End of lambda expression                        
}                                                // End of containing scope


//############
// Lambda Expressions and Local Variables
//############

/*
- If a lambda expression neeeds full access to local variables, it can "capture" them
- This is done by putting the local variables insided the [] 

int n{2};
[n](int arg){ return (n * arg); }           // Captures the local variable n

int x{2}; y{3};
[x, y](int arg){ return (x * arg + y); }    // Captures the local variables x and y
*/

//############
// Variable Capture Examples
//############

/*
- The find_if() algorithm returns an iterator to the first element for which itrs predicate returns true

auto res = find_if(cbegin(words), cend(words), 
            [](const string& str){ return str.size() > 5; });

- Instead of hard - coding the number 5, we can use a variable and capture it

int n{5};
auto res = find_if(cbegin(words), cend(words), 
            [n](const string& str){ return str.size() > n; });

*/

void main2(){
    std::vector<string> words{ "a", "collection", "of", "words", "with", "varying", "lengths"};

    int n{5}; // Local variable
    // Find the first element with more than 5 characters
    auto res = find_if(cbegin(words), cend(words), 
            [n](const string& str){ return str.size() > n; });   // Lambda expression captures n

    //  Display it
    if (res != cend(words)){
        cout << R"(First word with more than 5 characters is ")" << *res <<  R"(")" << endl;
    }
}



//############
// lambda Capture implementation
//############

/*
- A lambda with capture is implemented as a "functor with state"

    - The functor has a private data member which stores the variable
    - it is initialized in the functor's constructor
    - The data member is available in the operator () body
- By default, the captured variable is passed to the functor's constructor by value
    - The functor has its own copy of the captured variable
    - "Capture by value"
- By default, the data member is const
    - The function call operator cannot modify its copy of the variable
*/

class ge_n{
    private:
        const int n;
    public:
    ge_n(const int n) : n{n} {}

    bool operator()(const string& str) const{
        return str.size() > n;
    }
};

void main3(){
    std::vector<string> words{ "a", "of", "words", "with", "collection",  "varying", "lengths"};

    int n{3}; // Local variable
    // Find the first element with more than 5 characters
    auto res = find_if(cbegin(words), cend(words), ge_n{n});   // Lambda expression captures n

    //  Display it
    if (res != cend(words)){
        cout << R"(First word with more than )" << n << R"(  letters long is ")" << *res <<  R"(")" << endl;
    }
}

// Find the idx

void main4()
{
    std::vector<string> words{ "a", "of", "words", "with", "collection",  "varying", "lengths"};

    int n{3} , idx{-1};                  // Add another variable for idx
    // Find the first element with more than 5 characters

    // This not work, idx is captured as const int, so it cannot be modified
    // auto res = find_if(cbegin(words), cend(words), 
    //         [n, idx](const string& str) { ++idx; return str.size() > n; });   // Lambda expression captures n

    auto res = find_if(cbegin(words), cend(words), 
            [n, idx](const string& str) mutable { ++idx; return str.size() > n; });   // Lambda expression captures n

    // idx is a copy, so the original value is not changed

    //  Display it
    if (res != cend(words)){
        cout << R"(First word with more than )" << n << R"(  letters long is ")" << *res <<  R"(")" << endl;
        cout << "Index of the word is: " << idx << endl;
    }
}


int main(){
    cout << endl << "main1" << endl << endl;
    main1();

    cout << endl << "main2" << endl<< endl;
    main2();

    cout << endl << "main3" << endl<< endl;
    main3();

    cout << endl << "main4" << endl<< endl;
    main4();

    return 0;
}
