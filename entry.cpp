//
// Created by Влад on 27.09.2023.
//

#include "entry.h"


entry::entry(int recordBookNumber,
             int groupNumber,
             const string& name) :
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

