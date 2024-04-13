// Author: Jeffrey Guaman
// Course: CSCI-135
// Instructor: Tong Yi
// Assignment: Project 1C
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <climits>
#include <string>
using namespace std; 
int main() {
    string fileName = "problems.csv";
    ifstream fin(fileName);
    string txt;
    string ans;
    double grade;
    double numQuestions = 0;
    double numCorrect = 0;
    double answer;
    while (getline(fin, txt, ',') && getline(fin, ans)){
        cout << txt;
        cout << " ? ";
        cin >> answer;
        double real = stof(ans);
        if (answer == real){
            numCorrect += 1;
            cout << "True \n";
        }
        else if (answer != stof(ans)){
            cout << "False \n";
        }
        numQuestions += 1;
    }
    grade = (numCorrect / numQuestions) * 100;
    cout << "percent: " << grade << endl;
    if (grade >= 90 ){
        cout << "Letter grade: A";
    }
    else if ((grade < 90) and (grade >= 80)){
        cout << "Letter grade: B";
    }
    else if ((grade < 80) and (grade >= 70)){
        cout << "Letter grade: C";
    }
    else if ((grade < 70) and (grade >= 60)){
        cout << "Letter grade: C";
    }
    else{
        cout << "Letter grade: F";
    }

}
