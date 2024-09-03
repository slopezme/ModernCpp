//###########
//#  List Operations
//###########

/*
- List suport many of the operations we would expect for a sequential container
    - we can use pusck_back() and push_front() to add elements
    - we can use iterators to loop over the elements of a list

- however, list do not support random access
    - We cannot jump straight to, for example, the 5th element
    - We have to start at the beginning of the list and iterate the requiered number of times

*/

//###########
//#  srot()
//###########

/*
- The generic sort() algorithm requieres random access to container elements
- This is not supported for list and forward_list

    sort(begin(l), end(l)); //error

- Instead, we have to use the member function sort()

    l.sort();

*/

//###########
//#  list member operations
//###########

/*
- in some cases, the list member function version of algorithms are faster than the generic equivalents
- The generic version of remove() shuffles the removed elements to the end of the container
- Th list member function version deleted the elements immediately
    - This just changes a couple of pointers 
    - no need to call erase()


*/

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

void listExample(){
    list<int> l = {4,3,1};

    cout << "Initial elements in list: " << endl;
    for (int i : l){
        cout << i << " ";
    }
    cout << endl;

    l.sort();

    cout << "Elements in list after sorting: " << endl;
    for (int i : l){
        cout << i << " ";
    }
    cout << endl;

    l.remove(3);

    cout << "Elements in list after removing 3: " << endl;
    for (int i : l){
        cout << i << " ";
    }
    cout << endl;

}

//###########
//#  Operations which move elements
//###########

/*
- reverse
    - reverses the order of the elements
- remove 
    - deletes certain elements from the list
- remove_if
    - deletes elements that satisfy a certain condition
- unique
    - Deletes duplicate elements from the list
- These all modify the object they are called on
*/

//###########
//#  merge()
//###########

/*
- merge() will remove elements from the argument list and merge them into the "list" list
- The list will be sorted in ascending order, provided both list were sorted before the operation

list<int> l2{1, 7 , 12, 24}
list<int> l3{9, 3 , 14}

l2.sort();
l3.sort();

l2.merge(l3);           // l2 now contains {1, 3, 7, 9, 12, 14, 24} and list2 is empty


*/

void mergeExample(){
    list<int> l1 = {1, 7, 12, 24};
    list<int> l2 = {9, 3, 14};

    l1.sort();
    l2.sort();

    l1.merge(l2);

    cout << "Elements in list after merging: " << endl;
    for (int i : l1){
        cout << i << " ";
    }
    cout << endl;

    cout << "Elements in list2 after merging: " << endl;
    for (int i : l2){
        cout << i << " ";
    }
    cout << endl;
}

//###########
//#  splice()
//###########

/*
- splice() moves elements from another list into a list
- The first argument is an iterator to an element in "this" list    
    - The elements will be inserted just before this element
- The second argument is the list to be spliced in

list<int> l1{1, 12, 6, 24}
list<int> l2{9, 3, 14}

auto p begin(l1);
advance(p, 2);
l1.splice(p, l2);       // l1 now contains {1, 12, 9, 3, 14, 6, 24} and l2 is empty

- There are also versions which move a single element or a range of elemments from the
argument list
*/

void spliceExample(){
    list<int> l1 = {1, 12, 6, 24};
    list<int> l2 = {9, 3, 14};

    cout << "Elements in list: " << endl;
    for (int i : l1){
        cout << i << " ";
    }
    cout << endl;

    cout << "Elements in list2: " << endl;
    for (int i : l2){
        cout << i << " ";
    }
    cout << endl;

    auto p = begin(l1);
    advance(p, 2);
    l1.splice(p, l2);

    cout << "Elements in list after splicing: " << endl;
    for (int i : l1){
        cout << i << " ";
    }
    cout << endl;

    cout << "Elements in list2 after splicing: " << endl;
    for (int i : l2){
        cout << i << " ";
    }
    cout << endl;
}

//###########
//#  splice() and std::forward_list
//###########

/*
- std::forward_list implements splice_after() instead of splice()
- this works almost the same way as splice() does for list
- however, the elemts are spliced in after the iterator argument, insted of before

forward_list<int> l1{1, 12, 6, 24}
forward_list<int> l2{9, 3, 14}

auto p begin(l1);
l4.splice_after(p, l2);       // l1 now contains {1, 12, 9, 3, 14, 6, 24} and l2 is empty

*/
#include <forward_list>

void forwardListExample(){
    forward_list<int> l1 = {1, 12, 6, 24};
    forward_list<int> l2 = {9, 3, 14};

    cout << "Elements in list: " << endl;
    for (int i : l1){
        cout << i << " ";
    }
    cout << endl;

    cout << "Elements in list2: " << endl;
    for (int i : l2){
        cout << i << " ";
    }
    cout << endl;

    auto p = begin(l1);
    l1.splice_after(p, l2);

    cout << "Elements in list after splicing: " << endl;
    for (int i : l1){
        cout << i << " ";
    }
    cout << endl;

    cout << "Elements in list2 after splicing: " << endl;
    for (int i : l2){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    cout << "\nList example:" << endl;
    listExample();

    cout << "\nMerge example:" << endl;
    mergeExample();

    cout << "\nSplice example:" << endl;
    spliceExample();

    cout << "\nForward list example:" << endl;
    forwardListExample();
    return 0;
}