#include <iostream>

using namespace std;

int main(){
    const char str[] = {'H', 'e', 'l', 'l', 'o'};
    const char *pEnd = str +5;  //Pointer to element after the last element
    const char *p = str;        //Pointer to the first element

    while (p != pEnd){          //Gone past last element?
        cout << *p;
        p++;                    // increment to move to next element
    }

    //std::string iteration
    // with std::string, we can use an iterator in the same way
    
    string str2{"Hello"};
    // string::iterator it = /* iterator to first element */;

    // while (it != /*Iterator to last element plus one*/){
    //     cout << *it;            // Deference to get the current element
    //     it++;                   // increment to move to next element
    // }
    
    // begin() and end()

/*
begin() -- returns an iterator to the first element
end()  Returns an iterator corresponding to "the element after the last element"
- this is an invalid iterator and must not be dereferenced

These iterators are specific to the object
- they must not be mixed with iterators from other objects
*/

//Iterating over string
// we can finalize out loop 

string::iterator it = str2.begin();  // Start of string

while (it != str2.end()){        // End of string
    cout << *it;
    it++;
}

// if the container is empty, begin() and end() will return the same iterator,
// the loop body is not executed


}


