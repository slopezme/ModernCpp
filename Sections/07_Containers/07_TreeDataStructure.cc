//###########
//#  Tree data Structure
//###########

/*
- C++ associative containers are implemented using a "tree"
- This is a data structure in which each element has its own node
- A node has a "key" for the element and two pointers
    - "left" and "right"

- The position of elements depends on the relative values of their keys
    - "left" points to an element which has a lower key than this node
    - "right" points to an element which has a higher key than this node

*/

//###########
//#  Adding and Removing Elements
//###########

/*
- To add or remove elements, we need to 
    - compare the element data
    - deference a pointer
    - Compare the element data
    - ...
    - Assing a pointer

- These operations are very fast
    - No memory is allocateed or released
    - Only one other element is modified
    - no elements are moved around

*/

//###########
//#  Finding Elements
//###########

/*
- Finding an element is also very fast
    - Compare the element data
    - Deference a pointer
    - Compare the element data


*/

//###########
//#  Tree Balancing
//###########

/*
- inserting and erasing elements may cause the tree to become "unbalanced"
    - Too many elements in one branch of the tree

- Thirs makes the tree les efficient
- We may need to "rebalance" the tree
    - Choose a new root
    - Move elements around until the tree is balanced

- "Balanced trees" automatically rebalance themselves when needed
    - Red - Black tree
    - AVL tree

*/

