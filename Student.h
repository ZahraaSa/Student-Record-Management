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

public:
    
    Student(string n, string id); 
    
    void calculateGPA(); 
    
    bool addGrade(string course, int value); 
    bool RemoveGrade(string courseName); 
    bool editGrade(string courseName, int value); 

}; 

#endif 