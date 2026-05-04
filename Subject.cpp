#include "Subject.h"

Subject::Subject() {}

Subject::Subject(string sC, string n, int cH, string d, string iN, double SM) {
    subjectCode = sC;
    name = n;
    creditHours = cH;
    department = d;
    instructorName = iN;
    studentMark = SM;
}

void Subject::setSubjectCode(string sC) {
    subjectCode = sC;
}

void Subject::setName(string n) {
    name = n;
}

void Subject::setCreditHours(int cH) {
    creditHours = cH;
}

void Subject::setDepartment(string d) {
    department = d;
}

void Subject::setInstructorName(string iN) {
    instructorName = iN;
}

void Subject::setStudentMark(double SM) {
    studentMark = SM;
}

string Subject::getSubjectCode() {
    return subjectCode;
}

string Subject::getName() {
    return name;
}

int Subject::getCreditHours() {
    return creditHours;
}

string Subject::getDepartment() {
    return department;
}

string Subject::getInstructorName() {
    return instructorName;
}

double Subject::getStudentMark() {
    return studentMark;
}
