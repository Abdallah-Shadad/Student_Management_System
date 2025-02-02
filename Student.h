#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int studentID;
    string name;
    int age;
    float grade;
    string email;

public:
    Student() {
        studentID = 0;
        name = "";
        age = 0;
        grade = 0.0;
        email = "";
    }

    Student(int id, string studentName, int studentAge, float studentGrade, string studentEmail) {
        studentID = id;
        name = studentName;
        age = studentAge;
        grade = studentGrade;
        email = studentEmail;
    }

    // Getters
    int getID() const {
        return studentID;
    }
    string getName() const {
        return name;
    }
    int getAge() const {
        return age;
    }
    float getGrade() const {
        return grade;
    }
    string getEmail() const {
        return email;
    }

    // Setters
    void setID(int id) {
        studentID = id;
    }
    void setName(string studentName) {
        name = studentName;
    }
    void setAge(int studentAge) {
        age = studentAge;
    }
    void setGrade(float studentGrade) {
        grade = studentGrade;
    }
    void setEmail(string studentEmail) {
        email = studentEmail;
    }

    void AddNewStudent() {
        cout << "Enter Student ID: ";
        cin >> studentID;
        cout << "Enter Student Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Student Age: ";
        cin >> age;
        cout << "Enter Student Grade: ";
        cin >> grade;
        cout << "Enter Student Email: ";
        cin.ignore();
        getline(cin, email);
    }
    bool searchByID(int id) {
        return (id == studentID);
    }
    void displayStudentInfo() {
        cout << "Student ID: " << studentID << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Grade: " << grade << endl;
        cout << "Email: " << email << endl;
        cout << endl;
    }
};