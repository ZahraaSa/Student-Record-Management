#ifndef STUDENTLIST_H   
#define STUDENTLIST_H 
#include <iostream>
#include "Student.h"

class StudentNode{
    public:
    Student* student;
    StudentNode* Next;
};

class StudentList{
public:
StudentNode* head;
StudentList(){
    head=nullptr;
}

//  StudentNode* newNode = new StudentNode();
// StudentList(Student* student){
//     newNode->student=student;
//     newNode->Next=nullptr;
// }

bool AddStudent(Student* student);
void DisplayStudent() ;
void sortbycompleted_hours ();
void sortbyGPA ();
void DisplayGrade();

};
#endif