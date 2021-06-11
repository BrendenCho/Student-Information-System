#include "course.h"
#include "student.h"
#include "semester.h"
#include <fstream>
#include <vector>
using namespace std;
#ifndef REPORTGENERATOR
#define REPORTGENERATOR


class ReportGenerator{
    public:
        void generateReport(Student*,vector<Semester>*);
        void setStudent(Student*);
        void setSemesterList(vector<Semester>*);
    private:
        ofstream outFile;
        int credits = 0,totalCredits = 0,rawCredits = 0;
        vector<Semester>* semesterList;
        Student* student;
        void openOutputFile(string);
        void generateReportHeader();
        void generateReportContent();
        void generateReportFooter();
        void closeOutputFile();
};






#endif