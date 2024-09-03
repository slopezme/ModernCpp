//############
// Reordering Algorithms
//############

/*
- A reordering algorithm re-arranges the elements inside an iterator range
- It does not change thier values
*/

//############
// reverese()
//############

/*
- reverse()  takes the elements in an iterator range and reverses their order

reverse(begin(vec), end(vec));

- Ther4e is aslo a _copy() version

reverse_copy(begin(vec), end(vec), back_inserter(vec2));
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

void reverseExample() {
    vector<int> vec{3, 1, 4, 1, 5, 9};
    vector<int> vec2;

    cout << "vec: ";
    print(vec);

    // make copy of original vector for use in loop later
    copy(begin(vec), end(vec), back_inserter(vec2));

    reverse(begin(vec), end(vec));

    cout << "vec after reverse(): ";
    print(vec);

    // use a loop to reverse the elemtns
    size_t len{vec2.size() - 1};

    for (int i = 0; i <= len / 2; ++i){
        /* This is the inneficient solution
        int temp{vec2[i]};
        vec2[i] = vec2[len - i];
        vec2[len - i] = temp;
        */
       swap(vec2[i], vec2[len - i]);
    }
    
    cout << " Result of loop reverse: ";
    print(vec2);

}

//############
// rotate()
//############

/*
- rotate() performs a rotation about a given element
- All the elements before the pivot are moved to the back of the range
- The pivot and all the elements behind it are moved to the front of the iterator range

{1, 2, 3, 4, 5} rotated about 3 will result in {3, 4, 5, 1, 2}

Elements before 3 move to the back

- rotate() takes three arguments
    - the beggining of the range
    - An iterator to the pivot element
    - The end of the range
- The return value is an iterator to the original first element
    - auto pivot = begin(vec); 
    -advance(pivot, 2);             // Use the third element as the pivot

    auto res = rotate(begin(vec), pivot, end(vec));

    - // res is an iterator to the element with a value 1
*/

void rotateExample() {
    vector<int> vec{1, 2, 3, 4, 5};

    cout << "vec: ";
    print(vec);

    // use 3 element as pivot

    auto pivot = begin(vec);
    advance(pivot, 2);

    // performs the rotation
    auto res = rotate(begin(vec), pivot, end(vec));

    cout << "vec after rotate(): ";
    print(vec);

    // res is an iterator to the element with a value 1
    cout << "Result of rotate(): " << *res << endl;



}

//############
// rotate_copy()
//############

/*
- rotate_copy() writes the result to a destination
- The return value is an iterator to the last plus one element written to the destination

auto pivot = begin(vec);
advance(pivot, 2);              // use the third element as the pivot

-// Perform the rotation 
auto res = rotate_copy(begin(vec), pivot, end(vec), begin(vec2));
-// res is an iterator to the element in vec2 with a value 2

*/

void rotateCopyExample() {
    vector<int> vec{1, 2, 3, 4, 5};
    vector<int> vec2(5);

    cout << "vec: ";
    print(vec);

    auto pivot = begin(vec);
    advance(pivot, 2);

    auto res = rotate_copy(begin(vec), pivot, end(vec), begin(vec2));

    cout << "vec2 after rotate_copy(): ";
    print(vec2);

    // res is an iterator to the element in vec2 with a value 2
    cout << "Last element copied was  " << *(res - 1) << endl;
}

int main() {

    cout << "\nreverseExample: " << endl;
    reverseExample();

    cout << "\nrotateExample: " << endl;
    rotateExample();

    cout << "\nrotateCopyExample: " << endl;
    rotateCopyExample();
    return 0;
}