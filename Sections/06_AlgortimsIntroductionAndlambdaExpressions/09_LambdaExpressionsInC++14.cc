//############
// generic lambda Expressions
//############

/*
- In C++14, the compiler can always deduce the return type of a lambda expression
    - In effect, the return type is implicitly auto

- We can also use "auto" for the type of the arguments to the lambda expression
    - These are known as "generic lambdas" or "polymorphic lambdas"
    - The most requested featured in C++14!
*/

//############
// Generic Lambda Example
//############

/*
- the compiler will deduce the argument types from the way the lambda expression is called
- It will use the same rules as for a template function

    - // The arguments of func can ahve any type
    - // So long as the + operator is defined for them

    auto func = [](auto a, auto b){return a + b;};

    func(1, 2);             // Arguments deduces as int
    func(1.1, 2.2);         // Arguments deduces as double
    func("str1", "str2");   // Arguments deduces as std::string
 */

#include <iostream>
#include <string>

using namespace std;

void main1(){
    string str1{"Hello, "};
    string str2{"World!"};

    auto func = [](auto a, auto b){return a + b;};

    cout <<  "Calling func(2,5) gives " << func(2, 5) << endl;
    cout <<  "Calling func(3.141, 4.2) gives " << func(3.141, 4.2) << endl;
    cout << R"(Calling func("str1", "str2") gives ")" << func(str1,str2) << R"(")" << endl;
}

//############
// Generic Lambda implementation
//############

/*
- the compiler generates a functor with a templated function call operator

class lambda_func{
    public:
        template <typename T>
        T operator()(T a, T b) const{return a + b;}    // lambda expression body
};

-// Create functor object, instantiate its function call operator and call it
lambda_func()(2,5);
*/

//############
// local Variable in Lambda
//############

/*
- In C++14, we can create variables in the capture specifier

[y=2](int x){return x + y;}    // y is a local variable in the lambda expression

- these variables are local to the lambda body
- Tehse variables are implicity "auto" and must be initialized
- They can be mixed with other captures

[=, &v, y=2]
*/

void main2(){
    auto add_two = [y=2](int x){return x + y;};
    cout << "Calling add_two(2) gives " << add_two(2) << endl;
    cout << "Calling add_two(5) gives " << add_two(5) << endl;
}


//############
// generalized capture with initialization
//############

/*
- these lambda-local variables can be initilized from captures

    int z = 1;                                  // Scopes local variable z
    [y = z + 1](int x){return x + y;}           // Lambda bodys local variable y

- No special sintax is neeeded to capture z from the enclosing scope
- note that z is in the containing scope, while y is in the scope of the lambda body
*/

void main3(){
    int z = 1;
    auto add_z = [y = z + 1](int x){return x + y;};

    cout << "Calling add_z(2) gives " << add_z(2) << endl;
    cout << "Calling add_z(5) gives " << add_z(5) << endl;
}

//############
// generalized lambda capture implementation
//############

/*
- the compiler will generate a functor with a provate member which is initialized using the capture code

template<typename T>
class functor{
    T y;
    public:
        functor(T z) : y{z + 1} {}                  // Initialize our y using capture expression
        T operator()(int x)  {return x + y;}        // lambda expression body
};

- the compiler the instantiates the functor and calls it

    functor<int> func(z);               // Initialize functor using outer scope z 
    func(x);                            // Call it
*/

//############
// Capture by Move
//############

/*
- Generalized lambda capture allows capture by move
- this was the 2nd most requested feature in C++14!
*/



int main(){

    cout << endl << "main1" << endl << endl;
    main1();

    cout << endl << "main2" << endl << endl;
    main2();

    cout << endl << "main3" << endl << endl;
    main3();
    return 0;
}   


