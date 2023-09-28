//
// Created by Влад on 28.09.2023.
//

#include "Node.h"

Node::Node(int key, entry value) {
    this->key = key;
    this->value = std::move(value);
    this->next = nullptr;

}
