
#ifndef DATABASE_TABLEREPO_H
#define DATABASE_TABLEREPO_H
#include <map>
#include "../Table.h"

template <typename T, typename Y, typename V>
class TableRepo {

public:
    TableRepo(const string &name);
    TableRepo(){};
    void addTable(Table<T, Y, V> table);
    void saveTable(string tableName, string fileName);
    void describeTableTypes(string name);
    void showTables();
    void print(string name);
    void renameTable(string oldName, string newName);
    void addColumn(string tableName,string columName, string columType);
    void count(string tableName, int searchedColumn, string value);
    void aggregate(string tableName, int searchColumn, double value, int targetColumn, string operation);
private:
    map<string, Table<T, Y, V>> savedTables;
    string name;


};
#endif //DATABASE_TABLEREPO_H


