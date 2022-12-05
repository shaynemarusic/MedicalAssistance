#pragma once
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;
class hospitalList {
private:
    class hospital {
    private:
        string name, city,facilityType, ratingOverall;
        vector<string> heartAttackData, heartFailureData, pneumoniaData, hipkneeData;
    public:
        hospital();
        void setString(string& stringData, string& category);
        void setVector(vector<string>& vectorData, string& category);
    };
    unordered_map<string, hospital> mainList;
public:
    void setHospital(vector<string>& hospitalData);
};