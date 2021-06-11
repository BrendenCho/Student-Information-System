#include "user.h"
using namespace std;

//getters setters
void User::setRole(string role){
    this -> role = role;
}

void User::setName(string name){
    this ->name = name;
}

void User::setID(string id){
    this -> id = id;
}

void User::setAuthenticated(bool isAuthenticated){
    this ->isAuthenticated = isAuthenticated;
}

string User::getRole(){
    return role;
}

string User::getName(){
    return name;
}

string User::getID(){
    return id;
}

bool User::getAuthenticated(){
    return isAuthenticated;
}