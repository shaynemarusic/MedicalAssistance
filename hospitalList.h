#pragma once
#include <unordered_map>
#include <map>
#include "hospital.h"
class hospitalList {
public:
    unordered_map<string,hospital> mainList;
    void setHospitalDataString(string& name, string& stringData, const string& category);
    void initializeAverageCosts();
    string initializeHospital(string& name);
    void pushHospital(hospital newHospital);
    unordered_map<string,hospital> accessList();
};