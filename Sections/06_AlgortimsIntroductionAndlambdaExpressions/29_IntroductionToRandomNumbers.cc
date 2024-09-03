//############
// Random Numbers
//############

/*
- A random number is a number that appears to be chosen by chance
- usually we assume that any number is equally likely to be chosen (uniform distribution)
- usually we assume that the next choice of number will not be affected by the current choice (independent)
*/

//############
// Applications of Random Numbers
//############

/*
- games (chance and uncertainty)
    - what hand is the player dealt?
    - which way will the opponent move?

- Simulation (Monte Carlo)
- Cryptography( unbreakable codes)
    - Security
    - Bitcoin and blockchain
*/


//############
// Random Numbers in old C++
//############


//############
// rand()
//############

/*
- rand() is inherited from C and is declared in <cstdlib>
- Calling rand() returns the next number in a sequence of pseudo-random numbers
- it return an integer between 0 and RAND_MAX inclusive

    -// Print out a pseudo-random number

    cout << rand() << endl;

*/

//############
// rand() example
//############

/*
- with a little arithmetic, we can get numbers within a different range of values

    -// Print out a pseudo-random floating point number with a value between 0 and 1

    cout << 1.0 * rand() / RAND_MAX << endl;    // Convert the result to double!

    -// Print out 10 pseudo-random integers with a value between 1 and 100

    for(int i = 0; i < 10; i++) {
        cout << (99*rand() / RAND_MAX + 1) << endl;
    }

*/

#include <iostream>
#include <cstdlib>

using namespace std;

void randomNumbersExample() {
    cout << "A pseudo-random number: " << rand() << endl;

    cout << "A pseudo-random floating point number between 0 and 1: " << 1.0 * rand() / RAND_MAX << endl;

    cout << "10 pseudo-random integers between 1 and 100: " << endl;
    for (int i = 0; i < 10; i++) {
        cout << (99 * rand() / RAND_MAX + 1) << ", ";
    }
    cout << endl;
}

//############
// seeding a PRNG (Pseudo-Random Number Generator)
//############

/*
- To seed the generator used by rand(), we call srand()
- Traditionally, programmers use the current time to provide a "random" seed

    -// time() is a C function, defined in <ctime>
    
    srand(time(0));         // time(0) returns the current time as a time_t

- The value returned by time() only changes once per second
- This makes it easier to guess the seed, which makes it easier to guess the random sequence


*/

void randomNumbersExample2() {
    srand(time(0));

    cout << "A pseudo-random number: " << rand() << endl;

    cout << "A pseudo-random floating point number between 0 and 1: " << 1.0 * rand() / RAND_MAX << endl;

    cout << "10 pseudo-random integers between 1 and 100: " << endl;
    for (int i = 0; i < 10; i++) {
        cout << (99 * rand() / RAND_MAX + 1) << ", ";
    }
    cout << endl;
}

//############
// Disadvantages of rand()
//############

/*
- The PRNG algorithm is chosen by the implementor
- Typical rand() implementations generate numbers which are not very random, 
especially in the last few digits
- if we dont want to get numbers between 0 and RAND_MAX, we must rescale the range. 
This introduces bias 
    - Some numbers appear more often than others

- rand() has poor cryptographic security

    - The sequence is short and repeats frequently
    - Guessing the next number is not difficult enough


*/

int main() {
    cout << "Random Numbers Example: " << endl;
    randomNumbersExample();

    cout << "Random Numbers Example 2: " << endl;
    randomNumbersExample2();

    return 0;
}