#include <iostream>
#include <string>

void main(){

// C Style String Literal

//the traditional string literal is an array of const char, terminated by a null character

const char *cca = "Hello,world!"; // C-style string literal - null-terminated array of const char

/*
very limited range of operations
only compatible with arrays of the same lenght
*/

//From C++14 we can crate std::string literals
// we add 's' after the closing double quote



using namespace std::literals; // C++14 literals have their own namespace
std::string str = "Hello, world!"s; // std::string

//supports all std::string operations

std::cout <<"Hello"s + ", world!"s; // can perform std::string operations

//can be used anywhere that expects an std::string object

std::cout <<"Hello" + ", world!"; // this will not work, cannot add two pointers

//std::string literals converts in place to std::string objects


//String Literals and Escape characters

/*
in a string literal, certain characetrs can be "escaped"
- this gives them a different meaning

This is done by putting a backslach \ in fron of them

\n - newline character in string literal (not character 'n')
\" - double quote character in string literal (not string terminator)

consider the followeing
<a href="file">C:\"Program Files"\</a>\n

wo write this as a string literal, we need to escape the " and \ characters"


string literal with escaped characters
*/
std::string url = "<a href=\"file\">C:\\\"Program Files\"\\</a>\\n";

//Raw String Literals

/*
C++11's raw string literals void "backslashitis"
we put the string literal inside R "()" to make it a raw string literal
*/

std::string url2 = R"(<a href="file">C:\"Program Files"\</a>\n)"; // Raw string literal with unescaped characters

//this prevents characters as " and \ from being processed as escape characters
// if the string cointains a ")" we need to add a delimiter

std::string url3 = R"x(<a href="file">C:\"Program Files"\</a>\n)x"; // Raw string literal with delimiter x


}