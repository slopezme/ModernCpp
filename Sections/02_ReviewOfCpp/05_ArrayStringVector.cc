#include <iostream>
#include <random>
#include <ctime>

int getRandomInt(int min, int max) {
    // Seed the random number generator
    std::mt19937 rng(time(0));  // Using current time as seed
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(rng);
}

void main(){
// Array

/*
-An indexed block of contiguous memory
- Inherit from C
- An Array can be allocated on the program stack
- but only if the number of elements is fixed and known at compile time
*/
// random number



int nElements = getRandomInt(1, 10); // Random number of elements
int arr[5];             // Array of 5 integers on the stack
int arr[nElements];     // Not allowed, nElements is not a constant expression



// Dynamic Array

/*
The array must be allocated on the heap if
- we do not know the number of elements at compile time
- Or we want to be able to vary the number of elements at runtime
*/

int *pArr = new int[nElements]; // Array of nElements integers on the heap
delete [] pArr; // Release memory allocated for nElements integers

//C-Style String

/*
A C-style string is an array of const char terminated by a null character '\0'
Each character of the string is stored in an element in the array
The array has a null extra character at the end to indicate the end of the string
String literals are C-style strings
*/

const char *str = "Hello"; // Equivalent to const char str[] = {'H', 'e', 'l', 'l', 'o', '\0'};

//std::string
/*
std::string is a class that represents a string of characters
it has a memeber which is a dynamic array
it also has a member which stores the number of elements in the array

class std::string {
    char *data;     // Block of contiguous memory
    size_t size;    // Number of characters in the array
    //...
};

std::String objects behave like a dynamic array, but are used like a local varaible
*/
std::string hello{"Hello"}; // Equivalent to string hello = "Hello";

//std::String interface

/*
suscript notation [] to access individual characters
elements are indexed, starting from 0
size() member function return number of elements
*/


//std::vector

/*
std::vector is similar to std::string, but can sotre data of any single type
the type of the data is a parameter of the class
*/
std::vector<int> vec {1, 2, 3, 4, 5}; // Vector has elements 1, 2, 3, 4, 5
vec.push_back(6);                     // Add 6 to the end of the vector
vec.emplace_back(7);                  // Add 7 to the end of the vector

// Difference between push back and emplace back

/*
push_back() copies the argument to the end of the vector
emplace_back() constructs the argument in place at the end of the vector

emplace_back() is more efficient than push_back() when constructing objects
emplace_back() is used to construct objects in place, avoiding the need to copy or move the object
*/




}
