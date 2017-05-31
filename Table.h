//
// Created by Lenovo on 4/25/2017.
//

#ifndef DATABASE_TABLE_H
#define DATABASE_TABLE_H


#include <map>
#include "TableRow.h"
template <typename T, typename Y, typename V>
class Table {


private:
    map<int,TableRow<T>> intRows;
    map<int,TableRow<Y>> stringRows;
    map<int,TableRow<V>> doubleRows;
    string name;
    int count;


public:
    const string &getName() const;
    void save(string fileName);
    Table(const string &name);
    void getTableData(int num);
    void  displayTableRow(int num);
    string getRowType(int num);
    int getAllMapsSize();
    void print();

    void setName(const string &name);

    void insertIntTableRow(TableRow<T> row);

    void insertStringTableRow(TableRow<Y> row);
    void countDoubleValues(int pos,V value);
    void countIntValues(int pos, T value);
    void countStringValues(int pos,Y value);
    void insertDoubleTableRow(TableRow<V> row);
    void describeTable();
    void min(int searchColumn,int targetColumn, double value);
    void max(int searchColumn,int targetColumn, double value);
    void sum(int searchColumn,int targetColumn, double value);
};


#endif //DATABASE_TABLE_H
