#ifndef RESULT_H
#define RESULT_H

#include "Subject.h"
#include <iostream>
using namespace std;

class Result {
private:
    Subject* subject;
    double studentMark;
    double GPA;

public:
    Result(Subject* sub = NULL, double marks = 0.0);

    double getPoints(double studentMark);
    double calculateGPA(double marks[], int hours[], int count);
    void generalGrade(double GPA);
};

#endif

