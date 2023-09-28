//
// Created by Влад on 28.09.2023.
//

#ifndef SIAOD_3_NODE_H
#define SIAOD_3_NODE_H


#include "entry.h"

class Node {
public:
    int key;
    entry value;
    Node *next;

    Node(int key, entry value);
};


#endif //SIAOD_3_NODE_H
