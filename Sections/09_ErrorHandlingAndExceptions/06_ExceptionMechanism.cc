
/*####################
# Exception throwing
####################*/

/*
- when an exception is thrown, severl thing happen:
- The thrown object is copied into a special area of memory
- This are is set up by the compiler
    - It is accessible by any catch block which can handle the object type
- Every local variable in scope is destroyed
    - Including the original exception object

- the programm immediately leaves this scope
    - It does not execute any further instructions in the scope

*/

/*####################
# Stack unwinding
####################*/

/*
- The program will look for a catch block that can be handle the exception
- If it cannot find one, it will immediately destroy all local variables and
 exit the current scope

 - It then looks in the enclosing scope
 - This continues until it finds a suitable handler
    - If it reaches main() without finding one, the program calls std::terminate()
- This process of repeatedly destroying local variables  and exiting the current scope
is known as "stack unwinding"

 */

/*####################
# Rethrowing an Exception
####################*/

/*
- When a suitable handler is found, the program executes the code in it and continues
- Normally, it will proceed to the next instruction after the try-catch block and 
continue executing the program from there
- however, the handler can "rethrow" the exception
- In this case, the exception will be handled again, but in a handler belonging to 
another try-catch block

- To rethrow the same exception object,  use throw with no argument
    - If we give an argument, it will throw a copy of that object
- Since the exception is thrown outside the current try block, the program will regard
this as completely new exception

- A fresh process of stack unwinding begins


*/

#include <iostream>
#include <vector>

using namespace std;

void func(const vector<int> &vec) {
    try {
        cout << vec.at(2) << endl; // Throws an out_of_range exception
    }
    catch (const std::out_of_range &e) {
        cout << "Out of range exception: " << e.what() << endl;
        throw; // Rethrow the exception
    }
}

int main() {
    vector<int> vec;
    try {
        func(vec);
    }
    catch (const std::exception &e) {
        cout << "Standard exception: " << e.what() << endl;
    }

}

/*####################
# Application of Rethrowing an Exception
####################*/

/*
- Rethrowing exceptions can be used to
    - Log the exception at the point where it happens
    - Add extra information to the exception object
    - convert the exception to a higher level type

catch(TcpHandShakeFailure &e) {
    logger<< e.what() << "\n";
    e.remoteHost = remoteHost;
    --// throw NetworkConnectionError(e);
    throw;
}

*/