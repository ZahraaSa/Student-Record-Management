#ifndef STUDENTLIST_H   
#define STUDENTLIST_H 
#include <iostream>
#include "Student.h"

class StudentNode{
    public:
    Student* student=new Student();
    StudentNode* Next;

};

class StudentList{
public:
StudentNode* head;
StudentList(){
    head=nullptr;
}

void AddStudent();
void DisplayStudent() ;
void sortbycompleted_hours ();
void sortbyGPA ();
void DisplayGrade();

};
#endif