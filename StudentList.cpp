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
                StudentNode* current = head;
                while (current->Next != NULL) {
                    current = current->Next;
                }
                current->Next = newNode;
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
                
                
                cout << "  - Current GPA: " << studentData->currentGPA << std::endl;
                cout << "  - Completed Hours: " << studentData->completedCreditHours << " hours" << std::endl;
                cout << "  - Total Grades Count: " << studentData->getGradeCount() << std::endl;
            }

            current = current->Next;
            index++;
        }
        std::cout << "==========================================================" << std::endl;
    }

    void StudentList::sortbycompleted_hours (){
    if (head == nullptr || head->Next == nullptr) {
            return;
        }

        StudentNode* current=head;
        StudentNode* prevCurrent = nullptr;
        int min_hours=current->student->completedCreditHours;
      
    while (current!=nullptr){
        StudentNode* minNode = current;
        StudentNode* minPrev = prevCurrent; 
        StudentNode* temp = current;
        StudentNode* ptr = current->Next;
        StudentNode* ptrPrev = current;
        temp=current;
            min_hours=current->student->completedCreditHours;
    while (ptr!=nullptr){
    if (ptr->student->completedCreditHours<min_hours){
        min_hours=ptr->student->completedCreditHours;
        minNode=ptr;
        minPrev=ptrPrev;
    }
    if (ptr->Next!=nullptr){
    ptrPrev=ptr;
    ptr=ptr->Next;
    }}
   
     if (current!=minNode){

     if (prevCurrent==nullptr){
        temp->Next=minNode->Next;
        minPrev->Next=temp;
        minNode->Next=current->Next;
        head=minNode;
     }
     else {
     minNode->Next=current->Next;
     prevCurrent=minNode;
     temp=minNode->Next;
     minPrev->Next=temp; 
     }}
     else continue;
    prevCurrent=current;
    current=current->Next;
}}