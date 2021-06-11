#include <vector>
#include<map>
#include "user.h"
#include "course.h"
#include "student.h"
#ifndef FACULTY
#define FACULTY


class Faculty:public User{    
    public:
        void viewCurrClasses(Faculty&,map<string,Course>&);
        void updateGrades(Faculty&,map<string,Course>&,map<string,Student>&);
};





#endif