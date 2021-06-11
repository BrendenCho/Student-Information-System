#include "user.h"
#include "course.h"
#include "student.h"
#include "faculty.h"
#include <map>
#ifndef STAFF
#define STAFF

class Staff:public User{
    public:
    void addClass(map<string,Course>&,map<string,Faculty>&);
    string generateReport(map<string,Student>&);
};


#endif