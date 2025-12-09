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
                
                cout << "Student " << index << " ID: " << studentData->studentID << "):" << endl;
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

void StudentList::sortbycompleted_hours() {

    if (head == nullptr || head->Next == nullptr)
        return;

    StudentNode* current = head;
    StudentNode* prevCurrent = nullptr;

    while (current != nullptr) {

        StudentNode* minNode = current;
        StudentNode* minPrev = prevCurrent;

        StudentNode* ptrPrev = current;
        StudentNode* ptr = current->Next;

        while (ptr != nullptr) {
            if (ptr->student->completedCreditHours < minNode->student->completedCreditHours) {
                minNode = ptr;
                minPrev = ptrPrev;
            }
            ptrPrev = ptr;
            ptr = ptr->Next;
        }


        // إذا minNode not current -> بدنا نبدل
        if (minNode != current) {

//head -> current
            if (prevCurrent == nullptr) {

                StudentNode* temp = minNode->Next;

                minPrev->Next = current;
                minNode->Next = current->Next;
                current->Next = temp;
                head = minNode;
 //.zahraa.
                prevCurrent = minNode;
                current = minNode->Next;
            }

            else {

                StudentNode* temp = minNode->Next;

                prevCurrent->Next = minNode;
                minPrev->Next = current;

                minNode->Next = current->Next;
                current->Next = temp;

                prevCurrent = minNode;
                current = minNode->Next;
            }
        }

        else {
            prevCurrent = current;
            current = current->Next;
        }
    }
}
void StudentList::sortbyGPA() {

    if (head == nullptr || head->Next == nullptr)
        return;

    StudentNode* current = head;
    StudentNode* prevCurrent = nullptr;

    while (current != nullptr) {

        StudentNode* minNode = current;
        StudentNode* minPrev = prevCurrent;

        StudentNode* ptrPrev = current;
        StudentNode* ptr = current->Next;

        while (ptr != nullptr) {
            if (ptr->student->currentGPA < minNode->student->currentGPA) {
                minNode = ptr;
                minPrev = ptrPrev;
            }
            ptrPrev = ptr;
            ptr = ptr->Next;
        }


        // إذا minNode not current -> بدنا نبدل
        if (minNode != current) {

//head -> current
            if (prevCurrent == nullptr) {

                StudentNode* temp = minNode->Next;

                minPrev->Next = current;
                minNode->Next = current->Next;
                current->Next = temp;
                head = minNode;
 //.zahraa.
                prevCurrent = minNode;
                current = minNode->Next;
            }

            else {

                StudentNode* temp = minNode->Next;

                prevCurrent->Next = minNode;
                minPrev->Next = current;

                minNode->Next = current->Next;
                current->Next = temp;

                prevCurrent = minNode;
                current = minNode->Next;
            }
        }

        else {
            prevCurrent = current;
            current = current->Next;
        }
    }
}
