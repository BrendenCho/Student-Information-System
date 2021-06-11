#include "student.h"
#include "mainData.h"
#ifndef UI
#define UI
using namespace std;


class userInterface{
    public:
        void loginScreen();
        void mainMenu();
        userInterface();
    private:
        Student* currStudent;
        Staff* currStaff;
        Faculty* currFaculty;
        string currRole;
        mainData data;

};

#endif