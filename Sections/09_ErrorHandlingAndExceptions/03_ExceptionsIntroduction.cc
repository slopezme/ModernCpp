#include <vector>
#include <iostream>

using namespace std;

// int main(){
//     vector<int>  vec;
//     cout << vec[2] << endl;         // Invalid element access - undefined behavior
//     //cout <<vec.at(2) << endl;     // Invalid element access -  error condtion
//     cout << "Finished" << endl;
// }

/*####################
# std::exception
####################*/

/*
- Any type can be used for an exception object, including built-in types
- C++98 added the std::exception class to the lenguage
- this provides a consistent interface to exceptions
- std::exception is the base class of an inheritance hierarchy
- It has a number of subclasses
    - Including std::out_of_range
- It has a what() virtual member function
    - This returns a C-style string describing the exception

*/

/*####################
# Try Block
####################*/

/*
- The exceptions mechanism some code to manage exceptions at runtime
- This code is added by the compiler, but we need to tell the compiler to generate it
- To do this we put code that could throw inside a "try" block


vector<int> vec;

try
{
    cout << vec.at(2) << endl;
}
catch(const std::exception& e)
{
    cout << "Standard exception: " << e.what() << endl;
}
*/

/*####################
# Catch Block
####################*/

/*
- the code to handle the exception 
- The type of ecxeption we are going to handle goes in brackets after the catch keyword
- if we put a base class here, all its subclasses will be handled as well
- if we put a reference to base, dynamic binding will be used

-// Catch block that can handle std::exception abd all its subclasses
catch(const std::exception& e)
{
    cout << "Standard exception: " << e.what() << endl;
}


*/

int main(){
    vector<int> vec;

    try
    {
        cout << vec.at(2) << endl;
    }
    catch(const std::exception& e)
    {
        cout << "Standard exception: " << e.what() << endl;
    }
    cout << "Finished" << endl;
}


/*####################
# Uncaught Exceptions
####################*/

/*
- if an exceptions is not handled by any of the catch blocks after the try block, 
the program will try to find one in the "enclosing" scope
    - If the try/catch block is in a function body, it will look for handler
    in the function
- If it does not find one, it will jump out of the current function and look 
for a handler in the functions caller
- if it does still not find one, it jumps to that functions caller, and so on
- if there is no suitable handler, the program termiantes

*/