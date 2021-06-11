#include "mainData.h"
#include <iostream>
#include <cstdlib>
using namespace std;
// adds users to correct map based on id
void mainData::addStudent(Student student){
    studentList[student.getID()] = student;
}

void mainData::addStaff(Staff staff){
    staffList[staff.getID()] = staff;
}

void mainData::addFaculty(Faculty faculty){
    facultyList[faculty.getID()] = faculty;
}
// returns users from map based on id
Student& mainData::getStudent(string id){
    return studentList[id];
}

Staff& mainData::getStaff(string id){
    return staffList[id];
}

Faculty& mainData::getFaculty(string id){
    return facultyList[id];
}
// parses users file and adds users into main maps
void mainData::parseUsers(){
    
    infile.open("users.csv");
    if(infile.fail()){
        cout << "Failed to open file." << endl;
        exit(1);
    }
     string temp;
     string id,name,role;
     while(getline(infile,temp,'\n')){

        int index = 0; 
        for(int x = 0; x < 5;x++){
            string parsedData ="";
            while(index < temp.size() && temp.at(index) != ','){
                parsedData += temp.at(index);
                index++;
            }
            if(x == 0){
                id = parsedData;
            }else if(x == 2){
                name = parsedData;
            }else if (x == 4){
                role = parsedData;
            }

            index++; 
        }

        if(role.compare("student") == 0){
            Student s;
            s.setID(id);
            s.setName(name);
            s.setRole(role);
            addStudent(s);
        }else if(role.compare("staff") == 0){
            Staff ss;
            ss.setID(id);
            ss.setName(name);
            ss.setRole(role);
            addStaff(ss);
        }else{
            Faculty f;
            f.setID(id);
            f.setName(name);
            f.setRole(role);
            addFaculty(f);
        }

        temp = "";
    }
    infile.close();
}
// reads classData and adds courses to course map
void mainData::parseClasses(){
    infile.open("classData.dat");

    if(infile.fail()){
        cout << "failed to open file" << endl;
        exit(1);
    }
    string temp;
    while(getline(infile,temp,'\n')){
        string semesterName,tempStr ="";
        int index = 0;
        
        while(temp.at(index) != ' '){
            semesterName += temp.at(index);
            index++;
        }
        index++;
        semesterName += ' ';
        while(temp.at(index) != ' '){
            semesterName += temp.at(index);
            index++;
        }
        index ++;
        Course c;
         while(temp.at(index) != ' '){
            tempStr += temp.at(index);
            index++;
        }
        index++;
        tempStr += ' ';
         while(temp.at(index) != ' '){
            tempStr += temp.at(index);
            index++;
        }
        index++;
        c.setCourseName(tempStr);
        tempStr = "";
        
        int credits;
        while(temp.at(index) != ' '){
            tempStr += temp.at(index);
            index++;
        }
        
        index++;
        c.setCredits(atoi(tempStr.c_str()));
        tempStr = "";
        
        while(index != temp.size() &&  temp.at(index) != ' '){
            tempStr += temp.at(index);
            index++;
        }
        index++;
        
        c.setInstructor(getFaculty((tempStr)).getName());

        if(index <= temp.size()){

        string parse = "";
        for(int x = index; x < temp.size();x++){
            
            if(temp.at(x) != ' '){
                parse += temp.at(x);
            }else{
                c.createStudentEntry(parse.substr(0,parse.size() - 1),parse.at(parse.size() - 1));
                parse = "";
                
            }
        }
      
        c.createStudentEntry(parse.substr(0,parse.size() - 1),parse.at(parse.size() - 1));
        }


        if(courseList.find(semesterName)!= courseList.end()){
            courseList[semesterName].addClass(c);
        }else{
            Semester s;
            s.setSemesterName(semesterName);
            s.addClass(c);
            courseList[semesterName] = s;
        }

    }
    infile.close();
}
//getters
map<string,Semester>& mainData::getCourseList(){
    return courseList;
}

string mainData::getCurrentSemester(){
    return currentSemester;
}

map<string,Student>& mainData::getStudentList(){
    return studentList;
}
//writes all info to classData
void mainData::writeData(){
    outfile.open("classData.dat");
    if(outfile.fail()){
        cout << "Failed to open file" << endl;
        exit(1);
    }

    for(auto it = courseList.begin();it != courseList.end();it++){
        for(auto i = it ->second.getClassList().begin(); i != it ->second.getClassList().end();i++){
            outfile << it ->second.getSemesterName() << " " <<  i ->second.getCourseName() << " " << i ->second.getCredits() << " ";
            string id;
            for(auto f = facultyList.begin();f != facultyList.end(); f++){
                if(f ->second.getName().compare(i ->second.getInstructor()) == 0){
                    id = f ->second.getID();
                }
            }
            outfile << id;
            
            for(auto s = i ->second.getGradeList().begin();s != i ->second.getGradeList().end();s++){
                outfile<< " " << s ->first << s ->second;
            }
            outfile << endl;
            }
    }



}
// getter
map<string,Faculty>& mainData::getFacultyList(){
    return facultyList;
}