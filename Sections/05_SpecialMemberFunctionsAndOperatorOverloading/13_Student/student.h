
#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
    std::string name;
    int id;
public:
    Student(const std::string& name, int id) : name{name}, id{id} {}
    friend bool operator ==(const Student& lhs, const Student& rhs);
    friend bool operator !=(const Student& lhs, const Student& rhs);
    friend bool operator <(const Student& lhs, const Student& rhs);
    void print();
};

#endif // STUDENT_H
