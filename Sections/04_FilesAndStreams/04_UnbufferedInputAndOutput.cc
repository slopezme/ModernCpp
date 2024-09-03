//############
// Unbuffered Input and Output
//############

/*
There are some applications where stream buffering is not suitable
- for example, network applications

- Data must be transmitted in "packets" of a specific size
- Data may need to be transmitted at specific times

C++ supports lower level operations on streams
- These bypass the streams buffer
- no formatting of data

These are mainly used when the programmer needs more control over how the data is trasmitted
- network applications
- communication directly with hardware


Streams have a member function for reading or writing data, one character at a time
- get() fetches the next character from an input stream
- put() writes a character to an output stream

These both take a char argument

char c 
while(cin.get(c)){
    cout.put(c);
}
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    cout << "Enter some text: " << endl;

    char c;
    while(cin.get(c)){
        cout.put(c);
    }
}

//############
// input and Output of blocks of characters
//############

/*
For reading and writing many characters, there are the read() and write() functions

As we are not using buffer managed by the stream, we have to provide our own buffer
- for write(), our buffer will contain all the data we want to send

- For read(), the buffer must be large enough to store all the data we expect to receive


*/

//############
// read() and write()
//############

/*
Both these member functions take two arguyments

- The address of the buffer
- the number of characters in the buffer

const int filesize{10};
char filebuf[filesize];
...
ifile.read(filebuf, filesize);
cout.write(filebuf, filesize);

*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){


    const int filesize{10};
    char filebuf[filesize];
    string filename{"file.txt"};

    ifstream ifile{filename};

    if (!ifile){
        std::cout << " Could not open file: " << filename << endl;
        return -1;
    }

    ifile.read(filebuf, filesize);
    ifile.close();

    std::cout << "File Data:" ;
    std::cout.write(filebuf, filesize);
    std::cout << endl;

}   

//############
// gcount()
//############

/*
Often, we need to know how much data an input stream has sent us
- we may need to allocate memory to process the data
- to detect partial or incomplete transfers

The gcount() member function returns the number of characters that wre actually received

auto nread = ifile.gcount();   // how many bytes did we receive?

*/



