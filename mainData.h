#include "staff.h"
#include "student.h"
#include "faculty.h"
#include <string>
#include <map>
#include <fstream>
#ifndef MAINDATA
#define MAINDATA
using namespace std;

class mainData{
    public:
    void addStudent(Student);
    void addStaff(Staff);
    void addFaculty(Faculty);
    Student& getStudent(string);
    Staff& getStaff(string);
    Faculty& getFaculty(string);
    void parseUsers();
    void parseClasses();
    map<string,Semester>& getCourseList();
    string getCurrentSemester();
    map<string,Student>& getStudentList();
    void writeData();
    map<string,Faculty>& getFacultyList();
    private:
    map<string,Student> studentList;
    map<string,Staff> staffList;
    map<string,Faculty> facultyList;
    map<string,Semester> courseList;
    ifstream infile;
    ofstream outfile;
    string currentSemester = "Spring 2021";


};








#endif