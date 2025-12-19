#ifndef ADMIN_H
#define ADMIN_H

#include "Patient.h"
#include "Doctor.h"
#include "Appointment.h"
#include "Room.h"
#include "Utility.h"
#include <string>
using namespace std;

class Admin {
private:
    string password; // default "123" unless changed
public:
    Admin();
    void setPassword(const string& p);
    bool login();
    void menu();
private:
    void patientMenu();
    void doctorMenu();
    void appointmentMenu();
    void roomMenu();
};

#endif // ADMIN_H
