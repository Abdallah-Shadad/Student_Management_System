#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Student.h"

class StudentManager {
private:
    vector <Student> students;

public:
    // Add a new student
    void addStudent() {
        Student student;
        student.AddNewStudent();
        students.push_back(student);
        cout << "\nStudent Added Successfully!\n\n";
    }

    // Display all students
    void displayAllStudents() {
        if (students.empty()) {
            cout << "There are no students to display.\n\n";
            return;
        }

        for (auto& student : students) {
            student.displayStudentInfo();
        }
    }

    // Search for a student
    void searchStudent() {
        int choice;
        cout << "\nWhat variable do you want to search with?\n";
        cout << "1. Student ID\n";
        cout << "2. Student Name\n";
        cout << "3. Student Grade\n";
        cout << "Enter your choice: ";
        cin >> choice;

        bool found = false;
        switch (choice) {
        case 1: {  // Search by ID
            int id;
            cout << "Enter Student ID: ";
            cin >> id;
            for (auto& student : students) {
                if (student.getID() == id) {
                    student.displayStudentInfo();
                    found = true;
                    break;
                }
            }
            break;
        }
        case 2: {  // Search by Name
            string name;
            cout << "Enter Student Name: ";
            cin.ignore();  // To clear input buffer
            getline(cin, name);
            for (auto& student : students) {
                if (student.getName() == name) {
                    student.displayStudentInfo();
                    found = true;
                    break;
                }
            }
            break;
        }
        case 3: {  // Search by Grade
            float grade;
            cout << "Enter Student Grade: ";
            cin >> grade;
            for (auto& student : students) {
                if (student.getGrade() == grade) {
                    student.displayStudentInfo();
                    found = true;
                    break;
                }
            }
            break;
        }
        default:
            cout << "Invalid choice.\n";
            break;
        }

        if (!found) {
            cout << "\nStudent not found.\n\n";
        }
    }

    // Edit a student
    void editStudent() {
        int id;
        cout << "Enter ID of student to edit: ";
        cin >> id;

        bool found = false;
        for (auto& student : students) {
            if (student.getID() == id) {
                found = true;
                int choice;
                cout << "What do you want to edit?\n";
                cout << "1. Name\n";
                cout << "2. Grade\n";
                cout << "Enter your choice: ";
                cin >> choice;

                if (choice == 1) {
                    string newName;
                    cout << "Enter new name: ";
                    cin.ignore();  // To clear input buffer
                    getline(cin, newName);
                    student.setName(newName);
                }
                else if (choice == 2) {
                    float newGrade;
                    cout << "Enter new grade: ";
                    cin >> newGrade;
                    student.setGrade(newGrade);
                }
                else {
                    cout << "Invalid choice.\n";
                }
                break;
            }
        }

        if (!found) {
            cout << "Student not found.\n\n";
        }
    }

    // Remove a student
    void removeStudent() {
        int id;
        cout << "Enter ID of student to remove: ";
        cin >> id;

        bool found = false;
        for (size_t i = 0; i < students.size(); i++) {
            if (students[i].getID() == id) {
                students.erase(students.begin() + i);
                cout << "\nStudent removed successfully!\n\n";
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Student not found.\n\n";
        }
    }
    // Sort Students
    void sortStudentsByID() {
        if (students.empty()) { // Use 'students' here instead of 'vStudents'
            cout << "There are no students to sort.\n";
            return; // Early exit if no students to sort
        }

        int n = students.size();

        // Bubble Sort: Compare each pair of adjacent students
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - 1 - i; ++j) {
                // If the current student's ID is greater than the next one, swap them
                if (students[j].getID() > students[j + 1].getID()) {
                    swap(students[j], students[j + 1]);
                }
            }
        }

        cout << "\nStudents sorted by ID successfully!\n\n";
    }

};
