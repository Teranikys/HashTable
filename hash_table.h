//
// Created by Влад on 27.09.2023.
//

#ifndef SIAOD_3_HASH_TABLE_H
#define SIAOD_3_HASH_TABLE_H


#include <vector>
#include "entry.h"
#include <iostream>
#include <functional>

class hash_table {
private:
    class MapNode {
    public:
        int key;
        int value;
        MapNode *next;

        MapNode(int key, int value) {
            this->key = key;
            this->value = value;
            this->next = nullptr;
        }
    };

    // The bucket array where
    // the nodes containing K-V pairs are stored
    std::vector<MapNode *> buckets;

    // No. of pairs stored - n
    size_t size{};

    // Size of the bucketArray - b
    size_t numBuckets;

    // Default loadFactor
    double DEFAULT_LOAD_FACTOR = 0.75;

    [[nodiscard]] size_t getBucketInd(int key) const;

public:
    hash_table();

    void insert(int key, int value);

    void rehash();

    void deleteAtPos(int key);
};


#endif //SIAOD_3_HASH_TABLE_H
