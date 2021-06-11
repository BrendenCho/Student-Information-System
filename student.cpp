#include "student.h"
#include "reportGenerator.h"
#include <iostream>
using namespace std;
// creates instance of report generator
void Student::generateReport(vector<Semester>* list){
    ReportGenerator report;
    report.generateReport(this,list);
}
// iterates through course list and prints course if they are found in grade map
void Student::viewCurrentClasses(map<string,Course>& courseList,string currSemester,string id){
    
     vector<Course> classes;
            for(auto it = courseList.begin();it != courseList.end();it++){
                    if(it ->second.getGradeList().find(id) != it-> second.getGradeList().end()){
                        classes.push_back(it ->second);
                    }
                
            }
      
    cout << "Currrent Classes" << endl;
    for(auto it = classes.begin();it != classes.end();it++){
        cout << it-> getCourseName() << endl;
    }  
}
// adds student to grade list in class
void Student::registerClass(Student* student,string className,map<string,Course>* classList){
    for(auto it = classList ->begin();it != classList ->end();it++){
        if(it ->second.getCourseName().compare(className) == 0){
            it ->second.getGradeList()[student->getID()] = 'A';
        }
    }
}

