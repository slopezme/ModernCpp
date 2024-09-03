//###########
//# std::Queue
//###########

/*
A queue is a data strcture in which elements are stored in the order in which they are inserted

As a queue is processed, the element at the front is removed and the element behind it moves to the front

When new elements are added to the queue, they are inserted at the back

Elements can only be removed from the front, in the same order they were added

*/

//###########
//# queue Implementation
//###########

/*
C++ has an std::queue implementation in the <queue> header
The frist element bo be added to the queue is always the first elements to be removed
The queue is a "fist in, first out" (FIFO) data structure
A queue is usually implemented as a deque (why?), although it can be implemented as a vector or a list
*/


//###########
//# Queue Operations
//###########

/*
Queue have a limited interface
    - use push() to add an element to the back of the queue
    - use pop() to remove the element at the front of the queue
    - use front() to returns the element at the front of the queue
    - use back() to returns the element at the back of the queue
    - use empty() to check if the queue is empty, true if it is
    - use size() to return the number of elements in the queue

No support for other typical container operations( such as iterators)


    - No iterators
    - No insert()
    - No erase()
    - No clear()

*/

//###########
//# Queue Applications
//###########

/*
Queues are mainly used for temporarily storing data in the order it arrived
    - network data packets waiting for CPU time
    - Must be processed in sequence
- Inventory system for perishable goods
    - oldest goods must be shipped first

*/

//###########
//# Queue Pros and Cons 
//###########

/*
useful for processing events in the order they occur
Can only access the front element
    - if you need to access other elements, use a vector or a map (with the arrival order as the key)
    insted of a queue

No provision for "queue jumping" which is often needed in real world applications
    - A patient arriving at a hospital needs emergency treatment
    - An aeroplane is delayed and misses its takeoff slot

*/


#include <iostream>
#include <queue>

using namespace std;

void print(const queue<int>& q){
    cout << " The queue is " << (q.empty() ? " " : "not ") << "empty\n";
    cout << " The queue contains " << q.size() << " elements\n";
    cout << " The first element is " << q.front() << endl;
    cout << " The last element is " << q.back() << endl;

}

int main(){
    queue<int> q;

    // Add some elements to the queue
    q.push(4);
    q.push(3);
    q.push(5);
    q.push(1);

    print(q);

    // Insert a new element at the end of the queue
    cout << "\n Adding element with value 2\n";
    q.push(2);
    print(q);

    // Remove the first element
    cout << "\n Removing the first element\n";
    q.pop();
    print(q);

}

