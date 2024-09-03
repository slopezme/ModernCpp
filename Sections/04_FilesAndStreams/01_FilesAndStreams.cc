

// Files in C++

/*
In C++, fil is represented by a sequence of bytes

Files and Streams


- File interactions are represented by fstream objects
- similar to iostream objects for console interactions

- fstream objects always access files "sequentially"

 A sequence of bytes
 in order
 of unknown length
 with no structure

 fstreams fo not understand file formats


*/

//############
// C++ fstream Operations
//############

/*
Open
- Connects the fstream object to a file
- the file becomes available for reading or writing

Read
- Data is copied from the file into the program memory

Write
- Data is copied from the program memory to the file

Close 
- Disconnects the fstream object from the file
- the file is no longer available for reading or writing
*/

//############
// Openining and closing a file
//############


/*
The file must be openend before we can use it
The file should be closed after use
- Ensures that any outsatnding data is written to the file
- Avoids the possibility of a "too many open files" error

When a C++ program ends, all open files are closed automatically

- However, it is good practice to close files explicitly

*/

//############
// Reading and writing files
//############

/*
As data passes between the rpogramn and the file, it may be temporarily stored in a memory buffer

- this makes large data transfers more efficient, but less timely

*/


