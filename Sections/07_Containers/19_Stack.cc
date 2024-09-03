//###########
//# Stack
//###########

/*
A stack is a data strcuture in which elements are stored in the order in which they are inserted

When new elements are added to the stack, they are inserted at the top

Only the element at the top can be accessed

As a stack is processed, the element at the top is removed and the element below it now becomes the top

Eelements are removed in the reverse order they were added

This is a LIFO strcture (last in, first out)

*/

//###########
//# Stack Operations
//###########

/*
The C++ stack is implemented using deque

std::stack has a similar interface to priority_queue
    - use push() to add an element to the top of the stack
    - use pop() to remove the element at the top of the stack
    - use top() to return the element at the top of the stack
    - use empty() to check if the stack is empty, true if it is
    - use size() to return the number of elements in the stack

No support for other typical container operations

*/

//###########
//# Stack Applications
//###########

/*
Stacks have many applications
    - Parsing expressions in compilers
    - checking for unbalanced parentheses in source code
    - implementing "undo" functionality
    - Storing history for back/ forward buttons in web browsers


*/

#include <iostream>
#include <stack>

using namespace std;

void print(const stack<int>& s){
    cout << "The stack is " << (s.empty() ? " " : "not ") << "empty\n";
    cout << "The stack contains " << s.size() << " elements\n";
    cout << "The top element is " << s.top() << endl;
}


int main(){
    stack<int> s;

    // Add some elements to the stack
    s.push(4);
    s.push(3);
    s.push(5);
    s.push(1);

    print(s);

    // Add some more elements
    s.push(2);
    print(s);

    // Remove the top element
    s.pop();
    print(s);

    return 0;
}