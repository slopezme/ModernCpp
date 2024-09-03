
//############
// A string class with RAII
//############

/*
We have used a very simple String class which stores its data in an std::string member

We are going to make our String class more realistic, by storing the data in a heap-allocated array

class String {
    char* data;      // Array member to store the characters
    int size;        // The number of elements in the array
    ...
    };

The String class will use the RAII idiom
- Allocate the mmeory for the array in the class constructor
- Release the memory in the class destructor

*/

//############
// A string class and Resource Management
//############

/*
- In the String class, the "resource" is the memory allocation
- The String class is responsible for managing the lifetime of this resource
    - It must make sure the resource is correctly acquired before being used
    - It must make sure the resource is correctly released when it is no longer needed
    - It must make sure that any copying of the resource is done correctly
    - It must make sure that any transfer of the resource to another object of this class is 
    handled correctly
*/


#include <iostream>
#include <string>

using namespace std;

class String {
    char* data;      // Array member to store the characters
    int size;        // The number of elements in the array
    public:
    // Constructor
    String(const std::string& s) : size (s.size()) {
        data = new char[size];
        for (int i = 0; i < size; i++) {
            data[i] = s[i];
        }
    }

    //Synthesized member functions
    // String(const String& arg) :size{arg.size}, data{arg.data} {}
    // String& operator=(const String& arg) { size = arg.size; data = arg.data; return *this; }

    //Destructor
    ~String() {
        cout << "Destructor called" << endl;
        delete[] data;    // Release the heap memory
    }

    int length() {
        return size;
    }

};

int main1() {
    String str("1"s);

    String str2("Two"s);
    String str3(str2);

    cout << "str2 size = " << str2.length() << endl;
    cout << "str3 size = " << str3.length() << endl;

    cout << "Str size = " << str.length() << endl;

    return 0;
}




//############
// Deep Assignment
//############

/*
We need to provide the target object with its own memory allocation
This must be large enough to hold the data

    delete [] data;
    data = new char[arg.size];

Before that, we neet to check for self-assignment
- if "this" and "arg" are the same object, they use the same memory pointer
- If this->data is deleted, arg-> data will be deleted as well
- We will not be able to access the characters in arg-> data

If the objects are the same, we do not modify them
*/




#include <iostream>
#include <string>

using namespace std;

class String2 {
    char* data;      // Array member to store the characters
    int size;        // The number of elements in the array
    public:
    // Constructor
    String2(const std::string& s) : size (s.size()) {
        data = new char[size];
        for (int i = 0; i < size; i++) {
            data[i] = s[i];
        }
    }

    //Assignment operator
    String2& operator=(const String2& arg) {
        cout << "Assignment operator called" << endl;

        if (&arg == this) {                     // Check for self-assignment
            delete[] data;                      // Release the original memory
            data = new char[arg.size];          // Allocate the data member

            size = arg.size;                    // Assign to the size member

            for (int i = 0; i < size; i++)      // Populate the data member
                data[i] = arg.data[i];
        }

            return *this;                       // Return the assigned to object
    }

    //Destructor
    ~String2() {
        cout << "Destructor called" << endl;
        delete[] data;    // Release the heap memory
    }

    int length() {
        return size;
    }

};

int main2() {
    String str("1"s);

    String str2("Two"s);
    String str3(str2);

    cout << "str2 size = " << str2.length() << endl;
    cout << "str3 size = " << str3.length() << endl;

    cout << "Str size = " << str.length() << endl;

    return 0;
}


//############
// Rule of three
//############

/*
if a class needs to implement one of
- Copy constructor
- Assignment operator
- Destructor

The it probably needs to implement the other two as well
- e.g class with pointer member allocated with "new" in constructor and released by "delete" in destructor
- Copy constructor is needed to perform deep copy when copying
- Assignment operator is needed to perform deep copy when assigning

This is known as the "Rule of Three"

*/


//############
// Default Constructor
//############

/*
The default constructor is not included in the Rule of Three as we usually need to implement a constructor anyway

String(const std::string& s) : size (s.size()) {
    data = new char[size];
    for (int i = 0; i < size; i++) {
        data[i] = s[i];
    }
}

Sometimes, it is useful to provide a default constructor which
initializes the object as "empty"

String () : data {nullptr}, size {0} {}     // String object with no data

*/



int main() {
    //main1();
    main2();
    return 0;
}
