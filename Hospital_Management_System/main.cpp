#include "Admin.h"
#include "Utility.h"
#include <iostream>
using namespace std;

int main() {
    string member1 = "Hassan Bajwa";            
    string member2 = "Sharyar Ali";     
    string adminPass = "123";            

    Admin admin;
    admin.setPassword(adminPass); 

    Utility::header("Hospital Management System");
    cout << "Group Members:\n";
    cout << "1. " << member1 << endl;
    cout << "2. " << member2 << endl << endl;
    Utility::pause();

    admin.menu();
    cout << "Thank you. Exiting...\n";
    return 0;
}
