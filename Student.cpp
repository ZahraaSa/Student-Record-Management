#include <iostream>
#include "Student.h"

using namespace std;

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
        totalPoints += points * 3;
        if (grade >= 50) {
            totalHours += 3;
        }
        current = current->next;
    }

    completedCreditHours = totalHours;
    if (totalHours > 0) {
        currentGPA = totalPoints / totalHours;
    } else {
        currentGPA = 0.0;
    }
}

bool Student::addGrade(int grade) {
    if (grade < 0) grade = 0;
    else if (grade > 100) grade = 100;

    GradeNode* newNode = new GradeNode();
    newNode->numericGrade = grade;
    newNode->next = nullptr;

    if (gradesHead == nullptr) {
        gradesHead = newNode;
    } else {
        GradeNode* temp = gradesHead;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    calculateGPA();
    return true;
}

bool Student::RemoveGrade(int ind) {
    if (ind < 0 || gradesHead == nullptr) return false;

    GradeNode* prevNode = nullptr;
    GradeNode* currentNode = gradesHead;
    int idx = 0;

    while (currentNode != nullptr && idx != ind) {
        prevNode = currentNode;
        currentNode = currentNode->next;
        idx++;
    }

    if (currentNode == nullptr) return false;

    if (prevNode == nullptr) {
        gradesHead = currentNode->next;
    } else {
        prevNode->next = currentNode->next;
    }
    delete currentNode;
    calculateGPA();
    return true;
}

bool Student::EditGrade(int index, int ngrade) {
    if (ngrade < 0) ngrade = 0;
    else if (ngrade > 100) ngrade = 100;

    if (index < 0 || gradesHead == nullptr) {
        return false;
    }

    GradeNode* temp = gradesHead;
    int currIndex = 0;
    while (temp != nullptr && currIndex < index) {
        temp = temp->next;
        currIndex++;
    }
    if (temp == nullptr) {
        return false;
    }
    temp->numericGrade = ngrade;
    calculateGPA();
    return true;
}

int Student::getGradeCount() {
    int GradeCount = 0;
    GradeNode* current = gradesHead;
    while (current != nullptr) {
        current = current->next;
        GradeCount++;
    }
    return GradeCount;
}

void Student::DisplayGrades() {
    cout << "Grades for " << name << " (" << studentID << "):" << endl;
    if (gradesHead == nullptr) {
        cout << "No grades available." << endl;
        return;
    }
    GradeNode* current = gradesHead;
    int index = 1;
    while (current != nullptr) {
        cout << index << ": " << current->numericGrade << endl;
        current = current->next;
        index++;
    }
}

Student::~Student() {
    GradeNode* current = gradesHead;
    while (current != nullptr) {
        GradeNode* temp = current;
        current = current->next;
        delete temp;
    }
}