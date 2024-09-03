/*####################
# Catch Statements 
####################*/

/*
A catch block can only come after a try block 
• We can have more than one catch block for the same try block 
• If we want to handle exceptions with different static types, we add another catch
 block for each type 
• The exception will be handled by the first catch block that can handle it
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    try
    {
        vector<int> vec;
        cout << vec.at(2) << endl;
    }
    catch(const std::out_of_range& e)
    {
        cout << "Out of range exception: " << e.what() << endl;
    }
    catch(const std::exception& e)
    {
        cout << "Standard exception: " << e.what() << endl;
    }
}

/*####################
# Multiple Catch and Inheritance 
####################*/

/*
·
Normally we use the std::exception hierarchy
• To make this work as expected, we should put the catch blocks in reverse orderMultiple Catch and Inheritance  • The most derived class first
• The base class last
catch (const out_of_range& e) { ... } catch (const exception& e) { ... }
    - First block that matches out_of_range
    - Handles all other sub-classes of std::exception

*/

/*####################
# Writing an exception handler
####################*/

/*
The exception handler should take the exception object by reference 
· This allows polymorphism to work what() is a virtual member
 function Unless you need to modify the exception object, make it a const reference

*/

/*####################
# Writing an exception handler contd
####################*/

/*

· When the program is executing in a catch block, it may not be in a stable state

    - Avoid allocating memory
    - Avoid creating new variables
    - Avoid calling functions
    - If possible, only use variables of built-in type
• Never do anything that might throw a new exception
Keep the code simple


*/

/*####################
# Nested try/catch blocks
####################*/

/*
• We can put a try/catch block inside another try block
· If the inner catch block cannot handle the exception, the program will
look for one in the outer catch block

try {
}
- // Outer try block
try {
}
- //Inner try block
catch (const std::bad_alloc& e) { ... }
catch (const std::exception& e) { ... }

*/

/*


#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> vec;

    try {
        try {
            cout << vec.at(2) << endl;
        }
        catch (const std::out_of_range& e) {
            cout << "Out of range exception: " << e.what() << endl;
        }
    }
    catch (const std::exception& e) {
        cout << "Standard exception: " << e.what() << endl;
    }



}
cout<<"Exception caught: << e.what() << endl;
// Print out a description of the exception



*/

/*####################
# Catching Exceptions in different functions
####################*/

/*
We sometimes want an exception to be handled in a different function from where it happened

    void getFile(){
    ... 
    }

    void processFile(){
    getFile();
    }

Here, we want any expcetions from getFile() to be handled in processFile()


*/