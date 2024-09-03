#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Test {
    int i{42};
    string str{"Hello"};
public:
    // A member function which prints out the data members of the Test class
    void print() {
        cout << "i: " << i << " str: " << str;
    }
    void print(std::ostream& os) {
        os << "i: " << i << " str: " << str;
    }
};

void main1() {
    Test test;
    //out << test << endl;  // Error: no operator << for class Test
    test.print();
    cout << endl << endl;
}


//############
// how output works for builtin types
//############

/*
- The standard library provides standalone functions which overload the operator << for all the built-in
library types

- This is a binary operator, so it is not a member function of ostream

int i{1};
cout << i;  // Calls operator<<(ostream&, int)

this is invoked as 
operator <<(cout, i);

*/

//############
// nested Calls of Operator <<
//############

/*
- We can chain together calls of operator <<
    int i{1}; j{2};
    cout << i << j;     // Calls operator<<(operator<<(cout, i), j);

- This is invoked as a pair of nested calls
    operator << (operator << (cout, i), j);

- The first call returns the ostream cout
- This returned object is used as an argument
- Because ostreams cannot be copied, operator << must return a reference to the ostream,
 os its prototype must be

 ostream& operator << (ostream&, int i);

*/



/*
overloaded operator << which prints out the data members of the Test class.
This calls the Test class's print()  method and returns the stream
*/


class Test2 {
	int i{42};
	string str{"Hello"s};
public:
	/*
	* A member function which prints out the data members of the Test class.
	* This version will work with any output stream, not just cout.
	* We pass the output stream by reference as it will be modified inside the function
	*/
	void print(ostream& os) const {
		os << "i = " << i << ", str = " << str;
	}
};

std::ostream& operator << (std::ostream& os, const Test2& test) {
    test.print(os);
    return os;
}

int main() {
    main1();


	Test2 test;
	cout << test << endl;
	
	ofstream ofile("test.txt");
	
	if (!ofile.is_open()) {
		cout << "could not open test.txt" << endl;
		return -1;
	}
	
	ofile << test << endl;
}