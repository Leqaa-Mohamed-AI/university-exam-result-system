#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>
using namespace std;

class Subject {
private:
    string subjectCode;
    string name;
    int creditHours;
    string department;
    string instructorName;
    double studentMark;

public:
    Subject();
    Subject(string sC, string n, int cH, string d, string iN, double SM);

    void setSubjectCode(string sC);
    void setName(string n);
    void setCreditHours(int cH);
    void setDepartment(string d);
    void setInstructorName(string iN);
    void setStudentMark(double SM);

    string getSubjectCode();
    string getName();
    int getCreditHours();
    string getDepartment();
    string getInstructorName();
    double getStudentMark();
};

#endif

