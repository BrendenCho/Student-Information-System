#include "semester.h"
using namespace std;

//gettters setters
map<string,Course>& Semester::getClassList(){
    return classList;
}

void Semester::addClass(Course course){
    classList[course.getCourseName()] = course;
}

void Semester::setSemesterName(string semesterName){
    this -> semesterName = semesterName;
}

string Semester::getSemesterName(){
    return semesterName;
}

Course& Semester::getCourse(string courseName){
    return classList[courseName];
}