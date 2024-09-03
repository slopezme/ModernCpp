


// ###########################
// ### Function Pointer   ###
// ##########################

/*
A function's executable code is stored in memory

we can get a pointer whose address is the start of this code
*/
void func(int,int);
auto func_ptr = &func; // func_ptr is a pointer to the function func

// void (*func_ptr)(int,int) = &func; // alternative syntax

//funct_ptr is a pointer to a function that takes two ints and returns void
// we can use a type alias for a function pointer

using pfunc = void(*)(int,int);


// ###########################
// ### Callable Object   ###
// ##########################

/*
A function pointer is a "callable object"
- Behaves like a variable
- Can be called like a function

We can call the function by dereferencing the pointer

(*func_ptr)(1,2);

A function pointer is a "first class object"
- we can pass a function pointer as argument to another function
- we can return a function pointer from a call to another function

*/

#include <iostream>

using namespace std;
void func(int a, int b){
    std::cout << "func(" << a << "," << b << ")" << std::endl;
}

int main(){
    auto func_ptr = &func;
    // auto func_ptr = func; // alternative syntax

    (*func_ptr)(1,2);
    // func_ptr(1,2); // alternative syntax

    return 0;
}


// ###################################
// ### Passing a function pointer  ###
// ###################################

// we can pass a function pointer as an argument to another function

void some_function(int, int, pfunc);

//the function can call the pointed-to function in its body

void some_func(int x, int y, pfunc func_ptr){
    (*func_ptr)(x,y);
}

//we can return a function pointer from a function

pfunc other_func(){
    return &func;
}

using pfunc = void(*)(int,int);   // the * is not optional;

// typedef void (*)(const string&, const string&) pfunc; // older C++ syntax



int main2(){
    auto func_ptr = other_func();

    some_func(1,2,func_ptr);
}

// ###########################################
// ### pros and Cons of Function Pointers  ###
// ###########################################


/*
Function pointers were inherited from c
usefull for writing callbacks
- operating systems, GUI's, event-driven code
- provide a function that will be called when "something happens"

"Raw" pointer
- can be overwirtten, null or uninitialized

Ugly syntax

*/
