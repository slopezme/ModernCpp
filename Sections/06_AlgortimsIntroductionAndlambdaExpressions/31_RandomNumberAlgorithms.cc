//############
// shuffle() Algorithm
//############

/*
- shuffle() rearranges an iterator range in a random order
- it takes a random number engine as its third argument

    vector<int> vec{3, 1, 4, 1, 5, 9};
    static mt19937 mt;
    shuffle(begin(vec), end(vec), mt);

- shuflle() call uniform_int_distribution internally
- It gives perfect shuffling - all permutations are equally likely
- random_shuffle()  uses rand() and is deprecated
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iterator>

using namespace std;

void print(const vector<int>& v) {
    ostream_iterator<int> out_it(cout, ", ");
    copy(begin(v), end(v), out_it);
    cout << endl;
}

void shuffleExample() {
    vector<int> vec{3, 1, 4, 1, 5, 9};

    cout << "Before shuffling: " << endl;
    print(vec);
    static mt19937 mt;
    shuffle(begin(vec), end(vec), mt);

    cout << "After shuffling: " << endl;
    print(vec);
}

//############
// std::bernoulli_distribution
//############

/*
- bernoilli_distribution rescales a sequence of numbers into boolean values
- This is useful for maing one-off decisions with random outcomes
*/

void bernoulliExample() {
    static mt19937 mt;
    static bernoulli_distribution bd;

    if (bd(mt)) {
        cout << "You won!" << endl;
    } else {
        cout << "You lost!" << endl;
    }
    
}

//############
// shuffle implementation
//############

/*
- We can implement shuffle by swapping elements at random

    std::swap(vec[i], vec[i_random]);
*/

void shuffleImpl(){

    vector<int> vec{3, 1, 4, 1, 5, 9};
    static mt19937 mt;

    cout << "Before shuffling: " << endl;
    print(vec);

    uniform_int_distribution<int> uid(0, vec.size() - 1);

    for (int i = 0; i < vec.size(); ++i) {
        std::swap(vec[i], vec[uid(mt)]);

    }

    cout << "After shuffling: " << endl;
    print(vec);
    cout << endl;

}

int main() {
    cout << "\nshuffle() Algorithm" << endl;
    shuffleExample();

    cout << "\nstd::bernoulli_distribution" << endl;
    bernoulliExample();

    cout << "\nshuffle implementation" << endl;
    shuffleImpl();
    return 0;
}