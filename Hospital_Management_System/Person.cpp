#include "Person.h"
using namespace std;

Person::Person() {
    name = "";
    age = 0;
    gender = "";
    address = "";
}

void Person::setBasicInfo() {
    // ensure previous newline cleaned
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Name: ";
    getline(cin, name);
    cout << "Age: ";
    cin >> age;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Gender: ";
    getline(cin, gender);
    cout << "Address: ";
    getline(cin, address);
}

void Person::displayBasicInfo() const {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Gender: " << gender << endl;
    cout << "Address: " << address << endl;
}
