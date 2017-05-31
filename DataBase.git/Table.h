//
// Created by Lenovo on 4/25/2017.
//

#ifndef DATABASE_TABLE_H
#define DATABASE_TABLE_H


#include <map>
#include "TableRow.h"
template <class T>
class Table {

private:
    map<int,TableRow<T>&> tableRows;
    string name;

public:

    Table(const string &name);

    /*const TableRow<T> &getTableRow(string name);*/

    void insertTableRow(TableRow<T>& row);

};


#endif //DATABASE_TABLE_H
