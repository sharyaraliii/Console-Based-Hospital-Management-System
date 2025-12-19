#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Room {
private:
    int roomNo;
    bool occupied;
    int patientReg;
public:
    Room();
    void inputRoom();
    void displayRoom() const;
    int getRoomNo() const;
    int getPatientReg() const;
    bool isOccupied() const;

    void saveToFile(const string& filename = "rooms.txt") const;
    static vector<Room> readAll(const string& filename = "rooms.txt");
    static void overwriteAll(const vector<Room>& list, const string& filename = "rooms.txt");
    void assignToPatient(int reg);
    void vacate();
};

#endif // ROOM_H
