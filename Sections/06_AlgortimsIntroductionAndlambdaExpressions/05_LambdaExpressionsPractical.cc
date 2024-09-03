//############
// Case insensitive string comparison
//############

/*
- In "Character Functions" we worte a function that compares two string arguments and ignores case
    - // Case insensitive string equality. Returns true it lhs and rhs are equal, otherwise false

    bool equal_strings(const string& lhs, const string& rhs);

    if (equal_strings(str1, str2))

- We will implement this function again, this time using a lambda expression     

*/

#include <iostream>
#include <string>

using namespace std;

// Case insensitive string equality. Returns true if lhs and rhs are equal, otherwise false

bool equal_strings(const string& lhs, const string& rhs){
    // If the Two strings are of different length, they are not equal
    if (lhs.length() != rhs.length())
        return false;

    // If the two strings are of the same length ...
    auto lit = cbegin(lhs);
    auto rit = cbegin(rhs);

    while (lit != cend(lhs) && rit != cend(rhs)){
        if (toupper(*lit) != toupper(*rit))
            return false;
        ++lit;
        ++rit;

    }
    return true;
}

void test(const string& str1, const string& str2){
    cout << str1 << " and " << str2 << " are " << (equal_strings(str1, str2) ? "" : "not ") << "equal" << endl;
            
}

void main1(){
    test("lambda", "Lambda");
    test("lambda", "lambada");

}

//############
// Equal() algorithm
//############

/*
- The equal() algorithm can be used to compare the elements in two containers

bool cmp = equal(cbegin(ct1, cend(ct1), cbegin(ct2), cend(ct2));

- This iterates through each element in ct1 and compares it to the coreesponding element in ct2

- it returns false as soon as it encounters a pair of elements that are not equal
    - If ct1 has more elements than ct2, it also returns false
    - If ct2 has more elements than ct1, the extra elements are ignored

- By default, the == operator is used to compare the elements
    - if the containers are std::string, the comparison will be case-sensitive
*/

//############
// Equal() algorithm with predicate
//############

/*
- There is an overload of the equal() algorithm which takes a predicate

bool cmp = equal(cbegin(ct1), cend(ct1), cbegin(ct2), cend(ct2), func);

- This pedicate will be called instead of the == operator 
- We can use this to define what we mean by "equalilty" for the elements in the containers
    - In this example, we want two string characters to be considered equal if they have the 
    same value after being converted to uppercase
*/
    
//############
// Lambda expression predicate
//############

/*
- we write a lambda expression for the predicate
- This will be passed one character from each string as arguments
- It will convert both characters to uppercase 
- It returns true if the converted characters are equal, otherwise false

[] (char lc, char rc) {return toupper(lc) == toupper(rc);}
*/

bool equal_strings2(const string& lhs, const string& rhs){
    // Call equal() algorithm function using a lambda expression 

    return equal(cbegin(lhs), cend(lhs), cbegin(rhs), cend(rhs), 
        [] (char lc, char rc) {return toupper(lc) == toupper(rc);});
}

void test2(const string& str1, const string& str2){
    cout << str1 << " and " << str2 << " are " << (equal_strings2(str1, str2) ? "" : "not ") << "equal" << endl;
            
}

void main2(){
    test2("lambda", "Lambda");
    test2("lambda", "lambada");

}

int main(){
    cout << endl << "main1" << endl << endl;
    main1();

    cout << endl << "main2" << endl<< endl;
    main2();
    return 0;
}


        