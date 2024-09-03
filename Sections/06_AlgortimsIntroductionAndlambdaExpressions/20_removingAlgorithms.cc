//############
// Removing Algorithms
//############

/*
- removing algorithms are used to remove elements from a range
- however,  the elemtns are "logically" removed
- They are still physically present in the range
*/

//############
// remove()
//############

/*
- Each element which has a given value is moved to the back of the range
    - the "removed" elements still exist in the container
    - the values of the removed elements are no longer defined
    - Accessing them will cause undefined behavior

- The elements which were behind it are moved forward
    - Calling size() will return the same values as before

- remove() returns an iterator to the first removed element
*/

//############
// call top remove()
//############

/*
vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
remove(begin(vec), end(vec), 5);            // Elements with value 5 are moved to the back

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

void removeExample() {
    vector<int> vec{3, 1, 4 , 1 ,5 , 9};
    cout << "vec: ";
    print(vec);

    cout << "vec before remove(): has  " << vec.size() << " elements" << endl;

    auto defunct = remove(begin(vec), end(vec), 1);

    cout << "vec after remove() : has  " << vec.size() << " elements" << endl;

    cout << "vec after remove() : ";
    print(vec);
}

//############
// erase()
//############

/*
- To physically remove the elements, we call the container's erase() member function

- We pass the returned iterator as the first argument

vector<int> vec{3, 1, 4, 1, 5, 9};

-   // Send all elements with value 1 to the back, invalidate them, 
-   // and return an iterator to the first one

auto defunct = remove(begin(vec), end(vec), 1);         // vec: 3 4 5 9 5 9
vec.erase(defunct, end(vec));                           // vec: 3 4 5 9

- After call erase the removed elements have been physically removed from the container

*/

void eraseExample() {
    vector<int> vec{3, 1, 4, 1, 5, 9};
    cout << "vec: ";
    print(vec);

    cout << "vec before remove(): has  " << vec.size() << " elements" << endl;

    auto defunct = remove(begin(vec), end(vec), 1);

    cout << "vec after remove() : has  " << vec.size() << " elements" << endl;

    cout << "vec after remove() : ";
    print(vec);

    vec.erase(defunct, end(vec));

    cout << "vec after erase()  : has  " << vec.size() << " elements" << endl;

    cout << "vec after erase()  : ";
    print(vec);
}

//############
// Remoiving Algorithms continued
//############

/*
- there are other versions of remove() 
    - remove_if() takes a predicate
    - _copy() versions write to a destination

*/

//############
// remove_if()
//############

/*
- remove() uses the == operator to compare elements
- remove_if() uses a predicate
- this determines wheter to remove an element

vector<int> vec{3, 1, 4, 1, 5, 9};
auto defunct = remove_if(begin(vec), end(vec), [](int i) { return (n % 3) == 0; });

- // Destroy the removed elements
vec.erase(defunct, end(vec));           // vec will now contain {1, 4, 1, 5}

*/

void remove_ifExample() {
    vector<int> vec{3, 1, 4, 1, 5, 9};
    cout << "vec: ";
    print(vec);

    auto defunct = remove_if(begin(vec), end(vec), [](int i) { return (i % 3) == 0; });
    vec.erase(defunct, end(vec));

    cout << "vec after remove_if() and erase(): ";
    print(vec);
}

//############
// remove_copy()
//############

/*
- remove_copy() writes the result to a destionation
- It performs a copy operation, which omits the matching elements
vector<int> vec{3, 1, 4, 1, 5, 9};

-// Populate vec2 with {3, 4, 5, 9};
remove_copy(cbegin(vec), cend(vec), back_inserter(vec2), 1);

- This is equivalent to copying all the elements which are not equal to the value

-// Populate vec3 with {3, 4, 5, 9};

copy_if(cbegin(vec), cend(vec), back_inserter(vec3), [](int i) { return i != 1; });

*/

void remove_copyExample() {
    vector<int> vec{3, 1, 4, 1, 5, 9};
    vector<int> vec2;
    vector<int> vec3;

    cout << "vec: ";
    print(vec);

    remove_copy(cbegin(vec), cend(vec), back_inserter(vec2), 1);
    copy_if(cbegin(vec), cend(vec), back_inserter(vec3), [](int i) { return i != 1; });

    cout << "vec2 after remove_copy(): ";
    print(vec2);

    cout << "vec3 after copy_if()   : ";
    print(vec3);
}

//############
// remove_copy_if()
//############

/*
- remove_copy_if() is similar, but takes a lambda
    remove_copy_if(cbegin(vec), cend(vec), back_inserter(vec2), [](int i) { return i % 3 == 0; });

    - // vec3 will now contain {1, 4, 1, 5}

- This cal also be rewritten using copy_if()

    copy_if(cbegin(vec), cend(vec), back_inserter(vec3), [](int i) { return i % 3 != 0; });

*/

