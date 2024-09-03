/*####################
# Exception Safety
####################*/

/*
- "Exception safety" means that code behaves correctly when exceptions are thrown
- All our programs should be exception safe
*/

/*####################
# Exception SGuarantees
####################*/

/*
- There are three main ways to write exception safe code
- Basic exception guarantee
    - If an exception is thrown during an operation, no resources are leaked
    - Files opened during the operation will be closed
    - memory allocated during the operation will be released

- Strong exception guarantee
    - If an exception is thrown, the program reverts to its previous state
    - As if the operation had not happened

- No throw guarantee
    - The operation will never throw an exception


*/

/*####################
# Basic Exception Guarantee
####################*/

/*
The basic exception guarantee provides the minimum level of exception safety
    - An operation will either succeed or throw an exception
    - if the operation throws an exception, no resources will be leaked

- Al the operations and functions in the C++ standard library provide  the basic guarantee
*/

/*####################
# Strong Exception Guarantee
####################*/

/*
- An operation will either succeed or have no effect
- if it throws an exception, the program will be left in the same state as it was before
 the operation
    - The operation has transactional semantics
    - Similar to commit and rollback in a database

- Al iterators or references which were obtained before the operation will remain valid,
even if the operation fails
- All operations on STL container provide the strong exception guarantee
    - Except for a couple of special cases of insert operations


*/


/*####################
# Providing the Basic Exception Guarantee
####################*/

/*
- For code to provide the basic guarantee, any resources acquired during the operation
must be released when an exception is thrown
- We can manually release the resources
    - Call delete on memory allocated with new

- or we use objects which automatically release the resource when destroyed
    - std::string and std::vector destructors release the memory
    - fstream destructor closes the file


*/