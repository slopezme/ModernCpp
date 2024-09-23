/*####################
# Move Semantics
####################*/

/*
- In a swap() function, we can save time by exchanging data instead of copying it
- With move semantics, we can save time by "moving" data in and out of function calls

*/

/*####################
# Value Semantics
####################*/

/*
- C++ often uses value semantics, in which data is copied
- Function calls
    - By default, function arguments are passed by value
    - By default, functions return by value
- STL containers copy data into their elements
    - suing references is not allowed ( too easy to create dangling references)
    - Pointers can be used, but may dangle or cause memory leaks

- Value semantics avoids the need for a garbage collector
- however, it requires copying objects
    This increases the execution time

- Traditional C++ can elide copies when returning temporary and local 
variables from functions

- Consider how the following code is excetued in C++03

    vector<string> vec(1'000'000);      // Vector of 1 million strings
    ...                                 // Populate the vector
    func(vec);                          // Pass the vector by value to a function
    ...                                 // vec is not used again

- The function call causes a new vector of 1 milliong string to be allocated for the function
argument
- The elements of vec are the copied into the new vector
- At the end of this scope, vec's destructor will destroy an empty vector

*/

/*####################
#  Move Semantics
####################*/

/*
-C++11 introduced move semantics
- This is an optmization over copying objects
- if the source object is an "rvalue", its data can be moved into the target instead
of being copied
- Similar to moving files between folders instead of copying them

*/
