#include "Result.h"

Result::Result(Subject* sub, double marks) {
    subject = sub;
    studentMark = marks;
    GPA = 0.0;
}

double Result::getPoints(double studentMark) {
    if (studentMark >= 90)
        return 4.0;
    else if (studentMark >= 80)
        return 3.0;
    else if (studentMark >= 70)
        return 2.0;
    else if (studentMark >= 60)
        return 1.0;
    else
        return 0.0;
}

double Result::calculateGPA(double marks[], int hours[], int count) {
    double totalPoints = 0.0;
    int totalHours = 0;

    for (int i = 0; i < count; i++) {
        totalPoints += getPoints(marks[i]) * hours[i];
        totalHours += hours[i];
    }

    if (totalHours > 0) {
        GPA = totalPoints / totalHours;
        return GPA;
    }

    return 0.0;
}

void Result::generalGrade(double GPA) {
    if (GPA >= 3.6)
        cout << "Excellent" << endl;
    else if (GPA >= 3.0)
        cout << "Very Good" << endl;
    else if (GPA >= 2.4)
        cout << "Good" << endl;
    else if (GPA >= 2.0)
        cout << "Pass" << endl;
    else
        cout << "Fail" << endl;
}
