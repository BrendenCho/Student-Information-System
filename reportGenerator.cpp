#include "reportGenerator.h"
#include <iostream>
#include <iomanip>
using namespace std;
// generates student report
void ReportGenerator::generateReport(Student* student,vector<Semester>* semesterList){
    setStudent(student);
    setSemesterList(semesterList);
    openOutputFile(student->getName());
    generateReportHeader();
    generateReportContent();
    generateReportFooter();
    closeOutputFile();
}
//setters
void ReportGenerator::setStudent(Student* student){
    this ->student = student;
}

void ReportGenerator::setSemesterList(vector<Semester>* semesterList){
    this -> semesterList = semesterList;
}


// opens output file
void ReportGenerator::openOutputFile(string fileName){
    outFile.open(fileName+".dat");
    if(outFile.fail()){
        cout << "Failed to open file." << endl;
        exit(1);
    }
}
// generates report header
void ReportGenerator::generateReportHeader(){
    cout << "Student Name:" << student ->getName() << endl;
    cout << "Student ID:" << student ->getID() << endl;
    outFile << "Student Name:" << student ->getName() << endl;
    outFile << "Student ID:" << student ->getID() << endl;
}
// generates main content
void ReportGenerator::generateReportContent(){
    
    int localcredits =0;
    int rawlocalcredits = 0;
    for(auto it = semesterList -> begin();it != semesterList -> end();it++){
        credits = 0;
        localcredits = 0;
        rawlocalcredits = 0;
        cout << it ->getSemesterName() << endl;
        cout <<setiosflags(ios::left) << setw(15) << "Course Name" << setw(15) << "Course Credits" << setw(15) 
        << setw(25) << "Instructor" << setw(5) << "Grade" << endl;

        outFile << it ->getSemesterName() << endl;
        outFile <<setiosflags(ios::left) << setw(15) << "Course Name" << setw(15) << "Course Credits" << setw(15) 
        << setw(25) << "Instructor" << setw(5) << "Grade" << endl;

        
        for(auto i = it ->getClassList().begin();i != it->getClassList().end();i++){
            if(i ->second.getGradeList().find(student ->getID()) != i ->second.getGradeList().end()){
            cout <<setiosflags(ios::left)<< setw(15) << i ->second.getCourseName() << setw(15) << i ->second.getCredits()<< setw(15) 
            << setw(25) << i ->second.getInstructor() << setw(5) << i ->second.getGradeList()[student->getID()] << endl;

            outFile <<setiosflags(ios::left)<< setw(15) << i ->second.getCourseName() << setw(15) << i ->second.getCredits()<< setw(15) 
            << setw(25) << i ->second.getInstructor() << setw(5) << i ->second.getGradeList()[student->getID()] << endl;

            totalCredits += i ->second.getCredits();
            char g = i ->second.getGradeList()[student->getID()];
      
            if(g == 'A'){
                credits = i ->second.getCredits() * 4;
            }else if(g == 'B'){
                credits = i ->second.getCredits() * 3;
            }else if(g == 'C'){
                credits = i ->second.getCredits() * 2;
            }else if(g == 'D'){
                credits = i ->second.getCredits() * 1;
            }
            
            rawlocalcredits += i -> second.getCredits();
            localcredits += credits;
            rawCredits += credits; 
            }
        }
    cout << "Credits Attempted:" << rawlocalcredits << endl;
    outFile << "Credits Attempted:" << rawlocalcredits << endl;
    if(rawlocalcredits != 0){
    cout << "Term GPA:" << setprecision(3) <<(double)((double)localcredits/(double)rawlocalcredits) << endl;
    outFile << "Term GPA:" << setprecision(3) <<(double)((double)localcredits/(double)rawlocalcredits) << endl;
    }else{
     cout << "Term GPA:" << setprecision(3) <<0<< endl;
     outFile << "Term GPA:" << setprecision(3) <<0<< endl;    
    }
    }
    
}
//generates footer
void ReportGenerator::generateReportFooter(){
    cout << "Total Units Attempted:" << totalCredits << endl;
    cout << "Cumulative GPA:" << setprecision(3) << (double)((double)rawCredits/(double)totalCredits) << endl;
    outFile << "Total Units Attempted:" << totalCredits << endl;
    outFile << "Cumulative GPA:" << setprecision(3) << (double)((double)rawCredits/(double)totalCredits) << endl;
}
// closes output file
void ReportGenerator::closeOutputFile(){
    outFile.close();
}