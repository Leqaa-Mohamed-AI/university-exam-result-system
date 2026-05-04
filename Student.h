#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <iostream>
using namespace std;

class Student : public Person {
private:
    string academicYear;
    string subjects;
    double GPA;
    string studentID;

public:
    Student();
    Student(string n, string id, string year, string subj, double gpa, string sID);

    void setGPA(double gpa);
    void setAcademicYear(string year);

    double getGPA();
    string getstudentID();

    void display() override;
};

#endif

