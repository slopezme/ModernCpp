#include <iostream>
#include <string>
#include <vector>

using namespace std;

//############
// data()
//############

/*
- std::String and std::vector have a data() member function.
- This returns a pointer to the container's internal memory buffer.
- For std::string, this is null- terminated
    - Equivalent to c_str()
-useful for working with APIs written in C

void print(int *arr, size_t size);

std::vector<int> numbers {1,2,3,4,5};

print(numbers.data(), numbers.size());

*/

void print(int *arr, size_t size){
    for (size_t i = 0; i < size; ++i)
        std::cout << arr[i] << ", ";

}

void fi(){
    std::vector<int> numbers {1,2,3,4,5};
    print(numbers.data(), numbers.size());
}


//############
// swapping()
//############

/*
std::string has a swap() member function that swaps the contents of two strings.

string s1{"Hello"};
string s2{"Goodbye"};

s1.swap(s2);

there is also a non member function swap() that swaps the contents of two strings

swap(s1,s2);

this flobal function has overloads for all the build-in and library types

*/

void f2(){
    string s1{"Hello"};
    string s2{"Goodbye"};

    cout << "s1: " << s1 <<  ", s2: " << s2 << endl << endl;

    //member swap function

    cout << "Using member swap()" << endl;
    s1.swap(s2);
    cout << "s1: " << s1 << ", s2: " << s2 << endl << endl;  // Output: s1: Goodbye, s2: Hello

    //non-member swap function

    cout << "Using non-member swap()" << endl;
    swap(s1,s2);
    cout << "s1: " << s1 << ", s2: " << s2 << endl;  // Output: s1: Hello, s2: Goodbye


}

/*
It htere is no olverload for a class, the default implementation of swap will be used

- this uses a temporary object

obj temp = obj1;
obj1 = obj2;
obj2 = temp;

For std::string, this would be a slow operation

- Each operation requieres all the data in a string to be copied
- The copy constructor will cause memory allocation
- The assignment operation may cause a memory allocation
*/


//############
// specialized swap() for std::string
//############

/*
the std::String class has a "header"
- Integer with the character count
- Pointer to the character data

The library implementation of swap reassigns the headers
- No memory operations
- No copying of data

// Pseudo - code

header temp = s1.hdrl    // pointer assignment + interger assignment
s1.hdrl = s2.hdrl;       // pointer assignment + interger assignment
s2.hdrl = temp;          // pointer assignment + interger assignment
*/
