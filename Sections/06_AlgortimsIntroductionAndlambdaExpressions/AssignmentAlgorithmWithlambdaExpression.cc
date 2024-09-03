
/*
Write a function that takes a vector of int as argument and uses a range-for loop to print out the elements of the vector.

Write a program that calls this function. Check that your program compiles and runs correctly.

Modify your program so that it sorts the elements in descending order, with the largest element first. For example, if the vector elements are 1, 2, 3, 4, 5, the result would be 5, 4, 3, 2, 1.

Use a suitable standard algorithm with a lambda expression as predicate.

Display the elements of the vector after sorting them. Check that your program still compiles and runs correctly.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(vector<int> vec){
    for (auto element : vec)
        cout << element << ", " ;
    
    cout << endl << endl;
}

int main(){

    vector<int> numbers{ 1, 2, 3, 4, 5};
    printVector(numbers);
    // Sort the data, using lambda expression as the predicate to sort in descending order
    auto sortDown = [](int first, int second) -> bool { return first > second; };
    sort(begin(numbers), end(numbers), sortDown);
    // sort(begin(numbers), end(numbers), [](int a, int b){return a > b;});
    printVector(numbers);
    return 0;
}


