#include "staff.h"
#include <iostream>
using namespace std;

// accepts user input, creates new class, and adds to master class list 
void Staff::addClass(map<string,Course>& courseList,map<string,Faculty>& facultyList){
    Course c;
    string input;
   while(true){
    input = "";
    cout << "Enter Course Name" << endl;
    cin.ignore();
    getline(cin,input,'\n');
    
    string trimInput;
    for(int x = 0; x < input.size();x++){
        if(input.at(x) >= 'a' && input.at(x) <= 'z'){
            trimInput += toupper(input.at(x));
        }else{
            trimInput += input.at(x);
        }
    }

    input = trimInput;

    if(courseList.find(input) != courseList.end()){
        cout << "Course Already Exists" << endl;
        continue;
    }

    break;
   }
   c.setCourseName(input);
   while(true){
       input = "";
       cout <<"Enter number of units" << endl;
       cin >> input;
        bool valid = true;
        for(int x = 0; x < input.size();x++){
            if(input.at(x) < '0' || input.at(x) > '9'){
                valid = false;
            }
        }
       
       if(valid == false){
           cout << "Invalid input" << endl;
           continue;
       }
        break;
   }
   c.setCredits(stoi(input));

   while(true){
       input = "";
       cout << "Input Instructor ID number" << endl;
       cin >> input;
       bool valid = true;
        for(int x = 0; x < input.size();x++){
            if(input.at(x) < '0' || input.at(x) > '9'){
                valid = false;
            }
        }
       
       if(valid == false){
           cout << "Invalid Input" << endl;
           continue;
       }
   
       if(facultyList.find(input) == facultyList.end()){
           cout << "Couldn't find instructor" << endl;
           continue;
       }
       break;
   
   }
   c.setInstructor(facultyList[input].getName());
   courseList[c.getCourseName()] = c;
   cout << c.getCourseName() << " created." << endl;
}
//accepts user input, checks if student exists, and then returns the id of the student
string Staff::generateReport(map<string,Student>& studentList){
        string input;
    while(true){
        input = "";
        cout << "Enter the Student ID of the Student you wish to generate a report of" << endl;
        cin >> input;
        bool valid = true;
        for(int x = 0; x < input.size();x++){
            if(input.at(x) < '0' || input.at(x) > '9'){
                valid = false;
            }
        }

        if(valid == false){
            cout << "Invalid Input" << endl;
            continue;
        }


        if(studentList.find(input) == studentList.end()){
            cout << "Couldn't find student" << endl;
            continue;
        }

        break;
    }
    return input;
}