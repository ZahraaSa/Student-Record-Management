#include <iostream>
#include <string>
#include <iomanip>
#include "StudentList.h"
#include "WaitingQueue.h"
#include "SearchStack.h"

using namespace std;

int main() {
    StudentList roster;
    WaitingQueue waitQueue;
    SearchHistoryStack history;

    int choice;
    do {
        cout << "\n--- Student Record Management System ---" << endl;
        cout << "1. Add Student to Waiting Queue" << endl;
        cout << "2. Process Waiting Queue" << endl;
        cout << "3. Add Grade to Student" << endl;
        cout << "4. Edit Grade by Index" << endl;
        cout << "5. Delete Grade by Index" << endl;
        cout << "6. Display Single Student (Basic Info)" << endl;
        cout << "7. Display Student Grades" << endl;
        cout << "8. Display All Students" << endl;
        cout << "9. Sort Students by Completed Hours (Descending)" << endl;
        cout << "10. Sort Students by GPA (Descending)" << endl;
        cout << "11. Show Search History" << endl;
        cout << "12. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        string id, name;
        int grade, index;
        Student* s;

        switch (choice) {
        case 1:
            cout << "Enter Student name: ";
            cin >> name;
            cout << "Enter Student ID: ";
            cin >> id;
            if (name.empty() || id.empty()) {
                cout << "Error: Name or ID cannot be empty." << endl;
            } else {
                Student* student = new Student(name, id);
                waitQueue.enqueueStudent(student);
                cout << "Student enqueued. Queue size: " << waitQueue.size << endl;
            }
            break;
        case 2:
            waitQueue.processQueue(roster);
            break;
        case 3:
            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter grade (0-100): ";
            cin >> grade;
            s = roster.FindStudentByID(id);
            if (s != nullptr && s->addGrade(grade)) {
                history.Push(id, "Add Grade");
                cout << "Grade added successfully." << endl;
            } else {
                cout << "Student not found or invalid grade." << endl;
            }
            break;
        case 4:
            cout << "Enter Student ID: ";
            cin >> id;
            s = roster.FindStudentByID(id);
            if (s != nullptr) {
                s->DisplayGrades();
                if (s->getGradeCount() > 0) {
                    cout << "Enter 1-based index to edit: ";
                    cin >> index;
                    index--;  // to 0-based
                    cout << "Enter new grade (0-100): ";
                    cin >> grade;
                    if (s->EditGrade(index, grade)) {
                        history.Push(id, "Edit Grade");
                        cout << "Grade edited successfully." << endl;
                    } else {
                        cout << "Invalid index." << endl;
                    }
                } else {
                    cout << "No grades to edit." << endl;
                }
            } else {
                cout << "Student not found." << endl;
            }
            break;
        case 5:
            cout << "Enter Student ID: ";
            cin >> id;
            s = roster.FindStudentByID(id);
            if (s != nullptr) {
                s->DisplayGrades();
                if (s->getGradeCount() > 0) {
                    cout << "Enter 1-based index to delete: ";
                    cin >> index;
                    index--;  // to 0-based
                    if (s->RemoveGrade(index)) {
                        history.Push(id, "Remove Grade");
                        cout << "Grade removed successfully." << endl;
                    } else {
                        cout << "Invalid index." << endl;
                    }
                } else {
                    cout << "No grades to delete." << endl;
                }
            } else {
                cout << "Student not found." << endl;
            }
            break;
        case 6:
            cout << "Enter Student ID: ";
            cin >> id;
            s = roster.FindStudentByID(id);
            if (s != nullptr) {
                history.Push(id, "Display Details");
                cout << "Basic Info for " << s->name << " (" << s->studentID << "):" << endl;
                cout << "  - Current GPA: " << fixed << setprecision(2) << s->currentGPA << endl;
                cout << "  - Completed Hours: " << s->completedCreditHours << endl;
                cout << "  - Number of Grades: " << s->getGradeCount() << endl;
            } else {
                cout << "Student not found." << endl;
            }
            break;
        case 7:
            cout << "Enter Student ID: ";
            cin >> id;
            s = roster.FindStudentByID(id);
            if (s != nullptr) {
                history.Push(id, "Display Grades");
                s->DisplayGrades();
            } else {
                cout << "Student not found." << endl;
            }
            break;
        case 8:
            roster.DisplayStudents();
            break;
        case 9:
            roster.sortByCompletedHoursDescending();
            cout << "Sorted by Completed Hours (Descending). Displaying all:" << endl;
            roster.DisplayStudents();
            break;
        case 10:
            roster.sortByGPADescending();
            cout << "Sorted by GPA (Descending). Displaying all:" << endl;
            roster.DisplayStudents();
            break;
        case 11:
            history.Display();
            break;
        case 12:
            cout << "Exiting and freeing memory..." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 12);

    // Destructors called automatically
    return 0;
}