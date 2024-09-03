//############
// mismatch()
//############

/*
- mismatch() takes two iterator ranges and looks for differences between the two ranges
- It returns a pair to the first element that has a different value in each range

vector<int>  vec1{1,2,2,3,2,3,3};
vector<int>  vec2{1,2,2,2,2,3,3};       // The vector differ at the fourth element

- // Returns a pair of iterators to the fourth element of each vector

auto elems = mismatch(cbegin(vec1), cend(vec1), cbegin(vec2), cend(vec2));
cout << *elems.first;  // 3             // Display 3
cout << *elems.second; // 2             // Display 2

- By default, the == operator of the elements is used to compare them
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vec(const vector<int>& vec){
    for (const auto& v: vec){
        cout << v << " ";
    }
    cout << endl;
}

void main1() {
    vector<int> vec1{1,2,2,3,2,3,3};
    vector<int> vec2{1,2,2,2,2,3,3};       // The vector differ at the fourth element

    cout << "Vector 1: ";
    print_vec(vec1);
    cout << "Vector 2: ";
    print_vec(vec2);

    // Returns a pair of iterators to the fourth element of each vector
    auto elems = mismatch(cbegin(vec1), cend(vec1), cbegin(vec2), cend(vec2));

    // elem is a pair of iterators to the corresponding elements in the two ranges
    if (elems.first != cend(vec1) && elems.second != cend(vec2)){
        cout << "Found mismatch at index " << distance(cbegin(vec1), elems.first) << endl;
        cout << "Vector has " << *elems.first << " , vec2 has " << *elems.second << endl;
    }
} 

//############
// "some of" algorithms
//############

/*
- These three algorithms take an iterator range and a predicate
    - all_of() returns true if the predicate is true for all elements
    - any_of() returns true if the predicate is true for at least one element
    - none_of() returns true if the predicate is false for all elements

    vector<int> vec{3,1,4,1,5,9};

    all_of(cbegin(vec), cend(vec), is_odd);     // Returns false
    any_of(cbegin(vec), cend(vec), is_odd);     // Returns true
    none_of(cbegin(vec), cend(vec), is_odd);    // Returns false


*/

void main2(){
    vector<int> vec{3,1,4,1,5,9};
    cout << "vec: ";
    print_vec(vec);

    auto is_odd = [](int i){return i % 2 != 0;};
    auto is_even = [](int i){return i % 2 == 0;};

    if(all_of(cbegin(vec), cend(vec), is_odd))
        cout << "All elements of vec are odd \n";
    if(all_of(cbegin(vec), cend(vec), is_even))
        cout << "All elements of vec are even \n";
    if(any_of(cbegin(vec), cend(vec), is_odd))
        cout << "vec has at least one odd element \n";
    if(any_of(cbegin(vec), cend(vec), is_even))
        cout << "vec has at least one even element \n";
    if(none_of(cbegin(vec), cend(vec), is_odd))
        cout << "vec has no odd elements \n";
    if(none_of(cbegin(vec), cend(vec), is_even))
        cout << "vec has no even elements \n";
}

//############
// binary_search()
//############

/*
- binary_search() is similar to find()
- It assumes the iterator range is sorted, which makes the search much faster

if(binary_search(cbegin(vec), cend(vec), 4))
    cout << "Found 4 in vec\n";

- By default, it uses the == operator of the elements to compare them
*/

void main3(){
    vector<int> vec{3,1,4,1,5,9};

    //sort vector 
    sort(begin(vec), end(vec));

    cout  << "Sorted vec: ";
    print_vec(vec);

    if(binary_search(cbegin(vec), cend(vec), 4))
        cout << "Found 4 in vec\n";
    else
        cout << "4 not found in vec\n";

    if(binary_search(cbegin(vec), cend(vec), 8))
        cout << "Found 8 in vec\n";
    else
        cout << "8 not found in vec\n";

}

//############
// includes()
//############

/*
- includes() takes two iterator ranges
- it also assumes the iterator ranges are sorted
- includes() returns a bool, depending on wheter all the elements in the second 
range are present in the first range

    - // Does str contain all the vowels, at least once?

    if(includes(cbegin(str), cend(str), cbegin(vowels), cend(vowels)))
        cout << "All vowels are present in str\n";
    else
        cout << "Not all vowels are present in str\n";

- By default, it uses the == operator of the elements to compare them
*/

void main4(){
    string str{"Hello World!"};
    cout << "String to search: " << str << endl;

    string vowels{"aeiou"};

    // Sort both the strings
    sort(begin(str), end(str));
    sort(begin(vowels), end(vowels));\

    cout << "Sorted str: " << str << endl;
    cout << "Sorted vowels: " << vowels << endl;

    if(includes(cbegin(str), cend(str), cbegin(vowels), cend(vowels)))
        cout << "All vowels are present in str\n";
    else
        cout << "Not all vowels are present in str\n";
}


int main(){
    cout <<  "\nExample 1: \n" << endl;
    main1();

    cout <<  "\nExample 2: \n" << endl;
    main2();

    cout <<  "\nExample 3: \n" << endl;
    main3();

    cout <<  "\nExample 4: \n" << endl;
    main4();
}

