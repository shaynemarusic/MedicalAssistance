#pragma once
#include <string>
#include <vector>
using namespace std;
class hospital {
private:
    string name, city,state,facilityType, ratingOverall, oldName, heartAttackCost, heartFailureCost, pneumoniaCost, hipkneeCost;
    int number;
public:
    hospital();
    hospital(string& name, string& oldName);
    void setString(string& stringData, const string& category);
    string returnString(const string& category);
};