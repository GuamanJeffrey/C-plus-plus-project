// Author: Jeffrey Guaman
// Course: CSCI-135
// Instructor: Tong Yi
// Assignment: Project 1A
#include <iostream>
#include <cstdlib>
using namespace std; 
int main() {
    char x[5];
    x[0] = '+';
    x[1] = '-';
    x[2] = '*';
    x[3] = '/';
    x[4] = '%';
    int set1 = rand() % 5 + 0;
    int set2 = rand() % 10 + 0;
    int set3 = rand() % 9 + 1;
    int number1 = set2;
    char operation = x[set1];
    int question;
    if ((operation == '%') or (operation == '/')) {
        int number2 = set3;
        cout << "What is " << number1 << " " << operation << " " << number2 << "? \n";
        cin >> question;
        if (operation == '%'){
            if (question == number1 % number2){
                cout << "True";
            }
            else {
                cout << "False";
            }
        }
        else if (operation == '/'){
            if (question == number1 / number2){
                cout << "True";
            }
            else {
                cout << "False";
        }
        }
    }
    else{
        int number2 = set2;
        cout << "What is " << number1 << " " << operation << " " << number2 << "? \n";
        cin >> question;
        if (operation == '+') {
            if (question == number1 + number2){
                cout << "True";
            }
            else {
                cout << "False";
            }
        }
        else if (operation == '-'){
            if (question == number1 - number2){
                cout << "True";
            }
            else{
                cout << "False";
            }
        }
        else if (operation == '*') {
            if (question == number1 * number2){
                cout << "True";
            }
            else{
                cout << "False";
            }
        }
    }
}