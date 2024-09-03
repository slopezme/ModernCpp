
//############
// Algorithm with if_versions
//############

/*
- many algortihms have two versions
    - the base version which takes a value argument
    - An _if() version which takes a predicate argument

- find() takes a value and searches for the first element that matches the value
- find_if()  takes a predicate function and searches for the first element that satisfies the predicate

- we can use a functor to provide this predicate
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

//Functor

class ge_5{
    public:
    // Overloaded () operator
    // Takes an std::string, returns true if the string has more thant 5 characters
        bool operator() (const string &s) const{
            return s.size() > 5;
        }
};

void main1(){
    // Manually coded example
    vector<string> names {"Dilbert", "PHB", "Dogbert", "Asok", "Ted", "Alice", "Wally"};

    ge_5 long_enough;
    for (auto name : names){
        if (long_enough(name)){
            cout << "Loop: the first name with > 5  characters is: \"" << name << "\"n";
            break;
        }
    }

// Find the first element with more than 5 characters
// pass a functor object as predicate

auto res = find_if(cbegin(names), cend(names), ge_5());

// Display it
if (res != cend(names))
    cout << "Algorithm: the first name with > 5 characters is: \"" << *res << "\"n";

}

//############
// pseudo - implementation of find_if()
//############

/*
-//Aceepts any container with elements of any type

iter find_if(iter begin, iter end, Callable func){
    for(iter it = begin; it != end; ++it){          //Loop over range, stopping before "last"
        if (func(*it))                              // is this the value we are looking for?
            return it;                              // its is - stop looping and return the caller
    }
    return end;                                     // End of range, no match found
}
*/

void main2(){
    vector<string> names {"Dilbert", "PHB", "Dogbert", "Asok", "Ted", "Alice", "Wally"};

    cout << endl << endl;
    // Find the first element with not more than 5 characters
    // pass a functor object as predicate
    auto res = find_if_not(cbegin(names), cend(names), ge_5());

    // Display it
    if (res != cend(names))
        cout << "Algorithm: the first name with <= 5 characters is: \"" << *res << "\"n";
}

// generalize version for any number of characters

class ge_n{
    private:
        const int n;
    public:
        ge_n(const int n) : n(n) {}

        bool operator() (const string &str) const{
            return str.size() > n;
        }
};

void main3(){
    vector<string> names {"Dilbert", "PHB", "Dogbert", "Asok", "Ted", "Alice", "Wally"};

    cout << endl << endl;
    // Find the first element with not more than 5 characters
    // pass a functor object as predicate
    auto res = find_if(cbegin(names), cend(names), ge_n(5));

    // Display it
    if (res != cend(names))
        cout << "Algorithm: the first name with > 5 characters is: \"" << *res << "\"n";
}

int main(){
    main1();
    main2();
    main3();
}







