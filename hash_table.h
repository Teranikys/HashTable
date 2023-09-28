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

    // Массив бакетов
    std::vector<Node *> buckets;

    // Количество пар, которые лежат в хэштаблице
    size_t size{};

    // Количество бакетов
    size_t numBuckets;

    // Пороговый коэффициент загрузки по умолчанию
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
