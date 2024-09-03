//###########
//#  Set
//###########

/*
- A set is an unstructured collections of elements
- The C++ library provides std::set in <set>
- This is an associative container
- An element consists only of a key, which must be unique
    - No duplicates allowed
- The elements of std::set are stored in order
    - By default, the < operator of the key is used to sort the elements
- For efficiency, std::set is implemented as a tree 
    - usually a red balck tree

*/

//###########
//#  Adding and removing elements
//###########

/*
- we use insert() to add an element
    - The set will add the new element in the right place in the tree
- we use erase() to remove an element
- these operations may cause thge tree to become unbalanced
*/

//###########
//#  Did it work?
//###########

/*
- if we try to insert an element into a std::set that is already present the insert will fail

- why?

- insert() returns a std::pair
- The second memeber is a boolean which is true/false depending on whether the insert was successful
- The first member is an iterator to an element in the set
    - the newly added element, if successful
    - The existing element with that key, if unsuccessful

*/


#include <iostream>
#include <set>

using namespace std;

void print (const set<int>& s){
    cout << "elements of set: ";
    for (int i : s){
        cout << i << " ";
    }
    cout << endl;
}

void setExample(){
    set<int> s;
    print(s);

    s.insert(4);
    s.insert(2);
    s.insert(1);
    s.insert(5);
    s.insert(3);
    print(s);

    auto result = s.insert(3);
    if (result.second){
        cout << "3 was inserted\n";
    } else {
        cout << "3 was not inserted\n";
    }
    print(s);

    s.erase(3);
    print(s);
}

//###########
//#  Finding elements
//###########

/*
s.find(k) returns an iterator to the element with key k
    - or end() if k is not found
- s.count(k) returns the number of elements with key k
    - since duplicates are not allowed, this can only be 0 or 1

*/

void findExample(){
    set<int> s{4, 2, 1, 5, 3};
    print(s);

    auto it = s.find(3);
    if (it != s.end()){
        cout << "3 was found\n";
    } else {
        cout << "3 was not found\n";
    }

    cout << "There are " << s.count(3) << " 3s\n";
    cout << "There are " << s.count(6) << " 6s\n";

}

//###########
//#  std::set and algorithms
//###########

/*
- Ther elements of std::set are const
- Also, the elements cannot be reordered
    - why?

- This means that many algorithms cannot be used with std::set
- We can use algorithms which read a range of std::set iterators
    
    auto it = find_if(cbegin(s), cend(s), [](int i){return i == 7;});

*/

#include <algorithm>

void find_ifExample(){
    set<int> s{4, 2, 1, 5, 3};
    auto it = find_if(cbegin(s), cend(s), [](int i){return i == 7;});
    if (it != cend(s)){
        cout << "The set as an element with value 7\n";
    } else {
        cout << "The set does not have an element with value 7\n";
    }

}

//###########
//#  std::set Pros and Cons
//###########

/*
- Very fast at accessing an arbitrary element
- insertion and deletion are usually very fast
    - Can be slow if the internal tree gets unbalanced
- Useful for checking membership (or non - membership) of an element
- useful when duplicate data is either not needed or not wanted
    - e.g. the number of disinct words in a document

*/

int main(){
    setExample();
    findExample();
    find_ifExample();
    return 0;
}