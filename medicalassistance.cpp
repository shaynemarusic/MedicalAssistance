#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include "hospitalList.h"
using namespace std;

int main() {
    hospitalList listOfHospitals;
    bool valid = false;
    string firstSelection, secondSelection;
    cout << "Welcome to Medical Assistance's Care Rec Tool\n"
            "---------------------------------------------\n"
            "1) Make a Recommendation\n"
            "2) Print Database\n"
            "3) Exit"<<endl;
    cout << "---------------------------------------------\n";
    while (!valid) {
        cout << "Please make a selection:" << endl;
        cin >> firstSelection;
        if (firstSelection.compare("1")==0||firstSelection.compare("2")==0||firstSelection.compare("3")==0) {
            valid = true;
            break;
        }
        cout << "Invalid selection."<<endl;
    }
    fstream file("hospitals.csv");

    //timing system from https://stackoverflow.com/questions/12231166/timing-algorithm-clock-vs-time-in-c
    auto t1 = std::chrono::high_resolution_clock::now();
    string data, placeholder;
    getline(file, placeholder);
    while (getline(file, data)) {
    stringstream categories(data);
    vector<string> tempData;
    string name, oldName, data2;
    //name
    getline(categories, name, ',');
    name = name.substr(1, name.size()-2);
    oldName = name;
    name = listOfHospitals.initializeHospital(name, oldName);
    //city
    getline(categories, data2, ',');
    data2 = data2.substr(1, data2.size()-2);
    listOfHospitals.setHospitalDataString(name, data2, "city");
    //state
    getline(categories, data2, ',');
    data2 = data2.substr(1, data2.size()-2);
    listOfHospitals.setHospitalDataString(name, data2, "state");
    //facility type
    getline(categories, data2, ',');
    data2 = data2.substr(1, data2.size()-2);
    listOfHospitals.setHospitalDataString(name, data2, "facility");
    //overall rating
    getline(categories, data2, ',');
    data2 = data2.substr(1, data2.size()-2);
    listOfHospitals.setHospitalDataString(name, data2, "overallrating");
    //other ratings data
    for (int i = 0; i < 7; i++) {
        getline(categories, data2, ',');
        data2 = data2.substr(1, data2.size()-2);
        tempData.push_back(data2);
    }
    tempData.clear();
    listOfHospitals.setHospitalDataVector(name, tempData, "overallrating");
    //heart attack data
    for (int i = 0; i < 3; i++) {
        getline(categories, data2, ',');
        data2 = data2.substr(1, data2.size()-2);
        tempData.push_back(data2);
    }
    tempData.clear();
    listOfHospitals.setHospitalDataVector(name, tempData, "heartattack");
    //heart failure data
    for (int i = 0; i < 3; i++) {
        getline(categories, data2, ',');
        data2 = data2.substr(1, data2.size()-2);
        tempData.push_back(data2);
    }
    tempData.clear();
    listOfHospitals.setHospitalDataVector(name, tempData, "heartfailure");
    //pneumonia data
    for (int i = 0; i < 3; i++) {
        getline(categories, data2, ',');
        data2 = data2.substr(1, data2.size()-2);
        tempData.push_back(data2);
    }
    tempData.clear();
    listOfHospitals.setHospitalDataVector(name, tempData, "pneumonia");
    //hip/knee data
    for (int i = 0; i < 3; i++) {
        getline(categories, data2, ',');
        data2 = data2.substr(1, data2.size()-2);
        tempData.push_back(data2);
    }
    listOfHospitals.setHospitalDataVector(name, tempData, "hipknee");
    tempData.clear();
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    //calculate time taken to initially create all hospital objects in seconds
    cout << "Initial database loaded in " <<chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() <<" milliseconds." <<endl;
    cout << "---------------------------------------------\n";
    cout << "Which of these criteria is important to you?\n"
            "1) Location\n"
            "2) Cost of Care\n"
            "3) Patient Ratings\n"
            "4) Timeliness\n"
            "5) Publicly or Privately Owned\n"
            "6) Safety\n"
            "---------------------------------------------"<<endl;
    cout << "Please make a selection:" << endl;
    valid = false;
    while (!valid) {
        cin >> secondSelection;
        if (secondSelection.compare("1")==0||secondSelection.compare("2")==0||secondSelection.compare("3")==0||secondSelection.compare("4")==0||secondSelection.compare("5")==0||secondSelection.compare("6")==0) {
            valid = true;
            break;
        }
        cout << "Invalid selection."<<endl;
    }
    for (auto & l : listOfHospitals.accessList()) {
        cout << l.second.returnString("name") <<" " << l.second.returnString("city") <<" "<<l.second.returnString("state")<< " " <<l.second.returnString("facility") << " " << l.second.returnString("overallrating") << endl;
    }
}