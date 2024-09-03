//###########
//#  Forward List
//###########

/*
- The containers we have looked at so far use a single block of memory to store their elements.
- In a list, each element has its own memory allocation ("node") .
- Each node contains the element value and a pointer
- The pointer stores the address of the next node in the list
    - The last node will have an invalid link pointer
    - This signifies that it does not have a next node
 */

//###########
//#  Linked List Structure
//###########

/*
- A linked list is a data structure that consists of a sequence of elements
*/

//###########
//#  list Iteration
//###########

/*
- To iterate through a list, we start with the first node
- We get its link pointer
- We then go to that address, which is the second node
- We then se that node's link pointer to go to the third node, and so on
- When we get to a node which has an invalid link pointer, we stop
*/

//###########
//#  Forward List
//###########

/*
- This data strcture is known as a forward list or single linked list
    - each node has a single link
    - we can iterate forwards through the list by following the links
    - going backwards through the list is more difficult

- The C++ standard library provides the forward_list class which implements
 this data structure 

*/

//###########
//#  Adding a Element
//###########

/*
- To add an element at the back of a linked list
    - create a node for it
    - Make the last node's link point to ti
    - The added node is now the last node

- To insert a node in the middle of a linked list
    - make the link from the node before point to the new node
    - then make the new node's link point to the node after

- The other elements are left unchanged

*/

//###########
//#  Removing an Element
//###########

/*
- To remove an element from a linked list
    - make the previous node link point to the next node
    - destroy the node
- Again, the other elements are left unchanged

*/

//###########
//#  std::forward_list Operations
//###########

/*
- usually, sequential container have insert() and erase() member functions
    - These add or remove an element before a given location
    - This requieres that the container supports reverse iterators
- std::forward_list only supports forward iterators
    - To add or removen an element, use insert_after() and erase_after()
    - These will add or remove an element after a given location
*/

#include <iostream>
#include <forward_list>

using namespace std;

int main(){

    forward_list<int> l {4,3,1};

    cout << "Initial element in list" << endl; 
    for (auto el :l){
        cout << el << " ";
    }
    cout << endl;

    auto second = l.begin();
    advance(second, 1);
    l.insert_after(second, 2);

    cout << "Elements in list after inserting 2" << endl;
    for (auto el : l){
        cout << el << " ";
    }

    cout << endl;

    l.erase_after(second);

    cout << "Elements in list after erasing 2" << endl;
    for (auto el : l){
        cout << el << " ";
    }
    cout << endl;

}
