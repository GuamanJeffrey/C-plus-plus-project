// Author: Jeffrey Guaman
// Course: CSCI-135
// Instructor: Tong Yi
// Assignment: Project 1B
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std; 
int main() {
    srand(time(NULL));
    char x[5];
    x[0] = '+';
    x[1] = '-';
    x[2] = '*';
    x[3] = '/';
    x[4] = '%';
    int number_questions;
    double truth;
    truth = 0;
    cout << "Enter total number of questions to ask: ";
    cin >> number_questions;
    while (number_questions <= 0){
        cout << "The number of questions cannot be zero or negative. Re-enter: ";
        cin >> number_questions;
    }
    cout << endl;
    int counter = 0;
    while (counter < number_questions){
        counter += 1;
        int set1 = rand() % 5 + 0;
        int set2 = rand() % 10 + 0;
        int set3;
        int number1 = set2;
        char operation = x[set1];
        int question;
        if ((operation == '%') or (operation == '/')) {
            int number2 = rand() % 9 + 1;
            cout << "(" << counter << ") " << "What is " << number1 << " " << operation << " " << number2 << "? ";
            cin >> question;
            if (operation == '%'){
                if (question == number1 % number2){  
                    cout << "true \n";
                    truth += 1;
                }
                else {
                    cout << "false \n";
                }
            }
            else if (operation == '/'){
                if (question == number1 / number2){
                    cout << "true \n";
                    truth += 1;
                }
                else {
                    cout << "false \n";
            }
            }
        }
        else{
            int number2 = rand() % 10;
            cout << "(" << counter << ") " << "What is " << number1 << " " << operation << " " << number2 << "? ";
            cin >> question;
            if (operation == '+') {
                if (question == number1 + number2){
                    cout << "true \n";
                    truth += 1;
                }
                else {
                    cout << "false \n";
                }
            }
            else if (operation == '-'){
                if (question == number1 - number2){
                    cout << "true \n";
                    truth += 1;
                }
                else{
                    cout << "false \n";
                }
            }
            else if (operation == '*') {
                if (question == number1 * number2){
                    cout << "true \n";
                    truth += 1;
                }
                else{
                    cout << "false \n";
                }
            }
        }
    }
    double grade = (truth / number_questions) * 100;
    cout << "percentage correct: " << grade << "%" << endl;
    if (grade >= 90 ){
        cout << "letter grade: A";
    }
    else if ((grade < 90) and (grade >= 80)){
        cout << "letter grade: B";
    }
    else if ((grade < 80) and (grade >= 70)){
        cout << "letter grade: C";
    }
    else if (grade >= 60){
        cout << "letter grade: D";
    }
    else{
        cout << "letter grade: F";
    }
}