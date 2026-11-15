#include "G.h"
#include <iostream>
#include <cstring>

Group::Group() {
    strcpy_s(groupName, 100, "");
    students = nullptr;
    count = 0;
}

Group::~Group() {
    delete[] students;
}

void Group::setGroupName(const char name[]) {
    strcpy_s(groupName, 100, name);
}

const char* Group::getGroupName() {
    return groupName;
}

int Group::getCount() {
    return count;
}

void Group::addStudent() {
    Student student;

    std::cout << "Enter student name: ";
    std::cin.getline(student.name, 100);

    std::cout << "Enter student age: ";
    std::cin >> student.age;
    std::cin.ignore(1000, '\n');

    Student* temp = new Student[count + 1];

    for (int i = 0; i < count; ++i) {
        strcpy_s(temp[i].name, 100, students[i].name);
        temp[i].age = students[i].age;
    }

    strcpy_s(temp[count].name, 100, student.name);
    temp[count].age = student.age;

    delete[] students;

    students = temp;
    ++count;

    std::cout << "Student added\n";
}

void Group::deleteStudent(int index) {
    if (index < 0 || index >= count) {
        std::cout << "Wrong student number\n";
        return;
    }

    Student* temp = nullptr;

    if (count > 1) {
        temp = new Student[count - 1];

        int j = 0;

        for (int i = 0; i < count; ++i) {
            if (i != index) {
                strcpy_s(temp[j].name, 100, students[i].name);
                temp[j].age = students[i].age;
                ++j;
            }
        }
    }

    delete[] students;

    students = temp;
    --count;

    std::cout << "Student deleted\n";
}

void Group::showStudents() {
    std::cout << "\nGroup: " << groupName << "\n";

    if (count == 0) {
        std::cout << "No students\n";
        return;
    }

    for (int i = 0; i < count; ++i) {
        std::cout << "\nStudent " << i + 1 << "\n";
        std::cout << "Name: " << students[i].name << "\n";
        std::cout << "Age: " << students[i].age << "\n";
    }
}