//Integers
//remineder 8 bits = 1 byte

/*
char        - 8 bits 
int         - at least 16 bits
long        - at least 32 bits
long long   - new in C++11 - at least 64 bits
*/

// Introduced in C++11 in <cstdint>

/*
int8_t      - 8 bits
int16_t     - 16 bits
int32_t     - 32 bits
int64_t     - 64 bits

Unsigned versions
uint8_t     - 8 bits
uint16_t    - 16 bits
uint32_t    - 32 bits
uint64_t    - 64 bits
*/

//Floating points types

/*
float       - ususallly 6 digits precision
double      - usually 15 digits precision
long double - usually 20 digits precision
*/

// we can use ' in numeric literlas to separate digits C++14
const int one_million = 1'000'000; // cout will show 1000000
double pi = 3.141'592'653'589'793; // cout will show 3.14159...

//this can go anywhere inside the number (but not at the start or end)
const int one_lakh = 10'0'00;  // cout will show 10000

//Default types

/*
floating - point literals are double by default
3.14159 // literal has type double

integers literals are int by default
- if too big for int, they are long
- if too big for long, they are long long

we can add a suffix to change the type of a literal

- 3.14159f      //Literal has type float
12345678990ULL  // Literal has type unsigned long long

*/

