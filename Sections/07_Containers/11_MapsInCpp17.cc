//###########
//# C++17 Structured Bindings
//###########

/*
C++17 Introduced the structured bindings feature
This is an easy way to access data structures
In a single statement, we
    - Declare local variables
    - Bind them to members of a compund data strcuture
    - The types are deduced by the compiler

*/

//###########
//# Structured Bindings
//###########

/*
With auto in C++11, the compiler can deduce the type of a single variable, given a scalar initializer
    auto i = 42;

In C++17, this has been extended to work with multiple variables and compund initializer
    - Each variable will be initilized from a mber of compund value
    - The compiler deduces the type of each variable

For example, we can initialize two variables from an std::pair
    pair p(1,3.142);        // std::pair<int, double>

The compiler will deduce the type of each variable from the corresponding element in the initializer

auto[i,d] = p;             // i => int, d => double
*/

#include <iostream>

using namespace std;

void StructuredBindings(){
    pair<int, double> p(1, 3.142);
    auto[i, d] = p;

    cout << "i => " << i << endl;
    cout << "d => " << d << endl;

}

//###########
//# Loops And Structured Bindings
//###########

/*
- Structured binding can make map loops more readable
    - C++11/14
    for(auto el: scores){
        cout << el.first << " has a score of  " << el.second << endl;
    }

    C++17
    for(auto [name, score]: scores){
        cout << name << " has a score of " << score << endl;
    }


*/

#include <map>
#include <string>

void print(const map<string, int> &scores){
    cout << "Map Elements: " << endl;
    for(auto it = scores.begin(); it != scores.end(); ++it){
        cout << it->first << " : " << it->second << endl;
    }
    cout << endl;
}

void mapExample1(){
    map<string, int> scores;
    scores.insert(make_pair("John", 90));
    scores.insert(make_pair("Paul", 80));

    cout << "Map Elements: " << endl;
    print(scores);

    cout << "Using structured bindings" << endl;
    cout << "Map elements: " << endl;
    for(auto [name, score]: scores){
        cout << name << " has a score of " << score << endl;
    }



}

//###########
//# Checking std::map insert() in C++17
//###########

/*
With a structured binding, checking the return value from insert() is much simpler

    -// Returns std::pair<std::map<string, int>::iterator, bool>

    auto[iter, success] = scores.insert(make_pair("Paul", 60));

    if (success)
        cout << "Insertion successful" << endl;
    else
        auto[name, score] = *iter;          // Get the members of the pair
        cout << "Insertion failed. Element with key " << name << " already exists" << endl;
    }

*/


//###########
//# insert_or_assign() 
//###########

/*
C++17 provides insert_or_assign() 
This takes two arguments
    - The new element key
    - Its value
The returned value is an std::pair
    - The first member is an iterator to the element
        - The new element on insertion
        - The old element on assignment
    - The Second memeber is a bool
        - true on insertion
        - false on assignment

The values type does not need to have a default constructor
If an exception is thrown during the operation, the insertion has no effect

    auto res = scores.insert_or_assign("Paul", 60);

    auto iter = res.first;
    if (res.second)
        -//The new element was inserted
    else{
        -// An existing element was assigned
    }
*/

void mapExample2(){
    map<string, int> scores;
    scores.insert(make_pair("John", 90));
    scores.insert(make_pair("Paul", 80));

    cout << "Map Elements: " << endl;
    for (auto [name, score]: scores){
        cout << name << " has a score of " << score << endl;
    }
    cout << endl;

    auto [iter, success] = scores.insert_or_assign("Paul", 60);
    auto [name, score] = *iter;

    if (success)
        cout << "Insertion successful" << endl;
    else
        cout << "Insertion failed. Element with key " << name << " already exists" << endl;

    cout <<endl << "Map elements: " << endl;
    for (auto [name, score]: scores){
        cout << name << " has a score of " << score << endl;
    }
}






int main(){
    cout << "Structured Bindings" << endl;
    StructuredBindings();

    cout << "Map Example 1" << endl;
    mapExample1();

    cout << "Map Example 2" << endl;
    mapExample2();
    return 0;
}