void remove_copy_ifExample() {
    vector<int> vec{3, 1, 4, 1, 5, 9};
    vector<int> vec2;
    vector<int> vec3;

    cout << "vec: ";
    print(vec);

    remove_copy_if(cbegin(vec), cend(vec), back_inserter(vec2), [](int i) { return i % 3 == 0; });
    copy_if(cbegin(vec), cend(vec), back_inserter(vec3), [](int i) { return i % 3 != 0; });

    cout << "vec2 after remove_copy_if(): ";
    print(vec2);

    cout << "vec3 after copy_if()       : ";
    print(vec3);
}

//############
// unique()
//############

/*
- unique()  removes duplicate adjacent elements
- the elements in the iterator range must be sorted
- unique() behaves similarly to remove() in that the elements are only "logically" removed
- To physically remote them, pass the returned iterator to erase()

vector<int> v{3, 1 ,4, 1, 5, 9};

- // Sort the vector so that duplicate elements are adjacent 
sort(begin(v), end(v));                         // v: 1 1 3 4 5 9
auto defunct = unique(begin(v), end(v));        // v: 1 3 4 5 9 9
v.erase(defunct, end(v));                       // v: 1 3 4 5 9
*/

void uniqueExample() {
    vector<int> v{3, 1, 4, 1, 5, 9};
    cout << "v: ";
    print(v);

    // Sort the vector so that duplicate elements are adjacent to each other
    sort(begin(v), end(v));

    cout << " Sorted vector: ";
    print(v);

    cout << " before calling unique, the vector has " << v.size() << " elements" << endl;
    auto defunct = unique(begin(v), end(v));

    cout << " before calling erase, the vector has " << v.size() << " elements" << endl;
    v.erase(defunct, end(v));

    cout << " after calling erase, the vector has " << v.size() << " elements" << endl;
    cout << "v after unique() and erase(): ";
    print(v);
}

//############
// unique() with predicate
//############

/*
- unique() uses the == operator
- we can also provide our own predicate
    -// if an element is greater by 1 than the previous element, remove it

    auto defunct = unique(begin(v), end(v), [](int a, int b) { return a + 1 == b; });
*/

void uniquePredicateExample() {
    vector<int> v{3, 1, 4, 1, 5, 9};
    cout << "v: ";
    print(v);

    // Sort the vector so that duplicate elements are adjacent to each other
    sort(begin(v), end(v));

    cout << " Sorted vector: ";
    print(v);

    cout << " before calling unique, the vector has " << v.size() << " elements" << endl;
    auto defunct = unique(begin(v), end(v), [](int a, int b) { return a + 1 == b; });

    v.erase(defunct, end(v));
    cout << "v after unique() and erase(): ";
    print(v);
}

//############
// unique_copy()
//############

/*
- unique_copy() writes the result to a destination
- It performs a copy operation, which omits duplicates of elements
- it can also take predicate

unique_copy(begin(vec), end(vec), back_inserter(vec2));

- // If an element is greater by 1 than the previous element, remove it

unique_copy(begin(vec), end(vec), back_inserter(vec3), [](int a, int b) { return a == b + 1; });

*/

void unique_copyExample() {
    vector<int> vec{3, 1, 4, 1, 5, 9};
    vector<int> vec2;
    vector<int> vec3;

    cout << "vec: ";
    print(vec);

    // Sort the vector so that duplicate elements are adjacent to each other
    sort(begin(vec), end(vec));

    cout << " Sorted vector: ";
    print(vec);

    unique_copy(begin(vec), end(vec), back_inserter(vec2));
    unique_copy(begin(vec), end(vec), back_inserter(vec3), [](int a, int b) { return b == a + 1; });

    cout << "vec2 after unique_copy(): ";
    print(vec2);

    cout << "vec3 after unique_copy() with predicate: ";
    print(vec3);
}

int main() {
    cout << "remove() example:" << endl;
    removeExample();
    cout << "\nerase() example:" << endl;
    eraseExample();
    cout << "\nremove_if() example:" << endl;
    remove_ifExample();
    cout << "\nremove_copy() example:" << endl;
    remove_copyExample();
    cout << "\nremove_copy_if() example:" << endl;
    remove_copy_ifExample();
    cout << "\nunique() example:" << endl;
    uniqueExample();
    cout << "\nunique() with predicate example:" << endl;
    uniquePredicateExample();
    cout << "\nunique_copy() example:" << endl;
    unique_copyExample();

    return 0;
}