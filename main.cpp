#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Student.h"
#include "StudentManager.h"
void DisplayMenu() {
    cout << "\n===== Student Management System =====\n";
    cout << "1. Add a new student\n";
    cout << "2. Display all students\n";
    cout << "3. Search for a student\n";
    cout << "4. Edit a student\n";
    cout << "5. Remove a student\n";
    cout << "6. Sort students (Asc) By ID\n";
    cout << "7. Sort students (Desc) By ID\n";
    cout << "8. Exit\n";
    cout << "====================================\n";
    cout << "Enter your choice: ";
}
using namespace std;
int main() {
    StudentManager manager;
    int choice;

    do {
        DisplayMenu();
        cin >> choice;

        switch (choice) {
        case 1: manager.addStudent(); break;
        case 2: manager.displayAllStudents(); break;
        case 3: manager.searchStudent(); break;
        case 4: manager.editStudent(); break;
        case 5: manager.removeStudent(); break;
        case 6: manager.sortStudentsByID(); break;
        case 7: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice.\n"; break;
        }
    } while (choice != 7);

    return 0;
}
