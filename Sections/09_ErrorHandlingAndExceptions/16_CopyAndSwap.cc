/*####################
# Copy and Swap
####################*/

/*
Alternative approach to writing an assignment operator
    - Create a local variable which is a copy of the argument
    - Swap the contents of the local variable with the "this" object
    - Return the "this" object, which now contains the argument's value
    - The local variable is then destroyed, releasing the memory
*/

/*####################
# Create and Initialize
####################*/

/*
To create a new object and initialize it with the values we want, we
use the copy constructor

    String& operator = (const String &arg){
        String temp(arg);       // Create a copy of the argument
        ...
    }

- If this throws
    - The "temp" object will be destroyed
    - The function returns immediately
    - "this" is unmodified
    - The exceptionis left for the caller to handle

*/

/*####################
# Swap the objects
####################*/

/*
- "temp" now contains the required values
- To get these values into "this", we use std::swap
    String& operator = (const String &arg){
        String temp(arg);       // Create a copy of the argument
        swap(temp);             // Swap the contents of temp with this
        return *this;
    }
- The swap operation is noexcept (cannot throw)
- "this" now contains the required values
- "temp" contains the original values

*/

/*####################
# Return the new object
####################*/

/*
- Finally, we return the assigned-to object

    String& operator = (const String &arg){
        String temp(arg);       // Create a copy of the argument
        swap(temp);             // Swap the contents of temp with this
        return *this;
    }   // Temp is destroyed

- When the function returns, the destructor for "temp" is called
- This releases the original memory allocation
    - No memory leak

*/

/*####################
# Assignment Operator with Strong Guarantee
####################*/

/*
- This is known as the "copy and swap" idiom
- Advantages
    - No need to check for self-assignment ("temp" and "this are distinct objects)
    - Code reuse - does not duplicate code from copy constructor and destructor
    - Much shorter code with less scope for errors

- Disadvantages
    - Always makes a new allocation, even if the target object already has enough memory
    - Creates an extra object, which increases memory usage

*/