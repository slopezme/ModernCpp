/*####################
# perfect Forwarding Practical
####################*/

/*
We will wirte a function that creates objects of this class

class Test{
        string m_str;
    public:
        Test(const string& str) : m_str{str} {}         // called when lvalue is passed
        Test(string&& str) : m_str{std::move(str)} {}    // called when rvalue is passed
        ...
};

*/

/*####################
# Make_test() function
####################*/

/*
- The make_test() function will use perfect forwarding to ensure that the move constructor
is called whenever possible

- The function will use a forwarding reference
    template <class T>
    Test make_test(T&& x) {
        return Test{std::forward<T>(x)};
    }
*/

#include <iostream>

using namespace std;

class Test {
    string m_str;
public:
    Test(const string& str) : m_str{str} {
        cout << "lvalue constructor called" << endl;
    }
    Test(string&& str) : m_str{std::move(str)} {
        cout << "rvalue constructor called" << endl;
    }
};

void g(Test& x) {
    cout << "Modifiable version of g called" << endl;
}

void g(const Test& x) {
    cout << "Immutable version of g called" << endl;
}

void g(Test&& x) {
    cout << "Move version of g called" << endl;
}

template <class T>
Test make_test(T&& x) {
    g(std::forward<T>(x));
    return Test{std::forward<T>(x)};
}

int main(){
    string hello{"Hello"};

    cout << "Calling make_test() with lvalue argument\n";
    Test t1 = make_test(hello);

    cout << "Calling make_test() with rvalue argument\n";
    Test t2 = make_test(std::move(hello));
    cout << endl;
}
