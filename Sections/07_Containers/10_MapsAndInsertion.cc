//###########
//# Map Insertion
//###########

/*
The Original STL provided two ways to insert an element into a map 
- Operator []
- The insert member function
*/

//###########
//# Operator []
//###########

/*
- Operator [] provides "insert or assign" functionality
- If there already is an element in the map with the requested key, its value is overwritten
- Otherwise, a new element is inserted into the map

map<string, int> scores;            // Create an std>>map object
...
scores["John"] = 90;                // Insert a new element with key "John" and value 90

There are two possible outcomes
    - we have inserted a new element with key "John" and value 90
    - we have overwritten the value of an existing element

Operator [] performs an insertion in two stages
    scores["John"] = 90;

First it creates the new element
    - the key is the argument
    - the value is default - initialized
    - Then it assigns the value

This requires that the values type has a default contrcutor
 If the assignment throws an expection, the partially - populated element is left in the map

 scores["John"] ;     //Element with the key "John" and undefined value

 Operator [] returns a value

 This is a reference to the elements value memeber

    auto res = scores["John"] = 90;         // res => 90

This does not tell us what happened!

*/


//###########
//# Insert()
//###########

/*
- The insert() member function will only insert a new element
- If the map already has an element with the same key, nothing happens
- The return value from insert() allows us to find out wheter a new element was added
- The values type does not need to have a defaul constructor
- If an exception is thrown during the operation, the insertion has no effect

*/

//###########
//# Insert or Assign with insert()
//###########

/*
auto res = scores.insert(make_pair("John", 90));

auto iter = res.first;
if (res.second)
    - // The new element was inserted
else{
    - // Not inserted - we need to assign the existing element
    
    iter->second = 90;
}

*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    map<string, int> scores;
    scores.insert(make_pair("Maybelline", 86));
    scores.insert({ "Graham", 78 });

    cout << "Map Elements: " << endl;
    for (auto it: scores){
        
        cout << it.first << " has a score of " << it.second << endl;
    }

    // Insert of assign an element with key "Graham" and value 66
    auto res = scores.insert(make_pair("Graham", 66));

    auto iter = res.first;
    if (res.second){
        cout << "Inserted a new element with name " << iter->first;
        iter->second = 66;
        cout << " to have score " << iter->second << endl;
    }
    else{
        cout << "Modifying existing element with name " << iter->first;
        iter->second = 66;
        cout << " to have score " << iter->second << endl;
    }
}
