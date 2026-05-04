#ifndef UNIVERSITYSYSTEM_H
#define UNIVERSITYSYSTEM_H

#include "Student.h"
#include "Subject.h"
#include "Exam.h"
#include <iostream>
#include <vector>
using namespace std;

class UniversitySystem {
private:
    vector<Student> students;
    vector<Subject> subjects;
    vector<Exam> exams;

    int studentCount;
    int subjectCount;
    int examCount;

public:
    UniversitySystem();

    void displayStudent(int index);
    void addStudent(Student s);
    void addSubject(Subject s);
    void addExam(Exam e);

    int searchStudent(string sID);
    void deleteStudent(string sID);
    void updateStudentData(string studentID, string academicYear, double GPA);
};

#endif

