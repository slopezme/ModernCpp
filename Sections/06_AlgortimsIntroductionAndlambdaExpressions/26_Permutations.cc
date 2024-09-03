//############
// permutatations
//############

/*
- if we have a set of every possible arrangement of some elements, this gives the "permutations" of the elements
- For example, all the different ways a gropu of people can be seated at dinner

- e.g. the permutations of "abc" are, in alphabetical order:
    - abc, acb, bac, bca, cab, cba

- There are STL algorithms functions to find the next and previous permutations in the sequence
    - next_permutation()
    - prev_permutation()

*/

//############
// next_permutation()
//############

/*
- next_permutation() takes an iterator range
- It reorders the elements to give the next permutation in ascending order
- e.g.  the next permutation of "abc" is "acb"
- It return a bool, depending on whether there is a next permutation

- if the elemnts are sorted in ascending order, calling next_permutation() 
in a loop gives all the permutations 

    - // Loop to print out all the permutations of "abc" in order

    string str{"abc"};
    do{
        cout << str << endl;
    } while(next_permutation(begin(str), end(str)));

- This uses the < operator by default, but we can supply a predicate
    
*/



#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int>& v) {
    for (int i : v) {
        cout << i << ", ";
    }
    cout << endl;
}

void permutationExample() {
    string str{"abc"};

    cout << "The permutation of " << str << " are: " << endl;

    // loop to print out all the permutations of "abc" in order

    do {
        cout << str << endl;
    } while (next_permutation(begin(str), end(str)));
}

//############
// prev_permutation()
//############

/*
- prev_permutation() reorders the elements to give the previous permutation
- To get all the permutations in reverse, the elements must be sorted in descending order

    - // Loop to print out all the permutations of "abc" in reverse order

    sort(begin(str), end(str), [](int a, int b) { return a > b; });
    do {
        cout << str << endl;
    } while (prev_permutation(begin(str), end(str)));

- This uses the < operator by default, but we can supply a predicate

*/

void permutationExample2() {
    string str{"abc"};

    cout << "The permutation of " << str << " are: " << endl;

    // Loop to print out all the permutations of "abc" in reverse order

    sort(begin(str), end(str), [](int a, int b) { return a > b; });
    do {
        cout << str << endl;
    } while (prev_permutation(begin(str), end(str)));
}

//############
// is_permutation()
//############

/*
- is_permutation() takes two iterator ranges
- It returns true if both ranges contain the same elements, even it they are in a different order

    - // Do vec and vec2 contain the same elements?

    if(is_permutation(cbegin(vec), cend(vec), cbegin(vec2))) {
        cout << "The vectors contain the same elements" << endl;
    }

- This uses the == operator by default, but we can supply a predicate
*/

void isPermutationExample() {
    vector<int> vec {3, 1, 4, 1, 5, 9};
    vector<int> vec2{1, 3, 4, 5, 9, 1};

    cout << "vec:  ";
    print(vec);
    cout << "vec2: ";
    print(vec2);

    //Do vec and vec2 contain the same elements?

    if (is_permutation(cbegin(vec), cend(vec), cbegin(vec2))) {
        cout << "The vectors contain the same elements" << endl;
    } else {
        cout << "The vectors do not contain the same elements" << endl;
    }

}

int main() {

    cout << "\nPermutation Example: " << endl;
    permutationExample();

    cout << "\nPermutation Example 2: " << endl;
    permutationExample2();

    cout << "\nIs Permutation Example: " << endl;
    isPermutationExample();
    return 0;
}


