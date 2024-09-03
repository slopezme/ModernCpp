//############
// Write algorithms
//############

/*
- Write algorithms can change the elemnts in an iterator range
*/

//############
// Replace()
//############

/*
- replace() changes all elements with a given value to anotehr value

    - // replace all occurrences of 1 with 2
    vector<int> vec{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    replace(begin(vec), end(vec), 1, 2);

- This is equivalent to the following loop

    for (auto &v : vec)
        if (v == 1)
            v = 2;

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(const vector<int> &vec) {
    for (const auto &v : vec)
        cout << v << " ";
    cout << endl;
}

void replaceExample() {
    vector<int> vec{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    vector<int> vec2 = vec;
    cout << "vec:                 ";
    print(vec);

    // Replace all occurrences of 1 with 2
    replace(begin(vec), end(vec), 1, 2);

    cout << "vec after replace(): ";
    print(vec);

    for (auto &v : vec2)            // Equivalent loop
        if (v == 1)
            v = 2;

    cout << "vec2 after loop:     ";
    print(vec2);
}

//############
// Replace_if()
//############

/*
- replace_if() changes all elements for which a given predicate is true to another value

    - // replace all even numbers by 6
    vector<int> vec{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    replace_if(begin(vec), end(vec), [](int i) { return i % 2 == 0; }, 6);

- This is equivalent to the following loop

    for (auto &v : vec)
        if (v % 2 == 0)
            v = 6;
*/

void replace_ifExample() {
    vector<int> vec{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    vector<int> vec2 = vec;
    cout << "vec:                     ";
    print(vec);

    // Replace all even numbers by 6
    replace_if(begin(vec), end(vec), [](int i) { return i % 2 == 0; }, 6);

    cout << "vec after replace_if():  ";
    print(vec);

    for (auto &v : vec2)            // Equivalent loop
        if (v % 2 == 0)
            v = 6;

    cout << "vec2 after loop:         ";
    print(vec2);
}


//############
// _copy() versions of algorithms
//############

/*
- Algorithms which change the elemnts have two versions
- the base version which overwrites the data in the original range
- A _copy version which writes the data to a different iterator range
    - This is useful when the data needs to be preserved for later use
    - useful for working with associative containers
*/

//############
// _replace_copy() 
//############

/*
- replace() has a _copy version
- replace_copy() writes the data to a destination, instead of overwriting the original data

    -// Replace all occurrences of 1 with 2

    replace_copy(cbegin(vec), cend(vec), back_inserter(vec2), 1, 2);
*/

void replace_copyExample() {
    vector<int> vec{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    
    cout << "vec:                  ";
    print(vec);

    vector<int> vec2;

    // Replace all occurrences of 1 with 2
    replace_copy(cbegin(vec), cend(vec), back_inserter(vec2), 1, 2);

    cout << "vec2 after replace(): ";
    print(vec2);

    vector<int> vec3;
    for (const auto &v : vec)           // Equivalent loop
        if (v == 1)
            vec3.push_back(2);
        else
            vec3.push_back(v);

    cout << "vec3 after loop:      ";
    print(vec3);
}

//############
// replace_copy_if()
//############

/*
- replace_if() has a _copy version
- If the predicate return true, the element will have a different value in 
the target container

    -// make a copy in which all even numbers are replaced by 6

    replace_copy_if(cbegin(vec), cend(vec), back_inserter(vec2), 
                    [](int i) { return i % 2 == 0; }, 6);

*/

void replace_copy_ifExample() {
    vector<int> vec{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    
    cout << "vec:                     ";
    print(vec);

    vector<int> vec2;

    // Make a copy in which all even numbers are replaced by 6
    replace_copy_if(cbegin(vec), cend(vec), back_inserter(vec2), 
                    [](int i) { return i % 2 == 0; }, 6);

    cout << "vec2 after replace_if(): ";
    print(vec2);

    vector<int> vec3;
    for (const auto &v : vec)           // Equivalent loop
        if (v % 2 == 0)
            vec3.push_back(6);
        else
            vec3.push_back(v);

    cout << "vec3 after loop:         ";
    print(vec3);
}




int main() {
    cout << "Replace Algorithm" << endl;
    replaceExample();

    cout << "\nReplace_if Algorithm" << endl;
    replace_ifExample();

    cout << "\nReplace_copy Algorithm" << endl;
    replace_copyExample();

    cout << "\nReplace_copy_if Algorithm" << endl;
    replace_copy_ifExample();

    return 0;
}