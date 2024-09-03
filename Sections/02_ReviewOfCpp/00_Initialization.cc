#include <string>
#include <iostream>

#include <algorithm>
#include <vector>

using namespace std;

int a = 1;                              // C-like initialization
int x {7};                              // Equivalent to int x = 7;
string s = "Hello"; 				    // Equivalent to string s("Hello");
string s1{"Hello"};                      // Equivalent to string s = "Hello";  

int *v;
void test() {
    v = new int[2];
    v[0] = 1;
    v[1] = 2;
    //....
    delete[] v;
}


int *v2 = new int[10];
void test2() {
    v2[0] = 1;
    v2[1] = 2;
    //....
    delete[] v2;
}

std::vector<int> v3;                    // Empty vector
std::vector<int> v4(10); 	            // Vector with 10 elements
std::vector<int> v5(10, 1);             // Vector with 10 elements, all initialized to 1
std::vector<int> v6 = {1, 2, 3, 4, 5};  // Vector with 5 elements
std::vector<int> v7(v6);                // Copy of v6

//Narrowing Conversiones

int y = 7.7;                            // y = 7 - Legal, although compilers may warn
//int y {7.7};                            // Error: narrowing conversion

//Avoids inconsistency 
vector<int> old_one(4); 			   // std::vector with elements 0, 0, 0, 0
vector<int> old_two(4, 1);             // std::vector with elements 1, 1, 1, 1
vector<int> uni_one{4};                // std::vector with 4 elements
vector<int> uni_two{4, 1};             // std::vector with 4,2

//Avoids Ambiguity

//Test test1();            // Object creation or function declaration? "Most vexing parse"
//Test test2{};            // Object creation

// Nested template

vector<vector<int>> matrix;            // 2D vector

using IntVec = vector<int>;  // Define a new type
vector<IntVec> vec_of_vec;

#include <iostream>
#include <vector>

// Void function equivalent of function1
void function1(void * ptr) {
    // Implementation logic
}

// Void function equivalent of func1
void func1(std::vector<int> vec) {
    // Implementation logic
}

// Void function equivalent of func2
void func2(std::vector<int> & vec) {
    // Implementation logic
}

int main() {
    function1(nullptr); // Call function with a null pointer

    // Example usage:
    std::vector<int> vec = {1, 2, 3};
    func1(vec); // Pass by value
    func2(vec); // Pass by reference

    std::cout << "test" << std::endl;

    return 0;
}
