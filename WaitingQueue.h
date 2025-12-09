class Waiting_QueueNode {
public:
    Student* student;
    Waiting_QueueNode* next;
};

class Wating_Queue {
public:
    Waiting_QueueNode* front;
    Waiting_QueueNode* rear;
    int size;

    Wating_Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueueStudent(Student* student){
        Waiting_QueueNode* newnode = new Waiting_QueueNode();
        newnode->student = student;
        newnode->next = nullptr;
if (rear == nullptr) {
            front = rear = newnode;
        }
        else {
            rear->next = newnode;
                rear = newnode;
        }
        size++;
    }
    Student* dequeueStudent() {
        if (front == nullptr) {
            return nullptr;
        }
        else {
            Waiting_QueueNode* temp = front;
            Student* student = front->student;
            front = front->next;
            if (front == nullptr) {
                rear = nullptr;
            }
            delete temp;
            size--;
            return student;
        }
    }
        bool isempty() {
            return front == nullptr;
        }
        void displayQueue(){
            Waiting_QueueNode* temp = front;
            if (temp == nullptr) {
                cout << "Queue is empty" << endl;
                return;
            }
            while (temp != nullptr) {
                cout << "Student name:" << temp->student->name << "ID:" << temp->student->studentID << endl;
                temp = temp->next;
        }
        }
       
void Wating_Queue::processQueue(StudentList& roster) {
    int transferred = 0;
    while (!isempty()) {
        Student* student = dequeueStudent();
        bool isDuplicate = false;

        StudentNode* current = roster.head;
        while (current != nullptr) {
            if (current->student->studentID == student->studentID) {
                isDuplicate = true;
                break;
            }
            current = current->Next;
        }

        if (!isDuplicate) {
            roster.AddStudent(student); 
            transferred++;
        } else {
            std::cout << "Warning: Duplicate ID (" << student->studentID << ") for student: " << student->name << ". Student rejected." << std::endl;
            delete student; 
        }
    }
    std::cout << transferred << " students were transferred from the waiting queue to the roster." << std::endl; 
}

        void PromtandEnqueue() {
            string name;
            string id;
            cout << "Enter Student name:" << endl;
            cin >> name;
            cout << "Enter Student ID:" << endl;
            cin >> id;

            if (name.empty() && id.empty()) {
                cout << "Invalid input" << endl;
                return;
            }
            Student* student = new Student(name, id);
            enqueueStudent(student);
            cout << "Enqueue done " << endl;
            cout << "Queue size:" << size << endl;
        }
};