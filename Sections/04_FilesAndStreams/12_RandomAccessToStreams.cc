
//############
// Stream Position Marker
//############

/*
C++ Streams have a position marker
This keeps track of where the next read or write operation will be performed
Normally the stream controls the markers position 
- At the end of the stream, for write operations
- Just after the last read, for read operations

However, in some cases, the programmer can alter its position
- fstream not openened in "app" mode
- stringstream

This allos us to read or write data anywhere in the stream
*/

//############
// Seek and tell operations
//############

/*
C++ Provides  "seek" member functions which change the position of the marker
- seekg gets the current position in an input stream
- seekp sets the current position in an output stream

- There are also "tell" member functions which return the current position

- tellg returns the current position in an input stream
- tellp returns the current position in an output stream
*/

//############
// Supported seek and tell operations
//############

/*
Seek and tell operations are only defined for the appropriate streams
- seekg and tellg are only defined for input streams ("get operations")
- seekp and tellp are only defined for output streams ("put operations")

They are defined for iostreams, but cannot do anything useful
- they will cause a runtime error if called
- the stream will be put into an invalid state

For an fstream which was openend in "app" mode, seekp will not work
- the output is always written at the end of the file

*/

//############
// tellg and tellp
//############

/*
- Thell operations return a pos_type object
-  this represents a position in the stream
- it can be converted to int
- the operation can fail, if the stream is in an invalid state
- in this case, the return value will be equal to -1

auto pos = ifile.tellg();
if (pos != -1){
    ...     // The position marker is valid
}
*/

//############
// seekg and seekp
//############

/*
Seek operations can take a pos_type object as an argument
seekp(pos); // use the return value from tellp

This will move the marker to an absolute position in the stream
They can also move the marker to a position which is relative to a base position

std::ios_base provides three base positions

- beg - the beginning of the stream
- end - the end of the stream
- cur - the current marker position

seekp(-10, std::ios_base::end); // move the marker 10 bytes before the end of the stream
*/

//############
// Stringstream example
//############

/*
Tell operations are useful for saving the current marker position, so we can retrieve it later

ostringstream output;           // open output string stream
...                             // Do something
auto marker = ofile.tellp();    // save the current position
...                             // Erite some data in the stream
if (cancel){                    // If we need to go back
    ofile.seekp(marker);        // Move the marker back
}
...

*/



