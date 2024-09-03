//###########
//# Member function Implementation
//###########

/*
- member functions are not sotred in the object 
- they are implemented as global functions
- When they are called, a pointer to the object is passed as an extra argument called "this"
*/


//###########
//# non virtual member function
//###########

/*

circle member functions  
    - Circle::draw() 
    - Circle::area()
*/

//###########
//# Virtual Member Function Implementation
//###########

/*
When the compiler encounters a class which has a virtual member functions, it creates and populates a data structure
    - This is the class's "virtual member function table, known as a "vtable"

When the compiler sees a call to a virtual member function, it generates some extra code
    - This code is executed at runtime
    - it checks the dynamic type of the object
    - it uses the vtable to call the correct version of the member function


    circle member functions     
        - Circle::draw() 
        - Circle::area()

    circle vtable 
        - Circle::draw() 
        - Circle::area()
*/

//###########
//# VVirtual Function Table
//###########

/*
The virtual function table sotres the addresses of all the member functions of the class which are declared virtual
- The vtable is an array of pointers to member functions
- Each virtual memeber functions is identified by an index into the table

*/

//###########
//# Virtual Function TCall
//###########

/*
When a virtual member function is called, the compiler replaces the name of the function by the coressponding index in the vtable
- The runtime code will
    - Determine the objects dynamic type
    - Locate the vtable for that dynamic type
    - Look up the element in the vtable
    - Deference the function pointer and call it


*/

//###########
//# Virtual Function Overhead
//###########

/*
- there is some overhead to using virtual member functions
- Efficiency
    - Calling a virtual member functions takes longer than for a non virtual one (about 25 - 50 % more time)

- Memory allocation 
    - Each class that has a virtual member functions needs a vtable
    - A pointer is needed for each virtual member function in the  class

- only use virtual member functions when the extra flexibility is requiered

*/
