#include "hospital.h"

void hospitalList::setHospital(vector<string>& hospitalData) {

}

hospitalList::hospital::hospital() {
    this->name = "";
    this->city = "";
    this->facilityType = "";
    this->ratingOverall = "";
//vectors are automatically empty so no need to do anything for them
}

void hospitalList::hospital::setString(string &stringData, string &category) {
    if (category=="name") {
        this->name = stringData;
    } else if (category=="city") {
        this->city = stringData;
    } else if (category=="facility") {
        this->facilityType = stringData;
    } else if (category=="overallrating") {
        this->ratingOverall = stringData;
    }
}

void hospitalList::hospital::setVector(vector<string> &vectorData, string &category) {
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
    }
}
