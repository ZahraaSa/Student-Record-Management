#include <iostream>
#include "StudentList.h"
#include "Student.h"

using namespace std;

bool StudentList::AddStudent(Student* student) {
    StudentNode* newNode = new StudentNode();
    newNode->student = student;
    newNode->Next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return true;
    } else {
        StudentNode* current = head;
        while (current->Next != nullptr) {
            current = current->Next;
        }
        current->Next = newNode;
        return true;
    }
}

void StudentList::DisplayStudents() {
    StudentNode* current = head;
    int index = 1;

    if (current == nullptr) {
        cout << "\n--- The Student Roster is Empty. ---" << endl;
        return;
    }

    cout << "               📝 Student Roster Overview" << endl;

    while (current != nullptr) {
        Student* studentData = current->student;

        if (studentData != nullptr) {
            cout << "Student " << index << " (ID: " << studentData->studentID << "):" << endl;
            cout << "  - Name: " << studentData->name << endl;
            cout << "  - Current GPA: " << studentData->currentGPA << endl;
            cout << "  - Completed Hours: " << studentData->completedCreditHours << " hours" << endl;
            cout << "  - Total Grades Count: " << studentData->getGradeCount() << endl;
        }

        current = current->Next;
        index++;
    }
    cout << "==========================================================" << endl;
}

void StudentList::sortByCompletedHoursDescending() {
    if (head == nullptr || head->Next == nullptr) return;

    bool swapped;
    do {
        swapped = false;
        StudentNode* prev = nullptr;
        StudentNode* curr = head;
        while (curr->Next != nullptr) {
            if (curr->student->completedCreditHours < curr->Next->student->completedCreditHours) {
                // Swap nodes
                if (prev == nullptr) {
                    head = curr->Next;
                    curr->Next = head->Next;
                    head->Next = curr;
                    prev = head;
                } else {
                    StudentNode* temp = curr->Next;
                    prev->Next = temp;
                    curr->Next = temp->Next;
                    temp->Next = curr;
                    prev = temp;
                }
                swapped = true;
            } else {
                prev = curr;
                curr = curr->Next;
            }
        }
    } while (swapped);
}

void StudentList::sortByGPADescending() {
    if (head == nullptr || head->Next == nullptr) return;

    bool swapped;
    do {
        swapped = false;
        StudentNode* prev = nullptr;
        StudentNode* curr = head;
        while (curr->Next != nullptr) {
            if (curr->student->currentGPA < curr->Next->student->currentGPA) {
                // Swap nodes
                if (prev == nullptr) {
                    head = curr->Next;
                    curr->Next = head->Next;
                    head->Next = curr;
                    prev = head;
                } else {
                    StudentNode* temp = curr->Next;
                    prev->Next = temp;
                    curr->Next = temp->Next;
                    temp->Next = curr;
                    prev = temp;
                }
                swapped = true;
            } else {
                prev = curr;
                curr = curr->Next;
            }
        }
    } while (swapped);
}

Student* StudentList::FindStudentByID(const string& id) {
    StudentNode* current = head;
    while (current != nullptr) {
        if (current->student->studentID == id) {
            return current->student;
        }
        current = current->Next;
    }
    return nullptr;
}

StudentList::~StudentList() {
    StudentNode* current = head;
    while (current != nullptr) {
        StudentNode* temp = current;
        current = current->Next;
        delete temp->student;
        delete temp;
    }
}