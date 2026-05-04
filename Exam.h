#ifndef EXAM_H
#define EXAM_H

#include "Student.h"
#include "Subject.h"
#include <iostream>
using namespace std;

class Exam {
private:
    string studentID;
    string subjectCode;
    double score;

public:
    Exam();
    Exam(Student s, Subject sub, double mark);

    double getScore();
};

#endif

