#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Appointment {
private:
    int appID;
    int patientReg;
    int doctorID;
    string date;
    string time;
public:
    Appointment();
    void inputAppointment();
    void displayAppointment() const;
    int getAppID() const;

    void saveToFile(const string& filename = "appointments.txt") const;
    static vector<Appointment> readAll(const string& filename = "appointments.txt");
    static void overwriteAll(const vector<Appointment>& list, const string& filename = "appointments.txt");
};

#endif // APPOINTMENT_H
