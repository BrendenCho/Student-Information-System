#include <string>
using namespace std;
#ifndef USER
#define USER


class User{
     private:
        string role;
        string name;
        string id;
        bool isAuthenticated = false;
    public:
       void setRole(string);
       void setName(string);
       void setID(string);
       void setAuthenticated(bool);
       string getRole();
       string getName();
       string getID();
       bool getAuthenticated();
};

#endif
