#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <string>
using namespace std;

namespace Utility {
    void clearScreen();
    void pause();
    void header(const string& title);
    bool confirm(const string& message);
}

#endif // UTILITY_H
