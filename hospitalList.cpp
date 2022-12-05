#include "hospitalList.h"

void hospitalList::setHospitalDataString(string& name, string &stringData, const string& category) {
    for (auto &i :mainList) {
        if (i.second.returnString("name")==name) {
            i.second.setString(stringData, category);
        }
    }
}

string hospitalList::initializeHospital(string &name) {
    for (auto &i :mainList) {
        if (i.second.returnString("name")==name) {
            for (int j = 2; j < 1000; j++) {
                string newName = name + " (" + to_string(j) + ")";
                bool isFound = false;
                for (auto &k: mainList) {
                    if (k.second.returnString("name") == newName) {
                        isFound = true;
                    }
                }
                if (!isFound) {
                    mainList[newName] = (hospital(newName, name));
                    mainList[newName].setString(to_string(j), "number");
                    return newName;
                }
            }
        }
    }
    mainList[name] = (hospital(name,name));
    return name;
}

unordered_map<string,hospital> hospitalList::accessList() {
    return this->mainList;
}

void hospitalList::initializeAverageCosts() {
    for (auto &i : mainList) {
        i.second.setString("", "average");
    }
}

void hospitalList::pushHospital(hospital newHospital) {
    mainList[newHospital.returnString("name")] = newHospital;
}
