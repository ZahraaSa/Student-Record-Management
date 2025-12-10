#ifndef SEARCHSTACK_H
#define SEARCHSTACK_H

#include <string>
#include <iostream>

using namespace std;

class SearchHistoryNode {
public:
    string studentID;
    string operation;
    SearchHistoryNode* next;

    SearchHistoryNode(string studentID, string operation) {
        this->studentID = studentID;
        this->operation = operation;
        next = nullptr;
    }
};

class SearchHistoryStack {
private:
    SearchHistoryNode* head;
    int count;
public:
    SearchHistoryStack() {
        head = nullptr;
        count = 0;
    }

    ~SearchHistoryStack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void Push(string ID, string operation) {
        SearchHistoryNode* newnode = new SearchHistoryNode(ID, operation);
        newnode->next = head;
        head = newnode;
        count++;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void Display() {
        if (isEmpty()) {
            cout << "Search history is empty" << endl;
            return;
        }
        cout << "Search history from newest to oldest" << endl;
        SearchHistoryNode* temp = head;
        while (temp != nullptr) {
            cout << "ID: " << temp->studentID << " The operation is: " << temp->operation << endl;
            temp = temp->next;
        }
        cout << "Total record lookups: " << count << endl;
    }

    bool pop() {
        if (isEmpty()) {
            cout << "There is no element to pop" << endl;
            return false;
        }
        SearchHistoryNode* temp = head;
        head = head->next;
        delete temp;
        count--;
        return true;
    }

    SearchHistoryNode* top() {
        if (isEmpty()) {
            cout << "There is no element" << endl;
            return nullptr;
        }
        return head;
    }
};
#endif