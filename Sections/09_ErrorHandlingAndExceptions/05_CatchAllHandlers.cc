/*####################
# Catch all handlers
####################*/

/*
- We can write a catch handler with "..." as the exception type

- This can handle an exception of any type

    - Including built in types, library types and custom classes

try{
    throw 20;
}
catch(...){
    cout << "Caught an exception" << endl;
}

*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    try {

        vector<int> vec;
        cout << vec.at(2) << endl; // Throws an out_of_range exception
    }
    catch (std::exception &e) {
        cout << "Standard exception: " << e.what() << endl;
    }
    catch (...) {
        cout << "Caught an exception" << endl;
    }
}

/*####################
# uses of Catch All Handlers
####################*/

/*
- it can be useful to put a catch all handlers after the other catch block
- This will catch any exceptions that have been misses

try {
    // Code that may throw exceptions
}
catch (const NetworkConnectionError &e) {
    // Handle network errors
}
catch (const std::exception &e) {
    // Handle other standard library exceptions
}
catch (...) {
    // Handle all other exceptions
}

It can also be useful to put catch all handlers in the main function
    - If the handler is executed, we will know that an exception was thrown but not caught
    - This will tel us that there are missing catch blocks, or errors in the code

*/


/*####################
# Pros and Cons of Catch All Handlers
####################*/

/*
- A catch all handler is useful when testing
- however, it is not helpful when debugging
    - Allowing the debugger to trap the exception instead will give more useful information

- It is better to catch specific exceptions when possible
    - This will allow us to handle the exception in a more specific way
    - And provide more useful information to the user
*/