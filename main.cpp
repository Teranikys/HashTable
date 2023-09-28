#include <iostream>
#include <windows.h>
#include <fstream>
#include "hash_table.h"
#include "entry.h"

using namespace std;

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    hash_table table;
    int op;
    int recordBookNumber;
    entry newEntry;

    while (true) {
        cout << "Введите номер команды:\n";
        cout << "1. Добавить в хэштаблицу запись.\n";
        cout << "2. Удалить запись из хэштаблицы.\n";
        cout << "3. Найти запись в хештаблице по ключу.\n";
        cout << "4. Вывести все записи хэштаблицы.\n";
        cout << "5. Заполнить хэштаблицу записями из файла.\n";
        cout << "6. Закончить исполнение программы.\n";
        cin >> op;
        switch (op) {
            case 1: {
                cout << "Введите имя студента, номер его зачётной книжки и группы: \n";
                cin >> newEntry;
                table.insert(newEntry.getRecordBookNumber(), newEntry);
                break;
            }
            case 2:
                cout << "Введите номер зачётной книжки студента, \n"
                        "запись которого хотите удалить из таблицы: \n";
                cin >> recordBookNumber;
                table.deleteAtKey(recordBookNumber);
                break;
            case 3:
                cout << "Введите номер зачётной книжки, \n"
                        "студента которой хотите найти: \n";
                cin >> recordBookNumber;
                cout << table[recordBookNumber];
                break;
            case 4:
                cout << table;
                break;
            case 5: {
                ifstream in(R"(C:\\CppProjects\\SIAOD-3\\source.txt)");
                int n;
                in >> n;
                for (int i = 0; i < n; i++) {
                    in >> newEntry;
                    table.insert(newEntry.getRecordBookNumber(), newEntry);
                }
                in.close();
                break;
            }
            case 6:
                exit(0);
            default:
                cout << "Введен неверный код программы. Повторите ещё раз.\n";
                break;
        }
    }
}
