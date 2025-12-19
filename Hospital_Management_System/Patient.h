#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Person.h"
using namespace std;

class Patient : public Person {
private:
    int regNo;
    string disease;
    string admitDate;
    double bill;
public:
    Patient();
    void inputPatient();
    void displayPatient() const;
    int getRegNo() const;

    // file helpers (text)
    void saveToFile(const string& filename = "patients.txt") const;
    static vector<Patient> readAll(const string& filename = "patients.txt");
    static void overwriteAll(const vector<Patient>& list, const string& filename = "patients.txt");
};

#endif // PATIENT_H
