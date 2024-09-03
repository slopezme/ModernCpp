//############
// member and non-member operators
//############

/*
most operators can be implemented as eiterh member functiosn or non-member functions

- usually they should be implemented as member functions
    - Provides direct access to private data
    - Keeps all class related code in one place
- However,  in some cases it is better to use non-member functions
    - Some operators cannot be implemented as member functions
*/

//############
// The problem with binary member operators
//############

/*
Binary member operators do not work if we need a type conversion

class String {
...
String operator+(const char* arg) {
    ...
};

String w{"world"}, bang{"!"};
String wbang = w + bang;    // OK
String hi = "Hello" + w; // Error
}

- The code fails to compile because the literal "Hello" is not a String object

*/

#include <iostream>
#include <string>

using namespace std;

class String {
    string s;
public:

    String(const char* str) : s{str} {}
    String(const string& s) : s(s){}

    String operator +(const String& arg) {
        return s + arg.s;
    }


    void print() {
        cout << s << endl;
    }
        
};

void main1() {
    String w{"world"}, bang{"!"};
    String wbang = w + bang;                // Calls w.operator+(bang) ; OK
    //String hi = "Hello"s + w;             // Cannot call "Hello" .operator+(w) ; compile error!
    cout << "wbang = "; wbang.print();

    // cout << "hi = "; hi.print();
}


//############
// Binary non-member operators
//############

/*
-  If we use a non - member operator, we can convert the left hand operand to the correct type

String operator +(const String& arg1, const String& arg2) {
    return arg1.s + arg2.s;
}

String wbang = w + bang;    // Calls operator+(w, bang) ; OK
String hi = "Hello"s + w;   // Calls operator+(String("Hello"), w) ; OK


- The compiler will convert "hello" to a String here because it is a function argument\
*/

class String2 {
    string s;
public:
    String2(const char* str) : s{str} {}
    String2(const string& s) : s(s){}

    friend String2 operator +(const String2& arg1, const String2& arg2);

    void print() {
        cout << s << endl;
    }
};

String2 operator +(const String2& arg1, const String2& arg2) {
    return arg1.s + arg2.s;
}

void main2() {
    String2 w{"world"}, bang{"!"};
    String2 wbang = w + bang;                // Calls operator+(w, bang) ; OK
    String2 hi = "Hello"s + w;                // Calls operator+(String("Hello"), w) ; OK
    cout << "wbang = "; wbang.print();
    cout << "hi = "; hi.print();
}

int main() {
    main1();
    main2();
    return 0;
}


//############
// When to use Member Operators? 
//############

/*
- operators which change the state of the object are best implemented as member functions
    - Compund assignment +=, -=, *=, /=
    - increment and decrement ++, --

- Operators which are closely related to the member types are best implemented as member functions
    - Defereference *, ->, []

Contd
Some operators must be defined as member functions
    - Assignment operator =
    - Function call operator ()
    - Subscript operator []
    - Member access operator ->
*/

//############
// When to use Non - member operators?
//############

/*
Binary operator which might requiere a type conversion of eiher argument should be non member functions
    - Arithmetic operators +, -, *, /
    - Equality operators ==, !=
    - relational operators <, >, <=, >=
    - Bitwise operators &, |, ^, ~

- The input / output operators <<and>> 
    - These should be non-member functions for compatibility with sintax

*/
