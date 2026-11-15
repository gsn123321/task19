#pragma once
struct Student {
    char name[100];
    int age;
};

class Group {
private:
    char groupName[100];
    Student* students;
    int count;

public:
    Group();
    ~Group();

    void setGroupName(const char name[]);
    const char* getGroupName();
    int getCount();

    void addStudent();
    void deleteStudent(int index);
    void showStudents();
};

