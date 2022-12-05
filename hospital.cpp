
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
    } else if (category=="heartattack") {
        this->heartAttackCost = stringData;
    } else if (category=="heartfailure") {
        this->heartFailureCost = stringData;
    } else if (category=="pneumonia") {
        this->pneumoniaCost = stringData;
    } else if (category=="hipknee") {
        this->hipkneeCost = stringData;
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
    } else if (category=="heartattack") {
        return this->heartAttackCost;
    } else if (category=="heartfailure") {
        return this->heartFailureCost;
    } else if (category=="pneumonia") {
        return this->pneumoniaCost;
    } else if (category=="hipknee") {
        return this->hipkneeCost;
    }
    return "";
}