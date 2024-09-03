

//############
// find()
//############

/*
the find() member functions looks for the first occurrence of its argument in the string.
The search is case sensitive.

- The argument to these member functions can be a char, a std::String, or a C-style string.

- it returns the index of the first match.

- If ther is no match, it returns string::npos

*/

// string str{"Hello World!"};
// str.find('o'); // returns 4
// str.find("or"); // returns 7
// str.find('O'); // returns string::npos


//We cam use return value from find() as an index, but we must first check if it is valid

#include <iostream>
#include <string>

using namespace std;

int main(){
    string str{"Hello World!"};
    size_t pos = str.find('o');

    if (pos != std::string::npos){
        str[pos] = 'p';
    } else {
        std::cout << " 'o' not found" << std::endl;
    };
}


//############
// rfind()
//############

/*
There is an rfind() member function that searches for the last occurrence of its argument in the string.

string str{"Hello World!"};
str.rfind('o'); // returns 7
str.rfind("or"); // returns 7

by default, the search starts from the end of the string.
we can change this by passing a second argument to rfind()

str.find('o', 5); // returns 4
*/

//######################
// More search Functions
//######################

/*
find_first_of() and find_last_of() search for the first and last occurrence of any character
in a string that is in a specified set of characters.

string vowels{"aeiou"};
str.find_first_of(vowels); // returns 1
str.find_last_of(vowels); // returns 7

find_first_not_of() and find_last_not_of() search for the first and last occurrence of any character

str.find_first_not_of(vowels); // returns 0
str.find_last_not_of(vowels); // returns 10

*/
