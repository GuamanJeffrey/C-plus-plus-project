/*
Author: Jeffrey Guaman
Course: CSCI-135
*/

/*
Instructor: Tong Yi
Assignment: Lab 10C
*/

/*
The 
program 
does
*/
#include <iostream>
using namespace std;

class Profile{
private:
    string displayname;
    string username;
public:
    Profile(string usrn, string dspn);

    Profile();
    string getUsername();
    string getFullName();
    void setDisplayName(string dspn);

};

string Profile::getUsername(){
    return username;
}

string Profile::getFullName(){
    string x = "";
    x += displayname;
    x += " (@";
    x += username;
    x += ")";
    return x;
}
Profile::Profile(string usrn, string dspn){
    username = usrn;
    displayname = dspn;
}
void Profile::setDisplayName(string dspn){
    displayname = dspn;
}

int main() {
    Profile p1("marco", "Marco");    
    cout << p1.getUsername() << endl; // marco
    cout << p1.getFullName() << endl; // Marco (@marco)

    p1.setDisplayName("Marco Rossi"); 
    cout << p1.getUsername() << endl; // marco
    cout << p1.getFullName() << endl; // Marco Rossi (@marco)
    
    Profile p2("tarma1", "Tarma Roving");    
    cout << p2.getUsername() << endl; // tarma1
    cout << p2.getFullName() << endl; // Tarma Roving (@tarma1)
}