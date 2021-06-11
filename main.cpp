#include "userInterface.h"
using namespace std;

// g++ main.cpp password.cpp userInterface.cpp user.cpp student.cpp mainData.cpp reportGenerator.cpp course.cpp Semester.cpp faculty.cpp staff.cpp


// main function
int main(){
    userInterface ui;
    ui.loginScreen();
    ui.mainMenu();
    return 0;
}