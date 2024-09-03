//############
// Write Only Algorithms
//############

/*
- The standard library defines a few algorithms that write to an iterator
range, but do not read any elements

- These are useful for populating sequential containers
*/

//############
// fill ()
//############

/*
- fil() assigns a given value to the elements in an iterator range

    vector<int> vec(10);                // Vector with 10 elements
    fill(vec.begin(), vec.end(), 5);     // Assign 5 to all elements

- This is equivalent to the following loop

    for (auto &v : vec)
        v = 5;
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void fillExample() {
    vector<int> vec(10);
    fill(vec.begin(), vec.end(), 5);

    cout << "\nVector populated with fill():" << endl;

    for (auto &v : vec)
        cout << v << " ";
    cout << endl << endl;

    vector<int> vec2(10);
    for (auto &v : vec2)
        v = 5;

    cout << "Vector populated with loop:" << endl;

    for (auto &v : vec2)
        cout << v << " ";
    cout << endl << endl;
}

//############
// fill_n ()
//############

/*
- fill_n() is similar, but takes a number instead of the second iterator
- this determines how many elements will be assigned
    - Starting from the first iterator

- It will return an iterator pointing to the element after the last one which was assigned

    -// Assign 42 to the first 5 elements and 99 tothe rest

    auto begin_rest = fill_n(vec.begin(), 5, 42);       // Returns an iterator to the 6th element
    fill(begin_rest, vec.end(), 99);                    // Assign the remaining elements to be 99


*/

void fill_nExample() {
    // Assign the first 10 elements to 42 and the rest to 99
    vector<int> vec(10);

    auto begin_rest = fill_n(vec.begin(), 5, 42);
    fill(begin_rest, vec.end(), 99);

    cout << "Vector populated with fill_n():" << endl;

    /*
    int i;
    for (i = 0; i < 5; ++i)
        vec[i] = 42;
    for (; i < 10; ++i)
        vec[i] = 99;
    */

    for (auto &v : vec)
        cout << v << " ";
    cout << endl << endl;
}

/*
NOTE: this is potentially dangerous because we are not checking the size of the vector
*/

void main3() {
    vector<int> vec;                    // Empty vector    
    int n = 5;                          // Number of elements to assign  
    // Resize vec to have n elements
    if (vec.size() < n){
        vector<int> new_vec(n);
        vec.swap(new_vec);
    }
    // This is a good technique to resize a vector, the allocation from vec and new_vec will be swapped
    // once the scope of the function ends, new_vec will be destroyed and vec will have the new size

    auto begin_rest = fill_n(vec.begin(), 5, 42);

    for (auto &v : vec)
        cout << v << " ";
    cout << endl << endl;
}

// Another option is to use an insert iterator

void main4() {
    vector<int> vec;                    // Empty vector    
    int n = 5;                          // Number of elements to assign  
    // Resize vec to have n elements
    auto begin_rest = fill_n(back_inserter(vec), 5, 42);

    /*
    for (int i = 0; i < 5; ++i)
        vec.push_back(42);
    */

    for (auto &v : vec)
        cout << v << " ";
    cout << endl << endl;
}

//############
// generate()
//############

/*
- generate() uses the value returned from calling a function to assign the elements
    - This function takes no arguments
    - it returns a value of the element type
    - it should return a different value each time it is called

    class square{
    private:
        int n{0};
        public:
        int operator()() {++n ; return n * n; }
    };

    vector<int> vec(10);                            // Define vector with 10 elements
    generate(vec.begin(), vec.end(), square());     // Populate it with the first 10 squares

*/

class square{
private:
    int n{0};
    public:
    int operator()() {++n ; return n * n; }
}; 

void main5() {
    vector<int> vec(10);
    generate(vec.begin(), vec.end(), square());

    /*
    square sq;
    for (auto &v : vec)
        v = sq();
    */

    for (auto &v : vec)
        cout << v << " ";
    cout << endl << endl;
}

//############
// generate_n()
//############

/*
- generate_n() has the same relation to generate() as fill_n() has to fill()
- It assigns the specified number of elements and returns an iterator to the first
untoched element

    -// Populate the first 10 elements with square

    vector<int> vec;
    generate_n(back_inserter(vec), 10, square());

*/

void main6() {
    vector<int> vec;
    generate_n(back_inserter(vec), 10, square());

    /*
    square sq;
    for (int i = 0; i < 10; ++i)
        vec.push_back(sq());
    
    */

    for (auto &v : vec)
        cout << v << " ";
    cout << endl << endl;
}

int main() {
    cout << "fill() Example" << endl;
    fillExample();

    cout << "fill_n() Example" << endl;
    fill_nExample();

    cout << "main3() Example" << endl;
    main3();

    cout << "main4() Example" << endl;
    main4();

    cout << "main5() Example" << endl;
    main5();

    cout << "main6() Example" << endl;
    main6();

    return 0;
}

