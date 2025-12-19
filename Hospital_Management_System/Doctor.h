#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Person.h"
using namespace std;

class Doctor : public Person {
private:
    int doctorID;
    string specialization;
public:
    Doctor();
    void inputDoctor();
    void displayDoctor() const;
    int getDoctorID() const;

    void saveToFile(const string& filename = "doctors.txt") const;
    static vector<Doctor> readAll(const string& filename = "doctors.txt");
    static void overwriteAll(const vector<Doctor>& list, const string& filename = "doctors.txt");
};

#endif // DOCTOR_H
