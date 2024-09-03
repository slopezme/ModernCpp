//############
// Storing Lambdas
//############

/*
- lambda expressions are mainly used for implementing temporary functions
- however, lambda expressions are "first class objects" in C++
- We can store them in variables and pass them to a function
    - // Store the lambda expression in a variable
    auto is_longer_than = [max](const string& str){ return str.size() > max; };

    - // Pass this variable as the predicate
    auto res = find_if(cbegin(words), cend(words), is_longer_than);

- we must use auto here, as it is not possible to know the type of the compiler-generated functor
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void main1(){
    vector<string> words{ "a", "of", "words", "with", "collection",  "varying", "lengths"};
    int max{5};

    // Store the lambda expression in a variable
    auto is_longer_than = [max](const string& str){ return str.size() > max; };

    // Pass this variable as the predicate
    auto res = find_if(cbegin(words), cend(words), is_longer_than);

    // Display it
    if (res != cend(words))
        cout << R"(First word with more than )" << max << R"( letters long is ")" << *res << R"(")" << endl;
}


//############
// Returning Lambda from a Function call
//############

/*
- We can also return a lambda expression from a function
    -// Function which returns a lambda function

    auto greeter(const string& salutation){
        return [salutation](const string& name){
            return salutation + ", "s + name ;};
    }

- Calling this function will return a lambda expression which captures "salutation"
    - auto hello = greeter("Hello");

- Greet is a lambda which takes a name as argument and adds the salutation and adds th
salutation to it
*/
// Function which returns a lambda function
auto greeter(const string& salutation){
    return [salutation](const string& name){return salutation + ", "s + name ;};   // The lambda function
}

void main2(){
    // Store the lambda function in a variable
    auto greet = greeter ("Hello");

    // Call the lambda function
    cout << "Greetings: " << greet("students"s) << endl;
    cout << "Greetings: " << greet("James"s) << endl; 
}

//############
// Partial Evaluation
//############

/*
- In partial evaluation, data is processed in stages
    - e.g formatting pages in a document viewer
    - Reduces computation
    - Can make processing simpler
    - many applications in AI, database queries, scientific computing, etc

- We can use lambda expressions with capture to implement partial evaluation

To perform a greeting, we call greet() with a person's name as argument
    - // Call the lambda function
    cout << "Greetings: " << greet("students"s) << endl;    // "Hello, students"
    cout << "Greetings: " << greet("James"s) << endl;       // "Hello, James"
*/

//############
// Partial Evaluation using Lambda contd
//############

/*
- When we call greeter(), it performs a partial evaluation
    - It processes the salutation part of the greeting, but not the name
    - Code which issues a greeting only has to provide the name
    - It does not need to process the salutation, or know how it processes
    - The salutation processing is written once, insted of every time someone is greeted

- If we want a differetn salutation, we call greeter() with a different argument
- This will performa a different partial evaluation

auto greet_formal = greeter("Good morning"s);           // Formal greeting

cout << "Formal greeting: " << greet_formal("Dr Stroustrup"s) << endl;  // "Good morning, Dr Stroustrup"
*/

void main3(){
    // Store the lambda function in a variable
    auto greet = greeter ("Hello");

    // Call the lambda function
    cout << "Greetings: " << greet("students"s) << endl;
    cout << "Greetings: " << greet("James"s) << endl; 

    // Store the lambda function in a variable
    auto greet_formal = greeter("Good morning"s);

    // Call the lambda function
    cout << "Formal greeting: " << greet_formal("Dr Stroustrup"s) << endl;
}

//############
// Capturing by Reference Caveats
//############

/*
- Returning a reference to a local variable is dangerous

int&  func(){           // Dangling reference!
    int x{7};
    return x;
    }                   // x is destroyed when the function returns

- A lambda which captures by reference has a reference to the variable
- if we call the stored lambda after the captured variable has gone out 
of scope, we have a "dangling reference" problem
- When we capture by reference, we must make sure the captured variable is still
 valid when the lambda is called



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

