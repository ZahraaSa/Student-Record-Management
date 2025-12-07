#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string> 
#include "gradeNode.h" 
using namespace std;

class Student {
private:
    string name;
    string studentID; 
    double currentGPA;
    int completedCreditHours;
    GradeNode* gradesHead; 
    
    double getGradePoint(int numericGrade); 
    bool checkGrade(int grade);

public:
    
    Student(){
        name = "";
        studentID = "";
        currentGPA = 0.0;
        completedCreditHours = 0;
        gradesHead = nullptr;
    } 
    Student(string n, string id) {
        name = n;
        studentID = id;
        currentGPA = 0.0;
        completedCreditHours = 0;
        gradesHead = nullptr;
    }
    void calculateGPA(); 
    bool addGrade(int value); 
    bool RemoveGrade(int ind); 
    bool EditGrade(int index, double ngrade);
    void DisplayGrades(string studentID) ;
}; 
#endif 