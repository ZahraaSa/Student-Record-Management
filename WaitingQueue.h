#ifndef WAITINGQUEUE_H
#define WAITINGQUEUE_H

#include <iostream>
#include "Student.h"
#include "StudentList.h"

using namespace std;

class WaitingQueueNode {
public:
    Student* student;
    WaitingQueueNode* next;
};

class WaitingQueue {
public:
    WaitingQueueNode* front;
    WaitingQueueNode* rear;
    int size;

    WaitingQueue() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    ~WaitingQueue();

    void enqueueStudent(Student* student);
    Student* dequeueStudent();
    bool isEmpty();
    void displayQueue();
    void processQueue(StudentList& roster);
};

#endif