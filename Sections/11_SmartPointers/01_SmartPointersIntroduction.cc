/*####################
# Traditional Pointers
####################*/

/*
The "traditional" pointer was inherited from C
    - it is a built-in type
- A pointer variable stores a binary number which represents an address in memory
    - Can represent the address of a stack variable (e.g function argument)
    - can be used to mamange memory allocated ont he heap (e.g. new, delete), typically 
    for variable - length arrays
    - Can be used to implement polymorphism (Base * pb = new Derived;)
*/

/*####################
# Drawbacks of Traditional Pointers
####################*/

/*
- No concept of ownership
    - Any code that uses a pointer can reassing it, overwrite it or invalidate it
- no destructor
    - Allocated memory can be released twice, or not at all

- From C++11, traditional pointers are very rarely needed
    - For working with stack memory, we can use references instead of pointers
    - We can use std::vector instead of variable - sized arrays
    - we can use "smart" pointers for working with heap memory
    - for dynamic binding, we can use smart pointers or references

*/

/*####################
# Smart Pointers
####################*/

/*
- Smart pointers are classes which encapsulate allocated memory
    - The class has a private data member which is a pointer to the memory
    - the smart pointer object has ownership of the allocated memory
    - The allocated memory can only be accessed through public member functions
    - pointer arithmetic is not allowed

- Smart pointers are implemented usin RAII
    - The memory is allocated in the constructor and released in the destructor

- Smart pointers save programmers a lot of work!
    - Both when coding and debugging
*/

/*####################
# std::auto_ptr
####################*/

/*
- first attempt at a smart pointer. Appeared in C++98
- It trasnferred the allocated memory when copied
    - The copied auto_ptr object has its pointer set to null
- This caused problems for code which assumes that a copied-from object is still valid
- Unpredictable behavior when auto_ptrs were stored in conainer or used in generic code
- auto_ptr was removed from the language in C++14
*/

/*####################
# std::unique_ptr
####################*/

/*
- unique_ptr appeared in C++11
    - A better version of auto_ptr
- A unique_ptr object cannot be copied or assigned to
- however, the memory can be moved from one unique_ptr object to another
*/

/*####################
# std::unique_ptr vs std::auto_ptr
####################*/

/*
- unique_ptr solves the problem with auto_ptr
- if we want to transfer the memory allocation, we have to do it explicity
    - use std::move()
- this makes it clear that the soruce object is now invalid
- We cannot accidentally transfer the memory
    - Code that tries to copy a unique_ptr will not compile

*/

/*####################
# std::shared_ptr
####################*/

/*
- A shared_ptr aslo appeared in C++11
- A shared_ptr object can share its memory allocation with other shared_ptr objects
- Reference counting is used to manage the memory
    - The memory is only released when the alst object which is using it is destroyed
- Similar to a garbage-collected object in other languages
- Shared_ptr has more overhead than unique_ptr
    - It should only be used when the extra features are needed



*/
