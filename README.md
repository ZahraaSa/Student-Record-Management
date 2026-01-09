# 📚 Student Record Management 

This project is an advanced application of fundamental data structures, required for the Algorithms and Programming course. It is developed entirely in **C++** as a console-based application.

## 🎯 Core Objectives and Constraints

The main goal is to build a student record system while strictly adhering to the following implementation constraints:

1.  **No STL Containers:** The core data structures—**Singly Linked List**, **Queue**, and **Stack**—must be implemented manually from scratch using dynamic memory allocation.
2.  **Memory Management:** Ensure full dynamic memory deallocation using destructors (`~ClassName()`) to prevent all memory leaks.

## 🗃️ Key Features and Functionality

* **Student Admission:** New students are first added to a **Waiting Queue** (using the custom Queue implementation) and then processed into the main Roster.
* **Grade Management:** Supports adding, editing, and deleting student grades (stored in a nested **Singly Linked List**). The **Current GPA** and **Completed Credit Hours** are recalculated immediately upon any grade modification.
* **Roster Sorting:** The main Roster can be sorted based on **Completed Hours** or **GPA** in descending order. This must be achieved by **rearranging the Linked List node pointers**, not by swapping data within nodes.
* **Operation Tracking:** A **Search History Stack** (using the custom Stack implementation) logs the ID and type of successful search or grade modification operations.

## 🧑‍💻 Team Contribution

This project was developed jointly by two students.

| Team Member | 


@Mohamed-Ghosen2
@ZahraaSa

<img width="842" height="1114" alt="umlads" src="https://github.com/user-attachments/assets/7ced2970-0fb5-457b-8bb1-ed557c200dd7" />
