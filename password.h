#include <fstream>
#include <iostream>
#include <string>
using namespace std;
#ifndef PASSWORD
#define PASSWORD

class Password{
    public:
        bool checkLogin(string,string);
        string getRole();
        string getID();
    private:
        ifstream inFile;
        void openFile();
        bool parseFile(string,string);
        void closeFile();
        void eraseAll();
        string role,id;
};

#endif