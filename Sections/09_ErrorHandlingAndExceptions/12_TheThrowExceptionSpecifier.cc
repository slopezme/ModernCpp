/*####################
# The No-Throw Guarantee
####################*/

/*
- The no throw guarantee means that an operation will not throw an exception
- When writing code that provides the basic or strong guarantee, it is helpful to know
that a sub operation will not throw
- none of the functions and operators in the core C++ launguage and library throw exceptions
apart from:
    - new
    - dynamic_cast
    - throw

*/

/*####################
# throw()
####################*/

/*
C++98 provided the thorw() exception specifier
- This comes after the functions parameter list
- The arguments list the exceptions that the function could throw
    - // Function with an exception list
    - // the function can throw NetworkConnectionError or DataError

    void func() throw(NetworkConnectionError, DataError) {
        ...
    }

- If the function throws an exception which is not in the list, the program is
immidiately terminated by default

*/

/*####################
# throw() with Arguments
####################*/

/*
- An empty argument list indicates that the function does not throw any exceptions
    -// Function that doest not throw exceptions
    void func() throw() {
        ...
    }

*/

/*####################
# Problems with throw()
####################*/

/*
- The list of exceptions is not checked by the compiler
- If the list of exceptions is incorrect, the program may be terminated unexpectedly

*/

/*####################
# Removal of throw() from C++
####################*/

/*
- throw() has been removed from the laguage and replaced by noexcept

    - throw() was deprecated in C++11
    - throw() with an argument list was removed in C++17
    - throw() with an empty argument list was removed in C++20


*/
