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
*/
/*
allows creates a network
for users profiles.
*/
#include <iostream>
#include <cctype>
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
class Network{
private:
    static const int MAX_USERS = 20;
    int numUsers;
    Profile profiles[MAX_USERS];

    int findID(string usrn);
public:
    Network();
    bool addUser(string usrn, string dspn);
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
Profile::Profile(){
    username = "";
    displayname = "";
}
Profile::Profile(string usrn, string dspn){
    username = usrn;
    displayname = dspn;
}
void Profile::setDisplayName(string dspn){
    displayname = dspn;
}

int Network::findID(string usrn){
    for (int i = 0; i < MAX_USERS; i++){
        if (profiles[i].getUsername() == usrn){
            return i;
        }
    }
    return -1;
}
Network::Network(){
    numUsers = 0;
}
bool Network::addUser(string usrn, string dspn){
    for (int i = 0; i < usrn.length(); i++){
        if (isspace(usrn[i])){
            return false;
        }
        else if ((isalpha(usrn[i]) == false) and (isdigit(usrn[i])==false)){
            return false;
        }
    }
    if ( numUsers >= 20){
        return false;
    }
    for (int i = 0; i < MAX_USERS; i++ ){
        if (usrn == profiles[i].getUsername()){
            return false;
        }
    }
    profiles[numUsers] = {usrn, dspn};
    numUsers += 1;
    return true;
}
int main() {
  Network nw;
  cout << nw.addUser("mario", "Mario") << endl;     
  cout << nw.addUser("luigi", "Luigi") << endl;     

  cout << nw.addUser("mario", "Mario2") << endl;    
  cout << nw.addUser("mario 2", "Mario2") << endl;  
  cout << nw.addUser("mario-2", "Mario2") << endl;  

  for(int i = 2; i < 20; i++)
      cout << nw.addUser("mario" + to_string(i),
                 "Mario" + to_string(i)) << endl;   

  cout << nw.addUser("yoshi", "Yoshi") << endl;   
}