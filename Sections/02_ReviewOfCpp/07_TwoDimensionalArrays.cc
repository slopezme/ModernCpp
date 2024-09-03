// Two dimensional arrays

#include <iostream>
#include <iomanip>

void main(){

std::string names[2][5];

// A two dimensional array is stores as single memory block
// The elements are stored in row-major order
// The first index is the row number and the second index is the column number

// we can intialize this like a single array

std::string names[2][4] = {
    "John", "Doe", "Jane", "Smith","Alice", "Brown", "Bob", "White"
};

// it is cleader to initialize it like it as two nested arrays

std::string names[2][4] = {
    {"John", "Doe", "Jane", "Smith"},
    {"Alice", "Brown", "Bob", "White"}
};

// We can use suscript notation to access individual elements
// names[1]; // Returns the second row

// names[1][2]; // Returns the third element of the second row (Jane)

// to iterate over a two dimensional array we can use nested loops

for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 4; j++) {
        std::cout << names[i][j] << " ";
    }
    std::cout << std::endl;
}

// Flattened two dimensional array

// names[m*numcols + n];  //equivalent to names[m][n]

//* This is useful if performance is more important than ease of notation */
for (int row = 0; row < 2; row++) {
    for (int col = 0; col < 4; col++) {
        std::cout << names[row * 4 + col] << " ";
    }
    std::cout << std::endl;
}

}

