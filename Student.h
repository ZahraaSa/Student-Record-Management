#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "gradeNode.h"

using namespace std;

class Student {
public:
    string name;
    string studentID;
    double currentGPA;
    int completedCreditHours;
    GradeNode* gradesHead;

    Student() {
        name = "";
        studentID = "";
        currentGPA = 0.0;
        completedCreditHours = 0;
        gradesHead = nullptr;
    }

    Student(string name, string studentID) {
        this->name = name;
        this->studentID = studentID;
        currentGPA = 0.0;
        completedCreditHours = 0;
        gradesHead = nullptr;
    }

    ~Student();

    double getGradePoint(int numericGrade);
    void calculateGPA();
    bool addGrade(int value);
    bool RemoveGrade(int ind);
    bool EditGrade(int index, int ngrade);
    void DisplayGrades();
    int getGradeCount();
};
#endif