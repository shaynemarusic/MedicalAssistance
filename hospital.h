#pragma once
#include <string>
#include <vector>
using namespace std;
class hospital {
private:
    string name, city,state,facilityType, ratingOverall, oldName;
    int number;
    vector<string> heartAttackData, heartFailureData, pneumoniaData, hipkneeData, ratingsData;
public:
    hospital();
    hospital(string& name, string& oldName);
    void setString(string& stringData, const string& category);
    void setVector(vector<string>& vectorData, const string& category);
    string returnString(const string& category);
};