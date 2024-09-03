/*####################
# noexcept keyword
####################*/

/*
- C++11 has the noexcept keyword
- This is equivalent to throw() with an empty list

    -// Function that doest not throw exceptions
    void func() noexcept {
        ...
    }

- If an exception is thrown, the program terminates immediately
*/

/*####################
# the No throw Guarantee
####################*/

/*
- noexcept is a promise to the caller that the function will not throw an exception
- A noexcept function provides the no throw guarantee
- This is helpful if we are writing exception safe code which calls the function

*/


/*####################
# Performance advantages of noexcept
####################*/

/*
- noexcept help the compiler generate better optimized code
    - more information about how the code behaves
    - not requiered to generate code for "stack unwinding"
- Modern C++ has optimized exception safe
- Standard library algorithms will only use these operators if they are declared noexcept
- Otherwise they will call the non-optimized versions which are slower


*/

/*####################
# when to use noexcept
####################*/

/*
- noexcept should be used where possible
    - if we are certain a function will not throw an exception
    - Or we cannot do anything useful if an exception is thrown (automatic termination)

Examples
    - std::swap() olverloads
    - Destructors
*/

/*####################
# No overloading on noexcept
####################*/

/*
- A function must either be noexcept or not be noexcept
    void func();
    void func() noexcept;       // Error - cannot overload on noexcept

- noexcept is part of the function type, but is not part of the function signature

    - similar to the return type

*/

/*####################
# noexcept and inheritance
####################*/

/*
- "noexcept-ness" is inherited
    - if a virtual functiion is noexcept in the base class, overrides in the derived class
    must be noexcept
    - Inheriting constructors will be noexcept if the base class constructor is noexcept
    - Synthesized speacial member functions will be noexcept if the base class version is noexcept

- A child can add "noexcept-ness", but not remove it
    - A virtual function in the base class which may throw can be overridden by an
    noexcept member function

*/