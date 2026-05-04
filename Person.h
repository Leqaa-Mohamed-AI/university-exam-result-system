#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
protected:
    string name;
    string nationalID;

public:
    Person(string n, string id);
    string getName();
    string getnationalID();
    virtual void display() = 0;
};

#endif

