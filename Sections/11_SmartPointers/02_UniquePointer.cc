/*####################
# std::Unique_ptr
####################*/

/*
- In most situation, unique_ptr is the best replacement for traditional pointers which manage heap memory
    - Allocates heap memory in its constructor and has sole ownership of it
    - Automatically releases the memory when it goes out of scope
    - This allows heap-allocated memory to be used like a stack object

- It has the usual advantages of smart pointers
    - The programmer does not need to manage the memory
    - The pointer to the memory cannot be overwirtten or invalidated
    - No issues with "shallow copying"

- Unique_ptr is very lightweight
    - A unique_ptr object has no more overhead than a tradicional pointer

- unique_ptr is defined in <memory>
- unique_ptr is a template class with a traditional pointer as member
- The public member functions of the class implement some of the operations on traditional pointers
- its template parameter is the type of the pointed-to data
    uniquye_ptr<int> p;

- unique_ptr is a move-only class
    - Moving a unique_ptr transfers the allocated memory from one object to another


*/

/*####################
# unique_ptr initialization in C++11
####################*/

/*
- In C++11, we have to provide the pointer by calling new() explicity

    -// allocate a single int with value 42
    unique_ptr<int> p1(new int(42));            // p1's member pointers to the int on the heap

- We can also create a fixed - size array
    -// Allocate array of 6 ints

    unique_ptr<int []> p2(new int[6]);          // p2's member pointers to the first element

    -// usually better to use std::array or std::vector

    std::array<int, 6> arr;
    std::vector<int> vec(6);
*/

/*####################
# unique_ptr initialization 
####################*/

/*
- In C++15 has make_unique, which calls new() internally
    auto p1 {make_unique<int>(42)};             // p1's member pointers to the int on the heap

    auto p2 {make_unique<int[]>(6)};             // p2's member pointers to the first element

- make_unique() uses perfect forwards its arguments to the constructor
*/

#include <memory>
#include <iostream>

using namespace std;

void unique_pointerExample(){
    // In C++11, we have to provide the pointer by calling new() explicity

    // allocate a single int with value 42
    unique_ptr<int> p1(new int(42));            // p1's member pointers to the int on the heap

    // Allocate array of 6 ints
    unique_ptr<int[]> p2(new int[6]);          // p2's member pointers to the first element

    // usually better to use std::array or std::vector
    // std::array<int, 6> arr;
    // std::vector<int> vec(6);

    // In C++14 has make_unique, which calls new() internally
    auto p3 {make_unique<int>(42)};             // p3's member pointers to the int on the heap
    auto p4 {make_unique<int[]>(6)};             // p4's member pointers to the first element

    cout << *p1 << endl;                         // Single object can be deferenced
    // cout << p1[0];                            // Error: unique_ptr does not support array indexing
    cout << p2[0] << endl;                       // Array can be indexed
//cout << *p2 << endl;                           // Error - array cannot be deferenced
// ++p1;                                         // Error: unique_ptr does not support pointer arithmetic
// ++p2;                                         // Error: unique_ptr does not support pointer arithmetic
// p1 = p2;                                      // Error: unique_ptr can only be moved, not copied
// unique_ptr<int> p5{p4};                       // Error: unique_ptr can only be moved, not copied
    unique_ptr<int> p5{std::move(p3)};           // OK: p5 now owns the memory
    // unique_ptr<int> p6{std::move(p4)};        // Error: - Incompatible types
    p1 = nullptr;                                // OK: p1 sets to nullptr      
}


struct Point{
    int x, y;
};

void structExample(){
    // Create a uniquye_ptr to a Point which has initial value{3,6}
    auto p{make_unique<Point>(Point{3, 6})};
    // unique_ptr<Point> p{new point{3, 6}};    // C++11

    cout << p->x << " , " << p->y << endl;
}


int main(){
    std::cout << "Unique Pointer Example" << std::endl;
    unique_pointerExample();

    std::cout << "Struct Example" << std::endl;
    structExample();
    return 0;
}
