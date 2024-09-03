
//############
// Capture by reference
//############

/*
To change a captured variable, we can capture it by reference
- To do this, we put & before the variable name in the capture list

int n{5};
[&n](const string& str){ return str.size() > n; }
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void main1(){
        std::vector<string> words{ "a", "of", "words", "with", "collection",  "varying", "lengths"};

    int n{3} , idx{-1};                  // Add another variable for idx
    // Find the first element with more than 5 characters

    // This not work, idx is captured as const int, so it cannot be modified
    // auto res = find_if(cbegin(words), cend(words), 
    //         [n, idx](const string& str) { ++idx; return str.size() > n; });   // Lambda expression captures n

    auto res = find_if(cbegin(words), cend(words), 
            [n, &idx](const string& str) mutable { ++idx; return str.size() > n; });   // Lambda expression captures n

    // idx is a copy, so the original value is not changed

    //  Display it
    if (res != cend(words)){
        cout << R"(First word with more than )" << n << R"(  letters long is ")" << *res <<  R"(")" << endl;
        cout << "Index of the word is: " << idx << endl;
    }

}

//############
// lambda Capture Implementation
//############

/*
- A lambda with capture by reference is also implemented as a "functor with state"
- however, the member variable is a reference to the captured variable
- The captured variable will be passed to the functor's constructor by reference

    - Ifs function call operator can modify the captured variable through the reference
    - "Capture by reference"
*/

class ge_n{
    private:
        const int n;
        int& idx;
    public:
    ge_n(const int n, int& idx) : n{n}, idx{idx} {}

    bool operator()(const string& str) const{
        ++idx;
        return str.size() > n;
    }
};

void main2(){
    vector<string> words{ "a", "of", "words", "with", "collection",  "varying", "lengths"};

    int max{5}, idx{-1};
    auto res = find_if(cbegin(words), cend(words), ge_n{max, idx});

    // Display it
    if (res != cend(words)){
        cout << R"(First word with more than )" << max << R"(  letters long is ")" << *res <<  R"(")" << endl;
        cout << "Index of the word is: " << idx << endl;
    }

}

//############
// Implicit Capture
//############

/*
- we can make a lambda function capture all variables in scope
- This is known as "implicit capture"
    - [=] will capture all variables by value
    - [&] will capture all variables by reference

- Capturing all local variables by reference can make the code difficult to maintain
    - The lambda body could moify any variable in scope
- usually it is safer to capture by reference only those variables which lambda function needs to alter

[=, &ix] will captures x by reference, all others by value

- To make sure that a and b are not altered

[&, =a, =b]  will capture a and b by value, all others by reference 
*/

//############
// lambda Functions and Member Functions
//############

/*
- A member function is called with an extra argument which is a pointer to the class instance it is being called on

test.do_it()

- // Called as Test::do_it(&test);
- // &Test is available in the member function body as "this"

- In effect, "this is a varaible in the scope of the member function
- When we have a lambda expression inside a member function,  it is allowed to capture "this"
- This allows the lambda expression to access data members and call other member functions of the class
*/

//############
// Capturing "this"
//############

/*
- To capture the class object we puth [this] , [&] or [=] in the capture list
    - [=this] and [&this] are not allowed
- These all capture the object by reference!

class Test{
    int time{0};                        // Data member
    void countdown(){                   // Member function which calls a lambda expression    
    [this]()}                           // Capture class
    if (time > 0)
        cout << time << endl;
    else if (time == 0)
        cout << "Lift off!" << endl;
        --time;                         // Modify class data member
    }();                                // Call the lambda expression   
};
*/

class Test{
    int time{10};                        // Data member
    public:
        void countdown(){                   // Member function which calls a lambda expression    
            [this](){                       // Capture class
                if (time > 0)
                    cout << time << endl;
                else if (time == 0)
                    cout << "Lift off!" << endl;
                --time;                         // Modify class data member
            }();                                // Call the lambda expression   
        }
};

void main3(){
    Test test;
    for (int i = 0; i < 12; ++i)
        test.countdown();
}

//############
// Capturing "this" Continued
//############

/*
- In C++17, we also have [*this]
- This will capture the object by value
    - The lambda expression has an immutable copy of the object
    - This prevents if from accidentally changing the object

    [*this](){                          // Capture class by value
        if (time > 0)
            cout << time << endl;
        else if (time == 0)
            cout << "Lift off!" << endl;
        --time;                         // Modify class data member
    }();                                // Call the lambda expression
    }
*/

class Test2{
    int time{10};                        // Data member
    public:
        void countdown(){                   // Member function which calls a lambda expression    
            [*this](){                       // Capture class by value
                if (time > 0)
                    cout << time << endl;
                else if (time == 0)
                    cout << "Lift off!" << endl;
                //--time;                         // object is read only, time cannot be modified
                                                  // if the expression is declared as mutable, it compiles,
                                                  // but the class object is wont be modified
            }();                                // Call the lambda expression   
        }
};



int main(){
    cout << endl << "main1" << endl << endl;
    main1();

    cout << endl << "main2" << endl << endl;
    main2();

    cout << endl << "main3" << endl << endl;
    main3();

    return 0;
}
