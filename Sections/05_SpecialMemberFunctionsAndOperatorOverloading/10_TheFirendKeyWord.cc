
//############
// Friend Functions
//############

/*
- normally a non-member function can only access a class's public members
- The class can declare a non-member function as a friend
- This allows the function to access the class's private members

class Test{
    int i;
    friend void set(Test& test, int i);
    public:
    Test(int i): i{i} {}
};
*/

//############
// Friend Classes
//############

/*
- We can also declare another class access to be a friend 

class Test{
    int i;
    friend class TestFriend;
    public:
    Test(int i): i{i} {}
};

- This gives all the membe functions of TestFriend access to the private members of Test

*/

#include <iostream>
#include <string>

using namespace std;

class Test{
    int i{42};
    string s{"Hello"};
    public:
    friend class Example;
};

class Example{
    public:
    void print(const Test& test) {
        cout << "i = " << test.i << ", s = " << test.s << endl;
    }
};

void main1() {
    Test test;
    Example example;
    example.print(test);
}

//############
// Avoiding the friend Keyword
//############

/*
- Some C++ programmers dislike "friend" because reduces encapsulation
- To avoid using friend, we can create a member function which implements the functionality of the operator

- This member functions has direct access to all members of the class
- The non member function the calls this member function

*/

class Test2{
    int i{42};
    string s{"Hello"};
    public:
    void print() const {
        cout << "i = " << i << ", s = " << s << endl;
    }
};

void print(const Test2& test) {
    test.print();
}

void main2() {
    Test2 test;
    print(test);
}

int main() {
    main1();
    main2();
    return 0;
}

