//############
// Other Numeric Algorithms
//############

/*
- There are some other algorithms in <numeric> which are useful in numerical computing
    - partial_sum()
    - adjacent_difference()
    - inner_product()

- C++17 also provides a number of special function in <cmath> 
    - Besssel functions, legendre polynomials, etc

*/

//############
// partial_sum()
//############

/*
- partial_sum() writes the "runingn total" of the elements in the range into another container
- Given a source container {a,b,c, ...}
- The target container will have elements {a, a+b, a+b+c, ...}

    vector<int> vec1{1, 2, 3, 4, 5};

    - // vec2 will contain {1, 3, 6, 10, 15}
    partial_sum(cbegin(vec1), cend(vec1), back_inserter(vec2));

- can be used to perform numerical integration
- By default, the + operator is used to combine the elements


*/

#include <numeric>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(const vector<int>& v) {
    for (int i : v) {
        cout << i << ", ";
    }
    cout << endl;
}

void partialSumExample() {
    vector<int> vec1{1, 2, 3, 4, 5};
    vector<int> vec2;

    cout << "The partial sum of ";
    print(vec1);

    // vec2 will contain {1, 3, 6, 10, 15}
    partial_sum(cbegin(vec1), cend(vec1), back_inserter(vec2));

    cout << "is: ";
    print(vec2);
}

//############
// adjacent_difference()
//############

/*
- adjacent_difference() writes the difference between successive elements into another container
- Given a source container {a,b,c, ...}
- The target container will have elements {a, b-a, c-b, ...}

    vector<int> vec1{1, 3, 6, 10, 15};

    - // vec2 will contain {1, 2, 3, 4, 5}

    adjacent_difference(cbegin(vec1), cend(vec1), back_inserter(vec2));

- can be used to perform numerical differentiation
    - the inverse of partial_sum()

- By default, the - operator is used to combine the elements
*/

void adjacentDifferenceExample() {
    vector<int> vec1{1, 3, 6, 10, 15};
    vector<int> vec2;

    cout << "The adjacent difference of ";
    print(vec1);

    // vec2 will contain {1, 2, 3, 4, 5}
    adjacent_difference(cbegin(vec1), cend(vec1), back_inserter(vec2));

    cout << "is: ";
    print(vec2);
}

//############
// inner_product()
//############

/*
- inner_product() multiplies the corresponging elements of two containers together
and calculates their sum
- Given two source containers {a1, a2, a3, ...} and {b1, b2, b3, ...}
- The result will be a1*b1 + a2*b2 + a3*b3 + ...
- Equivalent to "scalar product"
- As with accumulate(), we have to provide an initial value for the sum
    auto result = inner_product(cbegin(vec1), cend(vec1), cbegin(vec2), 0);

- By default, the + and * operators are used to combine the elements

- inner_product() is equivalent to transform() followed by accumulate()
    - a1*b1 + a2*b2 + a3*b3 + ... 

- A transform step which multiplies elements from each range together and stores the 
results in another range

    transform(cbegin(vec1), cend(vec1), cbegin(vec2), back_inserter(vec3), multiplies<int>());

- An accumulate step which sums the elements in the new range

    auto result = accumulate(cbegin(vec3), cend(vec3), 0);
*/

void innerProductExample() {
    vector<int> vec1{1, 3, 6, 10, 15};
    vector<int> vec2{1, 2, 3, 4, 5};

    cout << "vec1: ";
    print(vec1);
    cout << "vec2: ";
    print(vec2);

    auto result = inner_product(cbegin(vec1), cend(vec1), cbegin(vec2), 0);

    cout << "The inner product of vec1 and vec2 is " << result << endl;

    vector<int> vec3;
    transform(cbegin(vec1), cend(vec1), cbegin(vec2), back_inserter(vec3), multiplies<int>());
    auto result2 = accumulate(cbegin(vec3), cend(vec3), 0);

    cout << "The result of transform + accumulate is  " << result2 << endl;

}

//############
// overloading inner_product()
//############

/*
- inner_product() can be overloaded by providing different binary functions instead
of the default + and * operators

- we can replace the * operator by a "transform" operation
    - This takes two arguments of the element type and returns a value of some return type

- We can replace the + operator by an "accumulate" operation
    - This takes two arguments of the return type and returns a value of the return type
    - This collects the results of all the transform operations and calculates the final result
*/

//############
// overloading inner_product() example
//############

/*
- The result of a scientific experiment are stored in a vector
- We have another vector which contains the theoretically predicted values
- We want to find the biggest error ( the maximum difference between an expected result
and the corresponging actual result)
- we can do this using an overlodaded version of inner_product()
    - The transform operation will find the difference between corresponding elements
    - The reduce operation will find go through these differences and find the largest
    signle difference
    - This result will be the maximum error in the data

- Replace the * operator by a function that finds the difference between corresponding elements
- Replace the + operator by a function that finds tje largest difference

    - // Find biggest difference between corresponding elements
    - // In two vectors of double (taken from Marco Arena blog)

    inner_product(begin(expected, end(expected), begin(actual), 0.0,
        [](auto a, auto b) { return max(a, b); },
        [](auto l, auto r) { return fabs(r - l); });

*/

#include <cmath>

void innerProductOverloadExample() {
    vector<double> expected{0.1, 0.2, 0.3, 0.4, 0.5};
    vector<double> actual{0.09, 0.22, 0.27, 0.41, 0.52};

    auto max_diff = inner_product(
        begin(expected), end(expected), begin(actual), 0.0,
        [](auto a, auto b) { return max(a, b); },           // Reduce operation
        [](auto l, auto r) { return fabs(r - l); });        // Transform operation

    cout << "The maximum difference between expected and actual results is " << max_diff << endl;
}

//############
// std::inner_product() and parallel processing
//############

/*
- Transform + accumulate is a common pattern in parallel programming
    - Break a large calculation into smaller parts which can be performed 
    independently of each other
    - Perform each sub-calculations on its own processor core
    - Combine the results of the sub-calculations to give the firnal result
- however, std::accumulate() is not suitable for parallel processing
- C++17 jas std::transform_reduce() 
    - same as inner_product(), but uses reduce() instead of accumulate()
    - std::reduce() is compatible with parallel processing

*/

int main() {
    cout << "\nPartial Sum Example: " << endl;
    partialSumExample();

    cout << "\nAdjacent Difference Example: " << endl;
    adjacentDifferenceExample();

    cout << "\nInner Product Example: " << endl;
    innerProductExample();

    cout << "\nInner Product Overload Example: " << endl;
    innerProductOverloadExample();
    return 0;
}
