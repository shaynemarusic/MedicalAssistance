#pragma once
#include <string>
#include <vector>
using namespace std;
class hospital {
private:
    string name, city,state,facilityType, oldName;
    int number, ratingOverall,heartAttackCost, heartFailureCost, pneumoniaCost, hipkneeCost, timelinessRating, safetyRating;
public:
    hospital();
    hospital(string& name, string& oldName);
    void setString(string& stringData, const string& category);
    string returnString(const string& category);
};