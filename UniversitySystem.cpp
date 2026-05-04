#include "UniversitySystem.h"

UniversitySystem::UniversitySystem() {
    studentCount = 0;
    subjectCount = 0;
    examCount = 0;
}

void UniversitySystem::displayStudent(int index) {
    students[index].display();
}

void UniversitySystem::addStudent(Student s) {
    students.push_back(s);
}

void UniversitySystem::addSubject(Subject s) {
    subjects.push_back(s);
}
void UniversitySystem::addExam(Exam e) {
    exams.push_back(e);
}
int UniversitySystem::searchStudent(string sID) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getstudentID() == sID)
            return i;
    }
    return -1;
}

void UniversitySystem::deleteStudent(string sID) {
    int index = searchStudent(sID);

    if (index != -1) {
        students.erase(students.begin() + index);
        cout << "Student deleted successfully" << endl;
    }
    else {
        cout << "ID not found" << endl;
    }
}

void UniversitySystem::updateStudentData(string studentID, string academicYear, double GPA) {
    int index = searchStudent(studentID);
    if (index != -1) {
        students[index].setAcademicYear(academicYear);
        students[index].setGPA(GPA);
        cout << "Student profile updated successfully" << endl;
        students[index].display();
     
    }
    else {
        cout << "Please verify the ID and try again" << endl;
    }
}
