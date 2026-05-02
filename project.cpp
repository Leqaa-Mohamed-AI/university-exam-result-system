#include <iostream>
#include <string>
using namespace std;
//person
class Person {
protected:
    string name;
    string nationalID;

public:
    Person(string n, string id) {
        name = n;
        nationalID = id;
    }
    string getName() {
        return name;
    }
    string getnationalID() {
        return nationalID;
    }
    virtual void display() = 0;
};
//Student
class Student : public Person {
private:
    string academicYear;
    string subjects;
    double GPA;
    string studentID;
public:
    Student() :Person("A", "0") {
    }
    Student(string n, string id, string year, string subj, double gpa, string sID)
        : Person(n, id) {
        academicYear = year;
        subjects = subj;
        GPA = gpa;
        studentID = sID;
    }
    void setGPA(double gpa) {
        GPA = gpa;
    }
    void setAcademicYear(string year) {
        academicYear = year;
    }
    double getGPA() {
        return GPA;
    }
    string getstudentID() {
        return studentID;
    }
    void display() {
        cout << name << "\n";
        cout << nationalID << "\n";
        cout << studentID << "\n";
        cout << academicYear << "\n";
        cout << GPA << "\n";
    }

};
//Subject
class Subject {
private:
    string subjectCode;
    string name;
    int creditHours;
    string department;
    string instructorName;
    double studentMark;
public:
    Subject() {
    }
    Subject(string sC, string n, int cH, string d, string iN, double SM) {
        subjectCode = sC;
        name = n;
        creditHours = cH;
        department = d;
        instructorName = iN;
        studentMark = SM;
    }
    void setSubjectCode(string sC) {
        subjectCode = sC;
    }
    void setName(string n) {
        name = n;
    }
    void setCreditHours(int cH) {
        creditHours = cH;
    }
    void setDepartment(string d) {
        department = d;
    }
    void setInstructorName(string iN) {
        instructorName = iN;
    }
    void setStudentMark(double SM) {
        studentMark = SM;
    }
    string getSubjectCode() {
        return subjectCode;
    }
    string getName() {
        return name;
    }
    int getCreditHours() {
        return creditHours;
    }
    string getDepartment() {
        return department;
    }
    string getInstructorName() {
        return instructorName;
    }
    double getStudentMark() {
        return studentMark;
    }
};
//Exam
class Exam {
private:
    string studentID;
    string subjectCode;
    double score;
public:
    Exam() {}
    Exam(Student s, Subject sub, double mark) {
        studentID = s.getstudentID();
        subjectCode = sub.getSubjectCode();
        score = mark;
        cout << "Student Name: " << s.getName() << endl;
        cout << "Subject Name: " << sub.getName() << endl;
        cout << "Final Score : " << score << endl;

    }
    double getScore() {
        return score;
    }
};
//Result
class Result {
private:
    Subject* subject;
    double studentMark;
    double GPA;
public:
    Result(Subject* sub = NULL, double marks = 0.0) {
        subject = sub;
        studentMark = marks;
        GPA = 0.0;
    }
    double getPoints(double studentMark) {
        if (studentMark >= 90)
            return 4.0; // A
        else if (studentMark >= 80)
            return 3.0; //B
        else if (studentMark >= 70)
            return 2.0; //C
        else if (studentMark >= 60)
            return 1.0; //D
        else
            return 0.0; //F 
    }
    double calculateGPA(double marks[], int hours[], int count) {
        double totalPoints = 0.0;
        int totalHours = 0;
        for (int i = 0; i < count; i++) {
            totalPoints += (getPoints(marks[i]) * hours[i]);
            totalHours += hours[i];
        }
        if (totalHours > 0) {
            GPA = totalPoints / totalHours;
            return GPA;
        }
        return 0.0;

    }
    void generalGrade(double GPA) {
        if (GPA >= 3.6)
            cout << "Excellent " << endl;
        else if (GPA >= 3.0)
            cout << "Very Good" << endl;
        else if (GPA >= 2.4)
            cout << "Good" << endl;
        else if (GPA >= 2.0)
            cout << "pass" << endl;
        else
            cout << "Fail" << endl;
    }
};
//UniversitySystem
class UniversitySystem {
private:
    Student students[1000];
    Subject subjects[1000];
    Exam exams[1000];
    int studentCount = 0;
    int subjectCount = 0;
    int examCount = 0;

public:
    void displayStudent(int index) {
        students[index].display();
    }
    void addStudent(Student s) {
        if (studentCount < 1000) {
            students[studentCount++] = s;
        }
        else {
            cout << "Student array is full" << endl;
        }
    }void addSubject(Subject s) {
        if (subjectCount < 1000) {
            subjects[subjectCount++] = s;
        }
        else {
            cout << "Subject array is full" << endl;
        }
    }

    void addExam(Exam e) {
        if (examCount < 1000) {
            exams[examCount++] = e;
        }
        else {
            cout << "Exam array is full" << endl;
        }
    }

    int searchStudent(string sID) {
        for (int i = 0; i < studentCount; i++) {
            if (students[i].getstudentID() == sID) {
                return i;
            }
        }
        return -1;
    }

    void deleteStudent(string sID) {
        int index = searchStudent(sID);
        if (index != -1) {
            students[index] = students[studentCount - 1];
            studentCount--;
            cout << "Student deleted successfully" << endl;
        }
        else {
            cout << "ID not found" << endl;
        }
    }
    void updateStudentData(string studentID, string academicYear, double GPA) {
        int index = searchStudent(studentID);
        if (index != -1) {
            students[index].setAcademicYear(academicYear);
            students[index].setGPA(GPA);
            cout << "Student profile updated successfully" << endl;
            students[index].display();
            cout << "Student ID: " << studentID << endl;
        }
        else {
            cout << "Please verify the ID and try again" << endl;
        }
       
    }
};
int main() {

    UniversitySystem MenoufiaUniversity;
    int userChoice;
    string studentID;
    cout << "    University Exam Result System   " << endl;
    do {

        cout << "1- Add Student\n";
        cout << "2- Search Student\n";
        cout << "3- Update Student\n";
        cout << "4- Delete Student\n";
        cout << "0- Exit\n";
        cout << " Enter your choice: ";
        cin >> userChoice;

        switch (userChoice) {
        case 1: {
            string name, nID, year, sID, sub;
            double gpa;
            cout << "Student Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Student ID: "; cin >> sID;
            cout << "National ID: "; cin >> nID;
            cout << "Year: "; cin >> year;
            cout << "Subject Name: "; cin >> sub;

            Student newStudent(name, nID, year, sub, 0.0, sID);
            MenoufiaUniversity.addStudent(newStudent);
            cout << "Student added to Exam System." << endl;
            break;
        }
        case 2: {
            cout << "Enter ID to search for Result: ";
            cin >> studentID;
            int idx = MenoufiaUniversity.searchStudent(studentID);

            if (idx != -1) {
                MenoufiaUniversity.displayStudent(idx);
            }

            else
                cout << "Result: Not Found." << endl;
            break;
        }
        case 3:
            cout << "Enter ID to update Exam Grade: ";
            cin >> studentID;

            MenoufiaUniversity.updateStudentData(studentID, "Updated", 3.8);
            cout << "Exam Result Updated." << endl;
            break;

        case 4:
            cout << "Enter ID to remove from Exam System: ";
            cin >> studentID;
            MenoufiaUniversity.deleteStudent(studentID);
            cout << "Student Record Deleted." << endl;
            break;

        case 0:
            cout << "Exiting System..." << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
            break;

        }
    }
        while (userChoice != 0);
   
    return 0;
}
    
