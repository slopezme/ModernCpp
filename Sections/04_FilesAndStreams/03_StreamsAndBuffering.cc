
//############
// C++ Streams and Output Buffering
//############

/*
C++ Streams use "Buffering" to minimize the number of system calls
- During write operations, data is temporarily stored in a buffer
- The size of this buffer is chosen to match the maximum amount of data
    that  the operating system can write in a single operation

- When the buffer is full, the stream will remove the data from the buffer and 
send it to the operating system

- This is known as "flushing" the output buffer
*/

//############
// When are Streams Buffers Flushed?
//############

/*
- For ostream, it depends on the terminal configuration
    - usually this is at the end of every line
    - cout is always flushed before the program reads from cin

- ofstream is only flushed when the buffer is full
- There is no direct way to flush the input streams
*/

//############
// std::flush
//############

/*
std::flush allows us to control when the streams buffer is flushed

- All the data in the buffer is immediately sent to its destination

cout << i << flush;  // i will appear immediately on the screen

this significantly affects the performance of the program

- It should only be used if the data reallly needs to be up to date


*/

#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ofstream ofile{"file.txt"};     // Define ofile and ofstream object

    if (ofile){
        ofile << "Hello, World!" << endl;       // Write to file
        return -1;
    }   

    for (int i = 0; i < 10'000'000; i++){
        cout << i << "\n" << flush;
        ofile << i << "\n" << flush;

        if (i == 66666){
            ofile << flush;
        }
    }
    ofile.close();              // Close file
    return 0;
}
