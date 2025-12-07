#include<iostream>
#include "Student.h"

double Student::getGradePoint(int numericGrade) {
        if (numericGrade >= 90) return 4.0;
   else if (numericGrade >= 85) return 3.5;
   else if (numericGrade >= 80) return 3.0;
   else if (numericGrade >= 75) return 2.5;
   else if (numericGrade >= 70) return 2.0;
   else if (numericGrade >= 65) return 1.5;
   else if (numericGrade >= 60) return 1.0;
   else if (numericGrade >= 50) return 0.5;
    return 0.0;
}
void Student::calculateGPA() {
    double totalPoints = 0.0;
    int totalHours = 0;
    
    GradeNode* current = gradesHead;
    
    while (current != nullptr) {
        int grade = current->numericGrade;
        double points = getGradePoint(grade);
        
        // 1. تجميع النقاط الكلية (Points)
        totalPoints += points * 3; // كل مقرر 3 ساعات
        
        // 2. تجميع الساعات المكتملة (Completed Hours)
        if (grade >= 50) {
            totalHours += 3; // تُحسب الساعات للدرجات >= 50
        }
        
        current = current->next;
    }

    completedCreditHours = totalHours;
    
    if (totalHours > 0) {
        currentGPA = totalPoints / (double)totalHours;
        // حطيت double مشان يطلع الجواب عشري
        // لان اذا التنين رح يكونوا int ما رح يطلع فواصل بالجواب . 
    } else {
        currentGPA = 0.0;
    }}
    bool Student::addGrade(string courseName,int value){
          
    }

