//###########
//# Priority Queues
//###########

/*
With a standard queue, the elements are arranged strictly in arrival order
We often need to process some elements out of sequence
    - In a restaurant customers who have a reservation are seated before customers without a reservation
    - VIP's expect to go to the front of the queue!

- This can be implemented using a priority queue
    
A priority queue is very similar to a queue

however, it orders its elements with the "most important" at the fron and the least important at the back

C++ provided a priority queue 
    - The < operator o the element type is used to order the queue
    - If two elements have equal priority, by default the queue doest not order them by arrival time

*/

//###########
//# Priority Queues implementation
//###########

/*
std::priority_queue can be implemented as a vector or a deque
It has a similar interface to std::queue
    - use push() to add an element to the queue. It will be inserted in front of all the other elements with lower priority
    - pop() removes the element from the front of the queue. The element with the next highest priority becomes the new front
    element
    - top() returns the element with the highest priority
    - empty() returns true if the queue is empty
    - size() returns the number of elements in the queue

*/

#include <iostream>
#include <queue>

using namespace std;

void print(const priority_queue<int>& pq){
    cout << "The priority queue is " << (pq.empty() ? " " : "not ") << "empty\n";
    cout << "The queue contains " << pq.size() << " elements\n";
    cout << "The highest priority element is " << pq.top() << endl;

}

int main(){
    priority_queue<int> pq;

    // Add some elements to the queue
    pq.push(4);
    pq.push(3);
    pq.push(5);
    pq.push(1);

    print(pq);

    // Add some more elements
    pq.push(2);
    print(pq);

        // Remove the highest priority element
    pq.pop();
    print(pq);

    
    return 0;
}

//###########
//# Priority Queues Applications
//###########

/*
priority queues are useful for processing data which needs to be prioritized
    - Operating system schedulers
        - importnat processes can be given more processor time
        - Inimportant processes get less processor time

    - "Out of band" communication in networking
        -e.g. command to drop the connection immediately

    - management system for bug reports
        - Serious bugs should be fixed before minor bugs

*/

//###########
//# Priority Queues Pros and Cons
//###########

/*
We can only access the "top" element
    - If you need to access other elements, use a map instead
        - The map's key is priority, value is data

Elements with the same priority are not guaranteed to be in arrival order

If ordering by arrival time is important
    - Use a nested map
        - The outher map's key is priority
        - The inner map's key is arrival time, value is data

Is we are using our own class, redefine the < operator


*/