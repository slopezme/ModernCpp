//###########
//# insert_or_assign() 
//###########

/*
Multiset and multimap are very similar to set and map, except that duplicate keys are allowed
However, multimap does not support subscripting
*/

#include <iostream>
#include <set>
#include <map>

using namespace std;

void multisetExample(){
    multiset<int> s;
    s.insert(6);            // Create empty std::multiset
    s.insert(7);            // Add some elements to it
    s.insert(4);
    s.insert(6);            // Add a duplicate element
    s.insert(6);

    for (auto el:s)
        cout << el << " ";
    cout << endl;


}

void multimapExample(){
    multimap<string, int> scores;
    scores.insert(make_pair("John", 90));
    scores.insert(make_pair("Paul", 80));
    scores.insert(make_pair("George", 85));
    scores.insert(make_pair("Ringo", 75));
    scores.insert(make_pair("John", 72));        // Add a duplicate key
    scores.insert(make_pair("John", 70));        // Add a duplicate key

    scores.erase("John");                       // Remove all elements with key "John"

    cout << "Multimap Elements: " << endl;
    for (auto it: scores){
        cout << it.first << " : " << it.second << endl;
    }
    cout << endl;
}


//###########
//# insert() and erase() 
//###########

/*
insert() always succeeds for multimap and multiset
erase(k) will remove all the elements which have the key k
    scores.erase("John");       // Remove all elements with key "John"

We can erase a single element, by passing an iterator to it
But how do we find it?

*/

//###########
//# The problem
//###########

/*
A map can only have one matching element
A multimap could contain many matching elements
We need to be able to manage these multiple matches
    - Because the multimap is sorted in the order of its keys, all the matching elements will be next to each other
    - These form a range of elements
    - Thes ecan be represented by an iterator range
One way to solve this problem is to use find() and count()

*/

//###########
//# Finding elements
//###########

/*
c.find(k) will return an iterator to the first element with key k 
    - or end() if not found
- This gives us the first element in the range
- c.count(k) will return the number of elements with key k
- This gives us the number of elements in the range
- Given these two values, we can loop over all the elements in the range


*/

void findMultimapExample(){
    multimap<string, int> scores;
    scores.insert(make_pair("John", 90));
    scores.insert(make_pair("Paul", 80));
    scores.insert(make_pair("George", 85));
    scores.insert(make_pair("Ringo", 75));
    scores.insert(make_pair("John", 72));        // Add a duplicate key
    scores.insert(make_pair("John", 70));        // Add a duplicate key

    auto res = scores.find("John");             // Find the first element with key "John"

    if (res != end(scores)){
        auto n_matches = scores.count("John");   // Count the number of elements with key "John"

        // Loop over the matching elements

        for (int i = 0; i < n_matches; ++i){
            cout << "Key = " << res->first << ", value = " << res->second << endl;
            ++res;
        }
    }


}

int main(){
    cout << "Multiset Example" << endl;
    multisetExample();

    cout << "Multimap Example" << endl;
    multimapExample();

    cout << "Finding elements in a multimap" << endl;
    findMultimapExample();
    return 0;
}

