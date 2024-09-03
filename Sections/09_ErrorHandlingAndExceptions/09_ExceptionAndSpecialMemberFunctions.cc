/*####################
# Destructor and Exception
####################*/

/*
- When an exception is thrown, the destructor is called for all local 
variables in the current scope

- Whet happends if a destructor throws an exception?
    - If the exception  is handled by a catch block in the destrcutor, this is safe
    - if the exception is not handled by the destructor, a stack undiwn will ensue
    - If another exception is being processed, there could be two stack unwind operations
    in progress at the same time
    - C++ implementations assume there is only one active exception at a time
    - undefined behavior
    - Destructor should never throw exceptions
    - If code in a destructor does throw, it must be handled by the destructor
    - usually this is not a problem, as destructors should only release resources
- If an unhandled excpetion is thrown during a constructor call, the partially - initialized
object will be destroyed
    - All its data members will also be destroyed
    - If the object is a child class, its parent part will be destroyed as well
- As far as the rest of the program is concerned, an object does not exist until
its constructor has completed successfully
- An excpetion thrown in a constructor should be left for the caller to handle
    - The caller will then know the object has not been successfully created
- The constructor should only handle the exception if it can solve the problem and coontinue
initilizing the object

- If we allow the caller to handle the exception there are only two possible outcomes
from calling a constructor:
    -  Either no exception and successfully created object
    - Or an exception is thrown and there is no object

*/

/*####################
# Constructors that throw exceptions
####################*/

/*
- Constructor can also throw exceptions to report errors to the caller
    - This is useful, because constructors do not have a return value
    - This is one of the advantages that exceptions have over error codes

*/

#include <iostream>

using namespace std;

class StudentGrade{
    int grade;
public:
    StudentGrade(int grade) : grade{grade} {
        if(grade < 0 || grade > 100) {
            throw std::invalid_argument{"Invalid grade"};
        }
    }
};

int main() {
    int result;
    cout << "Please enter the student's grade (between 0 and 100): ";
    cin >> result;
    try {
        StudentGrade student{result};
    }
    catch (const std::exception &e) {
        cout << "Exception: " << e.what() << endl;
    }
}
