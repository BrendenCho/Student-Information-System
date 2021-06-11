#include <string>
#include <map>
#include "course.h"
#ifndef SEMESTER
#define SEMESTER
using namespace std;

class Semester{
    private:
        map<string,Course> classList;
        string semesterName;
    public:
        map<string,Course>& getClassList();
        void addClass(Course);
        void setSemesterName(string);
        string getSemesterName();
        Course& getCourse(string);
    

};








#endif