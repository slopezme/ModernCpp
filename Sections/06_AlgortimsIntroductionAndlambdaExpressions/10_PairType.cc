//############
// Pair Type
//############

/*
- std::pair is defined in <utility>
- It has two public data members
    - These can be of different types
    - they are accessed as "first" and "second"

- std::pair can be used to return two related data items from a function\
- std::pair is used by some of the containers in the Standard Library
 */

//############
// Creating a std::pair variable
//############

/*
- std::pair is a templated type
- When we call the pair constructor, we need to specify the types of both members

pair<string,string> wordpair("Hello", "World");
wordpair.first;    // "Hello"
wordpair.second;   // "World"

- We can call make_pair() to create a pair variable

auto wordpair{make_pair("Hello", "World")};

- In C++17, the compiler can deduce the types of the pair members

pair wordpair("Hello"s, "there"s);          // C++17 CTAD   
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

void main1(){
    //pair<string, string> wordpair("Hello"s, "World"s);
     auto wordpair{make_pair("Hello"s, "there"s)}; // Call to std::make_pair() 
    //pair wordpair("Hello"s, "there"s);            // C++17 CTAD

    cout << "First  element of pair is \"" << wordpair.first << "\"\n";
    cout << "Second element of pair is \"" << wordpair.second << "\"\n";
}

pair<string, int> find_index(const vector<string>& vec, int max){
    int idx{-1};

    auto res = find_if(cbegin(vec), cend(vec), 
    // Capture idx by reference
    [max, &idx](const string& str) { ++idx; return str.size() == max; }
    );

    if (res != cend(vec)){
        return { *res, idx };
    }
    else {
        return { ""s, idx };
    }
} 

void main2(){
    vector<string> words{"a", "collection", "of", "words", "with", "different", "lengths"};

    int max{5};

    auto res = find_index(words, max);

    if (res.first != ""s){
        cout << R"(The first word which is more than)" << max << R"( letters long is ")" ;
        cout << res.first << R"(")" << endl;
        cout << "It is at index: " << res.second << endl;
    }
        

}

class ge_n{
    private:
        const int n;
        int& idx;
    public:
        ge_n(const int n, int& idx): n{n}, idx{idx}{}

        bool operator()(const string& str) const{
            ++idx; return str.size() > n;
        }
};

pair<string, int> find_index2(const vector<string>& vec, int max){
    int idx = -1;

    vector<string>::const_iterator res = find_if(vec.begin(), vec.end(), ge_n(max, idx));

    if (res != vec.end()){
        return make_pair(*res, idx);
    }
    else {
        return make_pair("", idx);
    }
}

void main3(){
    vector<string> words{"a", "collection", "of", "words", "with", "different", "lengths"};

    int max = 5;

    pair<string, int> res = find_index2(words, max);

    if (res.first != ""){
        cout << R"(The first word which is more than)" << max << R"( letters long is ")" ;
        cout << res.first << R"(")" << endl;
        cout << "It is at index: " << res.second << endl;
    }

}

            


int main(){
    cout << endl << "main1" << endl << endl;
    main1();

    cout << endl << "main2" << endl << endl;
    main2();

    cout << endl << "main3" << endl << endl;
    main3();

    return 0;


}

