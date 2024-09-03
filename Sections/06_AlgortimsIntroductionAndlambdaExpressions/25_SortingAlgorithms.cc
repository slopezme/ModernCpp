//############
// Sorting Algorithms
//############

/*
- Sorting Algorithms put the elements in an iterator range into order
- By default, the elemtents < operator is used to compare the elements
- We can override this by providing a custom comparison function

*/

//############
// sort()
//############

/*
- sort() orders the elements in ascending order
- usually implemented as a "quicksort"
- Elements which have the same key may have their order changed

sort(begin(students), end(students));           // Sort  the elements using < operator
*/

//############
// sort() with predicate
//############

/*
- we can supply a comparison function as an optional argument
- This will be used instead of the < operator to order the elements

vector<int> v = {3, 1, 4, 1, 5, 9};

sort(begin(v), end(v), [](int a, int b) { return a > b; });    // Sort in descending order

*/

//############
// is_sorted()
//############

/*
- is_sorted() returns a bool, depending on whether the iterator range is sorted

    is_sorted(cbegin(students), cend(students));    // True if the elements are sorted

*/


//############
// is_sorted_until()
//############

/*
- is_sorted_until() returns an iterator to the first element which is not in order

    vector<int> vec = {1, 4, 5, 6, 2, 7, 5};

    is_sorted_until(cbegin(vec), cend(vec));    // Returns an iterator to the 2

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(const vector<int>& v) {
    for (int i : v) {
        cout << i << ", ";
    }
    cout << endl;
}

void sortExample() {
        vector<int> v = {3, 1, 4, 1, 5, 9};

    cout << "Before sorting: " << endl;
    print(v);
    cout << "vec is sorted:  " << boolalpha <<  is_sorted(cbegin(v), cend(v)) << endl;

    sort(begin(v), end(v));

    cout << "vec is sorted:  " << boolalpha <<  is_sorted(cbegin(v), cend(v)) << endl;

    cout << "After sorting: " << endl;
    print(v);

    sort(begin(v), end(v), [](int a, int b) { return a > b; });
    print(v);

    cout << "vec is sorted in ascending order " << boolalpha <<  is_sorted(cbegin(v), cend(v), 
     [](int a, int b) { return a > b; }) << endl;
    

}

void sortUntilExample() {
    vector<int> vec = {1, 4, 5, 6, 2, 7, 5};

    cout << "vec is sorted:  " ;
    print(vec);

    auto it = is_sorted_until(cbegin(vec), cend(vec));

    if (it == cend(vec)) {
        cout << "the first " << distance(cbegin(vec), it) << " elements are sorted\n"; 
        cout << " The first element which is not in order has value " << *it << endl;
    }
    else{
        cout << "The first element which is not in order has value " << *it << endl;
    
    }

}


//############
// partial_sort()
//############

/*
- sometimes we only need to sort part of a container
    e.g. display the first 20 results only

- In this case, we can use a partial sort
    - The first 20 elements will be in order
    - The elmenents which come after these will not be ordered

- This is faster than doing a complete sort

- partial_sort() takes an extra iterator
- The offset of this iterator gives the number of elements we want in the result

- e.g begin() + 5 gives the first 5 results

    string keys{"qwertyuiopasdfghjkl"};

    partial_sort(begin(keys), begin(keys) + 5, end(keys));      // sort the first 5 elements
*/

void partialSortExample() {


    string keys{"qwertyuiopasdfghjkl"};
    cout << "keys" << keys << endl << endl;

    auto it = begin(keys);

    partial_sort(it, it + 5, end(keys));

    cout << "The first 5 elements of keys are: " << keys.substr(0, 5) << endl;
    cout << "Full keys string is: " << keys << endl << endl;

    advance(it, 5);         // Move the iterator to the 5th element
    partial_sort(it, it + 5, end(keys));

    cout << "The next 5 elements of keys are: " << keys.substr(5, 5) << endl;
    cout << "Full keys string is: " << keys << endl << endl;


}

//############
// partial_sort_copy()
//############

/*
- partial_sort_copy() does a partial sort and stores the result in a different container

    partial_sort_copy(cbegin(keys), cend(keys), begin(result), end(result));

- This will sort as many elements as will fit into "result" and writhe them there
    - if the destionation is large enough, it will sort the entire range

*/

void partialSortCopyExample() {

    string keys{"qwertyuiopasdfghjkl"};
    string result(5, ' ');

    cout << "keys" << keys << endl << endl;

    partial_sort_copy(cbegin(keys), cend(keys), begin(result), end(result));

    cout << "The first 5 elements of keys are: " << result << endl;
    cout << "Full keys string is: " << keys << endl << endl;

    // result2 with same size as keys

    string result2(keys.size(), ' ');

    partial_sort_copy(cbegin(keys), cend(keys), begin(result2), end(result2));

    cout << "Full result2 is: " << result2 << endl;

}

//############
// nth_element()
//############

/*
- nth_element() takes an iterator to an element in the range
- it rearranges the element so that the iterator points to the element 
that would be in that position if the range was sorted
    - e.g if the iterator is begin() + 3
    - The iterator will porint to the element which ranks 4th

- It then performs a partition with this element as the partition point
    - All the elements before it will have a lower value
    - All the elements after it will no have a lower value


*/

void nthElementExample() {

    vector<int> vec{1, 4, 5, 6, 2, 7, 5};
    vector<int> vec2{vec};
    sort(begin(vec2), end(vec2));

    cout << "vec:           ";
    print(vec);

    cout << "vec if sorted: ";
    print(vec2);

    cout << endl << "Calling nth_element" << endl;

    auto mid = begin(vec) +  4;

    nth_element(begin(vec), mid, end(vec));

    cout << "The mid element is " << *mid << endl;

    cout << "vec: ";
    print(vec);
}

int main() {

    cout << "Sorting Algorithms" << endl;
    sortExample();

    cout << "\nis_sorted_until()" << endl;
    sortUntilExample();

    cout << "\npartial_sort()" << endl;
    partialSortExample();

    cout << "\npartial_sort_copy()" << endl;
    partialSortCopyExample();

    cout << "\nnth_element()" << endl;
    nthElementExample();



    return 0;
}