/*
A simple C++ class represents a URL, such as "http://www.example.com/index.html".

The class has two members of type std::string. One member stores the protocol of 
the URL (the "http" part) and the other stores its resource 
(the "www.example.com/index.html" part which comes after the separator).

Questions for this assignment
Define the class.

Write a constructor for the class which takes the protocol and resource as arguments.

Add a member function to the class which displays the complete URL: the protocol, 
followed by the separator, followed by the resource. For example, "http://www.example.com/index.html"

Write a program to test your class. This program will create an object of the class, 
then call its member function to display the complete URL.
*/

#include <iostream>
#include <string>

using namespace std;

class URL {
    private:
        string protocol;
        string resource;
    public:
        URL(string protocol, string resource) : protocol(protocol), resource(resource) {}

        void displayURL() {
            cout << protocol << "://" << resource << endl;
        }
};

int main() {
    URL url("http", "www.example.com/index.html");
    url.displayURL();
    return 0;
}