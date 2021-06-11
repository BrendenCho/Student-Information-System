#include "user.h"
#include "course.h"
#include "semester.h"
#include <vector>
#ifndef STUDENT
#define STUDENT
using namespace std;

class Student:public User{
    public:
        void registerClass(Student*,string,map<string,Course>*);
        void generateReport(vector<Semester>*);
        void viewCurrentClasses(map<string,Course>&,string,string);
       
   
       
};


#endif