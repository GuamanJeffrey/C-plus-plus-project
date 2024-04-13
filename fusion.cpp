/*
Author: Jeffrey Guaman
Course: CSCI-135
*/

/*
Instructor: Tong Yi
Assignment: Lab 12A
*/

/*
the 
p
rogram 
allows users to
*/
/*
w
r
*/
/*
i
t
e
*/
#include <iostream>
#include <vector>
using namespace std;

void gogeta(vector<int> &goku, vector<int> &vegeta){
    for (auto index = 0; index < vegeta.size(); index++){
        goku.push_back(vegeta[index]);
    }
    vegeta.erase(vegeta.begin(), vegeta.end());
}