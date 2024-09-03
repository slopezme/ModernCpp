/*
The following code defines a lambda expression and evaluates it twice:

int x{42}, y{99}, z{0};
 
auto lam = [=,&z]() mutable { ++x; ++y; z = x + y; };
lam();
lam();
After executing this code, the resulting values of x, y and z will be one of the following:

x = 42, y = 99, z = 0

x = 42, y = 99, z = 141

x = 42, y = 99, z = 143

x = 42, y = 99, z = 145

x = 44, y = 101, z = 145

Questions for this assignment
Without writing any code, what do you expect the final values of x, y, and z to be?

Write a program to check your answer to the previous question. Check that your program compiles and runs correctly.

Explain your results.

*/

#include <iostream>


using namespace std;
int main(){
    int x{42}, y{99}, z{0};
 
    auto lam = [=,&z]() mutable { ++x; ++y; z = x + y; };
    lam();
    lam();

    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;

}