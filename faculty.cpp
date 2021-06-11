#include "faculty.h"
#include "course.h"
#include "student.h"
#include <iostream>
using namespace std;
// iterates through refrence to main course map and displays if name is found in course
void Faculty::viewCurrClasses(Faculty& faculty,map<string,Course>& list){
    cout << "Current Sections"<< endl;
    for(auto it = list.begin();it != list.end();it++){
        if(it -> second.getInstructor().compare(faculty.getName())==0){
        cout << it ->second.getCourseName() << endl;
        }

    }
}
//finds all courses instructor is teaching, prompts for input, then iterates through the selected course grade map and updates values
void Faculty::updateGrades(Faculty& faculty,map<string,Course>& list,map<string,Student>& studentList){
 while(true){
    cout << "Current Sections"<< endl;
    cout << "Enter the number of section you wish to update grades on" << endl;
    int index = 1;
    map<int,Course> tempMap;
    for(auto it = list.begin();it != list.end();it++){
        if(it -> second.getInstructor().compare(faculty.getName())==0){
        tempMap[index] = it ->second;
        cout <<index <<"."<<it ->second.getCourseName() << endl;
        index++;
        }
    }

    string input;
    cin >> input;
    bool validInput = true;
    for(int x = 0; x < input.size();x++){
        if(input.at(x) < '0' || input.at(x) > '9'){
            validInput = false;
        }
    }
    int option;
    if(validInput){
         option = stoi(input);
    }else{
        cout << "Invalid Input" << endl;
        continue;
    }

    if(list.find(tempMap[option].getCourseName()) == list.end()){
        cout << "Invalid Input" << endl;
    }

    Course c = list[tempMap[option].getCourseName()];

    for(auto it = c.getGradeList().begin();it != c.getGradeList().end();it++){
        while(true){
        cout << "Enter New Grade for " << studentList[it ->first].getName() << endl;
        string in;
        cin >> in;
        if(in.size() != 1){
            cout << "Invalid Input" << endl;
            continue;
        }

        if(in.compare("a") == 0 || in.compare("A") == 0){
            list[tempMap[option].getCourseName()].getGradeList()[studentList[it ->first].getID()] = 'A';
        }else if(in.compare("b") == 0 || in.compare("B") == 0){
            list[tempMap[option].getCourseName()].getGradeList()[studentList[it ->first].getID()] = 'B';
        }else if(in.compare("c") == 0 || in.compare("C") == 0){
            list[tempMap[option].getCourseName()].getGradeList()[studentList[it ->first].getID()] = 'C';
        }else if(in.compare("d") == 0 || in.compare("D") == 0){
            list[tempMap[option].getCourseName()].getGradeList()[studentList[it ->first].getID()] = 'D';
        }else if(in.compare("f") == 0 || in.compare("F") == 0){
            list[tempMap[option].getCourseName()].getGradeList()[studentList[it ->first].getID()] = 'F';
        }else{
            cout << "Invalid Input" << endl;
            continue; 
        }


        break;
        }
    }
    
    break;
 }
    cout << "Grades Updated" << endl;
}

