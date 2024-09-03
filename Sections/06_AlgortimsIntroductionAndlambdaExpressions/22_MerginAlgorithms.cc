//############
// Mergin Algorithms
//############

/*
- This functions takes two iterators and assumes that the ranges are sorted
*/

//############
// merge()
//############

/*
- merge() combines two sorted iterator ranges into a destionation
- The destination will contain all the elements from both ranges, in order
- In set theory, this is the "sum" of the ranges
    - // Merge elements from vec1 and vec2 into vec3

    merge(cbegin(vec1), cend(vec1), cbegin(vec2), cend(vec2), back_inserter(vec3));

- By default, the < operator is used to order the elements of vec3

- vector<int> vec1{1, 3, 4};
- vector<int> vec2{1, 2, 3};

- merge(cbegin(vec1), cend(vec1), cbegin(vec2), cend(vec2), back_inserter(vec3));

- vec3 will contain the result of merging the elements of vec1 and vec2

- vec3 will now contain {1, 1, 2, 3, 3, 4}
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(const vector<int> &vec) {
    for (const auto &v : vec)
        cout << v << ", ";
    cout << endl;
}

void mergeExample() {
    vector<int> vec1{3, 1, 4, 1, 5, 9};
    vector<int> vec2{3, 1, 4, 2, 8};
    vector<int> vec3;

    sort (begin(vec1), end(vec1));
    cout << "vec1: ";
    print(vec1);

    sort (begin(vec2), end(vec2));
    cout << "vec2: ";
    print(vec2);

    merge(cbegin(vec1), cend(vec1), cbegin(vec2), cend(vec2), back_inserter(vec3));

    cout << "vec3 after merge(): ";
    print(vec3);
}

//############
// set_intersection()
//############

/*
- set_intersection() combines two sorted iterator ranges into a destination
- The destination will contain only the elements which are present in both ranges, in order
- In set theory, this is the "intersection" of the ranges

    - // Merge elementrs from vec1 and vec2 into vec3
    set_intersection(cbegin(vec1), cend(vec1), cbegin(vec2), cend(vec2), back_inserter(vec3));

- By default, the < operator is used to order the elements of vec3

- vector<int> vec1{1, 3, 4};
- vector<int> vec2{1, 2, 3};

- vec3 will contain the intersection of the elements of vec1 and vec2

- vec3 will now contain {1, 3}

*/

void setIntersectionExample() {
    vector<int> vec1{3, 1, 4, 1, 5, 9};
    vector<int> vec2{3, 1, 4, 2, 8};
    vector<int> vec3;

    sort(begin(vec1), end(vec1));
    cout << "vec1: ";
    print(vec1);

    sort(begin(vec2), end(vec2));
    cout << "vec2: ";
    print(vec2);

    set_intersection(cbegin(vec1), cend(vec1), cbegin(vec2), cend(vec2), back_inserter(vec3));

    cout << "vec3 after set_intersection(): ";
    print(vec3);
}


//############
// set_union()
//############

/*
- set_union() combines two sorted iterator ranges into a destination    
- the destination will contain all the elements from both ranges, in order
- Elements which are present in both ranges will only appear once

    - // Populate vec3 with the union of vec1 and vec2

    set_union(cbegin(vec1), cend(vec1), cbegin(vec2), cend(vec2), back_inserter(vec3));

- By default, the < operator is used to order the elements of vec3

- vector<int> vec1{1, 3, 4};
- vector<int> vec2{1, 2, 3};

- vec3 will contain the union of the elements of vec1 and vec2

- vec3 will now contain {1, 2, 3, 4}
*/

void setUnionExample() {
    vector<int> vec1{3, 1, 4, 1, 5, 9};
    vector<int> vec2{3, 1, 4, 2, 8};
    vector<int> vec3;

    sort(begin(vec1), end(vec1));
    cout << "vec1: ";
    print(vec1);

    sort(begin(vec2), end(vec2));
    cout << "vec2: ";
    print(vec2);

    set_union(cbegin(vec1), cend(vec1), cbegin(vec2), cend(vec2), back_inserter(vec3));

    cout << "vec3 after set_union(): ";
    print(vec3);
}

int main() {
    cout << "\nmergeExample: \n";
    mergeExample();

    cout << "\nsetIntersectionExample: \n";
    setIntersectionExample();

    cout << "\nsetUnionExample: \n";
    setUnionExample();
    return 0;
}


