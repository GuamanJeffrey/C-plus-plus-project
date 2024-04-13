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
#include <vector>
using namespace std; 
int main() {
    string line, leftpart;
    string rightpart;
    int size;
    double ans;
    double correct = 0;
    vector <pair<string, double>> data;
    srand(time(0));
    string fileName = "problems.csv";
    ifstream fin(fileName);
    while(getline(fin,leftpart, ',') && getline(fin, rightpart)){
        data.push_back(make_pair(leftpart, stof(rightpart)));
    }
    fin.close();
    size = data.size();
    int isize = size;
    for (int i = 0; i < size; i++){
        int index = rand() % isize;
        cout << "("<< i + 1 << ") what is " << data[index].first << "? ";
        cin >> ans;
        if (ans == data[index].second){
            correct += 1;
            cout << "True \n";
        }
        else if (ans != data[index].second){
            cout << "False \n";
        }
        double grade = (correct / size) * 100;
        swap(data[index], data[isize - 1]);
        isize -= 1;
        if (grade >= 60){
            cout << "At least 60% is correct. Stop." << endl;
            break;
        }
        else if(isize == 0){
            break;
        }
    }
    double grade = (correct / size) * 100;
    cout << "percentage correct: " << grade << "%" << endl;
}
