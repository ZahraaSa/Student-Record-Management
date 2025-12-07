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
    
    double getGradePoint(int numericGrade); 
    bool checkGrade(int grade);
    
    Student(){
        name = "";
        studentID = "";
        currentGPA = 0.0;
        completedCreditHours = 0;
        gradesHead = nullptr;
    } 
    Student(string name, string studentID) {
         if (studentID.empty() || name.empty()) {
        cout << "Error: Name or ID cannot be empty." << endl;
        return;
    }
       this->name = name;
       this->studentID = studentID;
        currentGPA = 0.0;
        completedCreditHours = 0;
        gradesHead = nullptr;
    }

    void calculateGPA(); 
    bool addGrade(int value); 
    bool RemoveGrade(int ind); 
    bool EditGrade(int index, double ngrade);
    void DisplayGrades(string studentID) ;
    double getCurrentGPA();
    int getCompletedHours();
    int getGradeCount();
}; 
#endif 