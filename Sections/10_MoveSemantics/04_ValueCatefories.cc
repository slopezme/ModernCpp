/*####################
#  Characteristics of lvalues
####################*/

/*
- lvalues represent persisting objects
- These occupy memory which is accessible to the programmer
    - Either on the stack or the heap

- They remain valid until they go out of scope or are deleted
    - Local variables
    - Global variables
    - Static variables
    - Function arguments

*/

/*####################
#  Characteristics of rvalues
####################*/

/*
- rvalues are stored in locations which are not accessible to the programmer, 
such as processor registers
- Literals like 2 or 'c'
- Temporary objects
    - Destroyed in the same statement in which there are created

*/

/*####################
#  Value Categories
####################*/

/*
- C++ has three "value categories"

Literals
    - These have no name and cannot be referred to again
    - These are called pure rvalues or "prvalues"

Temporary objects
    -These represnet an object and their data can be moved
    - They are known as "xvalues" (x for "eXpiring"?)

lvalues

Every expression has a type and value category
*/

/*####################
#  Value Categories Diagram
####################*/

/*
lvalue

rvalue
    - prvalue
    - xvalue

*/

/*####################
#  Value Categories Contd
####################*/

/*
- lvalues and xvalues are objects
- Their dynamic type can be different from their static type
- They are collectively known as "generalized lvalues" or "glvalues"

*/

/*####################
#  Value Categories Diagram Contd
####################*/

/*
glvalue
    - lvalue
    - xvalue
        
rvalue
    - prvalue
    - xvalue

*/