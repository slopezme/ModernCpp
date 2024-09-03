#include <iostream>
#include <string>

int main(){
    std::string str{"Hello"};

// ###############################
// #### Iterator Arithmetic Functions
// ###############################

/* We can perform arithmetic on iterators
- similar to pointers
Adding to an iterator moves it towrds the back of the container*/

auto second = begin(str) + 1; // second element

/* subtracting from an interator moves it towrds the front of the container */

auto last = end(str) - 1; // last element

/* end() - being() gives the number of elements*/
auto mid = begin(str) + (end(str) - begin(str)) / 2; // middle element
//   first element iterator + middle element iterator = position of middle element

/* nest() takes an iterator and return the following iterator*/
auto second = next(begin(str)); // returns iterator to second element

/* prev() takes an iterator and returns the previous iterator */
auto last = prev(end(str)); // returns iterator to last element

/* distance() takes two iterators and returns the number of elements between them */
auto d = distance(begin(str), end(str)); // returns number of elements in the container (5

/* advance() takes an iterator and an integer and returns an iterator advanced by that many positions */
auto mid = begin(str);
advance(mid, distance(begin(str), end(str)) / 2); // mid is iterator to middle element


// ###############
// half-open Range
// ##############

/*Imagine we have a loop with an integer loop counter */

for (int i = 0; i < 10; i++){
    std::cout << i << std::endl;

/* In the loop body, 'i' han an allowed range of values
- 0, 1, 2, 3, 4...,9 but not 10

this is known as a "half-open" range
it is written [0, 10)
- i >= 0 and i < 10
- i == 10 is not allowed
*/

// ###############
// Iterator Ranges
// ##############

/*
the iterators returned by begin() and end() define an iterator range
if we have loop with an iterator as loop counter
*/

for (auto it = begin(str); it != end(str); ++it){
    std::cout << *it << std::endl;

/*
in the loop body, 'it has an allowed range values
- begin(), beign() + 1, begin() + 2, ..., but not end()

this is also a half-open range
it >= begin() and it < end()
it == end() is not allowed
*/


//Note: Division is not supported on iterators

// auto mid = begin(str)/2 + end(str)/2; // Error


}
