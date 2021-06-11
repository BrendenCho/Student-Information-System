#include "password.h"
#include <cstdlib>
#include <iostream>
using namespace std;
// returns if password and username match records
bool Password::checkLogin(string userName,string password){
    
    openFile();
    if(parseFile(userName,password) == true){
        closeFile();
        return true;
    }
    closeFile();
    
    return false;
}
// opens input file
void Password::openFile(){
    inFile.open("users.csv");
    if(inFile.fail()){
        cout <<"users.csv failed to open" << endl;
        exit(1);
    }
}
// checks username and password aginst info found in file
bool Password::parseFile(string username,string password){
    string temp = "";
    
    while(getline(inFile,temp,'\n')){
        bool match = false;    
        bool secondMatch = false;
        int index = 0; 
        for(int x = 0; x < 5;x++){
            string parsedData ="";
            while(index < temp.size() && temp.at(index) != ','){
                parsedData += temp.at(index);
                index++;
            }
            if(x == 0){
                id = parsedData;
            }else if(x == 1){
                if(username.compare(parsedData) == 0){
                    match = true;
                }
            }else if(x == 3 && match == true){
                if(password.compare(parsedData) == 0){
                    secondMatch = true;
                }
            }else if (x == 4){
                role = parsedData;
            }

           


            index++; 
        }

         if(match == true && secondMatch == true){
                return true;
         }
        temp = "";
    }
    eraseAll();
    return false;
}
//closes file
void Password::closeFile(){
    inFile.close();
}
//getters
string Password::getRole(){
    return role;
}

string Password::getID(){
    return id;
}
//utility function
void Password::eraseAll(){
    role = id  = "";
}