#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Person {
protected:
    string name;
    int age;
    string gender;
    string address;
public:
    Person();
    void setBasicInfo();
    void displayBasicInfo() const;
};

#endif // PERSON_H
