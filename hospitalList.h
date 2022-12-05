#pragma once
#include <unordered_map>
#include <map>
#include "hospital.h"
class hospitalList {
private:
    vector<pair<string, hospital>> mainList;
public:
    void setHospitalDataString(string& name, string& stringData, const string& category);
    string initializeHospital(string& name, string& oldName);
    vector<pair<string, hospital>> accessList();
};