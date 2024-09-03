

//############
//  Stream Types
//############

/*
Iostream
-ostream(cout)
-istream(cin)

fstream
- ofstream (file stream for writing)
- ifstream (file stream for reading)

As there are many different files on a computer, we need to associat 
each file with a stream object


*/

//############
//  How to Open a File for Reading
//############

/*
The easist way to opne a file is to pass its name to the ifstream constructor

This will create a stream object will open the file for input

ifstream ifile{"file.txt"};

this represents a "  communication channel" between the program and the file

We should check the streams state before using it

if (!ifile){
    cout << "Error opening file" << endl;
}

*/

//############
//  fstream constructor
//############

/*
in C++11
string str{"file.txt"};
fstream file{str};    

we can use ifile the same way as cin

while(ifile >> word){
    cout << word << endl;
}

this will read one word at a time and remove all whitespace from the input

- this may not be waht is requiered
- if the file has an internal structure, the code can be difficult to get right
- Diffictul to handle errors it the file strcuture doest not exactly match the code
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main1(){

    ifstream ifile{"file.txt"};     // Define ifile and ifstream object

    if (ifile){
        string test{""};
        while(ifile >> test){       // Read from file
            cout << test << endl;
        }

        cout << endl;
        ifile.close();              // Close file
    }   

}

//############
//  Reading from a file Contd
//############

/*
- Often it is easier to read a complete line from a file
- The getline() function reads a line of text from a file
- The input will be in an std::string argument

while(getline(ifile, line)){
    cout << line << endl;
}  

- The string object will contain the entire line of input
    - Except for the newline character

- The program can the validate the data in this variable and process it as required

- getline() will return false at the end of the file

*/

int main2(){

    ifstream ifile{"file.txt"};     // Define ifile and ifstream object

    if (ifile){
        string test{""};
        while(getline(ifile, test)){       // Read from file
            cout << test << endl;
        }

        cout << endl;
        ifile.close();              // Close file
    }   

}

//############
//  how to Open a File for Writing
//############

/*
- Create a stream object which will open the file

ofstream ofile{"file.txt"};

- this represents a "communication channel" between the program and the file
- we should check the stream state before using it

if (!ofile){
    cout << "Error opening file" << endl;
}

we can use ofile the same way as cout

vector<string> words{"one", "two", "three"};

for (const auto& word : words){
    ofile << word << endl;
}

*/

#include <vector>

void main3(){

    ofstream ofile{"file.txt"};     // Define ofile and ofstream object

    if (ofile){
        vector<string> words{"one", "two", "three"};

        for (const auto& word : words){
            ofile << word << endl;
        }

        ofile.close();              // Close file
    }  

}

//############
//  Fstream destructor
//############

/*
- when fstream destructor is called, the file is closed
- The will cause any unsaved data to be written to the file
- if an fstream object goest out of scope after we have finished with it, we do not need to 
explicitly close the file 
- However, it is good practice to close files explicitly


*/