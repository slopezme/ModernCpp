#include <iostream>
#include <string>
#include <vector>

#include <algorithm>

// ################
//  Const iterator
// ################

// if we want to prevent the loop from modifying the string, we can use a const iterator

void func(){

std::string str{"Hello"};
std::string::const_iterator cit;

for (cit = str.begin(); cit != str.end(); cit++){
    std::cout << *cit <<std::endl;
}

}
// ################
// Reverse Iterator
// ################

//we can also use a reverse iterator to iterate backwards from the last element

void func2(){

std::string str{"Hello"};
std::string::reverse_iterator rit;

for (std::string::reverse_iterator rit = str.rbegin(); rit != str.rend(); ++rit){
    std::cout << *rit << std::endl;
}

}

int main() {
    using namespace std;

    string str{"Hello"};

    cout << "iterator: " << endl;
    for (auto it = str.begin(); it != str.end(); it++){
        cout << *it << endl;
    }

    cout << "reverse iterator: " << endl;
    for (auto it = str.rbegin(); it != str.rend(); it++){
        cout << *it << endl;
    }
}
// ###############################
// const form of begin() and end()
// ###############################

void func3(){

/*
modern C++ has const forms of begin() and end()
- these make it easier to use auto to iterate over containers

cbegin() and cend() return const iterators
*/

std::string str{"Hello"};

for (auto it = str.cbegin(); it != str.cend(); it++){
    std::cout << *it << std::endl;
}

//crbeing() and crend() return const reverse iterators

for (auto it = str.crbegin(); it != str.crend(); it++){
    std::cout << *it << std::endl;
}
}


// ###########################
// Non - member begin() and end()
// ###########################

void func4(){
/*
C++11 provides begin() and end() global functions
these are more readable than the member functions
*/

std::string str = "Hello";
for (auto it = begin(str); it != end(str); ++it){
    std::cout << *it << std::endl;
}

// they also work with built-in arrays
int arr[] = {1, 2, 3, 4, 5};

for (auto it = begin(arr); it != end(arr); ++it){
    std::cout << *it << std::endl;
}

//C++14 adds the other form

for (auto it = cbegin(arr); it != cend(arr); ++it){

}
for (auto it = rbegin(arr); it != rend(arr); ++it)
{

}
for (auto it = crbegin(arr); it != crend(arr); ++it){

}

// ###########################
// Range for loops
// ###########################

void func5(){
// Special concise syntax for iterating over containers
std::vector<int> vec {1, 2, 3, 4, 5};
for (auto el: vec)
    std::cout << el << std::endl;

//this is equivalent to

for (auto it = vec.begin(); it != vec.end(); ++it){
    int el = *it;
    std::cout << el << std::endl;
}

// Any changes which are made to "el" do not affect the container elements

// Range for loops with modification
// to modify the elemts, we need to use a reference

for (auto& el: vec)
    el *= 2;

// this is equivalent to

for (auto it = vec.begin(); it != vec.end(); ++it){
    int& el = *it;
    el *= 2;
}
// ###########################
// When to use range for loops
// ###########################

// range for loops are only suitable if we wish to visit each element once, in order,
// without adding or removing elements
// otherwise, we should use an iterator-based loop


}
