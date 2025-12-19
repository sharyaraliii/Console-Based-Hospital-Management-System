#include "Appointment.h"
#include <sstream>
#include <limits>
using namespace std;

Appointment::Appointment() {
    appID = 0; patientReg = 0; doctorID = 0; date = ""; time = "";
}

void Appointment::inputAppointment() {
    cout << "Enter Appointment ID (integer): ";
    cin >> appID;
    cout << "Enter Patient Reg No (integer): ";
    cin >> patientReg;
    cout << "Enter Doctor ID (integer): ";
    cin >> doctorID;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter Date (dd/mm/yyyy): ";
    getline(cin, date);
    cout << "Enter Time (hh:mm): ";
    getline(cin, time);
}

void Appointment::displayAppointment() const {
    cout << "AppointmentID: " << appID << "  PatientReg: " << patientReg << "  DoctorID: " << doctorID << endl;
    cout << "Date: " << date << "  Time: " << time << endl;
}

int Appointment::getAppID() const { return appID; }

void Appointment::saveToFile(const string& filename) const {
    ofstream fout(filename, ios::app);
    if (!fout) { cout << "Error opening appointment file.\n"; return; }
    fout << appID << "," << patientReg << "," << doctorID << "," << date << "," << time << "\n";
    fout.close();
}

vector<Appointment> Appointment::readAll(const string& filename) {
    vector<Appointment> list;
    ifstream fin(filename);
    if (!fin) return list;
    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        Appointment a;
        string token;
        getline(ss, token, ','); a.appID = stoi(token);
        getline(ss, token, ','); a.patientReg = stoi(token);
        getline(ss, token, ','); a.doctorID = stoi(token);
        getline(ss, a.date, ',');
        getline(ss, a.time, ',');
        list.push_back(a);
    }
    fin.close();
    return list;
}

void Appointment::overwriteAll(const vector<Appointment>& list, const string& filename) {
    ofstream fout(filename, ios::trunc);
    if (!fout) { cout << "Error opening appointment file for overwrite.\n"; return; }
    for (const auto& a : list) {
        fout << a.appID << "," << a.patientReg << "," << a.doctorID << "," << a.date << "," << a.time << "\n";
    }
    fout.close();
}
