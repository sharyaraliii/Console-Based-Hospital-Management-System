#include "Patient.h"
#include <sstream>
#include <limits>
using namespace std;

Patient::Patient() {
    regNo = 0;
    disease = "";
    admitDate = "";
    bill = 0.0;
}

void Patient::inputPatient() {
    cout << "Enter Registration No (integer): ";
    cin >> regNo;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Age: ";
    cin >> age;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter Gender: ";
    getline(cin, gender);
    cout << "Enter Address: ";
    getline(cin, address);
    cout << "Enter Disease/Diagnosis: ";
    getline(cin, disease);
    cout << "Enter Admit Date (dd/mm/yyyy): ";
    getline(cin, admitDate);
    cout << "Enter Bill Amount (numeric): ";
    cin >> bill;
}

void Patient::displayPatient() const {
    cout << "RegNo: " << regNo << endl;
    displayBasicInfo();
    cout << "Disease: " << disease << endl;
    cout << "Admit Date: " << admitDate << endl;
    cout << "Bill: " << bill << endl;
}

int Patient::getRegNo() const { return regNo; }

void Patient::saveToFile(const string& filename) const {
    ofstream fout(filename, ios::app);
    if (!fout) {
        cout << "Error opening patient file for writing.\n";
        return;
    }
    // simple CSV (no escaping for commas)
    fout << regNo << "," << name << "," << age << "," << gender << "," << address
        << "," << disease << "," << admitDate << "," << bill << "\n";
    fout.close();
}

vector<Patient> Patient::readAll(const string& filename) {
    vector<Patient> list;
    ifstream fin(filename);
    if (!fin) return list;
    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string token;
        Patient p;
        getline(ss, token, ','); p.regNo = stoi(token);
        getline(ss, p.name, ',');
        getline(ss, token, ','); p.age = stoi(token);
        getline(ss, p.gender, ',');
        getline(ss, p.address, ',');
        getline(ss, p.disease, ',');
        getline(ss, p.admitDate, ',');
        getline(ss, token, ','); // last token might be end-of-line without comma
        if (token.empty()) {
            // try to read until end
            if (getline(ss, token)) p.bill = stod(token);
            else p.bill = 0.0;
        }
        else p.bill = stod(token);
        list.push_back(p);
    }
    fin.close();
    return list;
}

void Patient::overwriteAll(const vector<Patient>& list, const string& filename) {
    ofstream fout(filename, ios::trunc);
    if (!fout) {
        cout << "Error opening patient file for overwrite.\n";
        return;
    }
    for (const auto& p : list) {
        fout << p.regNo << "," << p.name << "," << p.age << "," << p.gender << "," << p.address
            << "," << p.disease << "," << p.admitDate << "," << p.bill << "\n";
    }
    fout.close();
}

