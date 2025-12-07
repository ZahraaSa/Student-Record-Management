#include<iostream>
#include "Student.h"

bool checkGrade(int grade){
return grade>=0 && grade <=100 ;}

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
        
        //  تجميع النقاط الكلية (Points)
        totalPoints += points * 3; 
        
        //  تجميع الساعات المكتملة (Completed Hours)
        if (grade >= 50) {
            totalHours += 3;
             // تُحسب الساعات للدرجات >= 50
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

    bool Student::addGrade(int grade)
    {
       if(checkGrade(grade)){
        GradeNode* newNode;
        newNode = new GradeNode;
        newNode->numericGrade = grade;
        newNode->next = nullptr;
        if (gradesHead == NULL) {
            gradesHead = newNode;
           
             calculateGPA();
            return true;
        }

        else {
            GradeNode* temp = gradesHead;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
             calculateGPA();
            return true;
        }}
        return false;

    }    

      bool Student::RemoveGrade(int ind){
        GradeNode* prevNode = NULL;
        GradeNode* currentNode = gradesHead;
        int idx=0;
        
        while (currentNode != NULL && idx!=ind) {
            prevNode = currentNode;
            currentNode = currentNode->next;
            idx++;
        }
        if (currentNode) {
            if (prevNode) {
                prevNode->next = currentNode->next;
                delete currentNode;
                calculateGPA();
                return true;
            }
            else {
                
                gradesHead = currentNode->next;
                delete currentNode;
                calculateGPA();
                return true;
            }
        }
    }
      
     bool Student::EditGrade(int index, double ngrade) {
     if (  checkGrade(ngrade) ){
        if (index < 0) {
            cout << "Index cannot be negative" << endl;
            return false;
        }

        if (index >= 0 && gradesHead == nullptr) {
            cout << "There is no grades to edit" << endl;
            return false;
        }

        GradeNode* temp = gradesHead;
        int currIndex = 0;
        while (temp != NULL && currIndex < index) {
            temp = temp->next;
            currIndex++;
        }
        if (temp == NULL) {
            return false;
        }
        temp-> numericGrade = ngrade;
        calculateGPA();
        return true;
    }
    return false;
    }



