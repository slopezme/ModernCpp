//###########
//#  Map
//###########

/*
- the C++ library provides std::map in <map>
- this is an associative container
- Each element consist of an std::pair
    -The first element is the key
    -The second element is the value

- Each element must have a unique key
    - the values do not have to be unique
- The elements are stored in order, using the < operator for the key to sort the elements
- For efficiency, std::map is implemented as a tree, usually a red-black tree
*/

//###########
//#  Map usage
//###########

/*
- the "value" member of the pair is used to store the data
- The "key" is used to locate the corresponding data
    - employee ID -> personal record
    - players name -> performance record

- We search for a particular key, then look up the data in the value member
- The key acts like an index 
*/

//###########
//#  Adding and Removing Elements
//###########

/*
- We can use insert() and erase() as we did with::set
- We need to pass the new element to insert() as an std::pair
    ,.insert(make_pair(k,v));

- With C++11, we can use a list initializer
    mymap.insert({k,v});
- insert() will fial if the map already has an element with the same key

*/

//###########
//# std::map insert()
//###########

/*
- insert() returns an std::pair, similar to std::set
- The "second" member is a bool indicating success/failure
- The "first"  member is an iterator to the new element on success
    - on failure, it is an iterator to the element that caused the insert() to fail
    - Whis will occur if an existing element in the map hast the same key

*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

void print(const map<string , int> &scores ){
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

    print(scores);

    cout << "Adding element with key 'George' and value 85" << endl;
    auto ret = scores.insert(make_pair("Paul", 60));

    if (ret.second)
        cout << "Insertion successful" << endl;
    else {
        auto it = ret.first;
        cout << "Insertion failed. Element with key " << it->first << " already exists" << endl;
        }

    cout << "Removing element with key 'George'" << endl;
    scores.erase("Paul");

    print(scores);

    auto ret2 = scores.insert(make_pair("Paul", 60));
    if (ret2.second)
        cout << "Insertion successful" << endl;
    else {
        auto it = ret2.first;
        cout << "Insertion failed. Element with key " << it->first << " already exists" << endl;
        }



}

//###########
//# Map Subscripting
//###########

/*
- Unlike list and set, map supports subscripting
- however, this works differently from vector and arrays
- it the element does not already exist, it is created

    scores["Graham"] ;      //Fetches the value with key "Graham"
    scores["Graham"] = 75;  //Sets the value with key "Graham" to 75
    scores["Grace"] = 75;   //Creates a new element with key "Grace" and value 75

- if the element does exist, this will overwrite the value

*/

void mapExample2(){

    map<string, int> scores;
    scores.insert(make_pair("John", 90));
    scores.insert({ "Paul", 80 });

    print(scores);

    cout << "Paul has a score of " << scores["Paul"] << endl;
    print(scores);

    cout <<  "Setting Paul's score to 85" << endl;
    scores["Paul"] = 85;
    print(scores);

    cout << "Setting George's score to 75" << endl;
    scores["George"] = 75;              // Creates a new element with key "George" and value 75
    print(scores);



}

#include <algorithm>

void mapExample3(){
    map<string, int> scores;
    scores.insert(make_pair("maybelline", 86));
    scores.insert({ "Graham", 78 });

    print(scores);

    cout << "Calling find_if() \n";
    auto gra = find_if(begin(scores), end(scores), [](pair<string, int> const& p) { return p.first == "Graham"s; });

    if (gra != end(scores))
    {
        cout << "Found an element with a key ";
        cout << gra->first << " which has a score of " << gra->second << endl;

        cout << "Changing Graham's score to 67" << endl;
        gra->second = 67;

        print(scores);
    }
    else
    {
        cout << "No element with key 'Graham' found" << endl;
    }

    cout << "Calling count_if() \n";

    auto n = count_if(cbegin(scores), cend(scores), [](pair<string, int> p ) { return p.first == "Graham"s; });

    if (n == 1)
        cout << "The map has 1 element with key 'Graham'" << endl;
    else
        cout << "The map has " << n << " elements with key 'Graham'" << endl;




}

//###########
//# map Pros and Const
//###########

/*
- Very fast at accessing an arbitrary element
- insertion and deletion are usually very fast
    - can be slow if the internal tree gets unbalanced
- very useful for indexed data (contacts list, empleyee records, etc)
- Also useful for storing data which is in the form of key-value pairs
(JSON, XML, etc)

*/

int main(){
    mapExample1();
    mapExample2();
    mapExample3();
    return 0;
}