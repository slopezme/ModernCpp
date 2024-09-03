
//############
//Callable objects and Functional Programming
//############

/*
- Procedural programming involves a sequence of commands
    - e.g processing a vector
    - Loop which processes an element on each iteration

- Functional programming involves a tree of function calls which transform data
    - e.g. processing a vector
    - A function which processes an element
    - Function "applies" that function to each element
- Callable objects are used to implement functional programming in C++
*/

//############
//Function Pointer
//############

/*
- C allows us to create callable objects
    - Define a non member function 
    void func(int,int);

    - Obtain a pointer to this function
    void(*funct_ptr)(int,int) = func;

    - The function pointer is a data variable
    - It can be called like a function

    funct_ptr(1,2);    // Calls func() with arguments 1 and 2

*/

//############
// Functors
//############
/*
- C++ classes can define a function call operator
- This allows us to make callable objects
    - An object of the class is a data variable
    - The object can be called like a function
- A C++ class which implements a function call operator is called a "functor"
*/

//############
// Function Call Operator summary
//############

/*
- Prototype
    some_type operator()(....);     // Can take any number of arguments and return anything
- How to invoke it
    test(...);                      // Called like a function
- Called as
    test.operator()(...);           // Called like a method
- The function call operator can take any type   
arguments and can return a value of any type
*/

#include <iostream>

using namespace std;

class evenp{
    public:
        bool operator()(int x) {
            return x % 2 == 0;
        }
};


//############
// Functors with state
//############

/*
- Functors are classes, so they could contain member functions and data members
- To keep things simple, they should only be used to "wrap" functions
- They can however have data members to store values which need to be kept between functions calls
    - This is known as "state"
*/

#include <vector>
class divisible {
    private:
        int divisor{1};
    public:
        divisible(int d) : divisor{d} {}
        bool operator() (int n) {
            return n % divisor == 0;
        }
};

void do_it(const vector<int>& vec, divisible is_div){
    for(auto v: vec){
        if(is_div(v)){
            cout << v << " is divisible" << endl;
        }
    }
}


int main() {
    cout << "Function Call Operator" << endl;
    evenp is_even;                      // Create a functor object
    if (is_even(6))                     // Call the functor object with argument 6
        cout << "6 is even" << endl;


    cout << "Functors with state" << endl << endl;

    vector<int> numbers {25, 26, 27, 28, 29, 30};

    cout << "Vector" ;
    for (auto n: numbers) {
        cout << n << ", ";
    }
    cout << endl;

    // Create a divisible object with member variable equal to 3
    cout << "Finding elements which are divisible by 3\n";

    divisible divisible_by_3(3);
    // Pass this as argument to the function call
    do_it(numbers, divisible_by_3);



}



