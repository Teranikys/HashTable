//
// Created by Влад on 27.09.2023.
//

#ifndef SIAOD_3_ENTRY_H
#define SIAOD_3_ENTRY_H

#include "string"

using namespace std;

class entry {
    int recordBookNumber;
    int groupNumber;
    string name;
public:
    [[nodiscard]] int getRecordBookNumber() const;

    void setRecordBookNumber(int inputRecordBookNumber);

    [[nodiscard]] int getGroupNumber() const;

    void setGroupNumber(int inputGroupNumber);

    [[nodiscard]] const string &getName() const;

    void setName(const string &inputName);

    entry() : recordBookNumber(0), groupNumber(0), name(){};

    entry(int recordBookNumber, int groupNumber, const string& name);

    friend ostream &operator<<(ostream &os, const entry &out);

    friend istream &operator>>(istream &is, entry &in);

};


#endif //SIAOD_3_ENTRY_H
