// You are given the attached languages.txt file and the following type definition:

// struct language {
//     string lang;
//     string designer;
//     int date;
// };
// The format of the languages.txt file is:

// C++ Stroustrup 1979
// Java Gosling 1991
// Write a program which will:

// Read in the data from the attached languages.txt file

// Use each line of input to populate a language object

// Add this object to a vector

// Print out all the data in the vector, separated by commas

// Your output should look like this:

// C++, Stroustrup, 1979
// Java, Gosling, 1991


// Questions for this assignment
// Implement the program as described. If you need help, click on the Instructor Example to get some hints.

// Part 2
// The file format has changed from the program in the first part of this workshop. It now looks like this:

// C Kernighan & Ritchie 1970
// C++ Stroustrup 1979
// Java Gosling 1991
// C# Hejlsberg 1999
// Python van Rossum 1991
// Modify your program so that it handles the attached languages2.txt correctly

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

struct language {
    string lang;
    string designer;
    int date;
};

void part1(string filename){
    ifstream ifile{filename};
    vector<language> languages;

    if (ifile){
        string line;
        while (getline(ifile, line)){
            istringstream is{line};
            language lang;
            is >> lang.lang >> lang.designer >> lang.date;
            languages.push_back(lang);
        }
    }

    for (const auto &lang : languages){
        cout << lang.lang << ", " << lang.designer << ", " << lang.date << endl;
    }
}


void part2(string filename) {
    ifstream ifile{filename};
    vector<language> languages;

    if (ifile) {
        string line;
        while (getline(ifile, line)) {
            size_t lastSpace = line.find_last_of(' ');
            int date = stoi(line.substr(lastSpace + 1));
            line = line.substr(0, lastSpace); // Remove the date part

            size_t firstSpace = line.find(' ');
            string lang = line.substr(0, firstSpace);
            string designer = line.substr(firstSpace + 1);

            languages.push_back({lang, designer, date});
        }
    }

    // Print the languages to verify the parsing
    for (const auto &lang : languages) {
        cout << lang.lang << ", " << lang.designer << ", " << lang.date << endl;
    }
}



int main(){

    cout << " Part1: \n" << endl;
    part1("languages.txt");
    cout << "Finished" << endl;

    
    cout << " Part2: \n" << endl;
    part2("languages2.txt");


 
    return 0;
}