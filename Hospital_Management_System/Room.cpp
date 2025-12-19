#include "Room.h"
#include <sstream>
#include <limits>
using namespace std;

Room::Room() { roomNo = 0; occupied = false; patientReg = 0; }

void Room::inputRoom() {
    cout << "Enter Room No (integer): ";
    cin >> roomNo;
    cout << "Is this room occupied now? (1=yes 0=no): ";
    int t; cin >> t; occupied = (t != 0);
    if (occupied) {
        cout << "Enter Patient Reg No assigned to this room: ";
        cin >> patientReg;
    }
    else patientReg = 0;
}

void Room::displayRoom() const {
    cout << "RoomNo: " << roomNo << "  Occupied: " << (occupied ? "Yes" : "No") << endl;
    if (occupied) cout << "Assigned to Patient RegNo: " << patientReg << endl;
}

int Room::getRoomNo() const { return roomNo; }
int Room::getPatientReg() const { return patientReg; }
bool Room::isOccupied() const { return occupied; }

void Room::assignToPatient(int reg) { occupied = true; patientReg = reg; }
void Room::vacate() { occupied = false; patientReg = 0; }

void Room::saveToFile(const string& filename) const {
    ofstream fout(filename, ios::app);
    if (!fout) { cout << "Error opening rooms file.\n"; return; }
    fout << roomNo << "," << (occupied ? 1 : 0) << "," << patientReg << "\n";
    fout.close();
}

vector<Room> Room::readAll(const string& filename) {
    vector<Room> list;
    ifstream fin(filename);
    if (!fin) return list;
    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        Room r;
        string token;
        getline(ss, token, ','); r.roomNo = stoi(token);
        getline(ss, token, ','); r.occupied = (stoi(token) != 0);
        getline(ss, token, ','); r.patientReg = stoi(token);
        list.push_back(r);
    }
    fin.close();
    return list;
}

void Room::overwriteAll(const vector<Room>& list, const string& filename) {
    ofstream fout(filename, ios::trunc);
    if (!fout) { cout << "Error opening rooms file to overwrite.\n"; return; }
    for (const auto& r : list) {
        fout << r.roomNo << "," << (r.occupied ? 1 : 0) << "," << r.patientReg << "\n";
    }
    fout.close();
}
