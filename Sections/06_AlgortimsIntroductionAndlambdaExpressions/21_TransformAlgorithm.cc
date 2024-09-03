
//############
// transform()
//############

/*
- transform() will call a given function on every element in a range
- the result is copied into a destination
    - // Double each element in vec and use the results to popolate vec2

    transform(begin(vec), end(vec), back_inserter(vec2), [](int i) { return i * 2; });

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

void transformExample() {
    vector<int> vec{3 , 1, 4, 1, 5, 9};
    vector<int> vec2;
    vector<int> vec3;

    cout << "vec: ";
    print(vec);

    transform(begin(vec), end(vec), back_inserter(vec2), [](int i) { return i * 2; });

    cout << "vec2: ";
    print(vec2);

    // Equivalent loop 
     for (const auto &v : vec)
        vec3.push_back(v * 2);

    cout << "vec3: ";
    print(vec3);
}

//############
// In - place transformation
//############

/*
- The destination iterator is allowed to overlap the source
- This allows us to do an in - place transformation

    - // Double each element in vec

    transform(begin(vec), end(vec), begin(vec), [](int i) { return i * 2; });
*/

void inPlaceTransformExample() {
    vector<int> vec{3, 1, 4, 1, 5, 9};

    cout << "vec: ";
    print(vec);

    transform(begin(vec), end(vec), begin(vec), [](int i) { return i * 2; });

    cout << "vec after in-place transform: ";
    print(vec);
}

//############
// Transform() overloaded
//############

/*
- There is an overload of transform() which a second iterator range
- The function will take two arguments, an element from each range
- The result is stored in the destination

    -// Populate vec3 with results of adding together elements from vec1 and vec2

    transform(cbegin(vec1), cend(vec1), cbegin(vec2), back_inserter(vec3), [](int i, int j) { return i + j; });

*/

void transformOverloadExample() {
    vector<int> vec1{3, 1, 4, 1, 5, 9};
    vector<int> vec2;
    vector<int> vec3;

    cout << "vec1: ";
    print(vec1);

    transform(begin(vec1), end(vec1), back_inserter(vec2), [](int i) { return i * 2; });

    cout << "vec2: ";
    print(vec2);

    transform(cbegin(vec1), cend(vec1), cbegin(vec2), back_inserter(vec3), [](int i, int j) { return i + j; });

    cout << "vec3: ";
    print(vec3);

    // Equivalent loop
    vector<int> vec4;

    for (size_t i = 0; i < vec1.size(); ++i)
        vec4.push_back(vec1[i] + vec2[i]);
    
    cout << "vec4: ";
    print(vec4);
}

//############
// Case - insensitive string comparison
//############

/*
- we can use transform() to implement equal_strings()
    -// Case - insensitive string equality. Returns trui if lhs and rhs are equal, otherwise false

    bool equal_strings(const string &lhs, const string &rhs) ;

- Make a copy of the argument string
- use transform() to convert the copies to upper case
- Call std::string operator == to compare them
*/

bool equal_strings(const string &lhs, const string &rhs) {
    // Copy the arguments
    string lhs_copy = lhs;
    string rhs_copy = rhs;

    // Convert to upper case
    transform(begin(lhs_copy), end(lhs_copy), begin(lhs_copy), ::toupper);
    transform(begin(rhs_copy), end(rhs_copy), begin(rhs_copy), ::toupper);

    // Compare the results
    return lhs_copy == rhs_copy;
}

void test(const string &str1, const string &str2) {
    cout << str1 << " and " << str2 << " are " << (equal_strings(str1, str2) ?  "" : "not ") << "equal" << endl;
}


int main() {
    cout << "\nremoveExample():" << endl;
    transformExample();

    cout << "\ninPlaceTransformExample():" << endl;
    inPlaceTransformExample();

    cout << "\ntransformOverloadExample():" << endl;
    transformOverloadExample();

    cout << "\nCase-insensitive string comparison:" << endl;
    test("lambda", "Lambda");
    test("lambda", "lambada");

    return 0;
}