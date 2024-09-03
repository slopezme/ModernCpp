//###########
//# Seaching Multimaps
//###########

/*
We can use find() and count() to find elements in a multiset of multimap which have the same key
It would be useful if we could get an iterator range for these elements
std::multimap and std::multiset have member functions which do this
There are also generic versions in <algorithm>
    - These are useful for working with sequential containers

*/

//###########
//# lower and Upper Bound
//###########

/*
c.upper_bound(k) returns an iterator to the first element whose key is graeter than k

c.lower_bound(k) returns an iterator to the first element whose key is greater than or equal to k
    - it there is no match, it returns the same iterator as upper_bound() and the range is empty

(lower_bound(k), upper_bound(k)] defines a half-open range of iterators to all the elements with the key k
    - Equivalent to begin() and end() for the elements with key k

-// The key types is T
-// This must implement the < operator

auto lower_bound(T target){
    for (auto it = begin(); it != end(); ++it){
        if (*it >= target)
            return it;
    }

auto upper_bound(T target){
    for (auto it = begin(); it != end(); ++it){
        if (*it > target)
            return it;
    }
    return end();
}

*/

#include <iostream>
#include <set>
#include <map>

using namespace std;

void findMultimapExample(){
    multimap<string, int> scores;
    scores.insert(make_pair("Graham", 90));
    scores.insert(make_pair("Grace", 80));
    scores.insert(make_pair("Graham", 85));
    scores.insert(make_pair("Hareesh", 75));
    scores.insert(make_pair("Graham", 72));        // Add a duplicate key


    cout << "Multimap Elements: " << endl;
    for (auto it: scores){
        cout << it.first << " : " << it.second << endl;
    }

    // Elements are in the order of the keys "Grace", "Graham", "Graham", "Graham", "Hareesh"
    auto gra_first = scores.lower_bound("Graham");       // Returns an iterator to "Graham"
    auto gra_last = scores.upper_bound("Graham");        // Returns an iterator to "Hareesh"

    cout << "Elements with key 'Graham': " << endl;
    for (auto it = gra_first; it != gra_last; ++it){
        cout << it->first << " : " << it->second << endl;
    }
}


//###########
//# equal_range()
//###########

/*
- equal_range() is equivalent to calling lower_bound() followed by upper_bound()
    - It returns an std::pair
    - The first member of the pair is the return value from lower_bound()
    - // Iterator range for elements with key "Graham"
    auto gra_keys = scores.equal_range("Graham");

    for (auto it = gra_keys.first; it != gra_keys.second; ++it)
        ...   

*/

//###########
//# finding an Element Using an Algorithm
//###########

/*
we can use the returned iterator range with generic algorithms
    - // Call find_if() with a lambda expression to search for an element with value 66

    auto result = find_if(start, finish, [](pair<string, int> p) { return p.second == 66; });

    if (result != finish)
        cout << "Found an element with value 66" << endl;
    else
        cout << "No element with value 66 found" << endl;

*/


int main(){
    cout << "Finding elements in a multimap" << endl;
    findMultimapExample();
    return 0;
}