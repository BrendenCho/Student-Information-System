#include "course.h"
using namespace std;
// all getters setters
void Course::setInstructor(string instructor){
    this -> instructor = instructor;
}

string Course::getInstructor(){
    return instructor;
}

void Course::setCredits(int credits){
    this -> credits = credits;
}

int Course::getCredits(){
    return this -> credits;
}

void Course::createStudentEntry(string id, char grade){
    gradeList[id] = grade;
}

map<string,char>& Course::getGradeList(){
    return gradeList;
}

void Course::setCourseName(string courseName){
    this-> courseName = courseName;
}

string Course::getCourseName(){
    return courseName;
}