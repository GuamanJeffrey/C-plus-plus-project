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
    bool following[MAX_USERS][MAX_USERS];
    int numUsers;
    Profile profiles[MAX_USERS];

    int findID(string usrn);
public:
    Network();
    bool addUser(string usrn, string dspn);

    bool follow(string usrn1, string usrn2);

    void printDot();
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
    for (int i = 0; i < MAX_USERS; i++){
        for (int j = 0; i < MAX_USERS; i++){
            following[i][j] = false;
        }
    }
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

bool Network::follow(string usrn1, string usrn2){
    if (Network::findID(usrn1) == -1 || Network::findID(usrn2) == -1){
        return false;
    }
    following[Network::findID(usrn1)][Network::findID(usrn2)] = true;
    return true;
}
void Network::printDot(){
    cout << "digraph {" << endl;
    for (int i = 0; i < Network::numUsers; i++){
        cout << "  \"@" << profiles[i].getUsername() << "\"" << endl;
    }
    for (int i = 0; i < MAX_USERS; i++){
        for (int j = 0; j < MAX_USERS; j++){
            if (following[i][j] == true && profiles[i].getUsername().length() > 3){
                cout << "  \"@" << profiles[i].getUsername() << "\"" << " -> \"@" << profiles[j].getUsername() << "\"" << endl;
            }
        }
    }
    cout << "}" << endl;
}
int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi"); 

    nw.printDot();
}