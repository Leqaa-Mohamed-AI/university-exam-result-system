#include "Student.h"

Student::Student() : Person("A", "0") {}

Student::Student(string n, string id, string year, string subj, double gpa, string sID)
    : Person(n, id) {
    academicYear = year;
    subjects = subj;
    GPA = gpa;
    studentID = sID;
}

void Student::setGPA(double gpa) {
    GPA = gpa;
}

void Student::setAcademicYear(string year) {
    academicYear = year;
}

double Student::getGPA() {
    return GPA;
}

string Student::getstudentID() {
    return studentID;
}

void Student::display() {
        cout << "Name: " << name << endl;
        cout << "ID: " << nationalID << endl;
        cout << "Student ID: " << studentID << endl;
        cout << "Year: " << academicYear << endl;
        cout << "GPA: " << GPA << endl;
    }
