
//############
// open()
//############

/*
we bind a file when we pass its name to the stream constructor

ofstream ofile{"file.txt"};

- we can also bind it later by calling the open() member function

ofstream ofile;
...
ofile.open("file.txt");

In both cases, when ofstream bind the file
- the file mode will be applied
- if the output file doest not already exist, it will be created

*/


//############
// is open()
//############

// we can use is_open() to check if the file is open


//############
// stream State Member Functions
//############

/*
C++ streams have member functions to check the state of the stream

- good()   // Return true if the input was read successfully
- fail()   // Return true if there was a recoverable error
- bad()    // Return true if there was an unrecoverable error
- clear()  // Clear the error flags
- eof()    // Return true if the end of the file was reached
*/


//############
// Input Processing
//############

/*
When this statement, is executed

cin >> i;

The stream will go through the caracters int its input buffer and try to 
interpret them as an integer

It will abandon the operation when it realises this is imppossible
- this will leave some characters in the buffer, unprocessed
- the next time the program reads from cin, the stream doest not need to wait for user input,
as it already has some data to work on

- The solution is to force cin fo flush its buffer

*/

//############
// ignore
//############

/*
Input streams do not support flush
however, there is an ignore() member function which will remove characters from the buffer
It takes two arguments
- the maximum number of characters to remove
- a delimiter character. This will cause it to stop removing characters

the removed characters will be thrown away and cannot be used for anything else

cin.ignore(100, '\n'); // Remove up to 100 characters or until a newline is found

*/


