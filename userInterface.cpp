#include "userInterface.h"
#include "password.h"
#include <iostream>
#include <string>
using namespace std;

userInterface::userInterface()
{
    data.parseUsers();
    data.parseClasses();
}

// acts as the login screen
void userInterface::loginScreen()
{
    string userName, password;
    Password pw;
    bool shouldRun = true;
    while (shouldRun)
    {
        cout << "----------Login----------" << endl;
        cout << "Username:";
        cin >> userName;
        cout << "Password:";
        cin >> password;

        if (pw.checkLogin(userName, password))
        {
            shouldRun = false;
        }
        else
        {
            cout << "Login Failed. Check Username/Password" << endl;
        }
    }

    currRole = pw.getRole();
    if (currRole.compare("student") == 0)
    {
        currStudent = &data.getStudent(pw.getID());
        currStudent->setAuthenticated(true);
    }
    else if (currRole.compare("faculty") == 0)
    {
        currFaculty = &data.getFaculty(pw.getID());
        currFaculty->setAuthenticated(true);
    }
    else
    {
        currStaff = &data.getStaff(pw.getID());
        currStaff->setAuthenticated(true);
    }
}
// displays menu depending on user and controls input
void userInterface::mainMenu()
{
    if (currRole.compare("student") == 0)
    {
        while (currStudent->getAuthenticated())
        {
            string userInput = "";
            cout << "----- Welcome " << currStudent->getName() << "-----" << endl;
            cout << "Enter the number of the option you want to preform." << endl;
            cout << "1.View Current Class Schedule" << endl;
            cout << "2.Register for Class" << endl;
            cout << "3.View Current Grades" << endl;
            cout << "4.View Transcript" << endl;
            cout << "5.Log Out" << endl;
            cin >> userInput;

            if (userInput.compare("1") == 0)
            {

                currStudent->viewCurrentClasses(data.getCourseList()[data.getCurrentSemester()].getClassList(), data.getCurrentSemester(), currStudent->getID());
            }
            else if (userInput.compare("2") == 0)
            {

                cout << data.getCurrentSemester() << " Class Sections" << endl;
                map<int, Course> tempMap;
                int num;
                while (true)
                {

                    for (auto i = data.getCourseList().begin(); i != data.getCourseList().end(); i++)
                    {
                        if (i->second.getSemesterName().compare(data.getCurrentSemester()) == 0)
                        {
                            int index = 1;
                            for (auto ii = i->second.getClassList().begin(); ii != i->second.getClassList().end(); ii++)
                            {
                                tempMap[index] = ii->second;
                                cout << index << "." << tempMap[index].getCourseName() << endl;
                                index++;
                            }
                        }
                    }
                    cout << "Enter the number of the class you wish to register for" << endl;
                    string input = "";
                    cin >> input;
                    bool valid = true;
                    for (int x = 0; x < input.size(); x++)
                    {
                        if (input.at(x) < '0' || input.at(x) > '9')
                        {
                            valid = false;
                        }
                    }

                    if (valid == false)
                    {
                        cout << "Invalid Input" << endl;
                        continue;
                    }

                    num = stoi(input);

                    if (tempMap.find(num) == tempMap.end())
                    {
                        cout << "Invalid Input" << endl;
                        continue;
                    }

                    break;
                }
                string registerName = tempMap[num].getCourseName();
                bool canAdd = true;
                bool alreadyRegistered = false;
                char c;
                for (auto it = data.getCourseList().begin(); it != data.getCourseList().end(); it++)
                {
                    for (auto i = it->second.getClassList().begin(); i != it->second.getClassList().end(); i++)
                    {
                        if (i->second.getCourseName().compare(registerName) == 0 && i->second.getGradeList().find(currStudent->getID()) != i->second.getGradeList().end())
                        {
                            c = i->second.getGradeList()[currStudent->getID()];
                            if (c == 'A' || c == 'B' || c == 'C' || it->second.getSemesterName().compare(data.getCurrentSemester()) == 0)
                            {
                                canAdd = false;
                                if (it->second.getSemesterName().compare(data.getCurrentSemester()) == 0)
                                {
                                    alreadyRegistered = true;
                                }
                            }
                        }
                    }
                }

                if (canAdd == false)
                {
                    if (alreadyRegistered)
                    {
                        cout << "You are already enrolled in this class" << endl;
                    }
                    else
                    {
                        cout << "Can't register for Class you have a grade of " << c << " in a previous class" << endl;
                    }
                }
                else
                {
                    currStudent->registerClass(currStudent, registerName, &data.getCourseList()[data.getCurrentSemester()].getClassList());
                    cout << "Succesfully Registered for " << registerName << endl;
                }
            }
            else if (userInput.compare("3") == 0)
            {
                vector<Semester> list;
                list.push_back(data.getCourseList()[data.getCurrentSemester()]);
                currStudent->generateReport(&list);
            }
            else if (userInput.compare("4") == 0)
            {
                vector<Semester> list;
                for (auto it = data.getCourseList().begin(); it != data.getCourseList().end(); it++)
                {
                    list.push_back(it->second);
                }
                currStudent->generateReport(&list);
            }
            else if (userInput.compare("5") == 0)
            {
                currStudent->setAuthenticated(false);
            }
            else
            {
                cout << "Invalid Input" << endl;
            }
        }
    }
    else if (currRole.compare("faculty") == 0)
    {
        while (currFaculty->getAuthenticated())
        {
            string userInput = "";
            cout << "----- Welcome " << currFaculty->getName() << "-----" << endl;
            cout << "Enter the number of the option you want to preform." << endl;
            cout << "1.View Current Class Sections" << endl;
            cout << "2.Input Grades" << endl;
            cout << "3.Log Out" << endl;
            cin >> userInput;

            if (userInput.compare("1") == 0)
            {
                currFaculty->viewCurrClasses(*currFaculty, data.getCourseList()[data.getCurrentSemester()].getClassList());
            }
            else if (userInput.compare("2") == 0)
            {
                currFaculty->updateGrades(*currFaculty, data.getCourseList()[data.getCurrentSemester()].getClassList(), data.getStudentList());
            }
            else if (userInput.compare("3") == 0)
            {
                currFaculty->setAuthenticated(false);
            }
            else
            {
                cout << "Invalid Input" << endl;
            }
        }
    }
    else
    {
        while (currStaff->getAuthenticated())
        {
            string userInput = "";
            cout << "----- Welcome " << currStaff->getName() << "-----" << endl;
            cout << "Enter the number of the option you want to preform." << endl;
            cout << "1.Create New Course" << endl;
            cout << "2.Generate Student Report" << endl;
            cout << "3.Log Out" << endl;
            cin >> userInput;

            if (userInput.compare("1") == 0)
            {
                currStaff->addClass(data.getCourseList()[data.getCurrentSemester()].getClassList(), data.getFacultyList());
            }
            else if (userInput.compare("2") == 0)
            {

                currStudent = &data.getStudent(currStaff->generateReport(data.getStudentList()));
                vector<Semester> list;
                for (auto it = data.getCourseList().begin(); it != data.getCourseList().end(); it++)
                {
                    list.push_back(it->second);
                }
                currStudent->generateReport(&list);
            }
            else if (userInput.compare("3") == 0)
            {
                currStaff->setAuthenticated(false);
            }
            else
            {
                cout << "Invalid Input" << endl;
            }
        }
    }

    data.writeData();
}
