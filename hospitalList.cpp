#include "hospitalList.h"

void hospitalList::setHospitalDataString(string& name, string &stringData, const string& category) {
    for (auto &i :mainList) {
        if (i.returnString("name")==name) {
            i.setString(stringData, category);
        }
    }
}

string hospitalList::initializeHospital(string &name, string& oldName) {
    for (auto &i :mainList) {
        if (i.returnString("name")==name) {
            for (int j = 2; j < 1000; j++) {
                string newName = name + " (" + to_string(j) + ")";
                bool isFound = false;
                for (auto &k: mainList) {
                    if (k.returnString("name") == newName) {
                        isFound = true;
                    }
                }
                if (!isFound) {
                    mainList.push_back(hospital(newName, oldName));
                    return newName;
                }
            }
        }
    }
    mainList.push_back(hospital(name,oldName));
    return name;
}

vector<hospital> hospitalList::accessList() {
    return this->mainList;
}
