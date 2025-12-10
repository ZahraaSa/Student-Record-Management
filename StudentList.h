#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include <iostream>
#include "Student.h"

using namespace std;

class StudentNode {
public:
    Student* student;
    StudentNode* Next;
};

class StudentList {
public:
    StudentNode* head;

    StudentList() {
        head = nullptr;
    }

    ~StudentList();

    bool AddStudent(Student* student);
    void DisplayStudents();
    void sortByCompletedHoursDescending();
    void sortByGPADescending();
    Student* FindStudentByID(const string& id);
};
#endif