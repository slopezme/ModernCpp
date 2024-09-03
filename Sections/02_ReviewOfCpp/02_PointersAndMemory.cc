//A pointer can be in the stack or the heap

int main() {
int *p;             // Pointer in the stack
int *v1 = new int;  // Allocate memory in the heap

int i{1};          // Variable in the stack
int *v2 = &i;      // Pointer in the stack pointing to a variable in the stack

//Built -in type, the data will be left uninitialized
int *p2 = new int{36}; // pe points to int with initial value 36 (C++11)

/*Heap Allocated Memory
* Memory from the heap will remain allocated to the program until it is explicitly deallocated
- if the programmer does not explicity relear it, the memory will remain allocated
until the program terminates

*The operating system restrict the amount of memory that can be allocated to a program
- if the program uses too much memory, the operating system may refuse to allocate
more memory, causing the program to crash
*/

/*Memory Leak

Failing to release memory when it is no longer needed causes a "memory leak"
void badfunc(){
    int *p = new int;
    //...
    //forget to delete p
    return;
}
*/

// Releasing Memory

delete v1;  // delete operator releases memory allocated by new

// This will call the destructor of the object and release the memory

//Array Allocation
int *pa = new int[10]; // Allocate memory for 10 integers
for (int i = 0; i < 10; i++) {
    pa[i] = i;
}

//In this case, we have to use a specilized delete operator to release the memory

delete[] pa; // Release memory allocated for 10 integers

//If we use delete instead of delete[], the behavior is undefined





}
