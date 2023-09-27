//
// Created by Влад on 27.09.2023.
//

#include "hash_table.h"

/// Возвращает индекс бакета в хэш-таблице
size_t hash_table::getBucketInd(int key) const {
    // Using the inbuilt function from the object class
    size_t hashCode = std::hash<int>()(key);

    // array index = hashCode%numBuckets
    return (hashCode % numBuckets);
}

/// Добавляет пару ключ-значение в хеш-таблицу
void hash_table::insert(int key, int value) {
        // Getting the index at which it needs to be inserted
        size_t bucketInd = getBucketInd(key);

        // The first node at that index
        MapNode *head = buckets[bucketInd];

        // First, loop through all the nodes present at that index
        // to check if the key already exists
        while (head != nullptr) {
            // If already present, the value is updated
            if (head->key == key) {
                head->value = value;
                return;
            }
            head = head->next;
        }

        // new node with the K and V
        auto *newElementNode = new MapNode(key, value);

        // The head node at the index
        head = buckets[bucketInd];

        // the new node is inserted
        // by making it the head,
        // and it's next is the previous head
        newElementNode->next = head;

        buckets[bucketInd] = newElementNode;

        std::cout << "Пара(" << key << ", " << value << ") успешно вставлена." << '\n';

        // Incrementing size
        // as new K-V pair is added to the map
        size++;

        // Load factor calculated
        double loadFactor = (double)(1 * size) / (double)numBuckets;

        std::cout << "Текущий коэффициент нагрзуки = " << loadFactor << '\n';

        // If the load factor is > 0.75, rehashing is done
        if (loadFactor > DEFAULT_LOAD_FACTOR) {
            std::cout << loadFactor << " больше чем " << DEFAULT_LOAD_FACTOR << '\n';
            std::cout << "Поэтому будет произведено рехеширование." << '\n';

            // Rehash
            rehash();

            std::cout << "Новый размер таблицы: " << numBuckets << '\n';
        }

        std::cout << "Количество пар в таблице: " << size << '\n';
}

///
void hash_table::rehash() {
    std::cout << "\n~~Рехеширование начато~~\n" << '\n';

    // The present bucket list is made temp
    std::vector<MapNode *> temp = buckets;

    // A New bucketList of double the old size is created
    buckets.resize(2 * numBuckets);

    for (int i = 0; i < 2 * numBuckets; i++) {
        // Initialised to null
        buckets[i] = nullptr;
    }

    // Now size is made zero,
    // and we loop through all the nodes in the original bucket list(temp)
    // and insert it into the new list
    size = 0;
    numBuckets *= 2;

    for (auto head : temp) {
        // head of the chain at that index
        while (head != nullptr) {
            int key = head->key;
            int val = head->value;

            // calling the insert function for each node in temp
            // as the new list is now the bucketArray
            insert(key, val);
            head = head->next;
        }
    }

    std::cout << "~~Рехеширование завершено~~\n" << '\n';
}

hash_table::hash_table() {
    numBuckets = 5;

    buckets.resize(numBuckets);

    std::cout << "Хэш-таблица создана\n";
    std::cout << "Количество пар в таблице: " << size << '\n';
    std::cout << "Количество бакетов в таблице: " << numBuckets << '\n';
    std::cout << "Коэффициент нагрузки по умолчанию: " << DEFAULT_LOAD_FACTOR << '\n';
}

void hash_table::deleteAtPos(int key) {

}
