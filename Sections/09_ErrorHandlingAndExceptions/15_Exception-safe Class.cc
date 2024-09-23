/*####################
# Exception-safe Class
####################*/

/*
- Consider our RAII class 

    class String{
        int size;
        char *data;

        ...
    };

is this class exception safe?
We will review the special member funcions


*/

/*####################
# Constructor
####################*/

/*
- The constructor allocates the memory used by the "data" member

    String(const char *str, int size) : size(size){
        data = new char[size];
        -// Any other code needed to condfigure the new object}
    }

- The constructor cannot be noexcept
- The constructor provides the strong exception guarantee
    - No objects are created or modified when there is an error condition
    - The function will return immediately, without allocating a value to "data"
    - The partially - created object will be destroyed


*/

/*####################
# Copy Constructor
####################*/

/*
- The copy constructor allocates memory for "data" member
- If then copies the characters from its argument

String(const String &arg) {
    size = arg.size;
    data = new char[size];
    
    -// Any other code needed to configure the new object
    
    for (int i = 0; i < size; ++i)
        data[i] = arg.data[i];
    }

Like the class constructor, it provides the strong exception guarantee

*/

/*####################
# Destructor
####################*/

/*
- The destructor releases the memory used by the "data" member

~String(){
    delete[] data;
}

- The destructor provides the no-throw guarantee
    - delete and delete[]  are defined as noexcept

*/

/*####################
# Assignment Operator
####################*/

/*
- The assignment operator performs a "deep copy" 
- This releases the memory for "data" and then reallocates it
- The only operation that could throw is new
    - The function will return immediately, without allocating a new value to "data"
    - The target object will be unmodified
    - The assignment operator provides the strong exception guarantee


*/

/*####################
# Exception Safety and RAII
####################*/

/*
- With RAII, the constructor and copy constructor automatically provide the strong 
exception guarantee
- The destructor automatically provides the no-throw guarantee
- The assignment operator, if implemented carefully, also offers the strong exception 
guarantee

*/
