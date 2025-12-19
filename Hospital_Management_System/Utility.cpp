// Utility.cpp
#include "Utility.h"
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

namespace Utility {

    void clearScreen() {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }

    void pause() {
        cout << "\nPress ENTER to continue...";
        cin.ignore();       // SIMPLE + SAFE
        cin.get();          // Waits for ENTER
    }

    void header(const string& title) {
        clearScreen();
        cout << "========================================\n";
        cout << "   " << title << "\n";
        cout << "========================================\n\n";
    }

    bool confirm(const string& message) {
        char ch;
        cout << message << " (y/n): ";
        cin >> ch;

        cin.ignore();   // clears the leftover newline

        return (ch == 'y' || ch == 'Y');
    }

} // namespace Utility
