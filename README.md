# Student Record Management System Using Singly Linked List in C++

A menu-driven console program that stores student records in a **singly linked list** using dynamic memory allocation in C++. It was built as a Project Based Learning (PBL) project at Delhi Technical Campus, Greater Noida.

## Table of Contents
- [About](#about)
- [Features](#features)
- [Tech Stack](#tech-stack)
- [Node Structure](#node-structure)
- [How It Works](#how-it-works)
- [Getting Started](#getting-started)
- [Sample Output](#sample-output)
- [Complexity](#complexity)
- [Limitations](#limitations)
- [Future Work](#future-work)
- [Project Structure](#project-structure)
- [Team](#team)

## About
Fixed-size arrays need a preset size, and inserting or deleting an element means shifting the others. This project avoids both problems by allocating memory one node at a time. Records live in memory only and are lost when the program exits.

## Features
- Add a student record (roll number, name, marks)
- Display all records
- Update a roll number
- Delete a record
- Reverse the list in place using three pointers
- Unique roll numbers (duplicates are rejected)
- Names with spaces are supported (read with `getline`)
- Clear messages for an empty list, a duplicate roll number and a record not found
- Input validation at the menu
- Frees all nodes on exit, so there is no memory leak

## Tech Stack
| Component | Details |
|---|---|
| Language | C++ |
| Data structure | Singly linked list |
| Memory | Dynamic allocation with `new` / `delete` |
| Interface | Menu-driven console |
| IDE / compiler | OnlineGDB |

## Node Structure
```cpp
struct Student {
    int rollNo;
    string name;
    float marks;
    Student* next;
};
```
- `head` points to the first node.
- `next` links a node to the following node.
- The last node's `next` is `nullptr`.

## How It Works
The program starts with `head = nullptr` and repeatedly shows this menu:

```
===== STUDENT RECORD MANAGEMENT SYSTEM =====
1. Add Student Record
2. Display All Records
3. Update Roll Number
4. Delete Student Record
5. Reverse Records
6. Exit
Enter your choice:
```

- **Add:** checks that the roll number is unique, then appends a new node at the end of the list.
- **Display:** walks the list from `head` and prints every record.
- **Update:** finds the current roll number and changes it to a new, unique roll number.
- **Delete:** finds the roll number, relinks the list and frees the node.
- **Reverse:** reverses the links in place (see below).
- **Exit:** frees all nodes and ends the program.

Invalid input at the menu is cleared and discarded, and the menu is shown again.

### In-place reversal
```cpp
while (current != nullptr) {
    nextNode = current->next;
    current->next = previous;
    previous = current;
    current = nextNode;
}
head = previous;
```
For the list A → B → C, the result is C → B → A → null. No new nodes are created.

## Getting Started

### Prerequisites
A C++ compiler such as `g++`. You can also paste the code into [OnlineGDB](https://www.onlinegdb.com).

### Run locally
```bash
git clone https://github.com/princesspundir/student-record-management-linked-list-cpp.git
cd student-record-management-linked-list-cpp
g++ main.cpp -o student_records
./student_records
```
On Windows, run `student_records.exe` instead of `./student_records`.

## Sample Output
```
Enter Roll Number: 101
Enter Student Name: Princess
Enter Marks: 89.5
Student record added successfully!

========== STUDENT RECORDS ==========
Roll Number: 101
Name       : Princess
Marks      : 89.5
-------------------------------------
```

## Complexity
| Operation | Worst-case time | Space |
|---|---|---|
| Add / Display | O(n) | O(1) |
| Update / Delete | O(n) | O(1) |
| Reverse | O(n) | O(1) |
| Free all | O(n) | O(1) |

## Limitations
- Memory only: no file or database
- No search; only the roll number can be edited
- Input is checked only at the menu
- Insertion is O(n)

## Future Work
- File handling or a database
- Search and sorting
- Editing of name and marks
- Tail pointer, stronger validation and a GUI

## Project Structure
```
.
├── main.cpp
└── README.md
```

## Team
| Name | Enrollment No. |
|---|---|
| [Princess Pundir](https://github.com/princesspundir) | 26518002725 |
| Karanveer | 26618002725 |

**Faculty Mentor:** Mr. Akash Bhardwaj
**Institution:** Delhi Technical Campus, Greater Noida (affiliated to GGSIPU, New Delhi)
**Programme:** B.Tech CSE (Core), 2nd Year – 3rd Semester, Session 2026–27
