#include <iostream>
#include <string>
#include "UniversitySystem.h"

using namespace std;

int main() {

    UniversitySystem MenoufiaUniversity;

    int userChoice;
    string studentID;

    cout << "                         =====  University Exam Result System  =====\n";

    do {
        cout << "\n--------- MENU ---------\n"<<endl;
        cout << "1- Add Student\n";
        cout << "2- Search Student\n";
        cout << "3- Update Student\n";
        cout << "4- Delete Student\n";
        cout << "0- Exit\n"<<endl;
        cout << "Enter your choice: ";
        cin >> userChoice;

        switch (userChoice) {

        case 1: {
            string name, nID, year, sID, sub;

            cout << "\n--- Add Student ---\n";

            cout << "Student Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Student ID: ";
            cin >> sID;

            cout << "National ID: ";
            cin >> nID;

            cout << "Year: ";
            cin >> year;

            cout << "Subject Name: ";
            cin >> sub;

            Student newStudent(name, nID, year, sub, 0.0, sID);
            MenoufiaUniversity.addStudent(newStudent);

            cout << "- Student added successfully to system.\n";
            break;
        }

        case 2: {
            cout << "\n--- Search Student ---\n";
            cout << "Enter ID to search: ";
            cin >> studentID;

            int idx = MenoufiaUniversity.searchStudent(studentID);

            if (idx != -1) {
                cout << "\n Student Found:\n";
                MenoufiaUniversity.displayStudent(idx);
            }
            else {
                cout << " Result: Not Found.\n";
            }
            break;
        }

        case 3: {
            cout << "\n--- Update Student ---\n";
            cout << "Enter ID to update: ";
            cin >> studentID;

            MenoufiaUniversity.updateStudentData(studentID, "Updated", 3.8);
            break;
        }

        case 4: {
            cout << "\n--- Delete Student ---\n";
            cout << "Enter ID to delete: ";
            cin >> studentID;

            MenoufiaUniversity.deleteStudent(studentID);
            break;
        }

        case 0:
            cout << "\nExiting System... Goodbye \n";
            break;

        default:
            cout << " Invalid choice! Please try again.\n";
            break;
        }

    } while (userChoice != 0);

    return 0;
}