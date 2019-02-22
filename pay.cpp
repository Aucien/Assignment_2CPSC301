#include "person.cpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int aSize = 0;

void readData(person list[],int size){
    ifstream myFile;
    myFile.open("input.txt");
    int iterator = 0;
    string lName;
    string fName;
    float hours;
    float rate;
    string line;

    if(myFile){
        myFile >> fName;
        while(!myFile.eof()){
            myFile >> lName >> hours >> rate;
            getline(myFile, line);
            list[iterator].setFirstName(fName);
            list[iterator].setLastName(lName);
            list[iterator].setHoursWorked(hours);
            list[iterator].setPayRate(hours);
            iterator++;
            aSize++;
            myFile >> fName;
        }
    }
    myFile.close();
}

void writeData(person list[], int size){
    
    ofstream ofs("output.txt");
    string Name;
    float total;
    if(ofs){
        for (int x = 0; x < aSize; x++){
            Name = list[x].fullName();
            total = list[x].totalPay();
            ofs << Name << " " << total << endl;
            cout << Name << " " << total << endl;
        }
        ofs.close();
    }
}

int main(){
    int size = 20;
    person list[size];
    readData(list, size);
    writeData(list, size);
    return 0;
}