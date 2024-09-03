//############
// erase()
//############

/*
The erase member function removes characters from the string
- It takes two arguments
- The first argument is the index of the first character to be removed
- The second argument is the number of characters to remove
*/

#include <iostream>
#include <string>

using namespace std;

void f1(){
    string str{"Hello"};
    cout << "str = " << str << endl;    // Output: "Hello"

    str.erase(3,1);                     // Erase fourth character

    cout << "str = " << str << endl;    // Output: "Helo"

    auto opos = str.find('e');          // First occurrence of 'e'

    if (opos != string::npos){
        str.erase(opos,2);              // Erase two characters starting at opos
    }

    cout << "str = " << str << endl;    // Output: "Ho"

}

//############
// erase() and iterators
//############

void f1(){
// When used tih an iterator, it will erase the corresponding element

    string hello{"Hello"};
    auto first = begin(hello);
    hello.erase(first); // Erase the first character

// with an iterator range, it will erase all elements in the range

    hello.erase(begin(hello) + 1, end(hello) - 1); // Erase all characters except the first and last
}

//############
// replace()
//############

/*
replace() will remove some of the characters from a string and replace them with other characters
- first argument is the index of the first character to be replaced
- second argument is the number of characters to be replaced
- third argument is the string that will replace the characters
*/

void f1(){
    string str{"Say hello"};

    auto gdx = str.find("H");
    if (gdx != string::npos)
        str.replace(gdx, 5, "Goodbye");   // Replace 5 characters starting at gdx with "H"

    cout << "str = " << str << endl;    // Output: "Say Goodbye"

}

//############
// replace() with iterator Range
//############

/*
we can also use an iterator range
- first argument is an iterator to the first character to be replaced
- second argument is an iterator to one past the last character to be replaced
- third argument is the string that will replace the characters
*/
void f2(){
    string str{"Say Goodbye"};
    cout << "str = " << str << endl;    // Output: "Say Goodbye"

    str.replace(begin(str), begin(str) + 3, "Wave"); // Replace first 3 characters with "Wave"

    cout << "str = " << str << endl;    // Output: "Wave Goodbye"


}

//############
// assign()
//############

/*
assign() will replace the contents of a string with a new string
- The arguments fiven the caracters that will replace them

string str{"Hello"};
str.assign("Goodbye");    // Replace "Hello" with "Goodbye"

*/

void f3(){
    string str{"Hello"};
    cout << "str = " << str << endl;    // Output: "Hello"

    str.assign("Goodbye");              // Replace "Hello" with "Goodbye"

    cout << "str = " << str << endl;    // Output: "Goodbye"

}
