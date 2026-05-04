#include "Exam.h"

Exam::Exam() {}

Exam::Exam(Student s, Subject sub, double mark) {
    studentID = s.getstudentID();
    subjectCode = sub.getSubjectCode();
    score = mark;

    cout << "Student Name: " << s.getName() << endl;
    cout << "Subject Name: " << sub.getName() << endl;
    cout << "Final Score : " << score << endl;
}

double Exam::getScore() {
    return score;
}
