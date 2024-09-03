//############
// Insert iterators
//############

/*
- An output stream iterator insters data into an output stream
- An insert iterator adds new elements to a container
- To add a new element, we assign to the insert iterator
- There are three types of iterator, which add an element at different positions
    - std::back_inserter_iterator adds an element at the end of the container
    - std::front_inserter_iterator adds an element at the beginning of the container
    - std::inserter_iterator adds an element at a specified position
*/

//############
// Insert Functions
//############

/*
- To get an insert iterator, we call "inserters" functions
- We pass the container object as the argument to the inserter
- The function returns an insert iterator for that object

    - back_inserter() returns a back_inserter_iterator
    - front_inserter() returns a front_inserter_iterator
    - inserter() returns an inserter_iterator

*/

//############
// Back_insert_iterator
//############

/*
- To add a new element at the back of the container, we assign a value to a back_inserter_iterator
- The push_back() member fucntion of the container will be called
- The value we assign will be passed as the argument to push_back()
- Every time we assign to this iterator, a nwe element is added at the back of the container
*/

#include <iostream>
#include <vector>

using namespace std;

void backInsertIteratorExample(){
    vector<int> vec;                        // Create an empty vector   

    cout << "Vector has" << vec.size() << " elements\n";
    cout << "Calling back_inserter()...\n";

    auto it = back_inserter(vec);           // Create a back_inserter_iterator

    // Assign to this iterator
    cout << "Assigning to insert iterator...\n";
    *it = 99;                               // Calls vec.push_back(99)
    *it = 88;                               // calls vec.push_back(88)

    // Vector elements are now {99, 88}
    cout << "Vector has " << vec.size() << " elements\n";

    for (auto v: vec){
        cout << v << " ";
    }
    cout << endl;
}

//############
// front_insert_iterator
//############

/*
- front_insert_iterator is similar, expect it calls push_front()  when we assign to it
    - This does not work with std::vector or std::string
*/

//############
// insert_iterator
//############

/*
- inserter() takes a second argument, which is a positional iterator
- This iterator represents the position where new elements will be added

    vector<int> vec = {1, 2, 3, 4, 5};              // Create a vector with some elements
    auto el2 = next(begin(vec));                    // Get a positional iterator to the second element

- The return value is an istert_iterator for the container at that position

    auto it = inserter(vec, el2);                    // New elements will be added after the second element

- To add a new element at this position, we assign to the insert iterator

    *it = 99;                                       // Calls vec.insert(el2, 99)
    *it = 88;                                       // Calls vec.insert(el2, 88)

*/

void insertIteratorExample(){
    vector<int> vec = {1, 2, 3, 4, 5};              // Create a vector with some elements
    
    // print out vector elements
    cout << "Vector elements: ";
    for (auto v: vec){
        cout << v << " ";
    }
    cout << endl;

    auto el2 = next(begin(vec));                    // Get a positional iterator to the second element

    auto it = inserter(vec, el2);                    // New elements will be added after the second element

    // Assign to this iterator
    *it = 99;                                       // Calls vec.insert(el2, 99)

    // vec now contains {1, 99, 2, 3, 4, 5}

    // Print out vector elements
    cout << "Vector elements: ";
    for (auto v: vec){
        cout << v << " ";
    }
    cout << endl;

    cout << "Data at el2\n";
    cout << *el2 << endl;
}

/*
NOTE: after using an insert iterator, we should not use the positional iterator again
the insert iterator may have invalidated it
*/

//############
// Applications of insert iterators
//############

/*
- Insert iterators can be used anywhere where a positional iterator is expected
- Insert iterator are useful for populating containers 
    - As arguments to algorithms that copy iterators ranges
    - In conjuction with stream iterators
*/

#include <iterator>

void main2(){
    cout << " Enter some words " << endl;

    istream_iterator<string> iis(cin);              // Create a stream iterator for cin
    istream_iterator<string> eof;                   // Empty iterator

    vector<string> vec;
    auto it = back_inserter(vec);                   // Create a back_inserter_iterator

    while (iis != eof){                             // Do we have any input to read?
        it = *iis;                                  // Add the input to the vector
        ++iis;                                      // Move to the next input
    }

    cout << " You entered " << vec.size() << " words\n";

    for (auto& w: vec){
        cout << w << " ";
    }

}
    

int main(){
    cout << endl << "back_insert_iterator Example" << endl;
    backInsertIteratorExample();

    cout << endl << "insert_iterator Example" << endl;
    insertIteratorExample();

    cout << endl << "Applications of insert iterators" << endl;
    main2();

    
    return 0;
}