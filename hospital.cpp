
#include "hospital.h"
hospital::hospital::hospital(string& name, string& oldName) {
    this->name = name;
    this->number = 0;
    this->oldName = oldName;
    this->city = "";
    this->state = "";
    this->facilityType = "";
    //placeholder until rating is set
    this->ratingOverall = 0;
//vectors are automatically empty so no need to do anything for them
}
hospital::hospital::hospital() {
    this->name = "";
    this->number = 0;
    this->oldName = "";
    this->city = "";
    this->state = "";
    this->facilityType = "";
    this->ratingOverall = 0;
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
            this->ratingOverall = stoi(stringData);
        } else {
            //no data
            this->ratingOverall = -1;
        }
    } else if (category=="state") {
        this->state = stringData;
    } else if (category=="heartattack") {
        this->heartAttackCost = stoi(stringData);
    } else if (category=="heartfailure") {
        this->heartFailureCost = stoi(stringData);
    } else if (category=="pneumonia") {
        this->pneumoniaCost = stoi(stringData);
    } else if (category=="hipknee") {
        this->hipkneeCost = stoi(stringData);
    } else if (category=="timeliness") {
        if (stringData=="Above") {
            this->timelinessRating = 3;
        } else if (stringData=="Below") {
            this->timelinessRating = 1;
        } else if (stringData=="Same") {
            this->timelinessRating = 2;
        } else if (stringData=="None") {
            this->timelinessRating = 0;
        }
    } else if (category=="safety") {
        if (stringData=="Above") {
            this->safetyRating = 3;
        } else if (stringData=="Below") {
            this->safetyRating = 1;
        } else if (stringData=="Same") {
            this->safetyRating = 2;
        } else if (stringData=="None") {
            this->safetyRating = 0;
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
        return to_string(this->ratingOverall);
    } else if (category=="state") {
        return this->state;
    } else if (category=="heartattack") {
        return to_string(this->heartAttackCost);
    } else if (category=="heartfailure") {
        return to_string(this->heartFailureCost);
    } else if (category=="pneumonia") {
        return to_string(this->pneumoniaCost);
    } else if (category=="hipknee") {
        return to_string(this->hipkneeCost);
    } else if (category=="timeliness") {
        return to_string(this->timelinessRating);
    } else if (category=="safety") {
        return to_string(this->safetyRating);
    }
    return "";
}