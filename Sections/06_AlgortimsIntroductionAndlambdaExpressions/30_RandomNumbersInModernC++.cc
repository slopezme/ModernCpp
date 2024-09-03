//############
// Random numbers in Modern C++
//############

/*
- C++11 introduced a number of classes for working with random numbers
- These are defined in <random>

    - use a random number engine to generate random numbers
    - use a distribution type to rescale the range
    - (Optional) use a random device to seed the engine
*/

//############
// Random number Engines
//############

/*
- A random number engine is implemented as a functor
    - the constructor generates the sequence of pseudo random numbers
    - When we call the () operator, we get the next number from the sequence

    default_random_engine eng;              // Create engine object - generates sequence

    for(int i = 0; i < 5; ++i) {
        cout << eng() << endl;               // Call the functor to get the next number
    }   

*/

#include <random>
#include <iostream>

using namespace std;

void randomNumbersExample() {
    default_random_engine eng;              // Create engine object - generates sequence

    cout << "5 pseudo-random numbers: " << endl;
    for(int i = 0; i < 5; ++i) {
        cout << eng() << ", ";               // Call the functor to get the next number
    }   
    cout << endl;
}

//############
// Distribution
//############

/*
- A distribution is also implemented as a functor
    - Its constructor takes the range as arguments
    -its overloaded () operator takes a function object as argument
    - This function object return a number each time it is called
    - The distribution will then rescale this number to fit in the range and return it

- A distribution can be used with any numberical data sequence, not just a random number
    - Very usefull in statistical applications

*/

//############
// Random number Engines
//############

/*
- the two main random number engines are
- default_random_engine
    - Impementetion - defined
    - may be wrapper around the rand() implementation

- mt19937
    - Mersenne Twister with period 2^19937 - 1
    - Very fast at generating random numbers
    - Almost crypto secure (very hard to predict the sequence)
    - has a lot of state (slow to initialize)
    - usually the best choice for most applications
*/

//############
// Distribution types
//############

/*
- A dsitribution type fits its input into a statistical distribution
- The C++ library provide a number of distribution types
    - Bernoulli, Normal, Poisson, etc
- We usually want our random numbers to be uniformly distributed
    - All values in the range are equally likely

- uniform_int_distribution<T>(a, b)
    - Produces uniformly distributed integers of type T with values between a and b

- uniform_real_distribution<T>(a, b)
    - Produces uniformly distributed floating point numbers of type T with values between a and b
*/

void randomNumbersExample2() {
    mt19937 mt;                            // Create engine object - generates sequence

    uniform_int_distribution<int> dist(0, 10);    // Create distribution object - rescales the range

    cout << " Five pseudo-random numbers between 0 and 10: " << endl;
    for(int i = 0; i < 5; ++i) {
        cout << dist(mt) << ", ";               // Call the functor to get the next number
    }
    cout << endl;

    uniform_real_distribution<double> dist2(0, 1);    // Create distribution object - rescales the range

    cout << " Five pseudo-random floating point numbers between 0 and 1: " << endl;

    for(int i = 0; i < 5; ++i) {
        cout << dist2(mt) << ", ";               // Call the functor to get the next number
    }
    cout << endl;


    
}

//############
// Random Devices
//############

/*
- random_device produces a hardware - generated random number from system entropy data
- however, it will produce a pseudo-random number if
    - The system does not provide entropy data
    - The compiler is GNU C++, which does not support entropy data

- If all the entropy data has been used up, it will stop and wait until more data becomes 
available

- random_device is much slower than mt19937 but is crypto secure if fully implemented


*/

//############
// using random_device
//############

/*
- random_device is also implemented as a functor

random_device rd;               // Create random device object

for(int i = 0; i < 5; ++i) {
    cout << rd() << endl;        // Call the functor to get the next number
}

- Because of the performance limitation, random_device is not suitable for generating numbers in 
large quantities
- instead, random_device is often used to seed the random number engine


*/

//############
// Recommendations
//############

/*
- use mt19937 as your random number engine unless you have a particular need to use one of the others
- check the documentation before using random_device 
- make engine and distribution objects static
    - Creating them is fairly time consuming
    - Every time an engine is initialized, the sequence starts again
    - usually you will only need one object per program anyway

*/

//############
// Health Warning
//############

/*
- Random numbers, like floating point numbers, contain a number of hidden subtleties
- need further search to covered this topic

*/


int main() {

    cout << "Random numbers in Modern C++" << endl;
    randomNumbersExample();

    cout << "\nRandom numbers in Modern C++" << endl;
    randomNumbersExample2();
    return 0;
}