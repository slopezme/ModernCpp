//###########
//#  Double Linked List
//###########

/*
- In a double linked list, each node has a link to the previous node as well as the next node
- A double linked list can be easily traversed backwards as well as forwards, by following
the pointer to the previous node
- The C++ standard library provides std::list to implement a double linked list

*/

//###########
//#  Appending an Element
//###########

/*
- To add an element at the back of the list
    - Create a node for it
    - Make the last node's "next" link point to it
    - Make our "previous" link point to the last node
    - The added node is now the last node
- The other elements are left unchanged

*/

//###########
//#  inserting an Element
//###########

/*
- To insert a node in the middle of a linked list
    - Make the new nodes "next" link point to the following node
    - Make the new nodes "previous" link point to the previous node
    - Make the before node's "next" link point to the new node
    - Make the following node's "previous" link point to the new node
- The other elements are left unchanged

*/

//###########
//#  Removing an Element
//###########

/*
- To remove an element from a linked list
    -  Make the "next" link of the before node point to the following node
    - Make the following node's "previous" link point to the before node
    - Destroy node
- Again, the other elements are left unchanged

*/

#include <iostream>
#include <list>

using namespace std;

int main(){
    list<int> l = {4,3,1};

    cout << "initial elements in list: " << endl;
    for (int i : l){
        cout << i << " ";
    }
    cout << endl;

    auto last = l.end();
    advance(last, -1);
    auto two = l.insert(last, 2);

    cout << "Elements in list after inserting 2: " << endl;
    for (int i : l){
        cout << i << " ";
    }

    cout << endl;

    l.erase(two);

    cout << "Elements in list after removing 2: " << endl;
    for (int i : l){
        cout << i << " ";
    }
    cout << endl;

}

//###########
//#  List Pros and Cons
//###########

/*
- Adding or removing elements from the middle of a list is faster than for vector
- Lists do not support indexing os subscrip notation
- Accessing an element is slower than for vector
- Lists use more memory to store an element than vector
- List are useful where we expect to add ore remove a lot of elements frequently

*/