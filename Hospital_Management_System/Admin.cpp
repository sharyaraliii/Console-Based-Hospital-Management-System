#include "Admin.h"
#include <limits>
using namespace std;

Admin::Admin() {
    // default password; change here if you want
    password = "123";
}

void Admin::setPassword(const string& p) {
    password = p;
}

bool Admin::login() {
    Utility::header("ADMIN LOGIN");
    cout << "Enter password: ";
    string pass;
    cin >> pass;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (pass == password) return true;
    cout << "Wrong password.\n";
    return false;
}

void Admin::menu() {
    if (!login()) {
        Utility::pause();
        return;
    }
    char ch = '0';
    while (ch != '5') {
        Utility::header("HOSPITAL MANAGEMENT - ADMIN");
        cout << "1. Patients\n2. Doctors\n3. Appointments\n4. Rooms\n5. Exit\nChoose: ";
        cin >> ch;
        switch (ch) {
        case '1': patientMenu(); break;
        case '2': doctorMenu(); break;
        case '3': appointmentMenu(); break;
        case '4': roomMenu(); break;
        case '5': break;
        default: cout << "Invalid choice.\n"; Utility::pause(); break;
        }
    }
}

void Admin::patientMenu() {
    Patient p;
    int choice = 0;
    while (choice != 6) {
        Utility::header("PATIENT MENU");
        cout << "1. Add Patient\n2. Show All Patients\n3. Search Patient\n4. Modify Patient\n5. Delete Patient\n6. Back\nChoose: ";
        cin >> choice;
        if (choice == 1) {
            p.inputPatient();
            p.saveToFile();
            cout << "Saved.\n"; Utility::pause();
        }
        else if (choice == 2) {
            auto list = Patient::readAll();
            Utility::header("ALL PATIENTS");
            if (list.empty()) cout << "No records found.\n";
            for (const auto& pt : list) { pt.displayPatient(); cout << "-----------------\n"; }
            Utility::pause();
        }
        else if (choice == 3) {
            cout << "Enter RegNo to search: ";
            int r; cin >> r;
            auto list = Patient::readAll();
            bool found = false;
            for (const auto& pt : list) if (pt.getRegNo() == r) { pt.displayPatient(); found = true; break; }
            if (!found) cout << "Not found.\n";
            Utility::pause();
        }
        else if (choice == 4) {
            cout << "Enter RegNo to modify: "; int r; cin >> r;
            auto list = Patient::readAll();
            bool found = false;
            for (auto& pt : list) {
                if (pt.getRegNo() == r) {
                    cout << "Enter new details:\n";
                    pt.inputPatient(); // re-enter including regNo
                    found = true;
                    break;
                }
            }
            if (found) { Patient::overwriteAll(list); cout << "Updated.\n"; }
            else cout << "Not found.\n";
            Utility::pause();
        }
        else if (choice == 5) {
            cout << "Enter RegNo to delete: "; int r; cin >> r;
            auto list = Patient::readAll();
            vector<Patient> newlist;
            for (const auto& pt : list) if (pt.getRegNo() != r) newlist.push_back(pt);
            if (newlist.size() != list.size()) { Patient::overwriteAll(newlist); cout << "Deleted.\n"; }
            else cout << "Not found.\n";
            Utility::pause();
        }
    }
}

void Admin::doctorMenu() {
    Doctor d;
    int choice = 0;
    while (choice != 5) {
        Utility::header("DOCTOR MENU");
        cout << "1. Add Doctor\n2. Show All Doctors\n3. Search Doctor\n4. Modify Doctor\n5. Back\nChoose: ";
        cin >> choice;
        if (choice == 1) {
            d.inputDoctor();
            d.saveToFile();
            cout << "Saved.\n"; Utility::pause();
        }
        else if (choice == 2) {
            auto list = Doctor::readAll();
            Utility::header("ALL DOCTORS");
            if (list.empty()) cout << "No records found.\n";
            for (const auto& doc : list) { doc.displayDoctor(); cout << "-----------------\n"; }
            Utility::pause();
        }
        else if (choice == 3) {
            cout << "Enter Doctor ID to search: "; int id; cin >> id;
            auto list = Doctor::readAll();
            bool found = false;
            for (const auto& doc : list) if (doc.getDoctorID() == id) { doc.displayDoctor(); found = true; break; }
            if (!found) cout << "Not found.\n";
            Utility::pause();
        }
        else if (choice == 4) {
            cout << "Enter Doctor ID to modify: "; int id; cin >> id;
            auto list = Doctor::readAll();
            bool found = false;
            for (auto& doc : list) {
                if (doc.getDoctorID() == id) {
                    cout << "Enter new details:\n";
                    doc.inputDoctor();
                    found = true;
                    break;
                }
            }
            if (found) { Doctor::overwriteAll(list); cout << "Updated.\n"; }
            else cout << "Not found.\n";
            Utility::pause();
        }
    }
}

