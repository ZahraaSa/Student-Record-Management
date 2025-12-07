#include<iostream>
#include "StudentList.h"
#include"Student.h"
bool StudentList::AddStudent(Student* student){

    StudentNode* newNode = new StudentNode();
       newNode->student=student;
        if (head == NULL) {
            head = newNode;
            return true;
        }

        else {
            StudentNode* temp = head;
            while (temp->Next != NULL) {
                temp = temp->Next;
            }
            temp->Next = newNode;
            return true;
        }
}
void StudentList::DisplayStudent() {
    StudentNode* current = head;
    int index = 1;

    if (current == nullptr) {
        std::cout << "\n--- The Student Roster is Empty. ---" << endl;
        return;
    }

    cout << "               📝 Student Roster Overview" << endl;

    while (current != nullptr) {
        Student* studentData = current->student;
        
        if (studentData != nullptr) {
            cout << "\nStudent " << index << " ID: " << studentData->studentID << "):" << endl;
            cout << "  - Name: " << studentData->name << endl; 
            
            
             cout << "  - Current GPA: " << studentData->getCurrentGPA() << std::endl;
             cout << "  - Completed Hours: " << studentData->getCompletedHours() << " hours" << std::endl;
             cout << "  - Total Grades Count: " << studentData->getGradeCount() << std::endl;
        }

        current = current->Next;
        index++;
    }
    std::cout << "==========================================================" << std::endl;
}
