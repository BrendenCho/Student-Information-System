#include <string>
#include <map>
#ifndef COURSE
#define COURSE
using namespace std;

class Course{
    private:
        string instructor,courseName;
        int credits;
        map<string,char> gradeList;
    public:
        void setInstructor(string);
        string getInstructor();
        void setCredits(int);
        int getCredits();
        void createStudentEntry(string,char);
        map<string,char>& getGradeList();
        void setCourseName(string);
        string getCourseName();
};

#endif