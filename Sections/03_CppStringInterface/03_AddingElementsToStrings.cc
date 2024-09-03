
//############
// Append()
//############

/*
Append() member function appends its argument to the string.

string hello{"Hello"};
hello.append(" World!");

- normally we use the += operator to append to a string
- however, append han an olverload which makes adding a substring more efficient

hello.append("wow!"s, 3,2); // String is now "Hello World!"
*/

#include <iostream>
#include <string>

using namespace std;

void printAppend(){
    string hello{"Hello"};

    hello.append(" World!"s);
    cout << "hello =" << hello << endl;

    string hello2{"Hello"s};

    hello2.append("wow!!!!"s, 3, 2);
    cout << "hello2 = " << hello2 << endl;


}


//############
// insert()
//############

/*
The insert() member function has a number of overloads
- it adds characters before a specified position
- we can insert a string literal or a string variable


*/
void printInsert(){
    string str{"for"};
    str.insert(2, "lde"s);  // Insert "Ide" before str[2] - string is now "folder"

    string str2{"care"};
    string str3{"omp"};

    str2.insert(1,str3);   // insert str3 before str2[1] - string is now "compare"
}

//############
// insert() Contd
//############

/*
We can isert a substring
*/

void f1(){
    string str{"xx"};
    string str2{"trombone"};
    str.insert(1, str2, 4, 2); // insert "bo" from str2 before str[1] - string is now "xbox" (TM)
}

// We can insert a char, multiple times

void f2(){
 string str3("cash");
 str3.insert(1, 3, 'r'); // insert 3 'r's before str3[1] - string is now "crash"
}

// we can insert at the result of a find call

void f3(){
    string hello{"hello"};
    auto opos = hello.find('o');
    hello.insert(opos, 2, 'o'); // Insert 'o' twice beofre first instance of 'o'

    // string is now "hellooo"

}

//############
// iterators
//############

// insert() can also take an iterator
void f4(){
    string str{"word"};
    auto last = end(str)-1; // Get iterator to last character

    // Insert 'l' before last character
    str.insert(last, 'l');  // string is now "world"

    string str2{"skip"};
    auto last2 = end(str2);  // Get iterator to last character plus one

    // Insert 'l' twice, after last character

    str2.insert(last2,2,'l'); // string is now "Skill"

}

//############
// iterator invalidation
//############

/*
-Inserting elements may fill up the string's memory buffer
- In this case, it will allocate a nwe buffer and copy its data into
 new buffer before adding the new element
 - Any saved iterators into the string will be pointing innto the old buffer
 - There iterators are now invalid and using them will cause undefined behavior

*/

void f5(){
    string str{"orld"};
    auto first = begin(str);

    str.insert(end(str), 16, 'd'); // Add enough elements for force a reallocation
    str.insert(first, 'w');     // use saved iterator from before the reallocation

    cout << "str = " << str << endl; // string is now "worlddddddddddddd"
}