void Admin::appointmentMenu() {
    Appointment a;
    int choice = 0;
    while (choice != 5) {
        Utility::header("APPOINTMENT MENU");
        cout << "1. Book Appointment\n2. List Appointments\n3. Cancel Appointment\n4. Search Appointment\n5. Back\nChoose: ";
        cin >> choice;
        if (choice == 1) {
            a.inputAppointment();
            a.saveToFile();
            cout << "Booked.\n"; Utility::pause();
        }
        else if (choice == 2) {
            auto list = Appointment::readAll();
            Utility::header("ALL APPOINTMENTS");
            if (list.empty()) cout << "No records found.\n";
            for (const auto& ap : list) { ap.displayAppointment(); cout << "-----------------\n"; }
            Utility::pause();
        }
        else if (choice == 3) {
            cout << "Enter Appointment ID to cancel: "; int id; cin >> id;
            auto list = Appointment::readAll();
            vector<Appointment> newlist;
            bool found = false;
            for (const auto& ap : list) {
                if (ap.getAppID() != id) newlist.push_back(ap);
                else found = true;
            }
            if (found) { Appointment::overwriteAll(newlist); cout << "Cancelled.\n"; }
            else cout << "Not found.\n";
            Utility::pause();
        }
        else if (choice == 4) {
            cout << "Enter Appointment ID to search: "; int id; cin >> id;
            auto list = Appointment::readAll();
            bool found = false;
            for (const auto& ap : list) if (ap.getAppID() == id) { ap.displayAppointment(); found = true; break; }
            if (!found) cout << "Not found.\n";
            Utility::pause();
        }
    }
}

void Admin::roomMenu() {
    Room r;
    int choice = 0;
    while (choice != 6) {
        Utility::header("ROOM MENU");
        cout << "1. Add Room\n2. Show All Rooms\n3. Assign Room\n4. Vacate Room\n5. Search Room\n6. Back\nChoose: ";
        cin >> choice;
        if (choice == 1) {
            r.inputRoom();
            r.saveToFile();
            cout << "Saved.\n"; Utility::pause();
        }
        else if (choice == 2) {
            auto list = Room::readAll();
            Utility::header("ALL ROOMS");
            if (list.empty()) cout << "No records found.\n";
            for (const auto& rm : list) { rm.displayRoom(); cout << "-----------------\n"; }
            Utility::pause();
        }
        else if (choice == 3) {
            cout << "Enter Room No to assign: "; int rn; cin >> rn;
            cout << "Enter Patient RegNo: "; int pr; cin >> pr;
            auto list = Room::readAll();
            bool found = false;
            for (auto& rm : list) {
                if (rm.getRoomNo() == rn) { rm.assignToPatient(pr); found = true; break; }
            }
            if (found) { Room::overwriteAll(list); cout << "Assigned.\n"; }
            else cout << "Room not found.\n";
            Utility::pause();
        }
        else if (choice == 4) {
            cout << "Enter Room No to vacate: "; int rn; cin >> rn;
            auto list = Room::readAll();
            bool found = false;
            for (auto& rm : list) {
                if (rm.getRoomNo() == rn) { rm.vacate(); found = true; break; }
            }
            if (found) { Room::overwriteAll(list); cout << "Vacated.\n"; }
            else cout << "Room not found.\n";
            Utility::pause();
        }
        else if (choice == 5) {
            cout << "Enter Room No to search: "; int rn; cin >> rn;
            auto list = Room::readAll();
            bool found = false;
            for (const auto& rm : list) if (rm.getRoomNo() == rn) { rm.displayRoom(); found = true; break; }
            if (!found) cout << "Not found.\n";
            Utility::pause();
        }
    }
}

