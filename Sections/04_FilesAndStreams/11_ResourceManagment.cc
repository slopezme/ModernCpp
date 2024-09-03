

/*
As programmer, we often use resources
- heap memory
- files
- database connections
- GUI windows

These need to be managed
- we have to allocate, open or arquire the resource before use
- we have to release, close or deallocate the resource after use
- we may need to give special thought to copying the resource
- we need to think about error handling

The Standard Library has some classes which manage resources
- allocated memory (std::string and std::vector)
- files (std::fstream)
- Objects used in multithreaded

These Follow the object oriented princple of encapsulation
- the details of managing the resource are hidden inside the class
- other code does not need to deal with resource directly
- Instead, it uses the class's interface (member functions)



*/

//############
// Fstream and Resources
//############

/*
- The fstream class "encapsulates" the details of hot to manage a file
- To use a file in C++ we just need to 
    - Give the name of the file to the fstream constructor
    - use the overload <<and>> operators for input and output
    - Close the file
- We only use the fstream interface
- We do not need to know anything about how to work with files directly
*/

//############
// Classes which manage resources
//############

/*
C++ Clasess which manage  a resource follow a common idiom
- The resource is stored as a  member of the class
- The class constructor acquires the resource
- The class's public member functions control access to the resource
- The class's destructor releases the resource

The idiom is called RAII (Resource Acquisition Is Initialization)

When an object is copied or assigned to, the target object gets a copy of the resource

*/

//############
// Advantages of RAII
//############

/*
Obtaining access to the resource is straightforward and deterministic
- Either the object seccessfully created, or the resource is not usable by the program

using the resource is straightforward
- Just call the object's member functions

Releasing the resource is straightforward and deterministic
- The resource is released when the object goes out of scope
- Either at the end of the scope or when an exception is thrown

Only one object can own a given resource at a time

*/