
#include <iostream>

#include "student.h"

using namespace std;

bool operator == (const Student& lhs, const Student& rhs) {
    if (lhs.id == rhs.id) {
        return true;
    }
    return false;
}

bool operator != (const Student& lhs, const Student& rhs) {
    return !(lhs == rhs);
}

bool operator < (const Student& lhs, const Student& rhs) {
    return lhs.name < rhs.name;    // Order by name (alphabetical sort)
}

void Student::print() {
    cout << "Student " << name << " has id: " << id << endl;
}