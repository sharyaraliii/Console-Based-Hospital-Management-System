#include "Doctor.h"
#include <sstream>
#include <limits>
using namespace std;

Doctor::Doctor() {
    doctorID = 0;
    specialization = "";
}

void Doctor::inputDoctor() {
    cout << "Enter Doctor ID (integer): ";
    cin >> doctorID;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Age: ";
    cin >> age;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter Gender: ";
    getline(cin, gender);
    cout << "Enter Address: ";
    getline(cin, address);
    cout << "Enter Specialization: ";
    getline(cin, specialization);
}

void Doctor::displayDoctor() const {
    cout << "DoctorID: " << doctorID << endl;
    displayBasicInfo();
    cout << "Specialization: " << specialization << endl;
}

int Doctor::getDoctorID() const { return doctorID; }

void Doctor::saveToFile(const string& filename) const {
    ofstream fout(filename, ios::app);
    if (!fout) {
        cout << "Error opening doctor file for writing.\n";
        return;
    }
    fout << doctorID << "," << name << "," << age << "," << gender << "," << address << "," << specialization << "\n";
    fout.close();
}

vector<Doctor> Doctor::readAll(const string& filename) {
    vector<Doctor> list;
    ifstream fin(filename);
    if (!fin) return list;
    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        Doctor d;
        string token;
        getline(ss, token, ','); d.doctorID = stoi(token);
        getline(ss, d.name, ',');
        getline(ss, token, ','); d.age = stoi(token);
        getline(ss, d.gender, ',');
        getline(ss, d.address, ',');
        getline(ss, d.specialization, ',');
        list.push_back(d);
    }
    fin.close();
    return list;
}

void Doctor::overwriteAll(const vector<Doctor>& list, const string& filename) {
    ofstream fout(filename, ios::trunc);
    if (!fout) {
        cout << "Error opening doctor file for overwrite.\n";
        return;
    }
    for (const auto& d : list) {
        fout << d.doctorID << "," << d.name << "," << d.age << "," << d.gender << "," << d.address << "," << d.specialization << "\n";
    }
    fout.close();
}

