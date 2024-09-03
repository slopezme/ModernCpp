
//############
// File Modes
//############

/*
C++ gives us a number of options for opening files. These are called "modes"

- we can pass the file mode as an optional second argument when opening the file

- by default, files are opened in "text mode"
    - If we write 42 to a file, it will be stored as the ASCII characters '4' and '2'
    - There are the binary numbers 110100 and 110010

- By default, output files are opened in "truncate mode"
    - Any data that was previously in the file will be overwritten
    - New data will be written from the beginning of the file


*/


//############
// Appending to Files
//############

/*
- To open an ofstream in append mode, we pass fstream::app as the second argument

ofile.open("file.txt", fstream::app);

when we write to the file, its current data will not be overwritten

Our data will be added after the data that was already in the file

ofile << "some more data";

*/

#include <iostream>
#include <fstream>

using namespace std;

int main(){

    ofstream ofile{"file.txt", fstream::app};

    if (ofile){
        ofile << "some more data" << endl;
    }

}

//############
// Binary Mode
//############

/*
In binary mode, the data stored in the file will be identical to the data in memory

- e.g. the numnber 42 will be stored as the binary number 00101010
- In text mode, it would be stored as two binary numbers
    - 00110100 and 00110010

Binary mode is complicated, low level and error prone. It can also cause protability issues
- it should be avoided unless absolutely necessary

*/

//############
// Other Modes
//############

/*
trunc
- Open the file in truncate mode

in
- Open the file for input

out
- Open the file for output
- Also in truncate mode, even if trunc is not specified

ate
- similar to append, but output can be wirtten anywhere in the file

*/

//############
// Combining Modes
//############

/*
We can combine modes by using a vertical bar (|) to separate them

fstrean file;
file.open("file.txt", fstream::out | fstream::app);  // open for output and append

if we combine in and out, we can read from and write to the file

file.open("file.txt", fstream::in | fstream::out);

- In this case, the file will not be truncated
- unless we specify trunc

file.open("file.txt", fstream::in | fstream::out | fstream::trunc);

*/

//############
// File Mode Restrinctions
//############

/*
out
- fstream and ofstream only

in
- fstream and ifstream only

trunc
- Only in output mode

app
- Cannot combine with trunc
- the file always be opened in output mode

*/
