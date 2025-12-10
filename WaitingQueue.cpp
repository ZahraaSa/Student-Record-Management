#include <iostream>
#include "WaitingQueue.h"
#include "StudentList.h"

using namespace std;

void WaitingQueue::enqueueStudent(Student* student) {
    WaitingQueueNode* newnode = new WaitingQueueNode();
    newnode->student = student;
    newnode->next = nullptr;
    if (rear == nullptr) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
    size++;
}

Student* WaitingQueue::dequeueStudent() {
    if (front == nullptr) {
        return nullptr;
    }
    WaitingQueueNode* temp = front;
    Student* student = front->student;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
    size--;
    return student;
}

bool WaitingQueue::isEmpty() {
    return front == nullptr;
}

void WaitingQueue::displayQueue() {
    WaitingQueueNode* temp = front;
    if (temp == nullptr) {
        cout << "Queue is empty" << endl;
        return;
    }
    while (temp != nullptr) {
        cout << "Student name: " << temp->student->name << " ID: " << temp->student->studentID << endl;
        temp = temp->next;
    }
}

void WaitingQueue::processQueue(StudentList& roster) {
    int transferred = 0;
    while (!isEmpty()) {
        Student* student = dequeueStudent();
        bool isDuplicate = false;

        Student* existing = roster.FindStudentByID(student->studentID);
        if (existing != nullptr) {
            isDuplicate = true;
        }

        if (!isDuplicate) {
            roster.AddStudent(student);
            transferred++;
        } else {
            cout << "Warning: Duplicate ID (" << student->studentID << ") for student: " << student->name << ". Student rejected." << endl;
            delete student;
        }
    }
    cout << transferred << " students were transferred from the waiting queue to the roster." << endl;
}

WaitingQueue::~WaitingQueue() {
    while (!isEmpty()) {
        Student* student = dequeueStudent();
        delete student;
    }
}