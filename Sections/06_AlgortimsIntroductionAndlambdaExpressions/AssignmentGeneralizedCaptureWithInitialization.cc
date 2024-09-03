/*
Consider the following code (do not compile it yet!)

int y = 1;
[y = y+1](int x) { return x + y; };
cout << y << endl;
Questions for this assignment
Explain what the code does.

What will be the result of calling the lambda expression with argument 5?

What will be displayed as the final value of y?

Write a program to check your answers.
*/

#include <iostream>
using namespace std;

int main() {
    int y = 1;
    auto f = [y = y+1](int x) { return x + y; };
    cout << f(5) << endl;
    cout << y << endl;
    return 0;
}

/*
- lambda expression creates auto y variable in its own body by assigning the value of y's main scope + 1  

- lambdas y value is 1+1 = 2

- y from outer scope is passed by value, so its value does not change

- lambda will returns x value + local lambda y value 

- print y value from outer scope,


*/