//###########
//#  Built-in Array
//###########

/*
- C++ has built in array inherited from C

    int arr[] = {1, 2, 3, 4, 5};

- This is faster than std::vector, and directly compatible with C code
-It has serious disadvantages, including:
    - No direct way to find the number of elements
    - Silent conversion to a pointer
    - Passing arrays to and from functions requires a size argument
    - Arrays cannot be assigned to each other

- Modern C++ provides std::array which overcomes the above
*/

//###########
//#  std::array
//###########

/*
- std::array is defined in <array>
- It is a templated type
    - The parameters are the element type and the number of elements
    - The number of elements is part of the type of the object
    - Trying to use an array with the wrong number of elements gives a compiler error

- It has a similar interface to STL containers, while retaining the speed of built-in arrays
    - Does not automatically "decay" to a pointer
    - Retains information about its size
    - Support for iterators and range-based for loops

*/

//###########
//#  std::array object creation
//###########

/*
- An std::array object can only be created on the stack
    - The number of elements must be known at compile time
- A contiguous block of memory is allocated to store the elements
- Unlike other containers, the default constructor created a fully-sized object. 
The elements are default-initialized

*/




#include <iostream>
#include <array>

using namespace std;


void arrayExample()
{
    // std::array can be list initialized
    std::array<int, 5> arr{1, 2, 3, 4, 5};

    //Elements can be accessed and assigned to using indexing
    cout << "arr[3] = " << arr[3] << endl;

    arr[3] = 42;
    cout << "After assignment, arr[3] = " << arr[3] << endl;


    cout << "Iterator loop:" << endl;
    for (auto it = arr.begin(); it != arr.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Range-based for loop:" << endl;
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Indexed loop:" << endl;
    for (size_t i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Arrays of the samy type and size can be assigned to each other
    std::array<int, 5> arr2 = arr;
    cout << "arr2 after assignment: ";
    for (int i : arr2)
    {
        cout << i << " ";
    }
    cout << endl;

}

//###########
//#  std::array interface
//###########

/*
- std::array has a similar interface to  std::vector
    - size()        //returns the number of elements
    - empty()       //returns true if the array is empty
    - operator[]    //accesses elements by index
    - at()          //accesses elements by index, with bounds checking
    - front()       //returns the first element
    - back()        //returns the last element
    - data()        //returns a built-in array of the elements
*/

// Function that takes built-in array as pointer to int
// n is the number of elements in the array

void somefunction(int *pi, int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << pi[i] << ", ";
    }
    cout << endl;
}   

// Function that takes std::array of 5 elements
void somefunction(std::array<int, 5> &arr)
{
    for (int i : arr)
    {
        cout << i << ", ";
    }
    cout << endl;
}

void arrayInterface()
{
    cout << "Built in array:" << endl;
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    somefunction(arr, n);               // &pa[0] is passed to the function

    cout << "std::array:" << endl;
    std::array<int, 5> arr2 = {1, 2, 3, 4, 5};
    somefunction(arr2);                 // arr2 is passed to the function
}


int main()
{
    cout << "\nstd::array example:" << endl;
    arrayExample();

    cout << "\nstd::array interface:" << endl;
    arrayInterface();
    return 0;
}