/*
Write a program which will

Reads strings entered by the user

Store them in a sequential container

Print out the strings in the order they were entered

Questions for this assignment
Implement this program using std::vector to store the strings. Check that your program compiles and runs correctly.

Implement this program using std::list to store the strings. Check that your program compiles and runs correctly.

Implement this program using std::deque to store the strings. Check that your program compiles and runs correctly.

Change the list and deque versions so that they store the strings in reverse order.

Do not perform any manipulation on the container elements.

Check that your program compiles and runs correctly.
*/

#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace std;

void vectorExample(){
    vector<string> v;
    string input;
    cout << "Enter a string: ";
    while (cin >> input){
        v.push_back(input);
        cout << "Enter a string: ";
    }

    cout << "Strings in order entered: " << endl;
    for (string s : v){
        cout << s << " ";
    }
    cout << endl;
}

void listExample(){
    list<string> l;
    string input;
    cout << "Enter a string: ";
    while (cin >> input){
        l.push_back(input);
        cout << "Enter a string: ";
    }

    cout << "Strings in order entered: " << endl;
    for (string s : l){
        cout << s << " ";
    }
    cout << endl;
}

void dequeExample(){
    deque<string> d;
    string input;
    cout << "Enter a string: ";
    while (cin >> input){
        d.push_back(input);
        cout << "Enter a string: ";
    }

    cout << "Strings in order entered: " << endl;
    for (string s : d){
        cout << s << " ";
    }
    cout << endl;
}

void listReverseExample(){
    list<string> l;
    string input;
    cout << "Enter a string: ";
    while (cin >> input){
        l.push_front(input);
        cout << "Enter a string: ";
    }

    cout << "Strings in reverse order entered: " << endl;
    for (string s : l){
        cout << s << " ";
    }
    cout << endl;

}

void dequeReverseExample(){
    deque<string> d;
    string input;
    cout << "Enter a string: ";
    while (cin >> input){
        d.push_front(input);
        cout << "Enter a string: ";
    }

    cout << "Strings in reverse order entered: " << endl;
    for (string s : d){
        cout << s << " ";
    }
    cout << endl;
}

int main    (){

    // cout << "Vector Example: " << endl;
    // vectorExample();

    cout << "List Example: " << endl;
    listExample();

    cout << "Deque Example: " << endl;
    dequeExample();

    cout << "List Reverse Example: " << endl;
    listReverseExample();

    cout << "Deque Reverse Example: " << endl;
    dequeReverseExample();


    return 0;
}