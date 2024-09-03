/*####################
# Custom Exception Class
####################*/

/*
- We can write our own exception classes
- usually it is best to derive it from one of the subclasses of std::exception
    - Existing interface
    - We can inherit code instead of rewriting it
    - Will be caught by std::exception handlers
- We do not derive from std::exception
    - std::exception has a default constructor only
    - No provision for passing a custom error message
*/

/*####################
# Custom Ecxeption Class Requirements
####################*/

/*
- A custom exception class needs constructors which take a string 
    - Both std::string and C-style
- It needs a copy constructor
    - This can be inherited or defaulted

- it can override the what() virtual member function
    - if extra functionality is requiered
- It can have data members to store information relevant to the error condition
    - Recommendation: only use built-in types

*/

/*####################
# Custom Ecxeption Class Considerations
####################*/

/*
- A custom exception object will copied into memory off the local stack
- The program may be in an unstable state
- the object should be lightweight
    - have the minimum number of data members
    - Perform minimal processing
- In particular, it should not do anything that might throw a fresh exception
*/

/*####################
# Custom Ecxeption Class Example
####################*/

/*
- We will create an exception class for our student grades program
- We will call our class invalid_student_grade
- This dhould be thrown when the user enters a grade which is negative or greater than 100%
- This error condtion represents a value which is outside its defined range
    - We will derive our class from std::out_of_range

*/

/*####################
# invalid_student_grade Constructor
####################*/

/*
- std::out_of_range has a constructor which takes a string argument
- we need to implement these for consistency
    - invalid_student_grade(const char *s) : std::out_of_range{s} {}
    - invalid_student_grade(const std::string &s) : std::out_of_range{s} {}

- We also implement a default constructor
- This calls the std::out_of_range constructor with a suitable error string

    invalid_student_grade() : std::out_of_range{"Invalid student grade"} {}
*/

/*####################
# invalid_student_grade members
####################*/

/*
- The only relevant data is the error string
- This is sotred in the std::out_of_range part of the class
    - we do not need any data members of our own
- Since we do not have any data members, we do not need to implement a copy constructor
- In this case, the compiler will generate a copy constructor which will copy
the std::out_of_range part of the class
- For similar reasons, we do not need to implement a destructor
*/

/*####################
# invalid_student_grade member functions
####################*/

/*
- We could also override the virtual what() member function
    - Not actually needed here
- This is declared const, because it does not change the exception object
- It is also declared noexcept, because it does not throw exceptions
- It returns the error string, as const char *

    const char *what() const noexcept override {
        ...}

*/

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class bad_student_grade : public std::out_of_range {
    public:
        // Default constructor
        bad_student_grade() : std::out_of_range{"Invalid student grade"} {}

        // We need constructors which take a string, for consistency with std::exception
        bad_student_grade(const char *s) : std::out_of_range{s} {}
        bad_student_grade(const string &s) : std::out_of_range{s} {}

        // These default operators are good enough as we do not have any data members
        bad_student_grade(const bad_student_grade &other) = default;
        bad_student_grade &operator=(const bad_student_grade &other) = default;

        // Finally , we can override the virtual what() member function
        // const char* what() const noexcept override { /* ... */ }
        
};

class StudentGrade {
    int grade;
    public:
        StudentGrade(int grade) : grade{grade} {
            if(grade < 0 ) {
                throw bad_student_grade{"bad grade"};
            }
            if (grade > 100) {
                throw bad_student_grade("bad grade");
            }
        }
};

int main() {
    int result;
    cout << "Please enter the student's grade (between 0 and 100): ";
    cin >> result;
    try {
        StudentGrade sgrade(result);
        // if we get here, no exception was thrown - safe to use grade
        cout << "Valid student grade: " << result << endl;
    }
    catch (const std::exception &e) {
        cout << "Exception: " << e.what() << endl;
    }
}
