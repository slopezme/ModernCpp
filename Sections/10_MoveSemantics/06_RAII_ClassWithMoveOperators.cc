/*####################
#  RAII Class with Move Operators
####################*/

/*
We need to add a move constructor and move assignement operator to our RAII class

class String{
    private:
        int size;
        char* data;
    public:
        ... // Member functions
};
*/

/*####################
#  move constructor (first attempt)
####################*/

/*
- Our move constructor needs to move the data members of the argument object
- As these are built-in types, we can just copy them

    -// Move constructor

String(String&& arg) noexcept {
    size = arg.size;
    data = arg.data;
    cout << "Move constructor called" << endl;
    -// Anything else?

    arg.data = nullptr;
    arg.size = 0;
}

*/

/*####################
#  move assignment operator 
####################*/

/*
- We can write a move assignment operator which is similar to the traditional
copy assignment operator

    -// Move assignment operator

    String& operator=(String&& arg) noexcept {
        if (this != &arg) {
            delete [] data;
            data = arg.data;
            size = arg.size;

            cout << "Move assignment operator called" << endl;

            arg.data = nullptr;
            arg.size = 0;
            return *this;
        }
    }


- Alternatively, we can use "move-and-swap" 

    -// Move assignment operator

    String& operator=(String&& arg) noexcept {
        String temp{std::move(arg)};            // Call move constructor
        swap(*this, temp);                      // Swap data with temp
        return *this;
    }

- This is similar to the copy-and-swap idiom except it uses the move constructor
to create the temporary object
    - "this" has the pointer from "arg"
    - "temp" has the original pointer from "this", which is deleted
    - "arg"  has a nullptr

*/