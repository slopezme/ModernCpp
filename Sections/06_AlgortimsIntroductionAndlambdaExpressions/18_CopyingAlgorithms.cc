//############
// Copy Algorithm
//############

/*
- Copying algorithms copy elements into another range
- these are often used to populate sequential containers
*/

//############
// copy()
//############

/*
- copy() is the most basic copying algorithm

    vector<int> vec1{1, 2, 3, 4, 5};
    vector<int> vec2(vec1.size());              // The target container must be big enough!
    copy(cbegin(vec1), cend(vec1), begin(vec2));

- We can use a back_insert_iterator to populate an empty vector
    
        vector<int> vec3;
        copy(cbegin(vec1), cend(vec1), back_inserter(vec3));

- This is equivalent to the following loop

    vector<int> vec4;
    for (const auto &v : vec1)
        vec4.push_back(v);

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(const vector<int> &vec){
    for (const auto &v : vec)
        cout << v << " ";
    cout << endl;
}

void copyExample() {
    vector<int> vec{1, 2, 3, 4, 5};
    cout << "vec: ";
    print(vec);

    //Copy elements from vec into vec2
    vector<int> vec2(vec.size());
    copy(cbegin(vec), cend(vec), begin(vec2));

    cout << "vec2: ";
    print(vec2);
}

//############
// copy_n()
//############

/*
copy_n() is similar to copy(), but takes a number instead of the second iterator

    vector<int> vec1{1, 2, 3, 4, 5};
    vector<int> vec2(3);                        // The target container must be big enough!
    copy_n(cbegin(vec1), 3, begin(vec2));

    - Equivalent to the following loop

    vector<int> vec3;
    for (size_t i{0}; i < 3; ++i)
        vec3.push_back(vec1[i]);
*/

void copy_nExample() {
    vector<int> vec{1, 2, 3, 4, 5};
    cout << "vec: ";
    print(vec);

    // Copy the first 3 elements from vec into vec2
    vector<int> vec2(3);
    copy_n(cbegin(vec), 3, begin(vec2));

    cout << "vec2: ";
    print(vec2);
}

//############
// copy_if()
//############

/*
- copy_if() copies only the elements for which a predicate is true
    vector<int> vec2;
    copy_if(cbegin(vec1), cend(vec1), back_inserter(vec2), 
            [](int i) { return i % 2 == 1; });                  // only copy odd numbers

- copy_if()  acts as a filter between the source and target containers
- Data will only be copied between the two vectors if it meets some criterion
        
*/

void copy_ifExample() {
    vector<int> vec1{1, 2, 3, 4, 5};
    cout << "vec1: ";
    print(vec1);

    // Copy only odd numbers from vec1 into vec2
    vector<int> vec2;
    copy_if(cbegin(vec1), cend(vec1), back_inserter(vec2),
            [](int i) { return i % 2 == 1; });

    cout << "vec2: ";
    print(vec2);

    //Equivalent loop
    vector<int> vec3;
    for (const auto &v : vec1)
        if (v % 2 == 1)
            vec3.push_back(v);

    cout << "vec3: ";
    print(vec3);
}

int main() {
    cout << "Copy Algorithm" << endl;
    copyExample();
    cout << "\nCopy_n Algorithm" << endl;
    copy_nExample();
    cout << "\nCopy_if Algorithm" << endl;
    copy_ifExample();
    return 0;
}