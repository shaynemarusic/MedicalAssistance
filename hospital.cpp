
#include "hospital.h"
hospital::hospital::hospital(string& name, string& oldName) {
    this->name = name;
    this->number = 0;
    this->oldName = oldName;
    this->city = "";
    this->state = "";
    this->facilityType = "";
    this->ratingOverall = "";
//vectors are automatically empty so no need to do anything for them
}
hospital::hospital::hospital() {
    this->name = "";
    this->number = 0;
    this->oldName = "";
    this->city = "";
    this->state = "";
    this->facilityType = "";
    this->ratingOverall = "";
//vectors are automatically empty so no need to do anything for them
}

void hospital::hospital::setString(string &stringData, const string& category) {
    if (category=="name") {
        this->name = stringData;
    } else if (category=="city") {
        this->city = stringData;
    } else if (category=="facility") {
        this->facilityType = stringData;
    } else if (category=="overallrating") {
        if (stringData != "-1") {
            this->ratingOverall = stringData;
        } else {
            this->ratingOverall = "No rating";
        }
    } else if (category=="state") {
        this->state = stringData;
    }
}

void hospital::hospital::setVector(vector<string> &vectorData, const string& category) {
    if (category=="heartattack") {
        for (int i = 0; i < vectorData.size(); i++) {
            this->heartAttackData.push_back(vectorData.at(i));
        }
    } else if (category=="heartfailure") {
        for (int i = 0; i < vectorData.size(); i++) {
            this->heartFailureData.push_back(vectorData.at(i));
        }
    } else if (category=="pneumonia") {
        for (int i = 0; i < vectorData.size(); i++) {
            this->pneumoniaData.push_back(vectorData.at(i));
        }
    } else if (category=="hipknee") {
        for (int i = 0; i < vectorData.size(); i++) {
            this->hipkneeData.push_back(vectorData.at(i));
        }
    } else if (category=="ratings") {
        for (int i = 0; i < vectorData.size(); i++) {
            this->ratingsData.push_back(vectorData.at(i));
        }
    }
}

string hospital::hospital::returnString(const string& category) {
    if (category=="name") {
        return this->name;
    } else if (category=="city") {
        return this->city;
    } else if (category=="facility") {
        return this->facilityType;
    } else if (category=="overallrating") {
        return this->ratingOverall;
    } else if (category=="state") {
        return this->state;
    }
    return "";
}