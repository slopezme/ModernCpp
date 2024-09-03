//###########
//#  Deque
//###########

/*
- std::deque implements a double-ended queue
    - similar to a vector, but element can also be added efficiently at the front

- Defined in the <deque> header

- Implemented as two dimensional array
    - std::vector has one memory block which stores all the elements
    - std::list has one memory block per element
    - std::deque has multiple memory blocks which each store several elements

- std::deque stores its elements over several blocks of memory
    - iterating from the first element of the frist block to the last element of the last block
    wil return all the elements in order
- std::deque a similar interace to std::vector
- deque also has a push_front() member function
    - This inserts an element before the first element
- If there is not enough room to store a new element, the deque will allocate another memory block
and sotre it in there
    - The existing elements remain where they are
    - This is different from std::vector, where the memory block is reallocated, and all the elements
    are copied into the new block
*/

#include <iostream>
#include <deque>

using namespace std;

void dequeExample(){
    deque<int> dq{4, 2, 3, 5, 1};
    dq.push_back(4);
    dq.push_back(2);
    dq.push_front(1);
    dq.push_front(5);
    dq.push_front(3);

    for (int i : dq){
        cout << i << " ";
    }
    cout << endl;

}

//###########
//#  Choosing a sequential container
//###########

/*
- Deque is slightly slower than fir vector most operations
    - however, it is faster than vector for adding and removing elements at the front

- list is much slower than a vector and deque for most operation, and uses more memory
    - however, list is much faster at adding and removing elements
    - But only if this does not involve searching
- Vector should be the default choice
    - modern hardware is optimized for accessing contiguous blocks of memory

*/

int main(){
    cout << "\nDeque example: " << endl;
    dequeExample();
}
