#include <iostream>
#include <memory>
#include <algorithm>



// Function using pointer (copy of a pointer)
void operation1(int *&a) {
    a = new int[2];
    a[0] = 1;
    a[1] = 2;
}

// Function using pointer to a pointer
void operation2(int **a) {
    *a = new int[2];
    (*a)[0] = 10;
    (*a)[1] = 20;
}

// Function using reference to a pointer
void operation3(int *&a) {
    a = new int[2];
    a[0] = 1;
    a[1] = 2;
}

// Function using unique_ptr (copy of a pointer)
void operation4(std::unique_ptr<int[]> a) {
    a = std::make_unique<int[]>(2);
    a[0] = 1;
    a[1] = 2;
}

// Function using unique_ptr (pointer to a pointer)
void operation5(std::unique_ptr<int[]> *a) {
    *a = std::make_unique<int[]>(2);
    (*a)[0] = 10;
    (*a)[1] = 20;
}

// Function using unique_ptr (reference to a pointer)
void operation6(std::unique_ptr<int[]> &a) {
    a = std::make_unique<int[]>(2);
    a[0] = 1;
    a[1] = 2;
}

// Function using shared_ptr (copy of a pointer)
void operation7(std::shared_ptr<int[]> a) {
    a = std::make_shared<int[]>(2);
    a[0] = 1;
    a[1] = 2;
}

// Function using shared_ptr (pointer to a pointer)
void operation8(std::shared_ptr<int[]> *a) {
    *a = std::make_shared<int[]>(2);
    (*a)[0] = 10;
    (*a)[1] = 20;
}

// Function using shared_ptr (reference to a pointer)
void operation9(std::shared_ptr<int[]> &a) {
    a = std::make_shared<int[]>(2);
    a[0] = 1;
    a[1] = 2;
}

int main() {
    // Example usage for each function
    int *b = nullptr;
    operation1(b);
    delete[] b;

    int *c = nullptr;
    operation2(&c);
    delete[] c;

    int *d = nullptr;
    operation3(d);
    delete[] d;

    std::unique_ptr<int[]> e;
    operation4(std::move(e));

    std::unique_ptr<int[]> f;
    operation5(&f);

    std::unique_ptr<int[]> g;
    operation6(g);

    std::shared_ptr<int[]> h = std::make_shared<int[]>(2);
    operation7(h);

    std::shared_ptr<int[]> i = std::make_shared<int[]>(2);
    operation8(&i);

    std::shared_ptr<int[]> j = std::make_shared<int[]>(2);
    operation9(j);

    return 0;
}
