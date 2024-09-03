#include <iostream>
#include <string>
#include <vector>

using namespace std;

//############
// Character Functions
//############

/*
The C++ standard library has a number of character functions which are inherited from C
These are defined in <cctype> and operate on chars

some of the most useful are

isdigit(c);   // Returns true if c is a digit (0-9)
islower(c);   // Returns true if c is a lowercase letter (a-z)
isupper(c);   // Returns true if c is an uppercase letter (A-Z)
isspace(c);   // Returns true if c is whitespace (space, tab, newline)
ispunct(c);   // Returns true if c is a punctuation character (not a letter, digit, or whitespace)

*/


//############
// tolower() and toupper()
//############

/*
tolower() and toupper() return the lower and upper case equivalents of their argument
*/


#include <cctype>
bool yer_or_no(const string& input){
    char c = input[0];

    if (toupper(c) == 'Y')
        return true;
    return false;
}

void f1(){
    string input;
    cout << "Do you want to proceed? (y/n): ";
    cin >> input;

    if (yer_or_no(input)){
        cout << "Evidently you do!\n" << endl;
    } else {
        cout << R"(I will take that as a "no"!)" << endl;
    }
}


//############
// case sensitvity and String comparison
//############

/*
Operations on std::string are case sensitive
- "One"s and "one"s are regarded as string with different data

These is no direct support for doing case- insensitive comparisons of two strings

Compiler implementations often provide functions which do this case-insensitive comparison
of C-style strings
- stricmp on Windows
- strcasecmp on Unix

Thse are not standard C++ functions, not portable and do not directly support std::string

The simplest solution is to convert all strings to a single case before comparing them

for (auto& c : s1)
    c = toupper(c);

- this changes the string and removes the original case information
- if we need to preserve this, in place conversion is not acceptable
- we can make a copy of the string and convert the copy to single case
- Alternatively, we can write our own comparison function
*/


//############
// equals_strings function
//############

/*
Our function should have the same interface as the built-in operator
- Take two strings by const reference and return a bool

// Case insensitive string equality. Returns true if lhs and rhs are equal, otherwise false

bool equal_strings(const string& lhs, const string& rhs){

it will do a case-insensitive comparison for each corresponding character in the two strings

First we compare the lengths of the two strings
- If they are different, the strings are not equal

if(lhs.size() != rhs.size())
    return false;

Then we compare the characters in the two strings

auto lit = cbegin(lhs);
auto rit = cbegin(rhs);

while(lit != cend(lhs) && rit != cend(rhs)){
    if(toupper(*lit) != toupper(*rit))
        return false;
    ++lit;
    ++rit;
}

*/

bool equal_strings(const string& lhs, const string& rhs){
    if(lhs.size() != rhs.size())
        return false;

    auto lit = cbegin(lhs);
    auto rit = cbegin(rhs);

    while(lit != cend(lhs) && rit != cend(rhs)){
        if(toupper(*lit) != toupper(*rit))
            return false;
        ++lit;
        ++rit;
    }

    return true;
}


int main(){
    string a{"one"}, b{"Two"}, c{"One"};

     cout << " Usi ng library == operator\n";
    cout << a << " and " << b << " are " << (a == b ? "equal " : " not equal \n");
    cout << b << " and " << c << " are " << (b == c ? "equal " : " not equal \n");
    cout << a << " and " << c << " are " << (a == c ? "equal " : " not equal \n");
    cout << "\n\nUsing equal_strings() function\n";
    cout << a << " and " << b << " are " << (equal_strings(a,b) ? "equal " : "not equal \n");
    cout << b << " and " << c << " are " << (equal_strings(b,c) ? "equal " : "not equal \n");
    cout << a << " and " << c << " are " << (equal_strings(a,c) ? "equal " : "not equal \n");


/*COUT log

Using library == operator
one and Two are not equal
Two and One are not equal
one and One are not equal

Using equal_strings() function
one and Two are not equal
Two and One are not equal
one and One are equal

*/


}
