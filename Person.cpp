#include "Person.h"

Person::Person(string n, string id) {
    name = n;
    nationalID = id;
}

string Person::getName() {
    return name;
}

string Person::getnationalID() {
    return nationalID;
}
