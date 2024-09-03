//############
// find_first_of()
//############

/*
- std::string has a member function find_first_of() 

    string str{"Hello World!"};
    string vowels{"aeiou"};
    str.find_first_of(vowels);          // Returns the index of the first vowel in str

- There is a generic algorithm function, std::find_first_of() 

    -// Returns an iterator to the first vowel
    auto vowel = find_first_of(cbegin(str), cend(str), cbegin(vowels), cend(vowels));

    if (vowel != cend(str)){
        cout << "The first vowel in str is " << *vowel << endl;             // First vowel is 'e'
    }

- By default, the == operator of the elements is used to compare them

*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void main1(){
    string str{"Hello World!"};
    cout << "String to search: " << str << endl;

    string vowels{"aeiou"};

    // Returns an iterator to the first character in "vowels"
    auto vowel = find_first_of(cbegin(str), cend(str), cbegin(vowels), cend(vowels));

    if (vowel != cend(str))
        cout << "The first vowel in str is " << *vowel << "at index " << distance(cbegin(str), vowel) << endl;
}

//############
// find_first_of()
//############

/*
- If we want to to find the next vowel in the str after the first one, we can use the following code:
- We search the rest of the string, beginning at the next character after the first vowel
- we pas the iterator range [next(vowel), cend(str)) 

    - // Returns an iterator to the next vowel
    auto next_vowel = find_first_of(next(vowel), cend(str), cbegin(vowels), cend(vowels));

    if (next_vowel != cend(str)){
        cout << "The next vowel in str is " << *next_vowel << endl;             // Next vowel is 'o'
    }
    

*/

void main2(){
    string str{"Hello World!"};
    cout << "String to search: " << str << endl;

    string vowels{"aeiou"};

    // Returns an iterator to the first character in "vowels"
    auto vowel = find_first_of(cbegin(str), cend(str), cbegin(vowels), cend(vowels));

    if (vowel != cend(str))
        cout << "The first vowel in str is " << *vowel << " at index " << distance(cbegin(str), vowel) << endl;

    // Returns an iterator to the next character in "vowels"
    auto next_vowel = find_first_of(next(vowel), cend(str), cbegin(vowels), cend(vowels));

    if (next_vowel != cend(str))
        cout << "The next vowel in str is " << *next_vowel << " at index " << distance(cbegin(str), next_vowel) << endl;
}


//############
// adjacent_find()
//############

/*
- std::adjacent_find() looks for two neighboring elements that have the same value
- It returns an iterator to the first element of the first match

string str{"Hello World!"};

    -// Returns an iterator to first element of "ll"
    auto pos = adjacent_find(cbegin(str), cend(str));

    if (pos != cend(str)){
        cout << "The first adjacent pair of characters with the same value is " << *pos << endl;
    }

- By default, the == operator of the elements is used to compare them
*/

void main3(){
    string str{"Hello World!"};
    cout << "String to search: " << str << endl;

    string vowels{"aeiou"};

    // Returns an iterator to the first character in "vowels"
    auto pos = adjacent_find(cbegin(str), cend(str));

    if (pos != cend(str))
        cout << "The first adjacent pair of characters with the same value is " << *pos << " at index " << distance(cbegin(str), pos) << endl;
}

//############
// search_n()
//############

/*
- std::search_n() looks for a sequence of n successive elements which have the same given value
- It return an iterator to the first element of the sequence

vector<int> { 1, 2, 2, 3, 2, 3, 3};

- // looks for a sequence of two elements with value ?
- // Returns an iterator to the start of the first such sequence
auto pos = search_n(cbegin(vec), cend(vec), 2, 3);

- By default, the == operator of the elements is used to compare them
*/

void main4(){
    vector<int> vec{1, 2, 2, 3, 2, 3, 3};
    cout << "Vector to search: ";
    for (const auto& v: vec){
        cout << v << " ";
    }
    cout << endl;

    // looks for a sequence of two elements with value 3
    auto pos = search_n(cbegin(vec), cend(vec), 2, 3);

    if (pos != cend(vec))
        cout << "The first sequence of two 3s starts at index " << distance(cbegin(vec), pos) << endl;
}

//############
// search()
//############

/*
- std::search()  takes two iterator ranges
- it looks for an occurrence of the second iterator range insided the first range
    - Similar to finding a substring in a string
- it returns an iterator to the first occurrence

    string str{"Hello world!"};
    string sub{"wo"};

    - // Returns an iterator to first element of "wo"

    auto pos = search(cbegin(str), cend(str), cbegin(sub), cend(sub));

- By default, the == operator of the elements is used to compare them

*/

void main5(){
    string str{"Hello world!"};
    cout << "String to search: " << str << endl;

    string sub{"wo"};
    cout << "searching for substring : " << sub << endl;

    // Returns an iterator to the first character in "wo"
    auto pos = search(cbegin(str), cend(str), cbegin(sub), cend(sub));

    if (pos != cend(str))
        cout << "The first occurrence of \"" << sub << "\" in str is at index " << distance(cbegin(str), pos) << endl;
    else
        cout << "The substring \"" << sub << "\" is not found in str" << endl;
}

int main(){

    cout <<  "\nExample 1: \n" << endl;
    main1();

    cout <<  "\nExample 2: \n" << endl;
    main2();

    cout <<  "\nExample 3: \n" << endl;
    main3();

    cout <<  "\nExample 4: \n" << endl;
    main4();

    cout <<  "\nExample 5: \n" << endl;
    main5();

}
