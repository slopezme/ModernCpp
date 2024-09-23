/*####################
# std::swap()  Function
####################*/

/*
- The C++ library provides an std::swap function
- This exchanges the data in its arguments

swap(a, b);         // Exchanges the values of a and b

- std::swap() is declared noexcept
    - It offers the no throw guarantee

*/


/*####################
# Overloads of std::swap() 
####################*/

/*
- std::swap() is a generic function
- it copies its arguments
- Tehre are overloads for library types which take advantage of their internal structure
- e.g. the std::string overload swaps the strings internal data buffers

-// Pseudo - Code 

char *temp = s1.ptr;
s1.ptr = s2.ptr;
s2.ptr = temp;

- Some algorithms need to swap elements internally 
    - e.g sort()
- They call the non member swap() function
- The call will be made to the generic std::swap() which uses copying 
    - Unless there is an overload for the elemts type

*/

/*####################
# Should we Overload swap()? 
####################*/

/*
- When we write a class, we can overload swap() for that class
- This is worth doing if
    - The class is expensie to copy
    - And its objects could be swapped, e.g. by sorting a container


*/

/*####################
# implementing swap
####################*/

/*
- Algorithms assume that swap() is fast and does not throw exceptions
- Our swap() will need access   do data members
    - Eotjer ,ake it a frioend, or delegate to a member function
- we write the code inline so that the compiler can optimize away the function call
- We make it noexcept
- We call swap() for each data member
*/

#include <iostream>

using namespace std;

class String {
    private:
        int size;
        char *data;
    public:
        String(int size) : size(size), data(new char[size]) {}

        String(const String &arg) : size(arg.size){
            cout << "Calling Copy Constructor" << endl;
            data = new char[size];              // Allocate the heap memory for args data

            for (int i = 0; i < size; ++i)      // Populate the data 
                data[i] = arg.data[i];      
        }
    
    //Assignment Operator
    String& operator=(const String &arg){
        cout << "Calling Assignment Operator" << endl;

        if (&arg != this){                  // Check for self assignment
            cout << "Reallocating Memory\n";
            delete[] data;                  // Release the original memory
            data = new char[arg.size];      // Allocate the data member 

            size = arg.size;                // Update the size

            for (int i = 0; i < size; ++i)  // Populate the data
                data[i] = arg.data[i];
        }
        return *this;

    }

    //Destructor
    ~String(){
        cout << "Calling Destructor" << endl;
        delete[] data;
    }

    // Declare overloaded swap() as a friend of this class

    friend void swap(String &l, String &r) noexcept;

    void print(){
        cout << "string with size =" << size;
        cout << " , data address = " <<  static_cast<void*>(data) << endl;
    }

};


inline void swap(String &l, String &r) noexcept {
    cout << "\nIn String::swap\n";
    swap(l.size, r.size);
    swap(l.data, r.data);
}

int main(){
    String a(5), b(6);
    cout << "Before Swap\n";
    cout << "a = "; a.print();
    cout << "b = "; b.print();

    swap(a, b);

    cout << "After Swap\n";
    cout << "a = "; a.print();
    cout << "b = "; b.print();

    cout << endl;

    return 0;
}


