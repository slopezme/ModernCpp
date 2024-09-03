//###########
//#  Sequential Containers
//###########

/*
- std::string and std::vector are sequential containers
- In a sequential container, the data is stored in an order which is determined by the program
    - The order of the data does not depend on its value
    - The data will remain in the same position unless the program performs some 
    actions which changes them

- Sequential containers are useful for storing data in an order which we can choose
    - usually, we can access data bi its position
*/

//###########
//#  sets and Maps
//###########

/*
- C++ provides two types of associative containers
    - std::set
    - std::map
- A set is an unordered collection of elements
    - An element is a single data idem consisting of a key
    - The key us used to check if the data item is present in the collection

- A map is similar to a "directory" or a "hash map" in other languages
    - An element consist of a pair of data items, a key and a value
    - The key is used to search for an element and look up its value
*/

//###########
//#  Associative Container Operations
//###########

/*
- Associative containers do not support push_back() or push_front() functions
    - The position of an element is determined by its key
- They do support many container operations
    - we can use insert() and erase() to add and remove elements
    - We can use iterators to loop over the container
- They have member functions which are similar to generic algorithms

*/

//###########
//#  Container Adaptors
//###########

/*
- The Standard Library also defines some "container adaptors"
    - queue
    - stack

- These are data structures (queues and stacks) which are implemented using sequential containers
- Data is sotred in these containers in an order which depended on when the data was added


*/

