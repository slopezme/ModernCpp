

#include <iostream>
#include <vector>

int main() {
using namespace std;

// ###############################
// ### Initializer in if statement
// ###############################

std::vector <int> vec = {1, 2, 3, 4, 5};

auto iter = begin(vec);
if(iter != end(vec))                            //check container is not empty
    cout << *iter << endl;


// C++17 allows initialization in if statements
if (auto iter = begin(vec); iter != end(vec)) { // check container is not empty
    cout << *iter << endl;

/* this has similar advantages to the for loop initializer
'iter' is local to the if statement
 this includes the "else" block*/

//Note Visual Studio 2022 uses C++17 by default

// ###################################
// ### Initializer in switch statement
// ###################################

auto get_next_char = []() -> char {
    static char c = 'A';
    return c++;
};

const char c = get_next_char();
switch (c){
 // ...
}

// C++17 allows initialization in switch statements

switch (const char c = get_next_char(); c){
    // ...

}

// again, the 'c' variable is local to the switch statement


char c;
int ws_count{0};

const char *arr = "how much whitespace in\t here?";
cout << "the test to process is \"" << arr << "\"" << endl;

for(int i = 0; c = arr[i]; i++){
    switch(const char c = arr[i]; c){
        case ' ':               // c is space character
        case '\t':              // c is tab character
        case '\n':              // c is newline character
            ++ws_count;         // increment whitespace count
            break;
        default:                // c is not whitespace
            break;
    }
}

// ########################################
// Falling Through Case Labels Deliberately
// ########################################

// it there is no break at the end of a case label, the program flow " falls through"
// to the next case label
// Ofthe this is useful

switch(c){
    case ' ':           // c is space character
                        // fall through to next case
    case '\t':          // c is tab character
                        // fall through to next case
    case '\n':          // c is newline character
        ++ws_count;     // increment whitespace count
        break;
}

// however, it can easily be done by accident
/*
switch(employee_location){
    case HEAD_OFFICE:
        vehicle_type = mercedes;
        break;
                                    //  No break - fall through to next case
    case SALES_OFFICE:
        vehicle_type = ford;
                                    // fall through to next case
    case WAREHOUSE:
        vehicle_type = truck;       // This is executed for all three cases
        break;
}
*/


// Fallthrough Attribute
/*
C++17 provides a [[fallthrough]] attribute to indicate that fallthrough is deliberate
- this is used with an empty statement
- it indicates that the break statement is missing intentionally
- the compiler will not generate a warning
*/

switch(c){
    case ' ':           // c is space character
        [[fallthrough]]; // fall through to next case
    case '\t':          // c is tab character
        [[fallthrough]]; // fall through to next case
    case '\n':          // c is newline character
        ++ws_count;     // increment whitespace count
        break;
}






}//main
