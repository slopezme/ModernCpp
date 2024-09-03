//###########
//# Unordered Associative Containers
//###########

/*
Associative containers store their elements in an order which depends on the keys

std::set, std::map etc use a tree

C++11 introduced "unordered" associative containers
    - These use a "hash table" to store their elements

*/

//###########
//# Buckets
//###########

/*
A hast table is an array of "buckets"

*/

#include <iostream>
#include <list>
#include <random>
#include <array>
#include <algorithm>

using namespace std;




void hashTable(){
    mt19937 mt;
    uniform_int_distribution<int> dist(0, 100);

    // The hash table is an array of linked lists
    std::array<list<int>, 10> buckets;

    // Generate 150 random numbers with values between 1 and 100
    // If between 1 and 10, add to bucket[0]
    // If between 11 and 20, add to bucket[1], etc

    for (int i = 0; i < 150; ++i){
        int num = dist(mt);                 // Get a random number
        int idx = (num-1) / 10;             // "Hash function" to compute the hash value
        buckets[idx].push_back(num);        // use the hash value as the index into the array

        // Print out the contents of the buckets
        for (int i = 0; i < 10; ++i){
            auto bucket = buckets[i];
            cout << "Bucket " << i << ": ";
            for (auto el: bucket){
                cout << el << " ";
            }
            cout << endl;
        }
    }


    // find "43" in the hash map

    int target{43};
    int idx = (target - 1) / 10;        // Compute the hash value

    cout << "Looking for " << target << " in bucket " << idx << endl;
    auto it = find(cbegin(buckets[idx]), cend(buckets[idx]), target);

    if (it != cend(buckets[idx]))
        cout << "Found " << target << " in bucket " << idx << endl;
    else
        cout << "Did not find " << target << " in bucket " << idx << endl;
}

//###########
//# Unordered Container Implementation
//###########

/*
In an unordered container, the buckets are linked lists of pointers to the container elements

The index of the array is calculated from the element
    - A "has function" generates a number based on the key
    - This is known as the "hash" of the key
    - This is usually a very fast operation
    - The hash of the key is used as the index into the array

*/

//###########
//# Elements insertion
//###########

/*
- Calculate the hash number of the new elements key
- Find the bucket which corresponds to that number
- Push a poibter to the new container element onto that buckets list

*/

//###########
//# Elements search
//###########


/*
Calculate the hash number of the key
use that number to identify the bucket to search
search the bucket for the elements with the required key
    - Uses the == operator of the key type


*/

//###########
//# hash Collisions
//###########

/*
- For maximum efficiency, each element should have its own bucket 
    - Each key produces a different hash value
    - This requieres the hash function to perform "perfect hashing"

- In practice, different keys sometimes give the same hash number 
    - A "hash collision"

- In a multimap or multiset, several elements can have the same key
- there more elements there are in a bucket, the longer it will take to perform an operationch 
which involves that bucket

*/

//###########
//# C++ Unodered Containers
//###########

/*
C++11 provides unordered versions of the associative containers
    - std::unordered_set
    - std::unordered_multiset
    - std::unordered_map
    - std::unordered_multimap

*/

//###########
//# Operations
//###########

/*
unoserted containers support typical associative container operations
    - insert()
    - erase()
    - find()

    There are also operations for managing the buckets

Operations on an unsorted container are usually faster than they are on a sorted container
    - Especially for large containers, with many insert() and erase() operations

However, they can be considerably slower if the hash table needs to be resized, ir if there are many collisions
    - In time critical applications, this delay may not be acceptable
   

*/

//###########
//# Iterators
//###########

/*
- Unordered containers only allow forward iteration
    -rbegin() and rend()  and crbegin() and crend() are not supported
    - An iterator to an unordered container cannot be decremented

As the containers have no concept of order, iterator ranges are not particularly useful

Except for 
    - Iterating over entiere container(forwards only!)
    - iterating over elements with the same key (multimap, multiset)

*/

//###########
//# unordered Multiset and Multimap
//###########

/*
The unordered versions of multiset and multimap do not support lower_bound() and upper_bound()
    - we can still use equal_range() 
    - we can also use find() and count() 

*/


//###########
//# Sorting an unsordered container
//###########

/*
Sometimes we need to have the elements sorted, but using a sorted container would add too much overhead
In this case, we can use an unsorted container and copy its elements into a sorted container

unordered_map<Key, Value> u_map;
...
map<Key, Value> s_map;

-//Copy into the ordered map
-// As we populated s_map with the elements, it will automatically sort them
copy(begin(u_map), end(u_map), inserter(s_map, end(s_map));



 */
#include <map>
#include <unordered_map>

void unorderedmapExample(){
    unordered_multimap<string, int> unsorted_scores;    // Create unordered multimap object
    unsorted_scores.insert({ "Graham", 78 });           // Insert some elements
    unsorted_scores.insert({ "Grace", 66 });
    unsorted_scores.insert({ "Graham", 66 });
    unsorted_scores.insert({ "Graham", 72 });
    unsorted_scores.insert({ "Hareesh", 77 });

    cout << "Unsorted: \n";
    for (auto it : unsorted_scores)
        cout << it.first << " has a score of " << it.second << endl;

    multimap<string, int> sorted_scores;                // Create a sorted multimap object

    // Copy into the ordered map
    // As we populated sorted_scores with the elements, it will automatically sort them

    copy(begin(unsorted_scores), end(unsorted_scores), inserter(sorted_scores, end(sorted_scores)));

    cout << "Sorted: \n";
    for (auto it : sorted_scores)
        cout << it.first << " has a score of " << it.second << endl;


}


int main(){
    cout << "Hash Table Example" << endl;
    //hashTable();

    cout << "Unordered Map Example" << endl;
    unorderedmapExample();
    return 0;
}