//
// Created by Влад on 27.09.2023.
//

#ifndef SIAOD_3_HASH_TABLE_H
#define SIAOD_3_HASH_TABLE_H


#include <utility>
#include <vector>
#include "entry.h"
#include "Node.h"
#include <iostream>
#include <functional>

class hash_table {
private:

    // The bucket array where
    // the nodes containing K-V pairs are stored
    std::vector<Node *> buckets;

    // No. of pairs stored - n
    size_t size{};

    // Size of the bucketArray - b
    size_t numBuckets;

    // Default loadFactor
    double DEFAULT_LOAD_FACTOR = 0.75;

    [[nodiscard]] size_t getBucketInd(int key) const;

public:
    hash_table();

    void insert(int key, const entry& value);

    void rehash();

    [[maybe_unused]] void deleteAtKey(int key);

    const entry &operator[](int key);

    friend const ostream &operator<<(ostream &os, const hash_table &out);

};


#endif //SIAOD_3_HASH_TABLE_H
