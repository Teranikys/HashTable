//
// Created by Влад on 27.09.2023.
//

#include "entry.h"
#include "iostream"


entry::entry(int recordBookNumber,
             int groupNumber,
             const string &name) :
        recordBookNumber(recordBookNumber),
        groupNumber(groupNumber),
        name(name) {
    this->recordBookNumber = recordBookNumber;
    this->groupNumber = groupNumber;
    this->name = name;
}

int entry::getRecordBookNumber() const {
    return recordBookNumber;
}

void entry::setRecordBookNumber(int inputRecordBookNumber) {
    entry::recordBookNumber = inputRecordBookNumber;
}

int entry::getGroupNumber() const {
    return groupNumber;
}

void entry::setGroupNumber(int inputGroupNumber) {
    entry::groupNumber = inputGroupNumber;
}

const string &entry::getName() const {
    return name;
}

void entry::setName(const string &inputName) {
    entry::name = inputName;
}

ostream &operator<<(ostream &os, const entry &out) {
    os << "{RecordBookNumber=" << out.getRecordBookNumber() << ", ";
    os << "GroupNumber=" << out.getGroupNumber() << ", ";
    os << "Name=" << out.getName() << "}";
    return os;
}

istream &operator>>(istream &is, entry &in) {
    is >> in.name;
    is >> in.recordBookNumber;
    is >> in.groupNumber;
    return is;
}


