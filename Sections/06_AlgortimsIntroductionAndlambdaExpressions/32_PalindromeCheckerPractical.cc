//############
// Palindrome Checker
//############

/*
- A palindrome is an expression which reads the same forwards and backwards
- Examples
    - Madam I'm Adam
    - Able was ere i saw elba
    - A man, a plan a canal, Panama!
- Space characters, punctuation and capitalization are ignored
- we will write a program which checks whether a string is a palindrome
    - If the input is not a palindrome, it will print out the mismatched characters
    and the input to the second mismatch

- We will use only standard library algorithms and functions (no loops)


*/

//############
// Normalization
//############

/*
- First we "normalize" the string
    
    - // make a copy, keeping only the alphabetical characters

    copy_if(cbegin(str), cend(str), back_inserter(retval), 
        [](char c) { return isalpha(c); });

    - // Convert all remaining characters to the same case

    transform(begin(retval), end(retval), begin(retval), 
        [](char c) { return tolower(c); });
*/

//############
// mismatch()
//############

/*
- Call std::mismatch()  to compare the string to the reverse of itself
- we use a reverse iterator 

    auto p = mismatch(cbegin(pal), cend(pal), crbegin(pal));

- The return value from mismatch() is a pair of iterators
- These point to the first mismatched element in each range
- It there is no mismatch, these will be equal to end()
    - The input string is a valid palindrome!

*/

//############
// Failure case
//############

/*
- If the returned iterators are not equal to end(). the input string is not a palindrome
    - There is a mismatch between the character at p.first and the character at p.second

- We make a copy of the string, up to the p.second

    -// use the base() member function to convert the reverse iterator to a forward iterator

    copy(cbegin(pal), p.second.base(), back_inserter(outstr));
*/

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

// Return a copy of the argument string
// with non-alphabetic characters removed, converted to lowercase

string normalize(const string& s) {
    string retval{""};

    copy_if(cbegin(s), cend(s), back_inserter(retval), 
        [](char c) { return isalpha(c); });

    transform(begin(retval), end(retval), begin(retval), 
        [](char c) { return tolower(c); });

    return retval;

}


int main() {
    string s{""};
    cout << "Please enter your palindrome: ";
    getline(cin, s);

    // Input string with punctuation and spaces removed
    string pal = normalize(s);

    // Call mismatch()  to compare the string to its reverse
    // use a reverse iterator

    auto p = mismatch(cbegin(pal), cend(pal), crbegin(pal));

    // The return value from mismatch() is a pair of iterators
    // These point to the first mismatched element in each range
    if (p.first == cend(pal) && p.second == crend(pal)) {
        cout << "The input string is a valid palindrome!" << endl;
    }
    else {
        cout << "The input string is not a palindrome!" << endl;

        // There is a mismatch between the character at p.first and the character at p.second
        // Make a copy of the string, up to the p.second
        string outstr{""};

        // use the base() member function to convert the reverse iterator to a forward iterator
        copy(cbegin(pal), p.second.base(), back_inserter(outstr));
        cout << "'" << *(p.first) << "'" << " doest not match " << "\'" << *(p.second.base()) << "\'";
        cout << " at \"" << outstr << "\"" << endl; 
    }


}