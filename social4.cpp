/*
Author: Jeffrey Guaman
Course: CSCI-135
*/

/*
Instructor: Tong Yi
Assignment: Lab 10C
*/

/*
the 
program 
allows users to
*/
/*
write posts 
and 
*/
/*
then 
check the timestream
*/
#include <iostream>
#include <cctype>
using namespace std;
struct Post{
    string username;
    string message;
};
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
    static const int MAX_POSTS = 100;
    int numPosts;
    Post posts[MAX_POSTS];

public:
    Network();
    bool addUser(string usrn, string dspn);

    bool follow(string usrn1, string usrn2);

    void printDot();
    bool writePost(string usrn, string msg);

    bool printTimeline(string usrn);
};
bool Network::writePost(string usrn, string msg){
    bool x = false;
    if (numPosts >= 100){
        return false;
    }
    for (int i = 0; i < MAX_USERS; i++){
        if (profiles[i].getUsername() == usrn){
            x = true;
        }
    }
    if (x == false){
        return false;
    }
    posts[numPosts] = {usrn,msg};
    Network::numPosts++;
    return true;
}
bool Network::printTimeline(string usrn){
    int x = findID(usrn);
    for (int i = numPosts; i > -1; i--){
        int index = findID(posts[i].username);
        if (posts[i].username == usrn){
                cout << profiles[x].getFullName() << ": " << posts[i].message << endl;
            }
        else if (following[x][index] == true){
            cout << profiles[index].getFullName() << ": " << posts[i].message << endl;
        }
    }
    return true;
}
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
    numPosts = 0;
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
   
  nw.follow("mario", "luigi");
  nw.follow("luigi", "mario");
  nw.follow("luigi", "yoshi");
  nw.follow("yoshi", "mario");

  // write some posts
  nw.writePost("mario", "It's a-me, Mario!");
  nw.writePost("luigi", "Hey hey!");
  nw.writePost("mario", "Hi Luigi!");
  nw.writePost("yoshi", "Test 1");
  nw.writePost("yoshi", "Test 2");
  nw.writePost("luigi", "I just hope this crazy plan of yours works!");
  nw.writePost("mario", "My crazy plans always work!");
  nw.writePost("yoshi", "Test 3");
  nw.writePost("yoshi", "Test 4");
  nw.writePost("yoshi", "Test 5");

  cout << endl;
  cout << "======= Mario's timeline =======" << endl;
  nw.printTimeline("mario");
  cout << endl;

  cout << "======= Yoshi's timeline =======" << endl;
  nw.printTimeline("yoshi");
  cout << endl;
}