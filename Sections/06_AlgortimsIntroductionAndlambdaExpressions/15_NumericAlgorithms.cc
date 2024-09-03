
//############
// Numeric Algorithms
//############

/*
- The standard library provides also defines some algorithms in <numeric>
- These are used for numerical processing of containers elements
*/

//############
// iota()
//############

/*
- iota() populated an iterator range with values which successively increase by 1
- it takes the iterator range and a starting value
    - it assigns this starting value to the first element in the range
    - iota() then increments the value and assigns it to the next element
- Each element is assigned a value which increases by 1

vector<int> vec(10);                // Create a vector with 10 elements

- // Call iota() with starting value 1

iota(begin(vec), end(vec), 1);      // Populate the vector elements as 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

-// iota() is equivalent to 

int n{1};

for (auto& v: vec){
    v = n++;
}
*/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void main1(){
    vector<int> vec(10);                // Create a vector with 10 elements

    // Call iota() with starting value 1
    iota(begin(vec), end(vec), 1);      // Populate the vector elements as 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

    cout << "vec iota : ";
    for (const auto& v: vec){
        cout << v << " ";
    }
    cout << endl;

    vector<int> vec2(10);               // Create a vector with 20 elements
    int n{1};
    for (auto& v: vec2){
        v = n++;
    }

    cout << "vec loop : ";
    for (const auto& v: vec2){
        cout << v << " ";
    }
    cout << endl;

}

//############
// accumulate()
//############

/*
- accumulate()  returns the sum of all elements in an iterator range
- The third argument is the initial value of the sum
- usually this is 0

    -// Returns the sum of the elements of vec
    auto sum = accumulate(cbegin(vec), cend(vec), 0);

- It could also be the result of another call to accumulate()

    - // Returns the sum of the elements of vec and vec2
    sum = accumulate(cbegin(vec2), cend(vec2), sum);

*/

void main2(){
    vector<int> vec{3,1,4,1,5,9};

    cout << "Vector: ";
    for (auto v: vec){
        cout << v << " ";
    }
    cout << endl;

    auto sum = accumulate(cbegin(vec), cend(vec), 0);           // Returns the sum of the elements

    cout << "Sum calculated by algortihm: " << sum << endl;

    sum = 0;
    for (auto v : vec)
        sum += v;
    
    cout << " Sum calculated by loop: " << sum << endl;
}

//############
// accumulate() with extra argument
//############

/*
- By default, the operator + is used to perform the addition
- To perform a different operation, we can pass a callable object as an addtional fourth argument
- We can use a lambda function for the extra argument

    -// Returns the sum of the odd elements 
    auto sum = accumulate(cbegin(vec), cend(vec), 0, 
    [](int sum, int n){ return (n % 2 == 1) ? sum + n : sum; }
    );

*/

void main3(){
    vector<int> vec{3,1,4,1,5,9};

    cout << "Vector: ";
    for (auto v: vec){
        cout << v << " ";
    }
    cout << endl;

    auto sum = accumulate(cbegin(vec), cend(vec), 0, 
    [](int sum, int n){ return (n % 2 == 1) ? sum + n : sum; }
    );

    cout << "Sum of odd elements: " << sum << endl;
}

//############
// std::accumulate() and parallel processing
//############

/*
- std::accumulate() is specified to execute sequentially

    vector<int> vec{1,2,3};
    auto sum = accumulate(cbegin(vec), cend(vec), 0);

- The execution is performed as
    (((0 + 1) + 2) + 3)         // Must be performed in left to right order, one addition at a time

- This cannot be parallelized
    - Each operation must be completed before the next one can start

*/

//############
// std::reduce() C++17
//############

/*
- C++17 introduces std::reduce()
- This is an alternative implementation of std::accumulate() which is compatible with parallel execution

    vector<int> vec{1,2,3};
    auto sum = reduce(cbegin(vec), cend(vec), 0);           // Sum elements of vec

- std::reduce() can perform the addition in any order
- Compatible with parallel processing
*/

int main(){
    cout <<  "\nExample 1: \n" << endl;
    main1();

    cout <<  "\nExample 2: \n" << endl;
    main2();

    cout <<  "\nExample 3: \n" << endl;
    main3();
    return 0;
}