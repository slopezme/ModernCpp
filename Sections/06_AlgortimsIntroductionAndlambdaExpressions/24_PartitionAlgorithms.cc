//############
// Partitioning
//############

/*
- we can "partition" the elements in a container into two gropus
    - Elements which have some property are at the front of the container
    - Elements which do not have that property are at the back of the container

- The partition point marks the boundary between the two groups
    
- partition is very useful, especially in interactive applications
    -  Display unread messages before messages which have been read
    - Display list items selected by the user above unselected items

*/

//############
// partition()
//############

/*
- partition() takes an iterator range and predicate function
- all elements for which the predicate function returns true are moved to the fron of the range
- all elements for which the predicate function returns false are moved to the back of the range
- The elements which each group may not be in order

    -// Partition by oddness: move all odd elements to the front

    partition(begin(vec), end(vec), [](int i) { return i % 2 ==1; });

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(const vector<int> &vec) {
    for (const auto &v : vec)
        cout << v << ", ";
    cout << endl;
}

void partitionExample() {
    vector<int> vec{3, 1, 4, 1, 5, 9, 2, 8, 6};

    cout << "vec: ";
    print(vec);

    // Partition by oddness: move all odd elements to the front
    partition(begin(vec), end(vec), [](int i) { return i % 2 == 1; });

    cout << "vec after partition(): ";
    print(vec);
}

//############
// stable_partition()
//############

/*
- stable_partition() is the same as partition(), except the elements within a group will
 keep their relative order
 - Longer execution time

 vector<int> vec{3, 1, 4, 1, 5, 9};

    stable_partition(begin(vec), end(vec), [](int i) { return i % 2 == 1; });
*/

void stablePartitionExample() {
    vector<int> vec{3, 1, 4, 1, 5, 9, 2, 8, 6};

    cout << "vec: ";
    print(vec);

    stable_partition(begin(vec), end(vec), [](int i) { return i % 2 == 1; });

    cout << "vec after stable_partition(): ";
    print(vec);
}

//############
// is_partitioned()
//############

/*
- is_partitioned() takes an iterator range and a predicate function
- it returnsa bool depending on whether the range of elements is already partitioned
by the predicate function

    -// Are all the odd elements at the front of vec?

    if (is_partitioned(begin(vec), end(vec), [](int i) { return i % 2 == 1; }))
        cout << "vec is partitioned" << endl;
    else
        cout << "vec is not partitioned" << endl;

*/

void isPartitionedExample() {
    vector<int> vec{3, 1, 4, 1, 5, 9, 2, 8, 6};
    auto isOdd = [](int i) { return i % 2 == 1; };

    cout << "vec: ";
    print(vec);

    // Are all the odd elements at the front of vec?
    if (is_partitioned(begin(vec), end(vec), isOdd))
        cout << "vec is partitioned by oddness" << endl;
    else
        cout << "vec is not partitioned by oddness" << endl;

    // Partition by oddness: move all odd elements to the front
    partition(begin(vec), end(vec), isOdd);

    cout << "vec after partition(): ";
    print(vec);

    // Are all the odd elements at the front of vec?
    if (is_partitioned(begin(vec), end(vec), isOdd))
        cout << "vec is partitioned by oddness" << endl;
    else
        cout << "vec is not partitioned by oddness" << endl;
}

//############
// partition_point()
//############

/*
- partition_point() takes the same arguments as is_partitioned()
- It returns an iterator to the first element for which the predicate is false
- If we have a container which is already partitioned, we can use this to
find the partition point

    -// Find the partition point of vec

    auto ppoint = partition_point(begin(vec), end(vec), [](int i) { return i % 2 == 1; });

    if (ppoint != end(vec))                     // Check that the call succeeded
        cout << "Partition point: " << *ppoint << endl;
*/

void partitionPointExample() {
    vector<int> vec{3, 1, 4, 1, 5, 9, 2, 8, 6};
    auto isOdd = [](int i) { return i % 2 == 1; };

    cout << "vec: ";
    print(vec);

    // Partition by oddness: move all odd elements to the front
    partition(begin(vec), end(vec), isOdd);

    cout << "vec after partition(): ";
    print(vec);

    if (is_partitioned(begin(vec), end(vec), isOdd)){
        cout << "vec is partitioned by oddness" << endl;

        auto ppoint = partition_point(cbegin(vec), cend(vec), isOdd);

        if (ppoint != cend(vec)){
            cout << "Partition point: " << *ppoint << endl;
            cout << "Partition point index: " << distance(cbegin(vec), ppoint) << endl;

        }

    }
    else {
        cout << "vec is not partitioned by oddness" << endl;
    }
    

}

int main() {
    cout << "\nPartition Example: \n";
    partitionExample();

    cout << "\nStable Partition Example: \n";
    stablePartitionExample();

    cout << "\nIs Partitioned Example: \n";
    isPartitionedExample();

    cout << "\nPartition Point Example: \n";
    partitionPointExample();


    return 0;

}

