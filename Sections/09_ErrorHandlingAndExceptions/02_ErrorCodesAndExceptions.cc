/*####################
# Error Handling 
####################*/

/*
- Often it is useful to handle errors in a different part of the code from where the error
occurred

- How do we transfer the information about the error?
*/

/*####################
# Error Codes
####################*/

/*
In C, the only way to communicate an error condition is with an error code
    - The function returns a coded number that corresponds to an error
    - The caller checks the return value
    - The caller can handle the error itself
    - Or return the error code to its own caller
    - Or return a different error code

When an error occurs, the function returns a value corresponds to the error

-//In get_data()
if (!file)
    return ERROR_FILE_NOT_FOUND;

- This is checked by the caller     
    - In get_data's caller

    int retval = get_data();

    switch(retval)
    {
        case ERROR_FILE_NOT_FOUND:
            -// Handle the error
        ...
    }


*/

/*####################
# Disadvantages of Error Codes
####################*/

/*
- Error codes make the code more complicated
    - Every potential error situation requieres an if statement, a return statement
    and perhaps a clean-up code
    - The caller has to check the returned value against every error code that the function
    could return

- Error codes often cause maintenance problems
    - Large switch statements which need to be kept up to date and in sync
    - Adding new error code requieres changes to other parts of the code

- Error codes do not work well with callback functions
- C++ constructors cannot return an error code

*/

/*####################
# Exception
####################*/

/*
- C++ provides "exceptions"
    - Code which could cause a run time error is put inside its own scope
    - If an error occurs, create an "exception" object and exit the current scope
    - Find a "handler" for the exception, depending on the type of exception
    - The handler processes the exception object

- the programmer specifies the type of the exception object and provides a handler for it

- The programmer specifies when to create the exception object

- The compiler will generate the code to create the exception object and invoke the correct
handler for it
*/

/*####################
# Advantages of Exceptions
####################*/

/*
- Exceptions avoid a lot of tedious and error-prone coding
    - The compiler and the runtime will take of the control flow
    - The type system prevents us from using the wrong handler
    - No switch statement and no error codes to maintain

- If there is no suitable handler, the program terminates immediately
- An exception object can convey more information that a number
- constructor can throw an exception


*/


/*####################
# Disadvantages of Exceptions
####################*/

/*
- handling exceptions requieres extra code to be executed at runtime
- throwing an exception takes much longer than returning an error code
    - The normal path takes the same time

- In some environments, the overhead from expceptions is not acceptable
    - real time systems, embedded systems, games

- Some C++ coding standards forbid exceptions
    - Early implementations were buggy and inefficient

- Some "boilerplate" code 
    - Can be minimized with RAII

*/



