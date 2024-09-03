//###########
//# Class Hierarchy
//###########

/*
Programmers often work with entities which are related or represent similar conpcets
    - Graphical shapes all postion on the screen, can be drawn, filled, rotated, etc.
    - Elements in a docmunet (test, tables, diagramas) can be formatted, moved, zoomed, etc.
    - C++ input streams process input from different sources and convert it to data

A class hierarchy can
    - Express these relationships
    - Make it easier for related classes to reuse code


*/

/*
Related classes are organized in a hierarchy
    - Shape 
        - Circle
        - Square
        - Triangle

*/

//###########
//# Input stream Hierachy
//###########

/*
- istream
    - ifstream
    - istringstream

*/

//###########
//# Base Class
//###########

/*
- The class at the top of the hierarchy represents the most general or the most basic version
- This is known as the base class

    - Grhaphical shapes have shape as their base class
    - input streams have istream as their base class

*/

//###########
//# Derived Classes
//###########

/*
Classes below the base class are known as "derived classes" or "subclasses"
- They are said to "inherit" from or "derive" from the base class
- These are more specialized versions of the base class, or enhanced versions with more features
- Shape has circle, trinagle, ... as derived class
    - Specific kinds of shape

- ifstream and istringstream derive from istream
    - Specialized streams which interact with files and std::string objects

*/

//###########
//# inheritance
//###########

/*
The relationship between classes at different levels in the hierarchy is called "inheritance"
- Inheritance models an "is-a" or "is-a-kind-of" relationship between classes
    - An istringsream is-a-kind-of istream
    - A Circle is a Shape

*/