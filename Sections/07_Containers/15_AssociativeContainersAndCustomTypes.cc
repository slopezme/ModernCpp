//###########
//# Associative Containers and Custom Types
//###########

/*
Custom types can be used with all the associative containers
    - map, set, multimap and multiset
    - ordered and unordered versions

- We can use a custom type as either the value in an associative container or the key, or both
*/

//###########
//# Custom type as value
//###########

/*
We are going to create a container to represent a library of books
We want to be able to search the container to find the books written by an autor (key - value)
An author can wirte more than one book (duplicate keys)
The contianer will be a multimap
The key will be a string
    - the autor name
The Value will be an objecto of a class
    - The details of the book

*/

//###########
//# Book Class
//###########

#include <iostream>
#include <map>

using namespace std;
// Class with book details

class book {
    private:
        string title;
        string publisher;

    public:
        book(string title, string publisher) : title(title), publisher(publisher) {}
        friend ostream& operator<<(ostream& os, const book& bk) {
            os << "(" << bk.title << ", " << bk.publisher << ")";
            return os;
        }
};

void main1() {
    multimap<string, book> library;             //Key is author, value is book

    // Add some books to the library
    book prog_princs("Programming Principles and Practice Using C++", "Addison-Wesley");
    library.insert({"Stroustrup, Bjarne", prog_princs});

    book cpp_primer("C++ Primer", "Addison-Wesley");
    library.insert({"Lippman, Stanley", cpp_primer});

    book cpp_prog("The C++ Programming Language", "Addison-Wesley");
    library.insert({"Stroustrup, Bjarne", cpp_prog});

    book cpp_tour("A Tour of C++", "Addison-Wesley");
    library.insert({"Stroustrup, Bjarne", cpp_tour});

    // Print all books
    for (auto b : library){
        cout << b.first << ": " << b.second << endl;
    }
}

//###########
//# Sorting the library
//###########

/*
The multimap will sort the books in order of their key
    - The author
Books by the same author will be gruped together, but the titles will probrably not be in order
    - It would be useful to be able to sort the titles as well

- We need  a compund key which included both the authgor and the title
    - This key will sort by the author first , then the title
    - We will write a class to provide this compund key

*/

//###########
//# Custom Type as key
//###########

/*
The new class will contain the fields we want to sort on

class book_idx{
    private:
        string author;
        string title;

    public:
        ...
        };

We will use this class as the key in our multimap

multimap<book_idx, book> library;

*/

//###########
//# Custom type and Container Organization
//###########

/*
Ordered associative containers use the < operator of their keys to sort their elements
    - The compiler will give an error if this is not defined
    - We need to define the < operator for our custom key class
    - To ensure our books are sorted correctly, the < operator needs to compare the author first, then the title

-Unordered associative containers use a hash value of their keys to organize their elements
    - Need to specialize std::hash<T> 
    - Need to define operator == for our class

*/

//###########
//# Identity, equality and equivalence
//###########

/*
Identity
    - The objects occupy the same memory, but are referred to differently
    - Cooresponds to a single copy of a book

- Equality
    - The objects occupy different memory, but have the same values
    - Corresponds to two copies of the same book

- Equivalence
    -"Important"  values are the same, but "unimportant" values are different
    - Corresponds to e.g hardback and paperback versions of the same book
    - Will sort as if they were equal

*/

//###########
//# book_idx < Operator
//###########

/*
bool operator<(const book_idx& other) const {
    -// If the author is the same, order by title
    if (author == other.author) 
        return title < other.title;

    -// Otherwise, order by author

    return author < other.author;
}

*/

#include <iostream>
#include <string>

class book_idx {
    private:
        std::string author;
        std::string title;

    public:
        book_idx(std::string author, std::string title) : author(author), title(title) {}

        bool operator<(const book_idx& other) const {
            // If the author is the same, order by title
            if (author == other.author) 
                return title < other.title;

            // Otherwise, order by author
            return author < other.author;

        }
        friend std::ostream& operator<<(std::ostream& os, const book_idx& bk) {
            os << "(" << bk.author << ", " << bk.title << ")";
            return os;
        }
};

class book2 {
    private:
        string title;
        string publisher;
        int date;

    public:
        book2(string title, string publisher, int date) : title(title), publisher(publisher), date(date) {}
        friend ostream& operator<<(ostream& os, const book2& bk) {
            os << "(" << bk.title << ", " << bk.publisher << ", " << bk.date << ")";
            return os;
        }
};

void main2(){
    multimap<book_idx, book2> library;       // Key is a book_idx, value is a book

    // Add some books to the library
    book2 prog_princs("Addison Wesley", "2nd Edition", 2014);
    book_idx prog_princs_idx("Stroustrup, Bjarne", "Programming Principles and Practice Using C++");
    library.insert(make_pair(prog_princs_idx, prog_princs));

    book2 cpp_primer("Addison Wesley", "5th Edition", 2012);
    book_idx cpp_primer_idx("Lippman, Stanley", "C++ Primer");
    library.insert(make_pair(cpp_primer_idx, cpp_primer));

    book2 cpp_prog("Addison Wesley", "4th Edition", 2013);
    book_idx cpp_prog_idx("Stroustrup, Bjarne", "The C++ Programming Language");
    library.insert(make_pair(cpp_prog_idx, cpp_prog));

    book2 cpp_tour("Addison Wesley", "1st Edition", 2013);
    book_idx cpp_tour_idx("Stroustrup, Bjarne", "A Tour of C++");
    library.insert(make_pair(cpp_tour_idx, cpp_tour));

    // Print all books
    for (auto b : library){
        cout << b.first << ": " << b.second << endl;
    }




}


int main(){
    std::cout << "main1: \n";
    main1();

    std::cout << "main2: \n";
    main2();
    return 0;
}
