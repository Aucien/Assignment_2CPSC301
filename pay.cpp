//Gordon Dan
//889330353
#include "person.cpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

void mainMenu(){
    cout << "Please choose an option" << endl;
    cout << " 1. Read data" << endl;
    cout << " 2. Write data" << endl;
    cout << " 3. Close Program" << endl;
}

void readData(vector <person> &list){
    ifstream myFile;
    myFile.open("input.txt");
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
            list.emplace_back(fName, lName, rate, hours);
            myFile >> fName;
        }
    }
    myFile.close();
}

void writeData(vector <person> &list){
    
    ofstream ofs("output.txt");
    string Name;
    float total;
    if(ofs){
        for (int x = 0; x < list.size(); x++){
            Name = list[x].fullName();
            total = list[x].totalPay();
            ofs << Name << " " << total << endl;
            cout << Name << " " << total << endl;
        }
        ofs.close();
    }
}

int main(){
    int choice;
    vector <person> list;
    do{
        mainMenu();
        cin >> choice;
        switch(choice){
            case 1:
                cout << endl;
                readData(list);
                break;
            case 2:
                cout << endl;
                if(list.size() != 0){
                    cout << "Creating/Updating out.txt" << endl;
                    writeData(list);
                }
                else{
                    cout << "Error: Did not do readData" << endl;
                }
                break;
            case 3:
                cout << endl;
                cout << "Creating/Updating out.txt" << endl;
                writeData(list);
                cout << "Program is closing..." << endl;
                break;
        }
    }
    while(choice != 3);
    return 0;
}