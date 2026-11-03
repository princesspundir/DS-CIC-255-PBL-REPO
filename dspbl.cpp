
#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
    Student* next;
};

Student* head = nullptr;

void addStudent() {
    Student* newStudent = new Student;

    cout << "\nEnter Roll Number: ";
    cin >> newStudent->rollNo;

    Student* temp = head;

    while (temp != nullptr) {
        if (temp->rollNo == newStudent->rollNo) {
            cout << "Roll number already exists!\n";
            delete newStudent;
            return;
        }
        temp = temp->next;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Student Name: ";
    getline(cin, newStudent->name);

    cout << "Enter Marks: ";
    cin >> newStudent->marks;

    newStudent->next = nullptr;

    if (head == nullptr) {
        head = newStudent;
    } else {
        temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newStudent;
    }

    cout << "Student record added successfully!\n";
}

void displayStudents() {
    if (head == nullptr) {
        cout << "\nNo student records available.\n";
        return;
    }

    Student* temp = head;

    cout << "\n========== STUDENT RECORDS ==========\n";

    while (temp != nullptr) {
        cout << "Roll Number: " << temp->rollNo << endl;
        cout << "Name       : " << temp->name << endl;
        cout << "Marks      : " << temp->marks << endl;
        cout << "-------------------------------------\n";

        temp = temp->next;
    }
}

void updateRollNo() {
    if (head == nullptr) {
        cout << "\nNo student records available.\n";
        return;
    }

    int oldRoll, newRoll;

    cout << "\nEnter current Roll Number: ";
    cin >> oldRoll;

    Student* temp = head;

    while (temp != nullptr && temp->rollNo != oldRoll) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Student record not found!\n";
        return;
    }

    cout << "Enter new Roll Number: ";
    cin >> newRoll;

    Student* check = head;

    while (check != nullptr) {
        if (check->rollNo == newRoll) {
            cout << "This roll number already exists!\n";
            return;
        }
        check = check->next;
    }

    temp->rollNo = newRoll;

    cout << "Roll number updated successfully!\n";
}

void deleteStudent() {
    if (head == nullptr) {
        cout << "\nNo student records available.\n";
        return;
    }

    int roll;
    cout << "\nEnter Roll Number to delete: ";
    cin >> roll;

    Student* temp = head;
    Student* previous = nullptr;

    while (temp != nullptr && temp->rollNo != roll) {
        previous = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Student record not found!\n";
        return;
    }

    if (previous == nullptr) {
        head = head->next;
    } else {
        previous->next = temp->next;
    }

    delete temp;

    cout << "Student record deleted successfully!\n";
}

void reverseRecords() {
    if (head == nullptr) {
        cout << "\nNo student records available.\n";
        return;
    }

    Student* previous = nullptr;
    Student* current = head;
    Student* nextNode = nullptr;

    while (current != nullptr) {
        nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }

    head = previous;

    cout << "Student records reversed successfully!\n";
}

void freeRecords() {
    while (head != nullptr) {
        Student* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int choice;

    do {
        cout << "\n===== STUDENT RECORD MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student Record\n";
        cout << "2. Display All Records\n";
        cout << "3. Update Roll Number\n";
        cout << "4. Delete Student Record\n";
        cout << "5. Reverse Records\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Enter a number from 1 to 6.\n";
            continue;
        }

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                updateRollNo();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                reverseRecords();
                break;

            case 6:
                freeRecords();
                cout << "Program exited successfully.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}

