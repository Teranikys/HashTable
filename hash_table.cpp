//
// Created by Влад on 27.09.2023.
//

#include "hash_table.h"


/// Возвращает индекс бакета в хэш-таблице
size_t hash_table::getBucketInd(int key) const {
    // Используем встроенную функцию хеширования
    size_t hashCode = std::hash<size_t>()(key);

    // Возвращаем индекс равный делению по модулю количества бакетов
    return (hashCode % numBuckets);
}

/// Добавляет пару ключ-значение в хеш-таблицу
void hash_table::insert(int key, const entry &value) {
    // Получаем индекс нужного бакета
    size_t bucketInd = getBucketInd(key);

    // Берём первую ноду из списка
    Node *head = buckets[bucketInd];

    // Пробегаем через весь список
    while (head != nullptr) {
        // Если значение по этому ключу уже существует,
        // то обновляем значение и выходим из списка
        if (head->key == key) {
            head->value = value;
            return;
        }
        head = head->next;
    }

    // иначе создаём новую ноду для этого ключа
    auto *newElementNode = new Node(key, value);

    // Опять берём ссылку на головную ноду
    head = buckets[bucketInd];

    // новая нода вставляется путём
    // объявления её новой головной нодой
    newElementNode->next = head;

    buckets[bucketInd] = newElementNode;

    std::cout << "Пара(" << key << ", " << value << ") успешно вставлена." << '\n';

    // Увеличение размера хэштаблицы
    size++;

    // Обновляем коэффициент загрузки хэштаблицы
    double loadFactor = (double) (1 * size) / (double) numBuckets;

    std::cout << "Текущий коэффициент нагрузки = " << loadFactor << '\n';

    // Если коэффициент нагрузки становится больше 0.75,
    // то производится рехэширование
    if (loadFactor > DEFAULT_LOAD_FACTOR) {
        std::cout << loadFactor << " больше чем " << DEFAULT_LOAD_FACTOR << '\n';
        std::cout << "Поэтому будет произведено рехеширование." << '\n';

        // Rehash
        rehash();

        std::cout << "Новый размер таблицы: " << numBuckets << '\n';
    }

    std::cout << "Количество пар в таблице: " << size << '\n';
}

/// Рехэширует хэштаблицу
void hash_table::rehash() {
    std::cout << "\n~~Рехеширование начато~~\n";

    // Текущий массив бакетов становится временным
    std::vector<Node *> temp = buckets;

    // Новый массив бакетов становится в два раза больше
    buckets.resize(2 * numBuckets);

    for (int i = 0; i < 2 * numBuckets; i++) {
        // Каждый бакет инициализируется нулевым указателем
        buckets[i] = nullptr;
    }

    // Текущий размер равен нулю,
    // и мы итерируемся по старому массиву
    // и вставляем значения в новый
    size = 0;
    numBuckets *= 2;

    for (auto head: temp) {
        while (head != nullptr) {
            int key = head->key;
            entry val = head->value;

            insert(key, val);
            head = head->next;
        }
    }

    std::cout << "~~Рехеширование завершено~~\n\n";
}

hash_table::hash_table() {
    numBuckets = 5;

    buckets.resize(numBuckets);

    std::cout << "Хэш-таблица создана\n";
    std::cout << "Количество пар в таблице: " << size << '\n';
    std::cout << "Количество бакетов в таблице: " << numBuckets << '\n';
    std::cout << "Коэффициент нагрузки по умолчанию: " << DEFAULT_LOAD_FACTOR << '\n';
}

/// Удаляет элемент по заданному ключу
[[maybe_unused]] void hash_table::deleteAtKey(int key) {
    // Получаем индекс нужного бакета
    size_t bucketInd = getBucketInd(key);

    // Берём первую ноду из списка
    Node *head = buckets[bucketInd];
    bool flag = false;

    if (head != nullptr) {
        if (head->key == key) {
            delete head;
            buckets[bucketInd] = nullptr;
            flag = true;
        } else {
            // Пробегаем через весь список
            while (head->next != nullptr) {
                // Если значение по этому ключу существует,
                // то удаляем эту ноду
                if (head->next->key == key) {
                    Node *temp = head->next;
                    head->next = temp->next;
                    delete temp;
                    flag = true;
                }
                head = head->next;
            }
        }
    }
    if (flag) {
        std::cout << "Пара по ключу " << key << " успешно удалена." << '\n';

        // Уменьшение размера хэштаблицы
        size--;

        // Обновляем коэффициент загрузки хэштаблицы
        double loadFactor = (double) (1 * size) / (double) numBuckets;

        std::cout << "Текущий коэффициент нагрузки = " << loadFactor << '\n';

        std::cout << "Количество пар в таблице: " << size << '\n';
        return;
    } else {
        std::cout << "Пара по ключу " << key << " не найдена." << '\n';
    }
}

/**
 * Возвращает элемент по заданному ключу или
 * создаёт новый пустой элемент,
 * если по ключу ничего не найдено
 * */
const entry &hash_table::operator[](int key) {
    // Получаем индекс нужного бакета
    size_t bucketInd = getBucketInd(key);

    // Берём первую ноду из списка
    Node *head = buckets[bucketInd];


    // Пробегаем через весь список
    while (head != nullptr) {
        // Если значение по этому ключу существует,
        // то возвращаем значение этой ноды
        if (head->key == key) {
            return head->value;
        }
        head = head->next;
    }
    entry &NewEntry = *new entry(key, 0, "");
    insert(key, NewEntry);
    return buckets[bucketInd]->value;
}

const ostream &operator<<(ostream &os, const hash_table &out) {
    for (auto bucket : out.buckets) {
        Node *head = bucket;
        while (head != nullptr) {
            os << head->value << '\n';
            head = head->next;
        }
    }
    return os;
}
