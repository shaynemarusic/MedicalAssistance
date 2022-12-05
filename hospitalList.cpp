#include "hospitalList.h"

void hospitalList::setHospitalDataString(string& name, string &stringData, const string& category) {
    for (auto &i :mainList) {
        if (i.first==name) {
            i.second.setString(stringData, category);
        }
    }
}

string hospitalList::initializeHospital(string &name, string& oldName) {
    for (auto &i :mainList) {
        if (i.first==name) {
            for (int j = 2; j < 1000; j++) {
                string newName = name + " (" + to_string(j) + ")";
                bool isFound = false;
                for (auto &k: mainList) {
                    if (k.first == newName) {
                        isFound = true;
                    }
                }
                if (!isFound) {
                    mainList.push_back(make_pair(newName, hospital(newName, oldName)));
                    return newName;
                }
            }
        }
    }
    mainList.push_back(make_pair(name,hospital(name,oldName)));
    return name;
}

vector<pair<string, hospital>> hospitalList::accessList() {
    return this->mainList;
}
