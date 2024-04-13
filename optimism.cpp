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

vector<int> goodVibes(const vector<int> v){
    vector<int> x;
    for (auto index = 0; index < v.size(); ++index){
        if (v[index] > 0){
            x.push_back(v[index]);
        }
    }
    return x;
}