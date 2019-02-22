#include "person.h"
#include <string> 

using namespace std;

string person::getFirstName(){
    return firstName;
}

void person::setLastName(string Lname){
    lastName = Lname;
}

string person::getLastName(){
    return lastName;
}

void person::setFirstName(string fName){
    firstName = fName;
}

void person::setPayRate(float rate){
    payRate = rate;
}

float person::getPayRate(){
    return payRate;
}

void person::setHoursWorked(float hours){
    hoursWorked = hours;
    return;
}

float person::getHoursWorked(){
    return hoursWorked;
}

float person::totalPay(){
    int total;
    total = hoursWorked * payRate;
    return total;
}

string person::fullName(){
    string fullName =firstName + " " +lastName;
    return fullName;
}

person::person(){
    
}